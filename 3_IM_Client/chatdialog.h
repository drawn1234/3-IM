#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QWidget>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QWidget
{
    Q_OBJECT
signals:
     //把聊天内容发给kernel
    void sig_chatMessage(int friendId,QString content);
public:

    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

    //保存并设置好友的昵称id
    void setFriendInfo(int id,QString name);

    //把聊天内容设置到窗口上
    void setChatMessage(QString content);

    //设置好友不在线
    void setFriendInfoOffline();
private slots:
    void on_pb_send_clicked();

private:
    Ui::ChatDialog *ui;
    int m_id;
    QString m_name;
};

#endif // CHATDIALOG_H
