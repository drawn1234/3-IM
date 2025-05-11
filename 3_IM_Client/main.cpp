#include "loginwindow.h"
#include "ckernel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CKernel kernel;
    return a.exec();
}



//QT的信号和槽机机制
//QT特有，有QT的编译器和QT的类才能实现
//QT特有的类，继承QMainWindow 或者Q_OBJECT
//1.自带槽 通过控件动作，绑定槽

//2.自定义槽
//功能（通知事件发送或者传输数据，两个类之间）
//1.两个类必须继承，直接或者间接继承自QObject，并且有Q_OBJECT宏才能使用
//2.在发送数据的类的头文件中使用signal声明信号，返回值必须是void，不能通过返回值返回数据
// 参数就是要传输的数据，也可以没有参数（单纯通知事件）
// 信号不是函数，不需要cpp中实现，需要在通知或者发送数据的地方使用Q_EMIT发送信号/qemit 信号名（参数列表）
//3.在接收数据的类的头文件中使用slots，声明槽函数 -public Slots/private slots /protected slots
// 槽函数的参数和返回值一模一样
// 槽函数需要在cpp中实现-收到数据后要实现的功能
//4.在接收数据的类里，发送信号的对象new出来的下面，连接信号和槽函数

//QT使用UTF-8编码，VS使用gb2312编码
//统一在客户端转码，英文和字母不管什么编码方式都一样
//QT先转成2312，再发给VS
//QT接收到的数据，先转发给UFT-8，再设置到界面上
//UTF-8编码方式的字符串存储在QString里
//gb2312编码方式的字符串保存在char*里
