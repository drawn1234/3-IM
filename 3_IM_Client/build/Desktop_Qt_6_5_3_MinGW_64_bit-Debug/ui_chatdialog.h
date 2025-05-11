/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QGroupBox *groupBox;
    QPushButton *pb_tool1;
    QPushButton *tb_tool2;
    QPushButton *tb_tool3;
    QTextEdit *te_chat;
    QPushButton *pb_send;
    QTextBrowser *tb_chat;

    void setupUi(QWidget *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName("ChatDialog");
        ChatDialog->resize(526, 394);
        ChatDialog->setMinimumSize(QSize(526, 394));
        ChatDialog->setMaximumSize(QSize(526, 394));
        groupBox = new QGroupBox(ChatDialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 220, 441, 51));
        pb_tool1 = new QPushButton(groupBox);
        pb_tool1->setObjectName("pb_tool1");
        pb_tool1->setGeometry(QRect(0, 10, 30, 30));
        tb_tool2 = new QPushButton(groupBox);
        tb_tool2->setObjectName("tb_tool2");
        tb_tool2->setGeometry(QRect(30, 10, 30, 30));
        tb_tool3 = new QPushButton(groupBox);
        tb_tool3->setObjectName("tb_tool3");
        tb_tool3->setGeometry(QRect(60, 10, 30, 30));
        te_chat = new QTextEdit(ChatDialog);
        te_chat->setObjectName("te_chat");
        te_chat->setGeometry(QRect(20, 260, 441, 91));
        pb_send = new QPushButton(ChatDialog);
        pb_send->setObjectName("pb_send");
        pb_send->setGeometry(QRect(400, 360, 61, 21));
        tb_chat = new QTextBrowser(ChatDialog);
        tb_chat->setObjectName("tb_chat");
        tb_chat->setGeometry(QRect(20, 10, 441, 221));

        retranslateUi(ChatDialog);

        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QWidget *ChatDialog)
    {
        ChatDialog->setWindowTitle(QCoreApplication::translate("ChatDialog", "Form", nullptr));
        groupBox->setTitle(QString());
        pb_tool1->setText(QString());
        tb_tool2->setText(QString());
        tb_tool3->setText(QString());
        pb_send->setText(QCoreApplication::translate("ChatDialog", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
