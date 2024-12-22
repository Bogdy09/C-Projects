//
// Created by lazab on 5/24/2024.
//

#ifndef TEST3_BILLS_GUI_H
#define TEST3_BILLS_GUI_H
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QComboBox>
#include <QMainWindow>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include "repository.h"


class GUI: public QMainWindow{
    Q_OBJECT
private:
    repository repo;
    QPushButton *display_button, *paid_button, *total_button;
    QComboBox *paid_choice;
    QLineEdit *company_name;
    QListWidget *bills_list;

public:
    GUI(repository repo, QWidget *parent= nullptr);

    void initGUI();

    void connectSignalsAndSlots();

    void populate();

    void paid();

    void total();
};


#endif //TEST3_BILLS_GUI_H
