//
// Created by lazab on 4/22/2024.
//

#include "UI.h"
#include <iostream>
#include <limits>
using namespace std;

UI::UI() {
    this->agency=real_estate_agency();
}

void UI::menu() {
    cout<<"1. Remove a client.\n";
    cout<<"2. Display all clients and dwellings.\n";
    cout<<"3. Add a dwelling.\n";
    cout<<"4. Save all clients to the file.\n";
    cout<<"Please enter a choice: ";
}

void UI::remove_client() {
    std::string name;
    cout<<"Please enter the name: ";
    cin>>name;
    this->agency.removeClient(name);
}

void UI::display_clients() {
    for(auto i:this->agency.getAllClients()) {
        cout << i->toString() << '\n';
    }
}

void UI::display_dwellings() {
    for(auto i:this->agency.getAllDwellings()) {
        cout << i->toString() << '\n';
    }
}

void UI::add_dwelling() {
    cout<<"Please enter the price: ";
    double price;
    cin>>price;
    cout<<"Please enter true if it is profitable or false otherwise: ";
    bool profitable;
    cin >> std::boolalpha >> profitable;
    this->agency.addDwelling(price, profitable);
    auto d=new Dwelling(price, profitable);
    std::vector<client*> all;
    all=this->agency.getAllClients();
    for(auto i:all){
        if(i->isInterested(*d))
            cout<<i->toString()<<'\n';
    }

}

void UI::write_to_file() {
    cout<<"Please enter the filename: ";
    std::string filename;
    cin>>filename;
    this->agency.writeToFile(filename);
}


void UI::run() {
    this->agency.add_client();
    this->agency.addDwelling(123.0, true);
    this->agency.addDwelling(23456.5, false);
    while(true) {
        menu();
        int choice;
        cin >> choice;
        if (choice == 1) {
            remove_client();
        }

        if (choice == 2) {
            display_clients();
            display_dwellings();
        }

        if(choice==3){
            add_dwelling();
        }

        if(choice==4){
            write_to_file();
        }
    }
}

