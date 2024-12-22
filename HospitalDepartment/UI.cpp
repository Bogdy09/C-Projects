//
// Created by lazab on 4/21/2024.
//

#include "UI.h"
#include <iostream>
using namespace std;

UI::UI(){
    this->services=Services();
}

void UI::print_menu(){
    cout<<"1. Add a new department.\n";
    cout<<"2. Show all departments.\n";
    cout<<"3. Show all the efficient departments.\n";
    cout<<"4. Save all hospital departments to a file.\n";
    cout<<"0. Exit.\n";
    cout<<"Please enter an option: ";
}

void UI::add_new_department() {
    cout<<"Please enter the type of the department: ";
    std::string type;
    cin>>type;
    cout<<"Please enter the number of doctors: ";
    int nr_doctors;
    cin>>nr_doctors;
    if(type=="NeonatalUnit"){
        cout<<"Please enter the number of mothers: ";
        int nr_mothers;
        cin>>nr_mothers;
        cout<<"Please enter the number of newborns: ";
        int nr_newborns;
        cin>>nr_newborns;
        double grade;
        cout<<"Please enter the average grade: ";
        cin>>grade;
        auto *n=new NeonatalUnit(type, nr_doctors, nr_mothers, nr_newborns, grade);
        this->services.addDepartment(n);
    }

    if(type=="Surgery"){
        cout<<"Please enter the number of patients: ";
        int nr_patients;
        cin>>nr_patients;
        auto *s=new Surgery(type, nr_doctors, nr_patients);
        this->services.addDepartment(s);
    }
}

void UI::display_all() {
    auto all=this->services.getAllDepartments();
    for(auto i:all){
        cout<<i->toString()<<'\n';
    }
}

void UI::display_efficient() {
    auto e=this->services.getAllEfficientDepartments();
    for(auto i:e){
        cout<<i->toString()<<'\n';
    }
}

void UI::run(){
    while(true){
        print_menu();
        int choice;
        cin>>choice;
        if(choice==1)
            add_new_department();

        if(choice==2){
            display_all();
        }

        if(choice==3){
            display_efficient();
        }

        if(choice==4){
            this->services.writeToFile();
        }
    }
}



