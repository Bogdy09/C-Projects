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
    QListWidget *task_list_widget;
    QLineEdit *priority_line_edit;
    QLabel *label;
    QPushButton *show_button;
    QLineEdit *uration_line_edit;
    QLabel *label_2;

    void setupUi(QWidget *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName("gui");
        gui->resize(400, 300);
        task_list_widget = new QListWidget(gui);
        task_list_widget->setObjectName("task_list_widget");
        task_list_widget->setGeometry(QRect(5, 0, 391, 161));
        priority_line_edit = new QLineEdit(gui);
        priority_line_edit->setObjectName("priority_line_edit");
        priority_line_edit->setGeometry(QRect(80, 190, 113, 31));
        label = new QLabel(gui);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 190, 81, 20));
        show_button = new QPushButton(gui);
        show_button->setObjectName("show_button");
        show_button->setGeometry(QRect(60, 230, 271, 61));
        uration_line_edit = new QLineEdit(gui);
        uration_line_edit->setObjectName("uration_line_edit");
        uration_line_edit->setGeometry(QRect(290, 190, 81, 26));
        label_2 = new QLabel(gui);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 190, 81, 20));

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QWidget *gui)
    {
        gui->setWindowTitle(QCoreApplication::translate("gui", "gui", nullptr));
        label->setText(QCoreApplication::translate("gui", "PRIORITY", nullptr));
        show_button->setText(QCoreApplication::translate("gui", "SHOW TASKS AND DURATION", nullptr));
        label_2->setText(QCoreApplication::translate("gui", "DURATION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
