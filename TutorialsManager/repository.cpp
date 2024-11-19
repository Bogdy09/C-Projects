//
// Created by lazab on 3/22/2024.
//

#include "repository.h"
#include "domain.h"
#include <iostream>
#include <fstream>
using namespace std;


repository::repository(){
    this->tutorials=std::vector<domain::Tutorial>();
    this->watch_list=std::vector<domain::Tutorial>();
    //initialize_repo();
    readFromFile();
}

void repository::add_repo(domain::Tutorial &t){
    this->tutorials.push_back(t);
    writeToFile();
}

void repository::writeToFile() {
    std::ofstream file("smth.txt");
    for (auto &tutorial: this->tutorials) {
        file << tutorial.get_title() << ","
             << tutorial.get_presenter() << ","
             << tutorial.get_duration().minutes << ":"
             << tutorial.get_duration().seconds<<","
             << tutorial.get_nr_likes() << ","
             << tutorial.get_link()<<'\n';
    }
    file.close();
}

std::istream& operator>>(std::istream& is, domain::Tutorial& tutorial) {
    std::string title, presenter, link;
    int seconds, likes;
    int minutes;
    if (std::getline(is, title, ',') &&
        std::getline(is, presenter, ',') &&
        is >> minutes && is.ignore() &&
        is >> seconds && is.ignore() &&
        is>>likes && is.ignore() &&
        std::getline(is, link)) {
        tutorial = domain::Tutorial(title, presenter, domain::time{minutes, seconds}, likes, link);
    }
    return is;
}
std::ostream& operator<<(std::ostream& os, domain::Tutorial& t) {
    os << t.get_title() << " " << t.get_presenter() << " " << t.get_duration().minutes<<" "<<t.get_duration().seconds << " " << t.get_nr_likes() << " " << t.get_link();
    return os;
}



void repository::readFromFile() {
    std::ifstream file("smth.txt");
    this->tutorials.clear();
    domain::Tutorial t;
    while (file >> t)
    {
        this->add_repo(t);
    }
    file.close();

}
void repository::initialize_repo(){
    domain::Tutorial t1("Introduction to C++", "John Smith", domain::time{20, 30}, 12000, "www.google.com");
    domain::Tutorial t2("Object-Oriented Programming in C++", "Alice Johnson", domain::time{25, 45}, 10500, "www.oopcpp.com");
    domain::Tutorial t3("STL Containers in C++", "Emma Brown", domain::time{15, 20}, 8500, "www.stlcontainers.com");
    domain::Tutorial t4("Exception Handling in C++", "Michael Clark", domain::time{18, 10}, 9300, "www.cppexceptions.com");
    domain::Tutorial t5("Template Metaprogramming", "Sophia Davis", domain::time{30, 50}, 11000, "www.cpptemplates.com");
    domain::Tutorial t6("Concurrency in C++", "David Martinez", domain::time{22, 15}, 9700, "www.google.com");
    domain::Tutorial t7("Advanced C++ Techniques", "Olivia Wilson", domain::time{35, 40}, 12500, "www.advancedcpp.com");
    domain::Tutorial t8("C++ Best Practices", "James Taylor", domain::time{28, 20}, 11500, "www.cppbestpractices.com");
    domain::Tutorial t9("Debugging in C++", "Ethan Miller", domain::time{17, 30}, 8900, "www.cppdebugging.com");
    domain::Tutorial t10("C++ Performance Optimization", "Ava Anderson", domain::time{40, 55}, 13000, "www.cppperformance.com");
    domain::Tutorial t11("s", "David Martine", domain::time{22, 15}, 9700, "www.google.com");

}


void repository::add_repo1(domain::Tutorial &t){
    this->watch_list.push_back(t);
}

void repository::delete_repo(int index){
    this->tutorials.erase(this->tutorials.begin()+index);
    writeToFile();
}

void repository::delete_repo1(int index){
    this->watch_list.erase(this->watch_list.begin()+index);
}

void repository::update_repo(int index, domain::Tutorial &t){
    this->tutorials[index]=t;
    writeToFile();
}

vector<domain::Tutorial> repository::get_all_repo(){
    return this->tutorials;
}

vector<domain::Tutorial> repository::get_all_repo1(){
    return this->watch_list;
}

int repository::get_size_repo(){
    return this->tutorials.size();
}

int repository::get_size_repo1(){
    return this->watch_list.size();
}

int repository::get_cap_repo(){
    return this->tutorials.capacity();
}

