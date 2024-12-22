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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui
{
public:
    QTableView *tableView;
    QLineEdit *title_line_edit;
    QLineEdit *duration_line_edit;
    QLineEdit *description_line_edit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *add_button;
    QPushButton *accept_button;

    void setupUi(QWidget *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName("gui");
        gui->resize(400, 300);
        tableView = new QTableView(gui);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(5, 10, 391, 192));
        title_line_edit = new QLineEdit(gui);
        title_line_edit->setObjectName("title_line_edit");
        title_line_edit->setGeometry(QRect(80, 210, 113, 26));
        duration_line_edit = new QLineEdit(gui);
        duration_line_edit->setObjectName("duration_line_edit");
        duration_line_edit->setGeometry(QRect(80, 270, 113, 26));
        description_line_edit = new QLineEdit(gui);
        description_line_edit->setObjectName("description_line_edit");
        description_line_edit->setGeometry(QRect(80, 240, 113, 26));
        label = new QLabel(gui);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 210, 63, 20));
        label_2 = new QLabel(gui);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 240, 81, 20));
        label_3 = new QLabel(gui);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 270, 63, 20));
        add_button = new QPushButton(gui);
        add_button->setObjectName("add_button");
        add_button->setGeometry(QRect(190, 240, 93, 29));
        accept_button = new QPushButton(gui);
        accept_button->setObjectName("accept_button");
        accept_button->setGeometry(QRect(290, 240, 93, 29));

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QWidget *gui)
    {
        gui->setWindowTitle(QCoreApplication::translate("gui", "gui", nullptr));
        title_line_edit->setText(QString());
        duration_line_edit->setText(QString());
        description_line_edit->setText(QString());
        label->setText(QCoreApplication::translate("gui", "Title:", nullptr));
        label_2->setText(QCoreApplication::translate("gui", "Description:", nullptr));
        label_3->setText(QCoreApplication::translate("gui", "Duration:", nullptr));
        add_button->setText(QCoreApplication::translate("gui", "ADD", nullptr));
        accept_button->setText(QCoreApplication::translate("gui", "ACCEPT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
