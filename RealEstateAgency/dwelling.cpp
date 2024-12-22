//
// Created by lazab on 4/22/2024.
//

#include "dwelling.h"

double Dwelling::getPrice() {
    return this->price;
}

std::string Dwelling::toString() {
    return "Price: "+std::to_string(this->price)+" Profitable: "+std::to_string(this->profitable);
}

bool Dwelling::isProfitable() {
    return this->profitable;
}




