//
// Created by lazab on 6/25/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"
#include <iostream>
#include "algorithm"
#include "QMessageBox"
using namespace std;

gui::gui(Repository &repo, table_model* m, std::string name, std::string position, QWidget *parent) :
        repo{repo}, QWidget(parent), name{name}, position{position}, ui(new Ui::gui), m{m} {
    ui->setupUi(this);
    std::string full=this->name+"     "+this->position;
    this->setWindowTitle(full.c_str());
    if(this->position!="senior")
        ui->accept_button->hide();
    ui->tableView->setModel(this->m);
    sort();
    connect(ui->add_button, &QPushButton::clicked, this, &gui::add);
    connect(ui->accept_button, &QPushButton::clicked, this, &gui::accept_update);
}

gui::~gui() {
    delete ui;
}

bool compare(Idea &i1, Idea &i2){
    return i1.duration<=i2.duration;
}

void gui::sort() {
    auto all=this->repo.get_ideas();
    std::sort(all.begin(), all.end(), compare);
    this->m->sort(all);
}

void gui::add() {
    std::string title=ui->title_line_edit->text().toStdString();
    if(title.empty())
        QMessageBox::critical(this, "Error", "Empty title!");
    std::string description=ui->description_line_edit->text().toStdString();
    int duration=ui->duration_line_edit->text().toInt();
    if(duration!=1 && duration!=2 && duration!=3)
        QMessageBox::critical(this, "Error", "Invalid duration!");
    std::string creator=this->name;
    std::string status="proposed";

    auto idea=Idea(title, description, status, creator, duration);
    this->repo.add(idea);
    this->m->add(idea);
}

void gui::accept_update() {
    QModelIndexList selected=ui->tableView->selectionModel()->selectedIndexes();
    if(selected.empty())
        return;
    int row=selected.at(0).row();
    cout<<row;
    Idea idea=this->repo.get_ideas()[row];
    if(idea.status=="proposed") {
        this->repo.update_status(row);
        this->m->sort(this->repo.get_ideas());
    }
}
