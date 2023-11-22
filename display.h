/********************************************************************************
** Form generated from reading UI file 'boggle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#include <vector>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *board_display;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_3;
    QLabel *label_0;
    QLabel *label_1;
    QLabel *label_4;
    QLabel *label_12;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_10;
    QLabel *label_14;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *label_15;
    QPushButton *start_button;
    QPushButton *pause_button;
    QLineEdit *input_line;
    QLabel *found_words_label;
    QLCDNumber *timer_display;
    QPushButton *give_up_button;
    QStatusBar *statusbar;
    std::vector<QLabel*> grid;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(861, 664);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(340, 120, 231, 151));
        board_display = new QGridLayout(gridLayoutWidget);
        board_display->setObjectName(QString::fromUtf8("board_display"));
        board_display->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        board_display->addWidget(label_2, 0, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        board_display->addWidget(label_8, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        board_display->addWidget(label_3, 0, 3, 1, 1);

        label_0 = new QLabel(gridLayoutWidget);
        label_0->setObjectName(QString::fromUtf8("label_0"));

        board_display->addWidget(label_0, 0, 0, 1, 1);

        label_1 = new QLabel(gridLayoutWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        board_display->addWidget(label_1, 0, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        board_display->addWidget(label_4, 1, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        board_display->addWidget(label_12, 3, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        board_display->addWidget(label_5, 1, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        board_display->addWidget(label_6, 1, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        board_display->addWidget(label_9, 2, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        board_display->addWidget(label_13, 3, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        board_display->addWidget(label_10, 2, 2, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        board_display->addWidget(label_14, 3, 2, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        board_display->addWidget(label_7, 1, 3, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        board_display->addWidget(label_11, 2, 3, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        board_display->addWidget(label_15, 3, 3, 1, 1);

        start_button = new QPushButton(centralwidget);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        start_button->setGeometry(QRect(160, 280, 89, 25));
        pause_button = new QPushButton(centralwidget);
        pause_button->setObjectName(QString::fromUtf8("pause_button"));
        pause_button->setGeometry(QRect(160, 310, 89, 25));
        input_line = new QLineEdit(centralwidget);
        input_line->setObjectName(QString::fromUtf8("input_line"));
        input_line->setGeometry(QRect(400, 90, 113, 25));
        found_words_label = new QLabel(centralwidget);
        found_words_label->setObjectName(QString::fromUtf8("found_words_label"));
        found_words_label->setGeometry(QRect(260, 290, 411, 301));
        timer_display = new QLCDNumber(centralwidget);
        timer_display->setObjectName(QString::fromUtf8("timer_display"));
        timer_display->setGeometry(QRect(420, 60, 64, 23));
        give_up_button = new QPushButton(centralwidget);
        give_up_button->setObjectName(QString::fromUtf8("give_up_button"));
        give_up_button->setGeometry(QRect(160, 340, 89, 25));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_0->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        start_button->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        pause_button->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        found_words_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        give_up_button->setText(QCoreApplication::translate("MainWindow", "Give Up", nullptr));

        grid = {label_0,label_1,label_2,label_3,label_4,label_5,label_6,label_7,label_8,label_9,label_10,label_11,label_12,label_13,label_14,label_15};

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DISPLAY_H
