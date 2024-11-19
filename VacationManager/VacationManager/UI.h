//
// Created by lazab on 3/16/2024.
//

#ifndef A2_3_BOGDY09_UI_H
#define A2_3_BOGDY09_UI_H
#include "OperationsStack.h"
#pragma once
#include "services.h"


typedef struct
{
    Service* serv;
} UI;

UI* createUI(Service* s);
void destroyUI(UI* ui);

void startUI(UI* ui);


#endif //A2_3_BOGDY09_UI_H
