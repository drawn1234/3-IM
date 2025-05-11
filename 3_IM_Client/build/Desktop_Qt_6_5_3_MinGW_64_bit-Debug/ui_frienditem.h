/********************************************************************************
** Form generated from reading UI file 'frienditem.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDITEM_H
#define UI_FRIENDITEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_friendItem
{
public:
    QPushButton *pb_icon;
    QLabel *lb_name;
    QLabel *lb_feeling;

    void setupUi(QWidget *friendItem)
    {
        if (friendItem->objectName().isEmpty())
            friendItem->setObjectName("friendItem");
        friendItem->resize(302, 73);
        friendItem->setMinimumSize(QSize(302, 73));
        friendItem->setMaximumSize(QSize(302, 73));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(11);
        friendItem->setFont(font);
        pb_icon = new QPushButton(friendItem);
        pb_icon->setObjectName("pb_icon");
        pb_icon->setGeometry(QRect(10, 10, 50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tx/24.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_icon->setIcon(icon);
        pb_icon->setIconSize(QSize(50, 50));
        pb_icon->setFlat(true);
        lb_name = new QLabel(friendItem);
        lb_name->setObjectName("lb_name");
        lb_name->setGeometry(QRect(70, 0, 221, 30));
        lb_feeling = new QLabel(friendItem);
        lb_feeling->setObjectName("lb_feeling");
        lb_feeling->setGeometry(QRect(70, 30, 221, 30));

        retranslateUi(friendItem);

        QMetaObject::connectSlotsByName(friendItem);
    } // setupUi

    void retranslateUi(QWidget *friendItem)
    {
        friendItem->setWindowTitle(QCoreApplication::translate("friendItem", "Form", nullptr));
        pb_icon->setText(QString());
        lb_name->setText(QCoreApplication::translate("friendItem", "\351\272\273\350\276\243\345\244\247\350\245\277\347\223\234", nullptr));
        lb_feeling->setText(QCoreApplication::translate("friendItem", "\345\245\275\344\272\272\344\270\200\347\224\237\345\271\263\345\256\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class friendItem: public Ui_friendItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDITEM_H
