//
// Created by lazab on 3/31/2024.
//

#ifndef SCHOOL_TEST1_UI_H
#define SCHOOL_TEST1_UI_H
#include "services.h"

class UI {
    services *services;
public:
    explicit UI(class services *services);
    void start();
};


#endif //SCHOOL_TEST1_UI_H
