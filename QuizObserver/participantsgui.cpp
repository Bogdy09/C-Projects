//
// Created by lazab on 6/24/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_participantsgui.h" resolved

#include "participantsgui.h"
#include "ui_participantsgui.h"
#include <iostream>
using namespace std;

participantsgui::participantsgui(Repository *repo, std::string name, QWidget *parent) :
        repo{repo}, name{name}, QWidget(parent), ui(new Ui::participantsgui) {
    ui->setupUi(this);
    this->setWindowTitle(this->name.c_str());
    populate();
}

participantsgui::~participantsgui() {
    delete ui;
}

bool compare1(Question q1, Question q2){
    return q1.score>=q2.score;
}

void participantsgui::populate() {
    ui->participants_list_widget->clear();
    auto all=this->repo->get_questions();
    std::sort(all.begin(), all.end(), compare1);
    for(auto each:all){
        ui->participants_list_widget->addItem(QString::fromStdString(std::to_string(each.id)+"---"+each.text+"---"+std::to_string(each.score)));
    }
}

void participantsgui::update() {
    populate();
}
