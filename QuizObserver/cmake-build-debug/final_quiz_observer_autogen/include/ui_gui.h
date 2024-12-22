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
    QListWidget *presenter_widget;
    QLineEdit *id_line_edit;
    QLineEdit *text_line_edit;
    QLineEdit *answer_line_edit;
    QLineEdit *score_line_edit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *add_button;

    void setupUi(QWidget *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName("gui");
        gui->resize(400, 300);
        presenter_widget = new QListWidget(gui);
        presenter_widget->setObjectName("presenter_widget");
        presenter_widget->setGeometry(QRect(5, 10, 391, 131));
        id_line_edit = new QLineEdit(gui);
        id_line_edit->setObjectName("id_line_edit");
        id_line_edit->setGeometry(QRect(70, 150, 113, 26));
        text_line_edit = new QLineEdit(gui);
        text_line_edit->setObjectName("text_line_edit");
        text_line_edit->setGeometry(QRect(70, 180, 113, 26));
        answer_line_edit = new QLineEdit(gui);
        answer_line_edit->setObjectName("answer_line_edit");
        answer_line_edit->setGeometry(QRect(70, 210, 113, 26));
        score_line_edit = new QLineEdit(gui);
        score_line_edit->setObjectName("score_line_edit");
        score_line_edit->setGeometry(QRect(70, 240, 113, 26));
        label = new QLabel(gui);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 150, 63, 20));
        label_2 = new QLabel(gui);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 180, 63, 20));
        label_3 = new QLabel(gui);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 210, 63, 20));
        label_4 = new QLabel(gui);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 240, 63, 20));
        add_button = new QPushButton(gui);
        add_button->setObjectName("add_button");
        add_button->setGeometry(QRect(260, 200, 93, 29));

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QWidget *gui)
    {
        gui->setWindowTitle(QCoreApplication::translate("gui", "gui", nullptr));
        label->setText(QCoreApplication::translate("gui", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("gui", "Text:", nullptr));
        label_3->setText(QCoreApplication::translate("gui", "Answer:", nullptr));
        label_4->setText(QCoreApplication::translate("gui", "Score:", nullptr));
        add_button->setText(QCoreApplication::translate("gui", "ADD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
