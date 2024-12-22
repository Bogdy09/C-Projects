//
// Created by lazab on 6/25/2024.
//

#include <sstream>
#include "domain.h"
#include "iostream"

Researcher::Researcher() {
    this->name="";
    this->position="";
}

Researcher::Researcher(std::string name1, std::string position1) {
    this->name=name1;
    this->position=position1;
}

std::istream& operator>>(std::istream& cin, Researcher &r) {
    std::string line;
    std::getline(cin, line);
    if(line.empty())
        return cin;
    std::stringstream ss(line);
    std::getline(ss, r.name, ';');
    std::getline(ss, r.position, ';');
    return cin;
}

Idea::Idea() {
    this->title="";
    this->description="";
    this->creator="";
    this->status="";
    this->duration=0;
}

Idea::Idea(std::string title1, std::string description1, std::string status1, std::string creator1, int duration1) {
    this->title=title1;
    this->description=description1;
    this->creator=creator1;
    this->status=status1;
    this->duration=duration1;
}

std::istream &operator>>(std::istream &cin, Idea &i) {
    std::string line;
    std::getline(cin, line);
    if(line.empty())
        return cin;
    std::stringstream ss(line);
    std::getline(ss, i.title, ';');
    std::getline(ss, i.description, ';');
    std::getline(ss, i.status, ';');
    std::getline(ss, i.creator, ';');
    std::string nr;
    std::getline(ss, nr, ';');
    i.duration=atoi(nr.c_str());
    return cin;
}
