#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT
signals:
    //把注册数据发给Kernel
    void sig_registerData(QString name,QString tel,QString pass);
    void sig_loginData(QString tel,QString pass);
    //通知kernel，关闭程序
    void sig_closeProcess();
public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    //重写父类的关闭事件
    void closeEvent(QCloseEvent *event);
signals:

private slots:
    void on_pb_clear_clicked();

    void on_pb_submit_clicked();

    void on_pb_clear_register_clicked();

    void on_pb_submit_register_clicked();

private:
    Ui::LoginWindow *ui;
};
#endif // LOGINWINDOW_H
