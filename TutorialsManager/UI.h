//
// Created by lazab on 3/22/2024.
//

#ifndef OOP_A4_5_BOGDY09_UI_H
#define OOP_A4_5_BOGDY09_UI_H
#include "services.h"

class UI {
    services Services;

public:
    explicit UI();
    void writeToDatabase();
    void readFromDatabase();
    static void print_menu1();
    static void print_menu2();
    void start();
    void print_all();
    void print_all1();
};


#endif //OOP_A4_5_BOGDY09_UI_H
