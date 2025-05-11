#ifndef FRIENDLIST_H
#define FRIENDLIST_H
#include <QMenu>
#include <QDialog>
#include <QVBoxLayout>
#include"frienditem.h"
namespace Ui {
class FriendList;
}

class FriendList : public QDialog
{
    Q_OBJECT
signals:
    void sig_offline();
    //添加好友的信号
    void sig_addFriend();
public:
    explicit FriendList(QWidget *parent = nullptr);
    ~FriendList();

    //添加自己的信息
    void setUserInfo(QString name,QString feeling,int iconId);
    //添加好友到列表上
    void addFriendList(friendItem* item);
    //重写关闭程序事件
    void closeEvent(QCloseEvent* event);
private slots:
    void on_pb_menu_clicked();
    //点击菜单栏的槽函数
    void slote_menuTriggered(QAction *action);

private:
    Ui::FriendList *ui;
    //定义一个垂直布局层
    QVBoxLayout* m_pLayout;
    //定义一个菜单
    QMenu* m_pMenu;

};

#endif // FRIENDLIST_H
