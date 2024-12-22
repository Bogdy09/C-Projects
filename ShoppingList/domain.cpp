//
// Created by lazab on 5/26/2024.
//

#include "domain.h"

item::item() {
    this->category="";
    this->name="";
    this->quantity=0;
}

item::item(std::string &category, std::string &name, int quantity):category{category}, name{name}, quantity{quantity} {
    this->category=category;
    this->name=name;
    this->quantity=quantity;
}

std::string item::get_category() {
    return this->category;
}

std::string item::get_name() {
    return this->name;
}

int item::get_quantity() {
    return this->quantity;
}


