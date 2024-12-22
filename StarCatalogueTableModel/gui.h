//
// Created by lazab on 6/23/2024.
//

#ifndef FINAL_STAR_CATALOGUE_TABLEMODEL__GUI_H
#define FINAL_STAR_CATALOGUE_TABLEMODEL__GUI_H

#include <QWidget>
#include "repository.h"
#include "stars_table_model.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget {
    Q_OBJECT

public:
    explicit GUI(Repository<Astronomer> astronomers1, Repository<Star> &stars1, std::string& name1, stars_table_model* m1, QWidget *parent = nullptr);

    ~GUI() override;

    void sort();

    void add();

private:
    Ui::GUI *ui;
    std::string name;
    Repository<Astronomer> astronomers;
    Repository<Star>stars;
    stars_table_model* m;
};


#endif //FINAL_STAR_CATALOGUE_TABLEMODEL__GUI_H
