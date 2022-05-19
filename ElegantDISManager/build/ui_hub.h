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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hub
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTextBrowser *text_browser;
    QHBoxLayout *horizontalLayout;
    QTreeView *topic_tree_view;
    QTextBrowser *sim_text_browser;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *start_sim_button;
    QPushButton *init_sim_button;
    QProgressBar *sim_process_bar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Hub)
    {
        if (Hub->objectName().isEmpty())
            Hub->setObjectName(QStringLiteral("Hub"));
        Hub->resize(831, 611);
        centralwidget = new QWidget(Hub);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        start_sim_button = new QPushButton(centralwidget);
        start_sim_button->setObjectName(QStringLiteral("start_sim_button"));

        horizontalLayout_2->addWidget(start_sim_button);

        init_sim_button = new QPushButton(centralwidget);
        init_sim_button->setObjectName(QStringLiteral("init_sim_button"));

        horizontalLayout_2->addWidget(init_sim_button);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        sim_process_bar = new QProgressBar(centralwidget);
        sim_process_bar->setObjectName(QStringLiteral("sim_process_bar"));
        sim_process_bar->setValue(24);

        gridLayout->addWidget(sim_process_bar, 1, 0, 1, 1);

        Hub->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Hub);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 831, 22));
        Hub->setMenuBar(menubar);
        statusbar = new QStatusBar(Hub);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Hub->setStatusBar(statusbar);

        retranslateUi(Hub);

        QMetaObject::connectSlotsByName(Hub);
    } // setupUi

    void retranslateUi(QMainWindow *Hub)
    {
        Hub->setWindowTitle(QApplication::translate("Hub", "Hub", Q_NULLPTR));
        start_sim_button->setText(QApplication::translate("Hub", "start sim", Q_NULLPTR));
        init_sim_button->setText(QApplication::translate("Hub", "init sim", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Hub: public Ui_Hub {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUB_H
