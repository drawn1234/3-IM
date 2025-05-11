#include "ckernel.h"
#include"./mediator/TcpClientMediator.h"
#include<QMessageBox>
#include <QDebug>
#include <QInputDialog>

CKernel::CKernel(QObject *parent)
    : QObject{parent}
{
    setProtocol();

    //new一个好友列表窗口的对象
    m_pFriendList=new FriendList;
    //绑定下线的信号和槽函数
    connect(m_pFriendList,&FriendList::sig_offline,
            this,&CKernel::slot_offline);
    //绑定添加好友的信号和槽函数
    connect(m_pFriendList,&FriendList::sig_addFriend,
            this,&CKernel::slot_addFriend);
    //new 一个登录窗口的对象
    m_pLoginWd=new LoginWindow;
    //显示窗口
    m_pLoginWd->show();
    //绑定处理注册信息的信号和槽函数
    connect(m_pLoginWd,&LoginWindow::sig_registerData,
            this,&CKernel::slot_registerData);
    //绑定处理登录信息的信号和槽函数
    connect(m_pLoginWd,&LoginWindow::sig_loginData,
            this,&CKernel::slot_loginData);
    //绑定退出进程的信号和槽函数
    connect(m_pLoginWd,&LoginWindow::sig_closeProcess,
            this,&CKernel::slot_closeProcess);
    //new 一个中介者类的对象
    m_pMediator =new TcpClientMediator;

    //连接处理所有的信号和槽函数
    QObject::connect(m_pMediator,&TcpClientMediator::sig_dealData,
                     this,&CKernel::slot_dealData);
   //打开客户端的网络
    if(!m_pMediator->openNet()){
        //弹出一个窗口提醒用户
        QMessageBox::about(m_pLoginWd/*弹出窗口的父窗口-决定了弹出窗口的位置*/,
                           /*弹出窗口的标题-可以中文或英文*/"标题",
                           /*提示信息*/"打开网络失败");
        //退出程序
        exit(1);
    }
    //测试代码：给服务端发个登录请求
    //_STRU_LOGIN_RQ rq;
    //strcpy_s(rq.tel,"12345678900");
    //strcpy_s(rq.passw,"qwe");
    //m_pMediator->sendData((char*)&rq,sizeof(rq),23);


}

CKernel::~CKernel() {
//析构函数回收资源
    //回收登录窗口指针
    if(m_pLoginWd){
        m_pLoginWd->hide();
        delete m_pLoginWd;
        m_pLoginWd=nullptr;
    }
    //回收好友列表窗口指针
    if(m_pFriendList){
        m_pFriendList->hide();
        delete m_pFriendList;
        m_pFriendList=nullptr;
    }
    //回收中介者指针
    if(m_pMediator){
    m_pMediator->closeNet();
        delete m_pMediator;
        m_pMediator=nullptr;
    }

}
//给函数指针初始化并存入数据
void CKernel::setProtocol()
{
    qDebug()<<__func__;
    //初始化成0
    memset(m_protocol,0,sizeof(m_protocol));
    //存入数据
    m_protocol[_def_register_rs-_DEF_PROTOCOL_BASE-1]=&CKernel::dealRegisterRs;
    m_protocol[_def_login_rs   -_DEF_PROTOCOL_BASE-1]=&CKernel::dealLoginRs;
    m_protocol[_def_friend_info-_DEF_PROTOCOL_BASE-1]=&CKernel::dealFriendInfo;
    m_protocol[_def_chat_rq    -_DEF_PROTOCOL_BASE-1]=&CKernel::dealChatRq;
    m_protocol[_def_offline_rq -_DEF_PROTOCOL_BASE-1]=&CKernel::dealOfflineRq;
    m_protocol[_def_add_friend_rq -_DEF_PROTOCOL_BASE-1]=&CKernel::dealAddFriendRq;
    m_protocol[_def_add_friend_rs -_DEF_PROTOCOL_BASE-1]=&CKernel::dealAddFriendRs;


}

QString CKernel::gb2312ToUtf8(char *src)
{
    QTextCodec* dc=QTextCodec::codecForName("gb2312");
   return dc->toUnicode(src);

}

void CKernel::utf8ToGb2312(QString src, char *dst, int len)
{
    QTextCodec* dc=QTextCodec::codecForName("gb2312");
    QByteArray ba=dc->fromUnicode(src);
    strcpy_s(dst,len,ba.data());
}

//处理注册回复
void CKernel::dealRegisterRs(char *data, int len, unsigned long from)
{
    qDebug()<<__func__;
    //1.拆包
    _STRU_REGISTER_RS* rs=(_STRU_REGISTER_RS*)data;
    //2.根据结果提示用户
    switch(rs->result){
    case _DEF_REGISTER_SUCCESS:
        QMessageBox::about(m_pLoginWd,"提示","注册成功");
        break;
    case _DEF_REGISTER_TEL_EXISTS:
        QMessageBox::about(m_pLoginWd,"提示","注册失败，电话已经被注册");
        break;
    case _DEF_REGISTER_NAME_EXISTS:
        QMessageBox::about(m_pLoginWd,"提示","注册失败，昵称已经被注册");
        break;
    default:
        break;
    }

    qDebug()<<"result:"<<rs->result;
}
 //处理登录回复
void CKernel::dealLoginRs(char *data, int len, unsigned long from)
{
    qDebug()<<__func__;
    //1.拆包
    _STRU_LOGIN_RS* rs=(_STRU_LOGIN_RS*)data;

    //2.根据结果提示用户
    switch(rs->result){
    case _DEF_LOGIN_SUCCESS:
        {
        //保存用户的id
        m_id=rs->userId;
        //隐藏登录界面，显示好友界面
        m_pLoginWd->hide();
        m_pFriendList->show();
    }
        break;
    case _DEF_LOGIN_TEL_NOT_EXISTS:
        QMessageBox::about(m_pLoginWd,"提示","登录失败，电话未注册");
        break;
    case _DEF_LOGIN_PASSW_ERROR:
        QMessageBox::about(m_pLoginWd,"提示","登录失败，密码错误");
        break;
    default:
        break;
    }


    qDebug()<<"result:"<<rs->result;
}
//处理自己和好友的信息
void CKernel::dealFriendInfo(char *data, int len, unsigned long from)
{
    qDebug()<<__func__;
    //1.拆包
    _STRU_FRIEND_INFO* info=(_STRU_FRIEND_INFO*)data;
    QString name=gb2312ToUtf8(info->name);
    QString feeling=gb2312ToUtf8(info->feeling);

    //qDebug()<<"name:"<<info->name<<",id:"<<info->id;

    //2.判断是不是自己的信息
    //-在登录成功的时候
    if(m_id==info->id){
        //保存自己的信息
        m_name=name;
        //把自己的信息设置到用户界面上
        m_pFriendList->setUserInfo(name,feeling,info->iconId);
        return;
    }

    //是好友的信息，判断是否添加到列表上
    if(m_mapIdToFriendItem.count(info->id)>0){

        //如果已经在列表上
        //取出好友的对象
        friendItem* item= m_mapIdToFriendItem[info->id];
        //更新好友的信息
        item->setFriendInfo(info->id,name,feeling,info->iconId,info->status);
    }else{

        //没有在列表上
        //new一个好友对象
        friendItem* item=new friendItem;
        //设置好友的信息
        item->setFriendInfo(info->id,name,feeling,info->iconId,info->status);
        //把好友添加到列表上
        m_pFriendList->addFriendList(item);
        //保存好友的对象friendItem<map>
        m_mapIdToFriendItem[info->id]=item;

        //绑定显示窗口的信号和槽函数
        connect(item,&friendItem::sig_showChatDialolg,
               this,&CKernel::slot_showChatDialolg);
        //new一个跟这个好友的聊天窗口
        ChatDialog* chat=new ChatDialog;
        //设置聊天窗口
        chat->setFriendInfo(info->id,name);

        //把聊天窗口保存到map中
        m_mapIdTocChatdlg[info->id]=chat;

        //绑定发送聊天内容的信号和槽函数
        connect(chat,&ChatDialog::sig_chatMessage,
                this,&CKernel::slot_chatMessage);
    }

}

//处理聊天请求
void CKernel::dealChatRq(char *data, int len, unsigned long from)
{
    qDebug()<<__func__;
    //1.拆包
    _STRU_CHAT_RQ* rq=(_STRU_CHAT_RQ*)data;

    //2.判断跟A客户端的聊天窗口是否存在
    if(m_mapIdTocChatdlg.count(rq->myId)>0){
        //取出跟A客户端的聊天窗口
        ChatDialog* chat=m_mapIdTocChatdlg[rq->myId];
        //把聊天内容设置到窗口上
        chat->setChatMessage(rq->content);
        //显示窗口
        chat->show();
    }
}

 //处理聊天回复（A是客户端，B好友不在线）
void CKernel::dealChatRs(char *data, int len, unsigned long from)
{
    qDebug()<<__func__;
    //1.拆包
     _STRU_CHAT_RS* rs=(_STRU_CHAT_RS*)data;

    //2.判断跟B客户端的聊天窗口是否存在
    if(m_mapIdTocChatdlg.count(rs->friendId)>0){
        //取出跟B客户端的聊天窗口
        ChatDialog* chat=m_mapIdTocChatdlg[rs->friendId];
        //把B不在线设置到窗口上
        chat->setFriendInfoOffline();
        //显示窗口
        chat->show();
    }
}
//处理下线请求（B是客户端，好友A下线了）
void CKernel::dealOfflineRq(char *data, int len, unsigned long from)
{
    qDebug()<<__func__;
    //1.拆包
    _STRU_OFFLINE_RQ* rq=(_STRU_OFFLINE_RQ*)data;

    //2.找到好友A的friendItem
    if(m_mapIdToFriendItem.count(rq->id)>0){
        //取出好友的friendItem
        friendItem* item=m_mapIdToFriendItem[rq->id];
        //设置好友为下线状态
        item->setFriendOffline();
    }

}
//处理添加好友请求(B客户端)
void CKernel::dealAddFriendRq(char *data, int len, unsigned long from)
{

    qDebug()<<__func__;
    //1.拆包
    _STRU_ADD_FRIEND_RQ* rq=(_STRU_ADD_FRIEND_RQ*)data;
    //弹出窗口询问，是否统一添加好友
    _STRU_ADD_FRIEND_RS rs;
    rs.myId=rq->myId;
    rs.friendId=m_id;
    strcpy_s(rs.myName,sizeof(rs.myName),rq->myName);
    strcpy_s(rs.friendName,sizeof(rs.friendName),rq->friendName);
    if(QMessageBox::Yes == QMessageBox::question(m_pFriendList,"添加好友",QString("【%1】想要添加你为好友，是否同意？").arg(rq->myName))){
        rs.result=_DEF_ADD_FRIEND_SUCCESS;
    }else{
        rs.result=_DEF_ADD_FRIEND_REFUSE;
    }
    //3.把添加结果发送给服务端
    m_pMediator->sendData((char*)&rs,sizeof(rs),67);
}
//处理添加好友回复（A客户端）
void CKernel::dealAddFriendRs(char *data, int len, unsigned long from)
{
    qDebug()<<__func__;
    //1.拆包
    _STRU_ADD_FRIEND_RS* rs=(_STRU_ADD_FRIEND_RS*)data;
    QString friendName=gb2312ToUtf8(rs->friendName);
    //2.根据回复的结果提示用户
    switch(rs->result){
    case _DEF_ADD_FRIEND_SUCCESS:
        QMessageBox::about(m_pFriendList,"提示",QString("添加【%1】为好友成功").arg(friendName));
        break;

    case _DEF_ADD_FRIEND_NOT_EXISTS:
        QMessageBox::about(m_pFriendList,"提示",QString("添加【%1】为好友失败，该用户不存在").arg(friendName));
        break;

    case _DEF_ADD_FRIEND_OFFLINE:
        QMessageBox::about(m_pFriendList,"提示",QString("添加【%1】为好友失败，好友不在线").arg(friendName));
        break;

    case _DEF_ADD_FRIEND_REFUSE:
        QMessageBox::about(m_pFriendList,"提示",QString("添加【%1】为好友失败，好友拒绝").arg(friendName));
        break;

    }

}



//处理所有接收到的数据
//处理回复请求
void CKernel::slot_dealData(char* data,int len,unsigned long from){
    qDebug()<<__func__;

    //取出协议头
    packtype type=*(packtype*)data;

    //计算数组下标
    int index=type-_DEF_PROTOCOL_BASE-1;
    //判断下标是否有效
    if(index>=0&&index<_DEF_PROTOCOL_COUNT){
        //根据数组下标，取出函数地址
        PFUN pf=m_protocol[index];
        if(pf){
            (this->*pf)(data,len,from);
        }else{
            qDebug()<<"type2:"<<type;
        }
    }else{
        qDebug()<<"type1:"<<type;
    }
    delete []data;
}
//处理注册数据，发给服务端
void CKernel::slot_registerData(QString name, QString tel, QString pass)
{
    qDebug()<<__func__;
    //1.打包
    _STRU_REGISTER_RQ rq;
   // strcpy_s(rq.name,sizeof(rq.name),name.toStdString().c_str());
    utf8ToGb2312(name,rq.name,sizeof(rq.name));
    strcpy_s(rq.tel,sizeof(rq.tel),tel.toStdString().c_str());
    strcpy_s(rq.passw,sizeof(rq.passw),pass.toStdString().c_str());
    //2.发给服务端
    m_pMediator->sendData((char*)&rq,sizeof(rq),89);
}
//处理登录的信息
void CKernel::slot_loginData(QString tel, QString pass)
{
    qDebug()<<__func__;
    //1.打包
    _STRU_LOGIN_RQ rq;
    strcpy_s(rq.tel,sizeof(rq.tel),tel.toStdString().c_str());
    strcpy_s(rq.passw,sizeof(rq.passw),pass.toStdString().c_str());
    //2.发给服务端
    m_pMediator->sendData((char*)&rq,sizeof(rq),89);
}

//通知kernel，显示和当前好友的窗口
void CKernel::slot_showChatDialolg(int friendId)
{
    qDebug()<<__func__;
    //判断map中有没有这个聊天窗口，有就取出来
    if(m_mapIdTocChatdlg.count(friendId)>0){
        ChatDialog* chat=m_mapIdTocChatdlg[friendId];
        chat->show();
    }
}

//处理聊天内容，发给服务端
void CKernel::slot_chatMessage(int friendId, QString content)
{
    qDebug()<<__func__;
//1.打包
    _STRU_CHAT_RQ rq;
    rq.myId=m_id;
    rq.friendId=friendId;
    strcpy_s(rq.content,sizeof(rq.content),content.toStdString().c_str());

    //2.发给服务端
    m_pMediator->sendData((char*)&rq,sizeof(rq),89);
}

//处理关闭程序的信号
void CKernel::slot_closeProcess()
{
    qDebug()<<__func__;
    //1.回收资源
    if(m_pLoginWd){
        m_pLoginWd->hide();
        delete m_pLoginWd;
        m_pLoginWd=nullptr;
    }
    if(m_pMediator){
        m_pMediator->closeNet();
        delete m_pMediator;
        m_pMediator=nullptr;
    }
    if(m_pFriendList){
        m_pFriendList->hide();
        delete m_pFriendList;
        m_pFriendList=nullptr;
    }

    for(auto ite=m_mapIdTocChatdlg.begin();ite !=m_mapIdTocChatdlg.end();){
        //取出节点中的窗口对象
        ChatDialog* chat=ite.value();
        //回收窗口对象
        if(chat){
            chat->hide();
            delete chat;
            chat=nullptr;
        }
        //把无效节点从map中移除（erase函数的返回值是下一个有效节点）
        ite=m_mapIdTocChatdlg.erase(ite);
    }
    //2.退出进程
    exit(0);
}

//处理下线的信号
void CKernel::slot_offline()
{
    qDebug()<<__func__;
    //1.给服务端发送下线请求
    _STRU_OFFLINE_RQ rq;
    rq.id=m_id;
    m_pMediator->sendData((char*)&rq,sizeof(rq),67);
    //2.回收资源，退出进程
    slot_closeProcess();

}

//处理添加好友的信号
void CKernel::slot_addFriend()
{
    qDebug()<<__func__;

    //弹出一个窗口，让用户输入好友的昵称
    QString name=QInputDialog::getText(m_pFriendList,"添加好友","请输入好友的昵称");
    QString nameTmp=name;
    //判断字符串是否为空或者全是空格
    if(name.isEmpty()||nameTmp.remove("").isEmpty()){
        QMessageBox::about(m_pFriendList,"提示","请输入正确的好友昵称");
        return;
    }
    //判断是否是自己的昵称
    if(m_name==name){
        QMessageBox::about(m_pFriendList,"提示","不能添加自己为好友");
        return;
    }

    //判断是否已经是自己的好友，遍历每一个好友
    for(auto ite=m_mapIdToFriendItem.begin();ite!=m_mapIdToFriendItem.end();ite++){
        //取出好友的friendItem
        friendItem* item=ite.value();
        //判断好友的昵称和输入的昵称是否相同
        if(name==item->name()){
            QMessageBox::about(m_pFriendList,"提示","已经是好友，不能重复添加");
        }
    }

    //给服务端发送添加好友请求
    _STRU_ADD_FRIEND_RQ rq;
    rq.myId=m_id;
    strcpy_s(rq.myName,sizeof(rq.myName),m_name.toStdString().c_str());
    utf8ToGb2312(name,rq.friendName,sizeof(rq.friendName));
    m_pMediator->sendData((char*)&rq,sizeof(rq),2);

}
