//
// Created by lazab on 6/25/2024.
//

#ifndef FINAL_RESEARCH_TABLE_MODEL_DOMAIN_H
#define FINAL_RESEARCH_TABLE_MODEL_DOMAIN_H


#include "string"

class Researcher{
public:
    std::string name;
    std::string position;

    Researcher();

    Researcher(std::string name1, std::string position1);

    friend std::istream& operator>>(std::istream& cin, Researcher &r);
};

class Idea{
public:
    std::string title;
    std::string description;
    std::string status;
    std::string creator;
    int duration;

    Idea();

    Idea(std::string title1, std::string description1, std::string status1, std::string creator1, int duration1);

    friend std::istream& operator>>(std::istream& cin, Idea &i);
};


#endif //FINAL_RESEARCH_TABLE_MODEL_DOMAIN_H
