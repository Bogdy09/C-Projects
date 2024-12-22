//
// Created by lazab on 4/22/2024.
//

#include "UI.h"
#include <iostream>
#include <algorithm>
using namespace std;

UI::UI() {
    this->device=Device();
}

void UI::print_menu(){
    cout<<"1. Add sensor.\n";
    cout<<"2. Display all sensors.\n";
    cout<<"3. Display all sensors that emit alerts.\n";
    cout<<"4. Save to file all sensors with a price less than a given value.\n";
    cout<<"Please enter a choice: ";
}

void UI::add_sensor() {
    cout<<"Please enter the producer: ";
    std::string producer;
    cin>>producer;
    cout<<"Please enter the type: ";
    std::string type;
    cin>>type;
    std::vector<double> s;
    double value;
    cout<<"Please enter the recordings: ";
    cin>>value;
    while(value!=-1){
        s.push_back(value);
        cin>>value;
    }
    if(type=="TemperatureSensor"){
        cout<<"Please enter the diameter: ";
        double diameter, length;
        cin>>diameter;
        cout<<"Please enter the length: ";
        cin>>length;
        auto t=new TemperatureSensor(producer, type, s, 9, diameter, length);
        this->device.addSensor(t);
    }

    if(type=="HumiditySensor"){
        auto t=new HumiditySensor(producer, type, s, 4);
        this->device.addSensor(t);
    }

    if(type=="SmokeSensor"){
        auto t=new SmokeSensor(producer, type, s, 25);
        this->device.addSensor(t);
    }
}

void UI::display() {
    for(auto i:this->device.getAllSensors())
        cout<<i->toString()<<'\n';
}

void UI::display_allerts() {
    for(auto i:this->device.getAllertingSensors()){
        cout<<i->toString()<<'\n';
    }
}

bool UI::compare_by_producer(Sensor* a, Sensor* b) {
    return a->getProducer()<b->getProducer();
}

void UI::write_to_file() {
    cout<<"Please enter a price: ";
    double price;
    cin>>price;
    std::vector<Sensor*> all;
    for(auto i:this->device.getAllSensors()){
        if(i->getPrice()<price)
            all.push_back(i);
    }
    std::sort(all.begin(), all.end(), UI::compare_by_producer);
    this->device.writeToFile(all);
}


void UI::run() {
    while(true) {
        print_menu();
        int choice;
        cin >> choice;
        if (choice == 1) {
            add_sensor();
        }

        if (choice == 2) {
            display();
        }

        if(choice==3){
            display_allerts();
        }

        if(choice==4){
            write_to_file();
        }
    }
}







