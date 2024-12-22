//
// Created by lazab on 4/22/2024.
//

#ifndef T2_REAL_ESTATE_AGENCY_UI_H
#define T2_REAL_ESTATE_AGENCY_UI_H
#include "real_estate_agency.h"

class UI {
private:
    real_estate_agency agency;

public:
    UI();

    void menu();

    void run();

    void remove_client();

    void display_clients();

    void display_dwellings();

    void add_dwelling();

    void write_to_file();
};


#endif //T2_REAL_ESTATE_AGENCY_UI_H
