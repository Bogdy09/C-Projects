//
// Created by lazab on 6/24/2024.
//

#ifndef FINAL_QUIZ_OBSERVER_REPOSITORY_H
#define FINAL_QUIZ_OBSERVER_REPOSITORY_H
#include "domain.h"
#include "vector"

class Repository {
private:
    std::vector<Participant> participants;
    std::vector<Question> questions;
    std::vector<Observer*> observers;

public:
    Repository();

    void load_questions();

    void load_participants();

    void notify();

    void register_observer(Observer *observer);

    std::vector<Question> get_questions();

    void add(Question &question);

    void saveToFile();

    std::vector<Participant> get_participants();

    int obs_size();
};

#endif //FINAL_QUIZ_OBSERVER_REPOSITORY_H
