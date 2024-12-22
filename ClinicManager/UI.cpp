//
// Created by lazab on 4/20/2024.
//

#include "UI.h"
#include <iostream>
using namespace std;

UI::UI() {
    this->person=Person();
}

void print_menu(){
    cout<<"1. Add a new analysis.\n";
    cout<<"2. Show all analyses.\n";
    cout<<"3. Show if the person is ill.\n";
    cout<<"4. Save to file all analyses between two dates.\n";
    cout<<"5. Exit.\n";
}

void UI::add_new_analysis(){
    std::string type, date;
    cout<<"Please enter the type: ";
    cin>>type;
    cout<<"Please enter the date";
    cin>>date;

    if(type=="BMI"){
        double value;
        cout<<"Please enter the value:";
        cin>>value;
        auto *b=new BMI(date, value);
        this->person.addAnalysis(b);
    }

    if(type=="BP"){
        int sys, dia;
        cout<<"Please enter the systolic value: ";
        cin>>sys;
        cout<<"Please enter the diastolic value: ";
        cin>>dia;
        auto *b=new BP(date, sys, dia);
        this->person.addAnalysis(b);
    }
}

void UI::display_analyses(){
    auto all=this->person.getAllAnalyses();
    for(auto i:all){
        cout<<i->toString();
    }
}

void UI::show_if_ill(){
    cout<<"Please enter the month: ";
    std::string month;
    cin>>month;
    bool ok=true;
    std::vector<MedicalAnalysis*> final1=this->person.getAnalysesByMonth(month);
    for(auto i:final1){
        if(i->isResultOK()) {
            ok = false;
        }
    }
    if(ok)
        cout<<"The person is ill.\n";
    else
        cout<<"The person is not ill.\n";
}

void UI::between_dates(){
    cout<<"Please enter the first date: ";
    std::string date1;
    cin>>date1;

    cout<<"Please enter the second date: ";
    std::string date2;
    cin>>date2;
    std::vector<MedicalAnalysis*> all;
    auto dates=this->person.getAllAnalyses();
    for(auto i:dates){
        if(i->getDate()>=date1 && i->getDate()<=date2) {
            all.push_back(i);
        }
    }
    this->person.writeToFile(all);
}

void UI::run_UI(){
    int choice;
    while(true) {
        print_menu();
        cout<<"Please enter a choice: ";
        cin>>choice;
        if (choice == 1) {
            add_new_analysis();
        }

        if(choice==2){
            display_analyses();
        }

        if(choice==3){
            show_if_ill();
        }

        if(choice==4){
            between_dates();
        }
    }
}