#ifndef FRIENDITEM_H
#define FRIENDITEM_H

#include <QWidget>

namespace Ui {
class friendItem;
}

class friendItem : public QWidget
{
    Q_OBJECT
signals:
    //通知kernel，显示和当前好友的窗口
    void sig_showChatDialolg(int friendId);
public:
    explicit friendItem(QWidget *parent = nullptr);
    ~friendItem();

    //保存好友信息到成员变量中并设置好友的信息
    //好友信息需要使用，局部变量会回收
    void setFriendInfo(int friendId,QString name,QString feeling,int iconId,int status);

    //设置好友为下线状态
    void setFriendOffline();
    const QString &name() const;


private slots:
    void on_pb_icon_clicked();

private:
    Ui::friendItem *ui;
    int     m_friendId;
    QString m_name;
    QString m_feeling;
    int     m_iconTd;
    int     m_status;
};

#endif // FRIENDITEM_H
