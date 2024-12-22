//
// Created by lazab on 5/25/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include "gui.h"
#include "ui_gui.h"
#include <iostream>
#include <algorithm>



gui::gui(repository repo, QWidget *parent) :
        QWidget(parent), ui(new Ui::gui), repo(repo) {
    ui->setupUi(this);
    this->connect();
}

gui::~gui() {
    delete ui;
}

void gui::populate() {
    ui->search_widget->clear();
    this->repo.read();
    auto searches=this->repo.get_all();

    std::sort(searches.begin(), searches.end(), [](search& a, search& b) {
        return a.get_name() < b.get_name();
    });

    for (auto s : searches) {
        std::string keywords_str;
        for (const auto& keyword : s.get_keywords()) {
            if (!keywords_str.empty()) {
                keywords_str += ", ";
            }
            keywords_str += keyword;
        }
        ui->search_widget->addItem(QString::fromStdString(s.get_name() + " ---- " + keywords_str));
    }
}

void gui::connect() {
    QObject::connect(ui->lineEdit, &QLineEdit::textChanged, this, &gui::search_documents);
    QObject::connect(ui->match_button, &QPushButton::clicked, this, &gui::show_best_match);

}

#include <QDebug>  // Include for debug printing

void gui::search_documents() {
    ui->search_widget->clear();
    std::string str = ui->lineEdit->text().toStdString();
    std::vector<search> searches = this->repo.get_all();
    std::vector<search> final;
    for (auto each: searches) {
        if (each.get_name().find(str) != std::string::npos)
            final.push_back(each);
        else {
            for (auto keyword: each.get_keywords()) {
                if (keyword.find(str) != std::string::npos)
                    final.push_back(each);
            }
        }
    }
    for (auto each: final) {
        std::string keywords_str;
        for (auto s: each.get_keywords()) {
            if (!keywords_str.empty()) {
                keywords_str += ", ";
            }
            keywords_str += s;
        }
        ui->search_widget->addItem(QString::fromStdString(each.get_name() + "----" + keywords_str));
    }
}

void gui::show_best_match() {
    std::string str=ui->lineEdit->text().toStdString();
    double similarity=0, aux=0;
    search s;
    for(auto each:this->repo.get_all()){
        if (each.get_name().find(str) != std::string::npos){
            std::cout<<str.length()<<' '<<each.get_name().length()<<'\n';
            similarity= double(str.length())/double(each.get_name().length());
            std::cout<<similarity;
        }
        if(similarity>aux){
            aux=similarity;
            s=each;
        }
    }
    if(aux!=0){
        ui->search_widget->clear();
        std::string keywords_str;
        for (auto each: s.get_keywords()) {
            if (!keywords_str.empty()) {
                keywords_str += ", ";
            }
            keywords_str += each;
        }
        ui->search_widget->addItem(QString::fromStdString(s.get_name()+"----"+keywords_str+"----"+s.get_content()));
    }
    else
        ui->search_widget->clear();
}



