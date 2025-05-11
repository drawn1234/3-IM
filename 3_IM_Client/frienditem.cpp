#include"frienditem.h"
#include "net/def.h"
#include "ui_frienditem.h"
#include<QBitmap>
friendItem::friendItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::friendItem)
{
    ui->setupUi(this);
}

friendItem::~friendItem()
{
    delete ui;
}

//保存好友信息到成员变量中并设置好友的信息
void friendItem::setFriendInfo(int friendId, QString name, QString feeling, int iconId, int status)
{
    //1.保存到成员变量中-赋值
     m_friendId=friendId;
     m_name=name;
     m_feeling=feeling;
     m_iconTd=iconId;
     m_status=status;

     //2.设置昵称和签名
     ui->lb_name->setText(m_name);//通过控件设置文本
     ui->lb_feeling->setText(m_feeling);

     //3.设置头像
     //拼接头像文件的路径
     QString path=QString(":/tx/%1.png").arg(iconId);
     //.arg(id)函数会将id的值替换到%1中。
     //判断状态是否在线
     if(_DEF_STATUS_ONLINE==m_status){
         //在线，高亮头像
         ui->pb_icon->setIcon(QIcon(path));
         //QIcon:一个有参构造函数

     }else{
         //不在线，暗显头像
         QBitmap bp;//不同的对象-二进制图对象
         bp.load(path);//用同一个文件加载
         ui->pb_icon->setIcon(bp);
     }
}

 //设置好友为下线状态
void friendItem::setFriendOffline()
{
    //设置状态为下线
    m_status=_DEF_STATUS_OFFLINE;
    //头像暗显
    QString path=QString(":/tx/%1.png").arg(m_iconTd);
    QBitmap bp;
    bp.load(path);
    ui->pb_icon->setIcon(bp);
    //重绘
    //让头像即刻暗显
    repaint();
}
//点击好友头像
void friendItem::on_pb_icon_clicked()
{
//通知krernel，显示和当前好友的聊天窗口
    Q_EMIT sig_showChatDialolg(m_friendId);
}

const QString &friendItem::name() const
{
    return m_name;
}


