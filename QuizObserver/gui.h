//
// Created by lazab on 6/24/2024.
//

#ifndef FINAL_QUIZ_OBSERVER_GUI_H
#define FINAL_QUIZ_OBSERVER_GUI_H

#include <QWidget>
#include "repository.h"


QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget {
    Q_OBJECT

public:
    gui(Repository *repo, QWidget *parent = nullptr);

    ~gui() override;

    void populate();

    void add();

private:
    Ui::gui *ui;
    Repository *repo;

};


#endif //FINAL_QUIZ_OBSERVER_GUI_H
