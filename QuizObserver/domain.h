//
// Created by lazab on 6/24/2024.
//

#ifndef FINAL_QUIZ_OBSERVER_DOMAIN_H
#define FINAL_QUIZ_OBSERVER_DOMAIN_H
#include <string>
#include "fstream"
#include "iostream"

class Question {
public:
    int id;
    std::string text;
    std::string answer;
    int score;

    Question();

    Question(int id1, std::string text1, std::string answer1, int score1);

    friend std::istream& operator>>(std::istream& cin, Question& question);

    std::string to_string();
};

class Participant{
public:
    std::string name;
    int score;

    Participant();
    Participant(std::string name1, int score1);

    friend std::istream& operator>>(std::istream& cin, Participant& participant);
};

class Observer{
public:
    virtual void update()=0;
};

#endif //FINAL_QUIZ_OBSERVER_DOMAIN_H
