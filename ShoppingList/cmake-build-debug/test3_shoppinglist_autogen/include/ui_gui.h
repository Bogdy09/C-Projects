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
    QListWidget *shopping_list_widget;
    QLineEdit *search_line_edit;
    QLabel *label;
    QPushButton *show_button;

    void setupUi(QWidget *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName("gui");
        gui->resize(400, 300);
        shopping_list_widget = new QListWidget(gui);
        shopping_list_widget->setObjectName("shopping_list_widget");
        shopping_list_widget->setGeometry(QRect(25, 131, 341, 161));
        search_line_edit = new QLineEdit(gui);
        search_line_edit->setObjectName("search_line_edit");
        search_line_edit->setGeometry(QRect(70, 40, 151, 51));
        label = new QLabel(gui);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 50, 63, 31));
        show_button = new QPushButton(gui);
        show_button->setObjectName("show_button");
        show_button->setGeometry(QRect(270, 40, 93, 51));

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QWidget *gui)
    {
        gui->setWindowTitle(QCoreApplication::translate("gui", "gui", nullptr));
        search_line_edit->setText(QString());
        label->setText(QCoreApplication::translate("gui", "Search:", nullptr));
        show_button->setText(QCoreApplication::translate("gui", "Show items", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
