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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hub
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextBrowser *text_browser;
    QTextBrowser *topic_browser;
    QPushButton *start_sim_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Hub)
    {
        if (Hub->objectName().isEmpty())
            Hub->setObjectName(QStringLiteral("Hub"));
        Hub->resize(800, 600);
        centralwidget = new QWidget(Hub);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        text_browser = new QTextBrowser(centralwidget);
        text_browser->setObjectName(QStringLiteral("text_browser"));

        gridLayout->addWidget(text_browser, 0, 0, 1, 1);

        topic_browser = new QTextBrowser(centralwidget);
        topic_browser->setObjectName(QStringLiteral("topic_browser"));

        gridLayout->addWidget(topic_browser, 1, 0, 1, 1);

        start_sim_button = new QPushButton(centralwidget);
        start_sim_button->setObjectName(QStringLiteral("start_sim_button"));

        gridLayout->addWidget(start_sim_button, 2, 0, 1, 1);

        Hub->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Hub);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
    } // retranslateUi

};

namespace Ui {
    class Hub: public Ui_Hub {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUB_H
