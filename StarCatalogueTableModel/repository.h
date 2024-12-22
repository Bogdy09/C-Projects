//
// Created by lazab on 6/23/2024.
//

#ifndef FINAL_STAR_CATALOGUE_TABLEMODEL__REPOSITORY_H
#define FINAL_STAR_CATALOGUE_TABLEMODEL__REPOSITORY_H
#include "domain.h"
#include "vector"
#include "fstream"
#include <iostream>
using namespace std;

template<typename T>
class Repository {
private:
    std::vector<T> v;
    std::string file;

public:
    Repository(std::string file1){
        this->file=file1;
        this->readFromFile();
    };

    void readFromFile(){
        std::ifstream file(this->file);
        T t;
        while(file>>t)
            this->v.push_back(t);
        file.close();
    };

    void writeToFile(){
        std::ofstream fout(this->file);
        for(auto &x:v) {
            cout << x.to_string() << '\n';
            fout << x.to_string() << '\n';
        }
        fout.close();
    }

    void add(T t){
        this->v.push_back(t);
        writeToFile();
    };

    std::vector<T> get_all(){
        return this->v;
    };

    int size(){
        return this->v.size();
    };
};


#endif //FINAL_STAR_CATALOGUE_TABLEMODEL__REPOSITORY_H
