//
// Created by lazab on 6/24/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"
#include <algorithm>
#include <QMessageBox>
#include <iostream>
using namespace std;

gui::gui(Repository *repo, QWidget *parent) :
        repo{repo}, QWidget(parent), ui(new Ui::gui) {
    ui->setupUi(this);
    this->setWindowTitle("Presenter");
    populate();
    connect(ui->add_button, &QPushButton::clicked, this, &gui::add);

}

gui::~gui() {
    delete ui;
}

bool compare(Question q1, Question q2){
    return q1.score<=q2.score;
}

void gui::populate() {
    ui->presenter_widget->clear();
    auto all=this->repo->get_questions();
    std::sort(all.begin(), all.end(), compare);
    for(auto each:all){
        ui->presenter_widget->addItem(QString::fromStdString(std::to_string(each.id)+"---"+each.text+"---"+each.answer+"---"+std::to_string(each.score)));
    }
}

void gui::add() {
    int id=ui->id_line_edit->text().toInt();
    for(auto each:this->repo->get_questions()){
        if(each.id==id)
            QMessageBox::critical(this, "Error", "Invalid ID!");
    }
    if(ui->text_line_edit->text().isEmpty())
        QMessageBox::critical(this, "Error", "Empty text!");
    std::string text=ui->text_line_edit->text().toStdString();
    std::string answer=ui->answer_line_edit->text().toStdString();
    int score=ui->score_line_edit->text().toInt();
    auto question=Question(id, text, answer, score);
    this->repo->add(question);
    populate();
}
