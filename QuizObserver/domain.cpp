//
// Created by lazab on 6/24/2024.
//

#include <sstream>
#include "domain.h"

Question::Question() {
    this->id=0;
    this->text="";
    this->answer="";
    this->score=0;
}

Question::Question(int id1, std::string text1, std::string answer1, int score1) {
    this->id=id1;
    this->text=text1;
    this->answer=answer1;
    this->score=score1;
}

std::istream &operator>>(std::istream &cin, Question &question) {
    std::string line;
    std::getline(cin, line);
    if(line.empty())
        return cin;
    std::stringstream ss(line);
    std::string id1;
    std::getline(ss, id1, ';');
    question.id=atoi(id1.c_str());
    std::getline(ss, question.text, ';');
    std::getline(ss, question.answer, ';');
    std::string score;
    std::getline(ss, score, ';');
    question.score=atoi(score.c_str());
    return cin;
}

std::string Question::to_string() {
    return std::to_string(this->id)+";"+this->text+";"+this->answer+";"+std::to_string(this->score);
}

Participant::Participant() {
    this->name="";
    this->score=0;
}

Participant::Participant(std::string name1, int score1) {
    this->name=name1;
    this->score=score1;
}

std::istream &operator>>(std::istream &cin, Participant &participant) {
    std::string line;
    std::getline(cin, line);
    if(line.empty())
        return cin;
    std::stringstream ss(line);
    std::getline(ss, participant.name, ';');
    std::string score1;
    std::getline(ss, score1, ';');
    participant.score=atoi(score1.c_str());
    return cin;
}
