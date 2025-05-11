/********************************************************************************
** Form generated from reading UI file 'friendlist.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLIST_H
#define UI_FRIENDLIST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendList
{
public:
    QPushButton *pb_icon;
    QLabel *lb_name;
    QLineEdit *le_feeling;
    QTabWidget *tw_page;
    QWidget *page_space;
    QWidget *page_friend;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *wdg_list;
    QSpacerItem *verticalSpacer;
    QWidget *page_message;
    QPushButton *pb_menu;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *FriendList)
    {
        if (FriendList->objectName().isEmpty())
            FriendList->setObjectName("FriendList");
        FriendList->resize(350, 642);
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(11);
        FriendList->setFont(font);
        pb_icon = new QPushButton(FriendList);
        pb_icon->setObjectName("pb_icon");
        pb_icon->setGeometry(QRect(20, 10, 60, 60));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tx/22.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_icon->setIcon(icon);
        pb_icon->setIconSize(QSize(60, 60));
        pb_icon->setFlat(true);
        lb_name = new QLabel(FriendList);
        lb_name->setObjectName("lb_name");
        lb_name->setGeometry(QRect(80, 0, 51, 30));
        le_feeling = new QLineEdit(FriendList);
        le_feeling->setObjectName("le_feeling");
        le_feeling->setGeometry(QRect(80, 30, 221, 30));
        tw_page = new QTabWidget(FriendList);
        tw_page->setObjectName("tw_page");
        tw_page->setGeometry(QRect(10, 80, 331, 521));
        page_space = new QWidget();
        page_space->setObjectName("page_space");
        tw_page->addTab(page_space, QString());
        page_friend = new QWidget();
        page_friend->setObjectName("page_friend");
        scrollArea = new QScrollArea(page_friend);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 321, 501));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 319, 499));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        wdg_list = new QWidget(scrollAreaWidgetContents);
        wdg_list->setObjectName("wdg_list");

        verticalLayout->addWidget(wdg_list);

        verticalSpacer = new QSpacerItem(20, 340, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);
        tw_page->addTab(page_friend, QString());
        page_message = new QWidget();
        page_message->setObjectName("page_message");
        tw_page->addTab(page_message, QString());
        pb_menu = new QPushButton(FriendList);
        pb_menu->setObjectName("pb_menu");
        pb_menu->setGeometry(QRect(10, 600, 30, 30));
        pushButton_3 = new QPushButton(FriendList);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(260, 600, 30, 30));
        pushButton_4 = new QPushButton(FriendList);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(210, 600, 30, 30));
        pushButton_5 = new QPushButton(FriendList);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(310, 600, 30, 30));

        retranslateUi(FriendList);

        tw_page->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FriendList);
    } // setupUi

    void retranslateUi(QDialog *FriendList)
    {
        FriendList->setWindowTitle(QCoreApplication::translate("FriendList", "Dialog", nullptr));
        pb_icon->setText(QString());
        lb_name->setText(QCoreApplication::translate("FriendList", "\345\210\230\346\263\275\346\263\275", nullptr));
        le_feeling->setText(QCoreApplication::translate("FriendList", "\345\225\246\345\225\246\345\225\246\345\225\246\345\225\246", nullptr));
        tw_page->setTabText(tw_page->indexOf(page_space), QCoreApplication::translate("FriendList", "\347\251\272\351\227\264", nullptr));
        tw_page->setTabText(tw_page->indexOf(page_friend), QCoreApplication::translate("FriendList", "\350\201\224\347\263\273\344\272\272", nullptr));
        tw_page->setTabText(tw_page->indexOf(page_message), QCoreApplication::translate("FriendList", "\346\266\210\346\201\257", nullptr));
        pb_menu->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendList: public Ui_FriendList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLIST_H
