#include "friendlist.h"
#include "ui_friendlist.h"

#include <QMessageBox>
#include<QCloseEvent>
#include<QDebug>
FriendList::FriendList(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FriendList)
{
    ui->setupUi(this);
    //new一个垂直布局的层的对象
    m_pLayout=new QVBoxLayout;
    //设置小控件之间的距离
    m_pLayout->setSpacing(3);
    //设置小控件和大控件之间的距离
    m_pLayout->setContentsMargins(0,0,0,0);//左上右下
    //把层设置到大控件上
    ui->wdg_list->setLayout(m_pLayout);
    //new一个菜单的对象
    m_pMenu=new QMenu;
    //添加菜单项
    m_pMenu->addAction("添加好友");
    m_pMenu->addAction("系统设置");
    //绑定菜单栏的槽函数
    connect(m_pMenu,&QMenu::triggered,
            this,&FriendList::slote_menuTriggered);
}

FriendList::~FriendList()
{
    delete ui;
    //回收指针
    if(m_pLayout){
        delete m_pLayout;
        m_pLayout=nullptr;
    }
}

void FriendList::setUserInfo(QString name, QString feeling, int iconId)
{
    ui->lb_name->setText(name);
    ui->le_feeling->setText(feeling);
    QString path=QString(":/tx/%1.png").arg(iconId);
    ui->pb_icon->setIcon(QIcon(path));

}

void FriendList::addFriendList(friendItem *item)
{
    m_pLayout->addWidget(item);
}
//重写关闭程序事件
void FriendList::closeEvent(QCloseEvent* event)
{

    //1.忽略关闭事件
    event->ignore();
    //2.弹出询问窗口，是否关闭
    if(QMessageBox::Yes==QMessageBox::question(this,"询问","是否关闭窗口")){
        //通知kernel，下线
        Q_EMIT sig_offline();
    }
}
//在鼠标点击的位置向上弹出一个菜单栏
void FriendList::on_pb_menu_clicked()
{
    //1.获取鼠标的位置
    QPoint p=QCursor::pos();

    //获取菜单的绝对大小
    QSize size =m_pMenu->sizeHint();
    //2.显示菜单
    QPoint pa=QPoint(p.x(),p.y()-size.height());
    m_pMenu->exec(pa);
}

//点击菜单栏的槽函数
void FriendList::slote_menuTriggered(QAction *action)
{
    qDebug()<<__func__;
    //1.判断用户点击的是哪个功能
    if(action->text()=="添加好友"){
        //通知kernel，添加好友
        Q_EMIT sig_addFriend();
    }else if(action->text()=="系统设置"){
        qDebug()<<"系统设置";
    }

}

