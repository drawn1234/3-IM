#include "chatdialog.h"
#include "ui_chatdialog.h"
#include <QTime>
ChatDialog::ChatDialog(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatDialog)
{
    ui->setupUi(this);
}

ChatDialog::~ChatDialog()
{
    delete ui;
}

//保存并设置好友的id和昵称
void ChatDialog::setFriendInfo(int id, QString name)
{
//保存好友的昵称和id
    m_id=id;
    m_name=name;
    //设置窗口的属性
    setWindowTitle(QString("与【%1】的聊天窗口").arg(m_name));

}
//把聊天内容设置到窗口上
void ChatDialog::setChatMessage(QString content)
{
    ui->tb_chat->append(QString("【%1】%2").arg(m_name).arg(QTime::currentTime().toString("hh::mm::ss")));
    ui->tb_chat->append(content);
}

//设置好友不在线
void ChatDialog::setFriendInfoOffline()
{
    ui->tb_chat->append(QString("【%1】%2 不在线").arg(m_name).arg(QTime::currentTime().toString("hh::mm::ss")));
}

//点击发送按钮
void ChatDialog::on_pb_send_clicked()
{
//1.获取用户输入的信息
    QString content=ui->te_chat->toPlainText();
//2.判断是否为空或者全是空格
    if(content.isEmpty()||content.remove("").isEmpty()){
        ui->te_chat->setText("");
        return;
    }
//3.获取用户输入的内容（带格式）
    content=ui->te_chat->toHtml();
//4.显示输入的内容到聊天窗口上
    ui->tb_chat->append(QString("我【%1】").arg(QTime::currentTime().toString("hh:mm::ss")));
    ui->tb_chat->append(content);
//5.清空编辑窗口
    ui->te_chat->setText("");
//6.把信息发给Kernel
    Q_EMIT sig_chatMessage(m_id,content);
}

