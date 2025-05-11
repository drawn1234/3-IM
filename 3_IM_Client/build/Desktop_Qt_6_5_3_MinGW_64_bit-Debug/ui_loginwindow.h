/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *lb_icon;
    QTabWidget *tb_page;
    QWidget *page_login;
    QLabel *lb_tel;
    QLabel *lb_password;
    QLineEdit *le_tel;
    QLineEdit *le_password;
    QPushButton *pb_clear;
    QPushButton *pb_submit;
    QWidget *ta_register;
    QLabel *lb_tel_register;
    QLabel *lb_password_register;
    QLineEdit *le_tel_register;
    QLineEdit *le_passwor_register;
    QPushButton *pb_submit_register;
    QPushButton *pb_clear_register;
    QLineEdit *le_name_register;
    QLabel *lb_name_register;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(586, 413);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        lb_icon = new QLabel(centralwidget);
        lb_icon->setObjectName("lb_icon");
        lb_icon->setGeometry(QRect(0, 0, 281, 461));
        lb_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/register.png")));
        lb_icon->setScaledContents(true);
        tb_page = new QTabWidget(centralwidget);
        tb_page->setObjectName("tb_page");
        tb_page->setGeometry(QRect(280, 0, 471, 461));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(12);
        tb_page->setFont(font);
        page_login = new QWidget();
        page_login->setObjectName("page_login");
        lb_tel = new QLabel(page_login);
        lb_tel->setObjectName("lb_tel");
        lb_tel->setGeometry(QRect(30, 80, 51, 21));
        lb_password = new QLabel(page_login);
        lb_password->setObjectName("lb_password");
        lb_password->setGeometry(QRect(40, 150, 51, 20));
        le_tel = new QLineEdit(page_login);
        le_tel->setObjectName("le_tel");
        le_tel->setGeometry(QRect(80, 80, 201, 21));
        le_password = new QLineEdit(page_login);
        le_password->setObjectName("le_password");
        le_password->setGeometry(QRect(80, 150, 201, 21));
        le_password->setEchoMode(QLineEdit::EchoMode::Password);
        pb_clear = new QPushButton(page_login);
        pb_clear->setObjectName("pb_clear");
        pb_clear->setGeometry(QRect(70, 230, 51, 31));
        pb_submit = new QPushButton(page_login);
        pb_submit->setObjectName("pb_submit");
        pb_submit->setGeometry(QRect(170, 230, 51, 31));
        tb_page->addTab(page_login, QString());
        ta_register = new QWidget();
        ta_register->setObjectName("ta_register");
        lb_tel_register = new QLabel(ta_register);
        lb_tel_register->setObjectName("lb_tel_register");
        lb_tel_register->setGeometry(QRect(19, 80, 51, 21));
        lb_password_register = new QLabel(ta_register);
        lb_password_register->setObjectName("lb_password_register");
        lb_password_register->setGeometry(QRect(30, 130, 51, 20));
        le_tel_register = new QLineEdit(ta_register);
        le_tel_register->setObjectName("le_tel_register");
        le_tel_register->setGeometry(QRect(70, 80, 201, 21));
        le_passwor_register = new QLineEdit(ta_register);
        le_passwor_register->setObjectName("le_passwor_register");
        le_passwor_register->setGeometry(QRect(70, 130, 201, 21));
        le_passwor_register->setEchoMode(QLineEdit::EchoMode::Password);
        pb_submit_register = new QPushButton(ta_register);
        pb_submit_register->setObjectName("pb_submit_register");
        pb_submit_register->setGeometry(QRect(170, 250, 51, 31));
        pb_clear_register = new QPushButton(ta_register);
        pb_clear_register->setObjectName("pb_clear_register");
        pb_clear_register->setGeometry(QRect(80, 250, 51, 31));
        le_name_register = new QLineEdit(ta_register);
        le_name_register->setObjectName("le_name_register");
        le_name_register->setGeometry(QRect(70, 180, 201, 21));
        lb_name_register = new QLabel(ta_register);
        lb_name_register->setObjectName("lb_name_register");
        lb_name_register->setGeometry(QRect(30, 180, 51, 20));
        tb_page->addTab(ta_register, QString());
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 586, 18));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        tb_page->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        lb_icon->setText(QString());
        lb_tel->setText(QCoreApplication::translate("LoginWindow", "\346\211\213\346\234\272\345\217\267", nullptr));
        lb_password->setText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201", nullptr));
        le_tel->setText(QCoreApplication::translate("LoginWindow", "12345678900", nullptr));
        le_password->setText(QCoreApplication::translate("LoginWindow", "123x", nullptr));
        pb_clear->setText(QCoreApplication::translate("LoginWindow", "\346\270\205\347\251\272", nullptr));
        pb_submit->setText(QCoreApplication::translate("LoginWindow", "\346\217\220\344\272\244", nullptr));
        tb_page->setTabText(tb_page->indexOf(page_login), QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        lb_tel_register->setText(QCoreApplication::translate("LoginWindow", "\346\211\213\346\234\272\345\217\267", nullptr));
        lb_password_register->setText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201", nullptr));
        pb_submit_register->setText(QCoreApplication::translate("LoginWindow", "\346\217\220\344\272\244", nullptr));
        pb_clear_register->setText(QCoreApplication::translate("LoginWindow", "\346\270\205\347\251\272", nullptr));
        lb_name_register->setText(QCoreApplication::translate("LoginWindow", "\346\230\265\347\247\260", nullptr));
        tb_page->setTabText(tb_page->indexOf(ta_register), QCoreApplication::translate("LoginWindow", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
