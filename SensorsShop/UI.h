//
// Created by lazab on 4/22/2024.
//

#ifndef IOT_UI_H
#define IOT_UI_H
#include "Device.h"

class UI {
private:
    Device device;

public:
    UI();
    static void print_menu();
    void run();
    void add_sensor();
    void display();
    void display_allerts();
    void write_to_file();
    static bool compare_by_producer(Sensor* a, Sensor* b);

};


#endif //IOT_UI_H
