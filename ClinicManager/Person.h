//
// Created by lazab on 4/20/2024.
//

#ifndef EX_T2_PERSON_H
#define EX_T2_PERSON_H
#include <string>
#include "MedicalAnalysis.h"
#include <utility>
#include <vector>

class Person {
private:
    std::string name;
    std::vector<MedicalAnalysis*> analyses;

public:
    void addAnalysis(MedicalAnalysis *a);
    explicit Person(std::string name=""):name{std::move(name)}{}
    ~Person(){
        for(auto i=this->analyses.begin();i!=this->analyses.end();i++)
            delete *i;
    }
    std::vector<MedicalAnalysis*> getAllAnalyses();
    void writeToFile(std::vector<MedicalAnalysis*> all);
    std::vector<MedicalAnalysis*> getAnalysesByMonth(std::string& month);
    bool isIll(std::string& month);
};


#endif //EX_T2_PERSON_H
