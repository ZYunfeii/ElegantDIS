/********************************************************************************
** Form generated from reading UI file 'settingwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWIDGET_H
#define UI_SETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWidget
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *max_total_steps;
    QHBoxLayout *horizontalLayout;
    QCheckBox *free_simulation;
    QPushButton *confirm_button;

    void setupUi(QWidget *SettingWidget)
    {
        if (SettingWidget->objectName().isEmpty())
            SettingWidget->setObjectName(QStringLiteral("SettingWidget"));
        SettingWidget->resize(361, 203);
        gridLayout_2 = new QGridLayout(SettingWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(SettingWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        max_total_steps = new QLineEdit(groupBox);
        max_total_steps->setObjectName(QStringLiteral("max_total_steps"));

        horizontalLayout_2->addWidget(max_total_steps);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        free_simulation = new QCheckBox(groupBox);
        free_simulation->setObjectName(QStringLiteral("free_simulation"));

        horizontalLayout->addWidget(free_simulation);

        confirm_button = new QPushButton(groupBox);
        confirm_button->setObjectName(QStringLiteral("confirm_button"));

        horizontalLayout->addWidget(confirm_button);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(SettingWidget);

        QMetaObject::connectSlotsByName(SettingWidget);
    } // setupUi

    void retranslateUi(QWidget *SettingWidget)
    {
        SettingWidget->setWindowTitle(QApplication::translate("SettingWidget", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SettingWidget", "Settings", Q_NULLPTR));
        label->setText(QApplication::translate("SettingWidget", "Max Total Steps:", Q_NULLPTR));
        free_simulation->setText(QApplication::translate("SettingWidget", "Free simulation", Q_NULLPTR));
        confirm_button->setText(QApplication::translate("SettingWidget", "confirm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingWidget: public Ui_SettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWIDGET_H
