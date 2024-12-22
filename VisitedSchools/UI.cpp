//
// Created by lazab on 3/31/2024.
//

#include "UI.h"
#include "services.h"
#include <iostream>
#include "domain.h"
#include "dynamic_array.h"
using namespace std;
UI::UI(class services *services){
    this->services=services;
}

void UI::start(){
    while(1){
        cout<<"1. Remove a school.\n";
        cout<<"2. Show all the schools sorted by name.\n";
        cout<<"3. Show all schools after a date.\n";

        int choice;
        cout<<"Please enter a choice: ";
        cin>>choice;
        if(choice==1){
            cout<<"Please enter the name: ";
            std::string name;
            cin>>name;
            std::string coordinates;
            cout<<"Please enter the coordinates: ";
            cin>>coordinates;
            if(this->services->remove_services(name, coordinates)==0)
                cout<<"Cannot add!\n";
        }
        if(choice==2){
            domain::school* sorted_schools=this->services->sort_by_name();
            int size = this->services->get_size();
            for(int i=0;i< size;i++){
                cout<<sorted_schools[i].to_string()<<'\n';
            }
        }
        if(choice==3){
            cout<<"Please enter the date(dd mm yyyy): ";
            int day, month, year;
            cin>>day>>month>>year;
            auto date1=domain::date{day, month, year};
            domain::school* all_schools=this->services->sort_by_name();
            int size = this->services->get_size();
            for(int i=0;i<size;i++){
                if(this->services->isDateLess(all_schools[i].get_date(), date1))
                    all_schools[i].set_visit();
                else{
                    cout<<all_schools[i].to_string()<<'\n';
                }
            }
        }
    }
}