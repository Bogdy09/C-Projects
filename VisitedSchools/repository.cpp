//
// Created by lazab on 3/31/2024.
//

#include "repository.h"
#include <iostream>
using  namespace std;

repository::repository(dynamic_array<domain::school> *repo){
    this->schools=repo;
}

int repository::get_size(){
    return this->schools->get_size();
}

domain::school * repository::get_vector(){
    return this->schools->get_vector();
}

void repository::remove_repo(int index){
    this->schools->remove_vector(index);
}

void repository::add_repo(domain::school &s){
    this->schools->add_vector(s);
}

void repository::input(){
    domain::school s1=domain::school("Avram_Iancu", "46.77,23.60", domain::date{15, 4, 2022}, true);
    domain::school s2=domain::school("George_Cosbuc", "46.77,23.58", domain::date{18, 4, 2022}, false);
    domain::school s3=domain::school("Alexandru_Vaida_Voievod", "46.77,23.63", domain::date{23, 4, 2022}, false);
    domain::school s4=domain::school("Romulus_Guga", "46.53,24.57", domain::date{4, 5, 2022}, false);
    domain::school s5=domain::school("Colegiul_Transilvania", "46.54,24.57", domain::date{3, 5, 2022}, false);

    add_repo(s1);
    add_repo(s2);
    add_repo(s3);
    add_repo(s4);
    add_repo(s5);
}