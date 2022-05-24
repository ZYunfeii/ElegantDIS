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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
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
    QLabel *label;
    QLineEdit *ip_edit;
    QLabel *label_2;
    QLineEdit *port_edit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *connect_button;
    QLCDNumber *time_lcd;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *info_browser;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *topic_pub_data_browser;
    QTextBrowser *topic_sub_data_browser;

    void setupUi(QWidget *interface)
    {
        if (interface->objectName().isEmpty())
            interface->setObjectName(QStringLiteral("interface"));
        interface->resize(611, 453);
        gridLayout = new QGridLayout(interface);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(interface);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        ip_edit = new QLineEdit(interface);
        ip_edit->setObjectName(QStringLiteral("ip_edit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ip_edit);

        label_2 = new QLabel(interface);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        port_edit = new QLineEdit(interface);
        port_edit->setObjectName(QStringLiteral("port_edit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, port_edit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        connect_button = new QPushButton(interface);
        connect_button->setObjectName(QStringLiteral("connect_button"));

        horizontalLayout_2->addWidget(connect_button);

        time_lcd = new QLCDNumber(interface);
        time_lcd->setObjectName(QStringLiteral("time_lcd"));
        time_lcd->setStyleSheet(QLatin1String("border:2pxsolidgreen;\n"
"color:#00FF00;\n"
"background:black;"));
        time_lcd->setSmallDecimalPoint(false);
        time_lcd->setDigitCount(12);
        time_lcd->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_2->addWidget(time_lcd);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        info_browser = new QTextBrowser(interface);
        info_browser->setObjectName(QStringLiteral("info_browser"));

        horizontalLayout->addWidget(info_browser);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        topic_pub_data_browser = new QTextBrowser(interface);
        topic_pub_data_browser->setObjectName(QStringLiteral("topic_pub_data_browser"));

        verticalLayout_2->addWidget(topic_pub_data_browser);

        topic_sub_data_browser = new QTextBrowser(interface);
        topic_sub_data_browser->setObjectName(QStringLiteral("topic_sub_data_browser"));

        verticalLayout_2->addWidget(topic_sub_data_browser);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(interface);

        QMetaObject::connectSlotsByName(interface);
    } // setupUi

    void retranslateUi(QWidget *interface)
    {
        interface->setWindowTitle(QApplication::translate("interface", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("interface", "HostIP:", Q_NULLPTR));
        ip_edit->setText(QApplication::translate("interface", "127.0.0.1", Q_NULLPTR));
        label_2->setText(QApplication::translate("interface", "HostPort:", Q_NULLPTR));
        port_edit->setText(QApplication::translate("interface", "9999", Q_NULLPTR));
        connect_button->setText(QApplication::translate("interface", "connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class interface: public Ui_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
