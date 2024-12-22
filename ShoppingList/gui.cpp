//
// Created by lazab on 5/26/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"
#include <algorithm>


gui::gui(repository repo, QWidget *parent) :
        QWidget(parent), ui(new Ui::gui), repo{repo} {
    ui->setupUi(this);
    QObject::connect(ui->search_line_edit, &QLineEdit::textChanged, this, &gui::search);
    QObject::connect(ui->show_button, &QPushButton::clicked, this, &gui::find_by_category);
}

gui::~gui() {
    delete ui;
}

void gui::populate() {
    ui->shopping_list_widget->clear();
    this->repo.read();
    auto all=this->repo.get_all();
    std::sort(all.begin(), all.end(), [](item &a, item &b){
        if(a.get_category()==b.get_category()){
            return a.get_name()<b.get_name();
        }
        return a.get_category()<b.get_category();
    });
    for(auto each:all){
        ui->shopping_list_widget->addItem(QString::fromStdString(each.get_category()+"----"+each.get_name()+"----"+std::to_string(each.get_quantity())));
    }
}

void gui::search() {
    ui->shopping_list_widget->clear();
    std::string str=ui->search_line_edit->text().toStdString();
    auto all=this->repo.get_all();
    std::vector<item> final;
    for(auto each:all){
        if(each.get_category().find(str)!=std::string::npos)
            final.push_back(each);
        else{
            if(each.get_name().find(str)!=std::string::npos)
                final.push_back(each);
        }
    }
    for(auto each:final){
        ui->shopping_list_widget->addItem(QString::fromStdString(each.get_category()+"----"+each.get_name()+"----"+std::to_string(each.get_quantity())));
    }
}

void gui::find_by_category() {
    ui->shopping_list_widget->clear();
    std::string str=ui->search_line_edit->text().toStdString();
    auto all=this->repo.get_all();
    std::vector<item> final;
    for(auto each:all){
        if(each.get_category()==str)
            final.push_back(each);
    }
    std::sort(final.begin(), final.end(), [](item &a, item &b){
        return a.get_quantity()<b.get_quantity();
    });
    for(auto each:final){
        ui->shopping_list_widget->addItem(QString::fromStdString(each.get_category()+"----"+each.get_name()+"----"+std::to_string(each.get_quantity())));
    }
}
