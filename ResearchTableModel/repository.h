//
// Created by lazab on 6/25/2024.
//

#ifndef FINAL_RESEARCH_TABLE_MODEL_REPOSITORY_H
#define FINAL_RESEARCH_TABLE_MODEL_REPOSITORY_H
#include "domain.h"
#include "vector"

class Repository {
private:
    std::vector<Researcher> researchers;
    std::vector<Idea> ideas;

public:
    Repository();

    void load_researchers();

    void load_ideas();

    int size() const;

    std::vector<Researcher> get_researchers();

    std::vector<Idea> get_ideas();

    void add(Idea i);

    void update_status(int row);
};


#endif //FINAL_RESEARCH_TABLE_MODEL_REPOSITORY_H
