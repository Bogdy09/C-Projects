//
// Created by lazab on 6/24/2024.
//

#include "repository.h"
#include "iostream"
using namespace std;

Repository::Repository() {
    this->load_participants();
    this->load_questions();
    cout<<"yes";
}

void Repository::load_questions() {
    Question q;
    std::ifstream file("questions.txt");
    while(file>>q) {
        this->questions.push_back(q);
    }
    file.close();
}

void Repository::load_participants() {
    Participant p;
    std::string filePath = "participants.txt";
    std::ifstream file(filePath);
    while (file >> p) {
        this->participants.push_back(p);
    }

    file.close();
}

void Repository::notify() {
    for(auto each:this->observers) {
        each->update();
    }
}

std::vector<Question> Repository::get_questions() {
    return this->questions;
}

void Repository::register_observer(Observer *observer) {
    this->observers.push_back(observer);
}

void Repository::add(Question &question) {
    this->questions.push_back(question);
    this->notify();
    //this->saveToFile();
}

void Repository::saveToFile() {
    std::ofstream fout("questions.txt");
    for(auto &each:this->get_questions()){
        fout<<each.to_string()<<'\n';
    }
    fout.close();
}

std::vector<Participant> Repository::get_participants() {
    return this->participants;
}

int Repository::obs_size() {
    return this->observers.size();
}




