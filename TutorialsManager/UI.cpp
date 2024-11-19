//
// Created by lazab on 3/22/2024.
//

#include "UI.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <vector>

using namespace std;

UI::UI(){
    this->Services=services();
}




void UI::print_all(){
    vector<domain::Tutorial> t=this->Services.get_all_services();
    auto i=t.begin();
    for(;i!=t.end();++i){
        domain::Tutorial current=*i;
        std::cout<<std::distance(t.begin(), i)<<" "<<current.get_title()<<" "<<current.get_presenter()<<" "<<current.get_duration().minutes<<":"<<current.get_duration().seconds<<" "<<current.get_nr_likes()<<" "<<current.get_link()<<'\n';
    }
}

void UI::print_all1(){
    vector<domain::Tutorial> t=this->Services.get_all_services1();
    auto i=t.begin();
    for(;i!=t.end();++i){
        domain::Tutorial current=*i;
        std::cout<<std::distance(t.begin(), i)<<" "<<current.get_title()<<" "<<current.get_presenter()<<" "<<current.get_duration().minutes<<":"<<current.get_duration().seconds<<" "<<current.get_nr_likes()<<" "<<current.get_link()<<'\n';
    }
}

void UI::print_menu1(){
    cout<<"1. Add a new tutorial.\n";
    cout<<"2. Delete a tutorial.\n";
    cout<<"3. Update a tutorial.\n";
    cout<<"4. Display all tutorials.\n";
    cout<<"0. Exit\n";
}

void UI::print_menu2() {
    cout<<"1. See the tutorials by presenter.\n";
    cout<<"2. Delete from watch lit.\n";
    cout<<"3. Display the watch list.\n";
    cout<<"0. Exit.";
}

void UI::start() {
    cout << "1. Administrator mode.\n";
    cout << "2. User mode.\n";
    cout << "Please choose the desired mode: ";
    int option;
    cin >> option;
    while (1) {
        while (option == 1) {
            print_menu1();
            cout << "Please enter a choice(0-4): ";
            int choice;
            cin >> choice;
            try {
                if (choice == 1) {
                    std::string title, presenter, link;
                    int minutes, seconds, nr_likes;
                    cout << "Please enter the title: ";
                    cin >> title;
                    cout << "Please enter the presenter: ";
                    cin >> presenter;
                    cout << "Please enter the duration(mm ss): ";
                    if (!(cin >> minutes) || !(cin >> seconds))
                        throw std::invalid_argument("Duration must be an integer!");
                    domain::time duration{};
                    duration = domain::time{minutes, seconds};
                    cout << "Please enter the number of likes: ";
                    if (!(cin >> nr_likes))
                        throw std::invalid_argument("Number of likes must be an integer!");
                    cout << "Please enter the link: ";
                    cin >> link;
                    if(link.substr(0, 4) != "www.")
                        throw std::invalid_argument("Invalid link!");
                    if (this->Services.add_services(title, presenter, duration, nr_likes, link) == 1)
                        throw std::invalid_argument("Links have to be unique! Try again!");

                }

                if (choice == 2) {
                    cout << "Please enter the link of the tutorial you want to delete: ";
                    std::string link;
                    cin >> link;
                    if (this->Services.delete_services(link) == 1)
                        throw std::invalid_argument("The link does not exist! Try again!");
                }

                if (choice == 3) {
                    std::string link, title, presenter, new_link;
                    int minutes, seconds, nr_of_likes;
                    cout << "Please enter the link of the tutorial you want to update: ";
                    cin >> link;
                    cout << "Please enter the title of the new tutorial: ";
                    cin >> title;
                    cout << "Please enter the presenter of the new tutorial: ";
                    cin >> presenter;
                    cout << "Please enter the duration of the new tutorial: ";
                    if (!(cin >> minutes) || !(cin >> seconds))
                        throw std::invalid_argument("Duration must be an integer!");
                    domain::time duration{};
                    duration = domain::time{minutes, seconds};
                    cout << "Please enter the number of likes of the new tutorial: ";
                    if (!(cin >> nr_of_likes))
                        throw std::invalid_argument("Number of likes must be an integer!");
                    cout << "Please enter link of the new tutorial: ";
                    cin >> new_link;
                    if (this->Services.update_services(link, title, presenter, duration, nr_of_likes, new_link) == 1)
                        throw std::invalid_argument("The link does not exist! Try again!");
                }
                if (choice == 4) {
                    print_all();
                }

                if (choice == 0) {
                    break;
                }
            } catch (const std::invalid_argument &e) {
                cout << "Error: " << e.what() << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }
        while(option==2){
            print_menu2();
            cout<<"Please enter an option: ";
            int choice;
            cin>>choice;
            if(choice==1){
                std::string presenter;
                std::cout << "Please enter the presenter: ";
                std::cin >> std::ws;
                std::getline(std::cin, presenter);
                auto tutorials_presenter=this->Services.find_by_presenter(presenter);
                int nr_elems=this->Services.find_by_presenter1(presenter);
                if(presenter=="0") {
                    nr_elems = this->Services.get_size_services();
                    tutorials_presenter=this->Services.get_all_services();
                }
                int unwatched_count = 0; // Counter for unwatched tutorials
                for (int i = 0; i < nr_elems; ++i) {
                    if (!tutorials_presenter[i].get_watched()) {
                        ++unwatched_count;
                    }
                }
                int i = 0;
                while (unwatched_count>0) {
                    if (!tutorials_presenter[i].get_watched()) {
                        std::cout << tutorials_presenter[i].to_string() << "\n";
                        std::string url = tutorials_presenter[i].get_link();
                        std::string command = "start " + url;
                        system(command.c_str());

                        std::cout << "Did you like the Tutorial?\n" << std::endl;
                        std::cout << "1. Yes!" << std::endl;
                        std::cout << "2. No! Go to the next tutorial." << std::endl;
                        int like;
                        std::cin >> like;
                        if (like == 1) {
                            std::cout << "Do you want to add the tutorial to your watch list?\n" << std::endl;
                            std::cout << "1. Yes!" << std::endl;
                            std::cout << "2. No!" << std::endl;
                            int add;
                            std::cin >> add;
                            if (add == 1) {
                                tutorials_presenter[i].set_watched();
                                if(this->Services.add_services1(tutorials_presenter[i])==1){
                                    cout<<"Link must be unique!";
                                }
                                --unwatched_count;
                            }
                        }
                    }
                    i = (i + 1) % nr_elems;
                    int continue1;
                    cout<<"Do you want to continue?\n";
                    cout<<"1. Yes!\n";
                    cout<<"2. No!\n";
                    cin>>continue1;
                    if(continue1==2)
                        break;
                }
            }
            if(choice==2){
                std::string link;
                cout<<"Please enter the link of the tutorial you want to delete: ";
                cin>>link;
                if(this->Services.delete_services1(link)==1)
                    cout<<"No such link!";
                else{
                    std::string command = "start " + link;
                    system(command.c_str());
                    cout<<"Do you want to like the tutorial?";
                    cout<<"1. Yes!\n";
                    cout<<"2. No!\n";
                    int like;
                    cin>>like;
                    if(like==1) {
                        auto t = this->Services.get_all_services();
                        auto it=t.begin();
                        int i = this->Services.find_services(link);
                        if (i != -1) {
                            std::advance(it, i);
                            int new_likes = it->get_nr_likes() + 1;
                            it->set_nr_likes(new_likes);
                           //changes not persisted
                        }
                    }
                }
                print_all1();
            }
            if(choice==3){
                print_all1();
            }
        }
    }
}