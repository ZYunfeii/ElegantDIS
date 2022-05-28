/********************************************************************************
** Form generated from reading UI file 'hub.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUB_H
#define UI_HUB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hub
{
public:
    QAction *setting_button;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *time_lcd;
    QTextBrowser *text_browser;
    QHBoxLayout *horizontalLayout;
    QTreeView *topic_tree_view;
    QTextBrowser *sim_text_browser;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *start_sim_button;
    QPushButton *init_sim_button;
    QPushButton *pause_continue;
    QPushButton *stop_sim_button;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLineEdit *max_step_show;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *cur_step_show;
    QProgressBar *sim_process_bar;
    QMenuBar *menubar;
    QMenu *setting;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Hub)
    {
        if (Hub->objectName().isEmpty())
            Hub->setObjectName(QStringLiteral("Hub"));
        Hub->resize(858, 708);
        setting_button = new QAction(Hub);
        setting_button->setObjectName(QStringLiteral("setting_button"));
        centralwidget = new QWidget(Hub);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        time_lcd = new QLCDNumber(centralwidget);
        time_lcd->setObjectName(QStringLiteral("time_lcd"));
        time_lcd->setStyleSheet(QLatin1String("border:2pxsolidgreen;\n"
"color:#00FF00;\n"
"background:black;"));
        time_lcd->setSmallDecimalPoint(false);
        time_lcd->setDigitCount(12);
        time_lcd->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(time_lcd);


        verticalLayout->addLayout(horizontalLayout_3);

        text_browser = new QTextBrowser(centralwidget);
        text_browser->setObjectName(QStringLiteral("text_browser"));

        verticalLayout->addWidget(text_browser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        topic_tree_view = new QTreeView(centralwidget);
        topic_tree_view->setObjectName(QStringLiteral("topic_tree_view"));

        horizontalLayout->addWidget(topic_tree_view);

        sim_text_browser = new QTextBrowser(centralwidget);
        sim_text_browser->setObjectName(QStringLiteral("sim_text_browser"));

        horizontalLayout->addWidget(sim_text_browser);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        start_sim_button = new QPushButton(groupBox);
        start_sim_button->setObjectName(QStringLiteral("start_sim_button"));
        start_sim_button->setStyleSheet(QLatin1String("border-radius: 6px;\n"
"background-color: rgb(165,165,165);"));

        gridLayout->addWidget(start_sim_button, 0, 0, 1, 1);

        init_sim_button = new QPushButton(groupBox);
        init_sim_button->setObjectName(QStringLiteral("init_sim_button"));
        init_sim_button->setStyleSheet(QLatin1String("border-radius: 6px;\n"
"background-color: rgb(165,165,165);"));

        gridLayout->addWidget(init_sim_button, 0, 1, 1, 1);

        pause_continue = new QPushButton(groupBox);
        pause_continue->setObjectName(QStringLiteral("pause_continue"));
        pause_continue->setStyleSheet(QLatin1String("border-radius: 6px;\n"
"background-color: rgb(165,165,165);"));

        gridLayout->addWidget(pause_continue, 1, 0, 1, 1);

        stop_sim_button = new QPushButton(groupBox);
        stop_sim_button->setObjectName(QStringLiteral("stop_sim_button"));
        stop_sim_button->setStyleSheet(QLatin1String("border-radius: 6px;\n"
"background-color: rgb(165,165,165);"));

        gridLayout->addWidget(stop_sim_button, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        max_step_show = new QLineEdit(groupBox_2);
        max_step_show->setObjectName(QStringLiteral("max_step_show"));
        max_step_show->setReadOnly(true);

        gridLayout_2->addWidget(max_step_show, 1, 2, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 3, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        cur_step_show = new QLineEdit(groupBox_2);
        cur_step_show->setObjectName(QStringLiteral("cur_step_show"));
        cur_step_show->setReadOnly(true);

        gridLayout_2->addWidget(cur_step_show, 1, 4, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        sim_process_bar = new QProgressBar(centralwidget);
        sim_process_bar->setObjectName(QStringLiteral("sim_process_bar"));
        sim_process_bar->setValue(24);

        verticalLayout->addWidget(sim_process_bar);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        Hub->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Hub);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 858, 22));
        setting = new QMenu(menubar);
        setting->setObjectName(QStringLiteral("setting"));
        Hub->setMenuBar(menubar);
        statusbar = new QStatusBar(Hub);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Hub->setStatusBar(statusbar);

        menubar->addAction(setting->menuAction());
        setting->addAction(setting_button);

        retranslateUi(Hub);

        QMetaObject::connectSlotsByName(Hub);
    } // setupUi

    void retranslateUi(QMainWindow *Hub)
    {
        Hub->setWindowTitle(QApplication::translate("Hub", "Hub", Q_NULLPTR));
        setting_button->setText(QApplication::translate("Hub", "setting", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Hub", "Control", Q_NULLPTR));
        start_sim_button->setText(QApplication::translate("Hub", "start sim", Q_NULLPTR));
        init_sim_button->setText(QApplication::translate("Hub", "init sim", Q_NULLPTR));
        pause_continue->setText(QApplication::translate("Hub", "pause_continue", Q_NULLPTR));
        stop_sim_button->setText(QApplication::translate("Hub", "stop sim", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Hub", "Para", Q_NULLPTR));
        label_2->setText(QApplication::translate("Hub", "cur step", Q_NULLPTR));
        label->setText(QApplication::translate("Hub", "max step", Q_NULLPTR));
        setting->setTitle(QApplication::translate("Hub", "Setting", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Hub: public Ui_Hub {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUB_H
