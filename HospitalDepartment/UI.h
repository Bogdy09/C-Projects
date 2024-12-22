//
// Created by lazab on 4/21/2024.
//

#ifndef T2_HOSPITAL_DEPARTMENT_UI_H
#define T2_HOSPITAL_DEPARTMENT_UI_H
#include "Services.h"

class UI {
private:
    Services services;
public:
    UI();
    static void print_menu();
    void run();
    void add_new_department();
    void display_all();
    void display_efficient();
};


#endif //T2_HOSPITAL_DEPARTMENT_UI_H
