#include "loginwindow.h"
#include "ui_loginwindow.h"
#include<QDebug>
#include<QMessageBox>
#include<QString>
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

 //重写父类的关闭事件
void LoginWindow::closeEvent(QCloseEvent *event)
{
  //通知kernel，关闭程序
    Q_EMIT sig_closeProcess();
}

void LoginWindow::on_pb_clear_clicked()
{
    ui->le_tel->setText("");
    ui->le_password->setText("");
}


void LoginWindow::on_pb_submit_clicked()
{
    //1.

    //ui指针指向控件 返回值QString
    QString tel=ui->le_tel->text();
    QString pass=ui->le_password->text();
    QString telTmp=tel;
    QString passTmp=pass;
    //打印日志
    qDebug()<<",tel"<<tel<<",passw"<<pass;
    //2.1
    //移除所有的空格之后判断是否为空
    //remove函数会改变数据内容 会将12 3 改变为123->会改变数据长度
    //可能将不合法数据改变为合法数据
    //解决：再定义一个对象，用拷贝的对象判断是否合法
    if(tel.isEmpty()||pass.isEmpty()||
       telTmp.remove(" ").isEmpty()||
        passTmp.remove(" ").isEmpty()){
        QMessageBox::about(this,"提示","输入不能为空或全是空格");
        return;
    }

    //2.2检查长度是否合法
    //查看数据库中数据的长度
    //电话号码11，密码不超过15
    if(tel.length()!=11||pass.length()>15){
        QMessageBox::about(this,"提示","电话号码11，密码不超过15");
        return;
    }
    //2.3内容是否合法（* 昵称-密码：只能是字母数字下划线电话号码-必须全数字-11位）
    //通过asscll码判断，通过循环，取出每一个字符判断
    //-正则表达式：四阶段


    //3.把注册数据发给kernel
    //使用信号和槽
    Q_EMIT sig_loginData(tel,pass);
    //kernel里写槽函数
}


void LoginWindow::on_pb_clear_register_clicked()
{
    ui->le_name_register->setText("");
    ui->le_passwor_register->setText("");
    ui->le_tel_register->setText("");
}


void LoginWindow::on_pb_submit_register_clicked()
{
    //1.
    QString name=ui->le_name_register->text();
    //ui指针指向控件 返回值QString
    QString tel=ui->le_tel_register->text();
    QString pass=ui->le_passwor_register->text();
    QString telTmp=tel;
    QString nameTmp=name;
    QString passTmp=pass;
    //打印日志
    qDebug()<<"name:"<<name<<",tel"<<tel<<",passw"<<pass;
    //2.1
    //移除所有的空格之后判断是否为空
    //remove函数会改变数据内容 会将12 3 改变为123->会改变数据长度
    //可能将不合法数据改变为合法数据
    //解决：再定义一个对象，用拷贝的对象判断是否合法
    if(name.isEmpty()||tel.isEmpty()||pass.isEmpty()||
        nameTmp.remove(" ").isEmpty()||telTmp.remove(" ").isEmpty()||
        passTmp.remove(" ").isEmpty()){
        QMessageBox::about(this,"提示","输入不能为空或全是空格");
        return;
    }

    //2.2检查长度是否合法
    //查看数据库中数据的长度
    //昵称不超过10，电话号码11，密码不超过15
    if(name.length()>10||tel.length()!=11||pass.length()>15){
        QMessageBox::about(this,"提示","昵称不超过10，电话号码11，密码不超过15");
        return;
    }
    //2.3内容是否合法（* 昵称-密码：只能是字母数字下划线电话号码-必须全数字-11位）
    //通过asscll码判断，通过循环，取出每一个字符判断
    //-正则表达式：四阶段


    //3.把注册数据发给kernel
    //使用信号和槽
    Q_EMIT sig_registerData(name,tel,pass);
    //kernel里写槽函数



}

