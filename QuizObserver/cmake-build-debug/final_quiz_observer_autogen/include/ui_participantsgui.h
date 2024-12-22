/********************************************************************************
** Form generated from reading UI file 'participantsgui.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTICIPANTSGUI_H
#define UI_PARTICIPANTSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_participantsgui
{
public:
    QListWidget *participants_list_widget;

    void setupUi(QWidget *participantsgui)
    {
        if (participantsgui->objectName().isEmpty())
            participantsgui->setObjectName("participantsgui");
        participantsgui->resize(400, 300);
        participants_list_widget = new QListWidget(participantsgui);
        participants_list_widget->setObjectName("participants_list_widget");
        participants_list_widget->setGeometry(QRect(5, 10, 391, 131));

        retranslateUi(participantsgui);

        QMetaObject::connectSlotsByName(participantsgui);
    } // setupUi

    void retranslateUi(QWidget *participantsgui)
    {
        participantsgui->setWindowTitle(QCoreApplication::translate("participantsgui", "participantsgui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class participantsgui: public Ui_participantsgui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTICIPANTSGUI_H
