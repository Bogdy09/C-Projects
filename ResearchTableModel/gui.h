//
// Created by lazab on 6/25/2024.
//

#ifndef FINAL_RESEARCH_TABLE_MODEL_GUI_H
#define FINAL_RESEARCH_TABLE_MODEL_GUI_H

#include <QWidget>
#include "repository.h"
#include "table_model.h"


QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget {
    Q_OBJECT

public:
    explicit gui(Repository &repo, table_model* m, std::string name, std::string position, QWidget *parent = nullptr);

    ~gui() override;

    void sort();

    void add();

    void accept_update();

private:
    Ui::gui *ui;
    Repository &repo;
    table_model* m;
    std::string name;
    std::string position;
};


#endif //FINAL_RESEARCH_TABLE_MODEL_GUI_H
