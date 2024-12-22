//
// Created by lazab on 5/25/2024.
//

#ifndef TEST3_SEARCH_ENGINE_GUI_H
#define TEST3_SEARCH_ENGINE_GUI_H

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

    void connect();

    void search_documents();

    void show_best_match();

private:
    Ui::gui *ui;
    repository repo;
};


#endif //TEST3_SEARCH_ENGINE_GUI_H
