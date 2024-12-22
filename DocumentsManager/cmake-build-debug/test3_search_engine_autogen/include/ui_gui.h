/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui
{
public:
    QListWidget *search_widget;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *match_button;

    void setupUi(QWidget *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName("gui");
        gui->resize(400, 300);
        search_widget = new QListWidget(gui);
        search_widget->setObjectName("search_widget");
        search_widget->setGeometry(QRect(30, 10, 331, 111));
        lineEdit = new QLineEdit(gui);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 170, 113, 26));
        label = new QLabel(gui);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 170, 63, 20));
        match_button = new QPushButton(gui);
        match_button->setObjectName("match_button");
        match_button->setGeometry(QRect(120, 230, 171, 51));

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QWidget *gui)
    {
        gui->setWindowTitle(QCoreApplication::translate("gui", "gui", nullptr));
        label->setText(QCoreApplication::translate("gui", "Search:", nullptr));
        match_button->setText(QCoreApplication::translate("gui", "Show best matching", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
