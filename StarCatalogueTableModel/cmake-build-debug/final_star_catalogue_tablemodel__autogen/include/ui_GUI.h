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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QTableView *stars_table_model;
    QCheckBox *checkBox;
    QPushButton *add_button;
    QLineEdit *name_line_edit;
    QLineEdit *coordinates_line_edit;
    QLineEdit *diameter_line_edit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListView *listView;
    QLineEdit *stars_line_edit;

    void setupUi(QWidget *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName("GUI");
        GUI->resize(400, 300);
        stars_table_model = new QTableView(GUI);
        stars_table_model->setObjectName("stars_table_model");
        stars_table_model->setGeometry(QRect(20, 10, 361, 141));
        checkBox = new QCheckBox(GUI);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(20, 160, 91, 24));
        add_button = new QPushButton(GUI);
        add_button->setObjectName("add_button");
        add_button->setGeometry(QRect(220, 270, 93, 29));
        name_line_edit = new QLineEdit(GUI);
        name_line_edit->setObjectName("name_line_edit");
        name_line_edit->setGeometry(QRect(100, 200, 113, 26));
        coordinates_line_edit = new QLineEdit(GUI);
        coordinates_line_edit->setObjectName("coordinates_line_edit");
        coordinates_line_edit->setGeometry(QRect(100, 230, 113, 26));
        diameter_line_edit = new QLineEdit(GUI);
        diameter_line_edit->setObjectName("diameter_line_edit");
        diameter_line_edit->setGeometry(QRect(100, 260, 113, 26));
        label = new QLabel(GUI);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 200, 51, 20));
        label_2 = new QLabel(GUI);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 230, 101, 20));
        label_3 = new QLabel(GUI);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 260, 81, 20));
        listView = new QListView(GUI);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(220, 160, 161, 61));
        stars_line_edit = new QLineEdit(GUI);
        stars_line_edit->setObjectName("stars_line_edit");
        stars_line_edit->setGeometry(QRect(230, 230, 113, 26));

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QWidget *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "GUI", nullptr));
        checkBox->setText(QCoreApplication::translate("GUI", "CheckBox", nullptr));
        add_button->setText(QCoreApplication::translate("GUI", "ADD", nullptr));
        label->setText(QCoreApplication::translate("GUI", "NAME", nullptr));
        label_2->setText(QCoreApplication::translate("GUI", "COORDINATES", nullptr));
        label_3->setText(QCoreApplication::translate("GUI", "DIAMETER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
