//
// Created by lazab on 6/25/2024.
//
#include <iostream>
using namespace std;
#include "repository.h"
#include <fstream>

Repository::Repository() {
    this->load_researchers();
    this->load_ideas();
}

void Repository::load_researchers() {
    Researcher r;
    std::ifstream file("researchers.txt");
    while(file>>r)
        this->researchers.push_back(r);
    file.close();
}

void Repository::load_ideas() {
    Idea i;
    std::ifstream file("ideas.txt");
    while(file>>i)
        this->ideas.push_back(i);
    file.close();
}

int Repository::size() const {
    return this->ideas.size();
}

std::vector<Researcher> Repository::get_researchers() {
    return this->researchers;
}

std::vector<Idea> Repository::get_ideas(){
    return this->ideas;
}

void Repository::add(Idea i) {
    this->ideas.push_back(i);
}

void Repository::update_status(int row) {
    this->ideas[row].status="accepted";
    for(auto each:this->ideas)
        cout<<each.title<<' '<<each.status<<'\n';
}
