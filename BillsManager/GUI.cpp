//
// Created by lazab on 5/24/2024.
//

#include "GUI.h"
#include <iostream>
#include <algorithm>
using namespace std;

GUI::GUI(repository repo, QWidget *parent): QMainWindow(parent), repo{repo} {
    this->initGUI();
    this->connectSignalsAndSlots();
}

void GUI::initGUI() {
    QFont buttons_font("Consolas", 30, true);
    this->display_button=new QPushButton("Display");
    this->display_button->setFont(buttons_font);

    this->paid_button=new QPushButton("Paid");
    this->paid_button->setFont(buttons_font);

    this->total_button=new QPushButton("Calculate total");
    this->total_button->setFont(buttons_font);

    this->paid_choice=new QComboBox{};
    this->paid_choice->setFont(buttons_font);
    this->paid_choice->addItem("Paid");
    this->paid_choice->addItem("Unpaid");

    QLabel *company = new QLabel();
    company->setText("Company");
    company->setFont(buttons_font);

    this->company_name = new QLineEdit();
    this->company_name->setFont(buttons_font);


    QVBoxLayout* mainLayout = new QVBoxLayout();

    QLabel *introduction = new QLabel();
    introduction->setText("BILLS:");
    introduction->setAlignment(Qt::AlignCenter);
    QFont introduction_font("Consolas", 100, true, true);
    introduction->setFont(introduction_font);
    QLabel *space = new QLabel();
    space->setText("");

    mainLayout->addWidget(introduction);
    mainLayout->addWidget(space);
    mainLayout->addWidget(space);

    QGridLayout* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(this->display_button, 0, 0);
    buttonsLayout->addWidget(this->paid_button, 0, 1);
    buttonsLayout->addWidget(this->total_button, 1, 0);

    QLabel *paid = new QLabel();
    paid->setText("Choose paid or unpaid: ");
    QFont font("Consolas", 30, true);
    paid->setFont(font);
    QFormLayout* paid_b = new QFormLayout();
    paid_b->addRow(paid, this->paid_choice);

    mainLayout->addLayout(paid_b);

    mainLayout->addLayout(buttonsLayout);

    QWidget *mainWindow = new QWidget();
    mainWindow->setLayout(mainLayout);
    setCentralWidget(mainWindow);

    this->bills_list=new QListWidget{};
    QLabel *bills_text=new QLabel();
    bills_text->setText("The list of bills: ");

    mainLayout->addWidget(bills_text);
    mainLayout->addWidget(this->bills_list);

    QFormLayout* bills = new QFormLayout();
    bills->addRow(company, this->company_name);
    mainLayout->addLayout(bills);

}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->display_button, &QPushButton::clicked, this, &GUI::populate);
    QObject::connect(this->paid_button, &QPushButton::clicked, this, &GUI::paid);
    QObject::connect(this->total_button, &QPushButton::clicked, this, &GUI::total);
}

void GUI::populate(){
    this->bills_list->clear();
    this->repo.read();
    auto bills= this->repo.get_all();
    std::sort(bills.begin(), bills.end(), [](domain::bill &a, domain::bill &b){
        return a.get_name()<b.get_name();
    });
    for(auto b:bills)
        this->bills_list->addItem(QString::fromStdString(b.get_name()+"-"+std::to_string(b.get_sum())));
}

void GUI::paid() {
    auto type=this->paid_choice->currentText().toStdString();
    std::vector<domain::bill> b;
    if(type=="Paid"){
        this->repo.read();
        auto bills=this->repo.get_all();
        for(auto each:bills)
            if(each.get_paid()) {
                b.push_back(each);
            }
    }
    else{
        this->repo.read();
        auto bills=this->repo.get_all();
        for(auto each:bills)
            if(!each.get_paid())
                b.push_back(each);
    }
    this->bills_list->clear();
    for(auto each:b)
        this->bills_list->addItem(QString::fromStdString(each.get_name()+"-"+std::to_string(each.get_paid())));
}

void GUI::total() {
    auto name=this->company_name->text().toStdString();
    double sum=0;
    bool ok=false;
    this->repo.read();
    auto bills=this->repo.get_all();
    for(auto each:bills){
        if(each.get_name()==name && !each.get_paid()){
            ok=true;
            sum+=each.get_sum();
        }
    }
    if(ok==false){
        QMessageBox::critical(this, "Error", "There are no such companies!");
        return;
    }
    this->bills_list->clear();
    this->bills_list->addItem(QString::fromStdString(std::to_string(sum)));
}
