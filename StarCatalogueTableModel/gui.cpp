//
// Created by lazab on 6/23/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <iostream>
#include <QMessageBox>
#include "sstream"
using namespace std;


GUI::GUI(Repository<Astronomer> astronomers1, Repository<Star> &stars1, std::string& name1, stars_table_model* m1, QWidget *parent) :
        astronomers{astronomers1}, stars{stars1}, QWidget(parent), ui(new Ui::GUI), name{name1}, m{m1} {
    ui->setupUi(this);
    this->setWindowTitle(this->name.c_str());
    ui->stars_table_model->setModel(m);
    connect(ui->checkBox, &QCheckBox::stateChanged, this, &GUI::sort);
    connect(ui->add_button, &QPushButton::clicked, this, &GUI::add);
}

void GUI::sort(){
    if(ui->checkBox->isChecked()) {
        std::string constelation;
        auto all_astronomers = this->astronomers.get_all();
        for (auto each: all_astronomers) {
            if (each.name == this->name) {
                constelation = each.constelation;
                break;
            }
        }
        std::vector<Star> filtered;
        for (auto each: this->stars.get_all()) {
            if (each.constelation == constelation)
                filtered.push_back(each);
        }
        this->m->filtered_stars(filtered);
    }
    else
        this->m->reset();
}

GUI::~GUI() {
    delete ui;
}

void GUI::add() {
    if(ui->name_line_edit->text().isEmpty()) {
        QMessageBox::critical(this, "Error", "No name!");
        return;
    }
    std::string _name=ui->name_line_edit->text().toStdString();
    for(auto each:this->stars.get_all())
        if(_name==each.name) {
            QMessageBox::critical(this, "Error", "Stars must have unique names!");
            return;
        }
    std::string coord=ui->coordinates_line_edit->text().toStdString();
    std::stringstream ss(coord);
    std::string ra1, dec1;
    std::getline(ss, ra1, ' ');
    std::getline(ss, dec1, ' ');
    int _ra=std::stoi(ra1);
    int _dec=std::stoi(dec1);
    int _diameter=ui->diameter_line_edit->text().toInt();
    if(_diameter<=0) {
        QMessageBox::critical(this, "Error", "diameter must be positive!");
        return;
    }
    std::string constelation;
    for(auto each: this->astronomers.get_all()){
        if(each.name==this->name) {
            constelation = each.constelation;
            break;
        }
    }
    auto star=Star(_name, constelation, _ra, _dec, _diameter);
    this->stars.add(star);
    this->m->add(star);
}


