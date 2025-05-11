#ifndef CKERNEL_H
#define CKERNEL_H

#include <QMap>
#include <QObject>
#include <QTextCodec>
#include <chatdialog.h>
#include "./net/def.h"
#include "loginwindow.h"
#include "friendlist.h"
#include"frienditem.h"
#include "./mediator/INetMediator.h"
class CKernel;
typedef void(CKernel::*PFUN)(char* data,int len,unsigned long from);
class CKernel : public QObject
{
    Q_OBJECT
public:
    explicit CKernel(QObject *parent = nullptr);
    ~CKernel();
    //给函数指针数组初始呼化
    void setProtocol();

    //gb2312转UTF-8
    QString gb2312ToUtf8(char* src);
     //src：gb2312指向的空间，是一个字符串，长度可知，不需要标明长度；QString：uft8转化为Qstring格式

    //UTF-8转GB2312
    void utf8ToGb2312(QString src,char* dst,int len);
     //src:UTF8原始数据;dst：目标数据：GBF8；目标数据需要空间存储-dst，需要标明长度

    //处理注册回复
     void dealRegisterRs(char* data,int len,unsigned long from);

    //处理登录回复
     void dealLoginRs(char* data,int len,unsigned long from);

     //处理好友信息
     void dealFriendInfo(char* data,int len,unsigned long from);

     //处理聊天请求
     void dealChatRq(char* data,int len,unsigned long from);

     //处理聊天回复
     void dealChatRs(char* data,int len,unsigned long from);


     //处理下线请求
     void dealOfflineRq(char* data,int len,unsigned long from);

     //处理添加好友请求（B客户端）
     void dealAddFriendRq(char* data,int len,unsigned long from);

     //处理添加好友回复(A客户端)
     void dealAddFriendRs(char* data,int len,unsigned long from);




signals:

private slots:
    //处理所有接收到的数据
    void slot_dealData(char* data,int len,unsigned long from);

    //处理注册数据，发给服务器
    void slot_registerData(QString name,QString tel,QString pass);

    //处理登录数据，发给服务端
    void slot_loginData(QString tel,QString pass);


    //通知kernel，显示和当前好友的窗口
    void slot_showChatDialolg(int friendId);


    //处理聊天内容，发给服务端
    void slot_chatMessage(int friendId,QString content);

     //处理关闭程序的信号
    void slot_closeProcess();

    //处理下线的信号
    void slot_offline();

    //处理添加好友的信号
    void slot_addFriend();
private:
    int m_id;//自己的id
    QString m_name;
    LoginWindow* m_pLoginWd;
    INetMediator*  m_pMediator;
    PFUN m_protocol[_DEF_PROTOCOL_COUNT];
    FriendList* m_pFriendList;
    //保存好友的对象friendItem
    QMap<int,friendItem*> m_mapIdToFriendItem;
    //保存跟好友的聊天窗口
    QMap<int,ChatDialog*> m_mapIdTocChatdlg;

};

#endif // CKERNEL_H
