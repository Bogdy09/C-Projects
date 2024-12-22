//
// Created by lazab on 5/27/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"
#include <algorithm>
#include <QMessageBox>


gui::gui(repository repo, QWidget *parent) :
        QWidget(parent), ui(new Ui::gui), repo{repo} {
    ui->setupUi(this);
    QObject::connect(ui->show_button,&QPushButton::clicked,this,&gui::show_tasks);
}

gui::~gui() {
    delete ui;
}

void gui::populate() {
    ui->task_list_widget->clear();
    this->repo.read();
    auto all=this->repo.get_all();
    std::sort(all.begin(), all.end(), [](task& a, task& b){
        if(a.get_priority()==b.get_priority())
            return a.get_duration()<b.get_duration();
        return a.get_priority()<b.get_priority();
    });
    for(auto each:all){
        QString taskString = QString::fromStdString(each.get_description() + "----" +
                                                    std::to_string(each.get_duration()) + "----" +
                                                    std::to_string(each.get_priority()));

        QListWidgetItem *item = new QListWidgetItem(taskString);
        if(each.get_priority()==1){
            QFont font = item->font();
            font.setBold(true);
            item->setFont(font);
        }
        ui->task_list_widget->addItem(item);
    }
}

void gui::show_tasks() {
    int total_duration=0, k=0;
    ui->task_list_widget->clear();
    auto priority=ui->priority_line_edit->text().toInt();
    auto all=this->repo.get_all();
    std::vector<task> final;
    for(auto each:all){
        if(each.get_priority()==priority) {
            k++;
            total_duration+=each.get_duration();
            final.push_back(each);
        }
    }
    if(k==0)
        QMessageBox::critical(this, "Error", "There are no such tasks!");
    for(auto each:final){
        ui->task_list_widget->addItem(QString::fromStdString(each.get_description()+"----"+std::to_string(each.get_priority())+"----"+std::to_string(each.get_duration())));
    }
    ui->uration_line_edit->setText(QString::fromStdString(std::to_string(total_duration)));
}
