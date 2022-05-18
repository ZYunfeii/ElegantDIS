/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interface
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *ip_edit;
    QLabel *label_2;
    QLineEdit *port_edit;
    QLabel *label;
    QPushButton *connect_button;
    QTextBrowser *info_browser;

    void setupUi(QWidget *interface)
    {
        if (interface->objectName().isEmpty())
            interface->setObjectName(QStringLiteral("interface"));
        interface->resize(536, 379);
        gridLayout = new QGridLayout(interface);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        ip_edit = new QLineEdit(interface);
        ip_edit->setObjectName(QStringLiteral("ip_edit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ip_edit);

        label_2 = new QLabel(interface);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        port_edit = new QLineEdit(interface);
        port_edit->setObjectName(QStringLiteral("port_edit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, port_edit);

        label = new QLabel(interface);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        verticalLayout->addLayout(formLayout);

        connect_button = new QPushButton(interface);
        connect_button->setObjectName(QStringLiteral("connect_button"));

        verticalLayout->addWidget(connect_button);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        info_browser = new QTextBrowser(interface);
        info_browser->setObjectName(QStringLiteral("info_browser"));

        gridLayout->addWidget(info_browser, 1, 0, 1, 1);


        retranslateUi(interface);

        QMetaObject::connectSlotsByName(interface);
    } // setupUi

    void retranslateUi(QWidget *interface)
    {
        interface->setWindowTitle(QApplication::translate("interface", "Form", Q_NULLPTR));
        ip_edit->setText(QApplication::translate("interface", "127.0.0.1", Q_NULLPTR));
        label_2->setText(QApplication::translate("interface", "HostPort:", Q_NULLPTR));
        port_edit->setText(QApplication::translate("interface", "9999", Q_NULLPTR));
        label->setText(QApplication::translate("interface", "HostIP:", Q_NULLPTR));
        connect_button->setText(QApplication::translate("interface", "connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class interface: public Ui_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
