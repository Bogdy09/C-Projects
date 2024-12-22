//
// Created by lazab on 5/27/2024.
//

#ifndef TEST3_TASK_MANAGER_GUI_H
#define TEST3_TASK_MANAGER_GUI_H

#include <QWidget>
#include "repository.h"


QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget {
    Q_OBJECT

public:
    explicit gui(repository repo, QWidget *parent = nullptr);

    ~gui() override;

    void populate();

    void show_tasks();
private:
    Ui::gui *ui;
    repository repo;
};


#endif //TEST3_TASK_MANAGER_GUI_H
