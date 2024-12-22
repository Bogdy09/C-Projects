//
// Created by lazab on 4/20/2024.
//

#ifndef EX_T2_UI_H
#define EX_T2_UI_H
#include "Person.h"

class UI {
private:
    Person person;

public:
    UI();
    ~UI(){}
    void run_UI();
    void add_new_analysis();
    void display_analyses();
    void show_if_ill();
    void between_dates();p

};


#endif //EX_T2_UI_H
