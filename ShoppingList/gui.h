//
// Created by lazab on 5/26/2024.
//

#ifndef TEST3_SHOPPINGLIST_GUI_H
#define TEST3_SHOPPINGLIST_GUI_H

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

    void search();

    void find_by_category();

private:
    Ui::gui *ui;
    repository repo;
};


#endif //TEST3_SHOPPINGLIST_GUI_H
