//
// Created by lazab on 6/23/2024.
//

#ifndef FINAL_STAR_CATALOGUE_TABLEMODEL__DOMAIN_H
#define FINAL_STAR_CATALOGUE_TABLEMODEL__DOMAIN_H
#include "string"

class Astronomer {

public:
    std::string name;
    std::string constelation;
    Astronomer()=default;
    Astronomer( std::string& name1, std::string& constelation1):name{name1}, constelation{constelation1}{};

    std::string to_string(){
        return this->name+" "+this->constelation;
    }

    friend std::istream& operator>>(std::istream& cin, Astronomer& astronomer);

};

class Star{

public:
    std::string name;
    std::string constelation;
    int ra;
    int dec;
    int diameter;
    Star()=default;
    Star(std::string& name1, std::string& constelation1, int ra1, int dec1, int diameter1):name{name1}, constelation{constelation1}, ra{ra1}, dec{dec1}, diameter{diameter1}{};

    std::string to_string(){
        return this->name+";"+this->constelation+";"+std::to_string(this->dec)+";"+std::to_string(this->ra)+";"+std::to_string(this->diameter);
    }

    friend std::istream& operator>>(std::istream& cin, Star& star);
};

#endif //FINAL_STAR_CATALOGUE_TABLEMODEL__DOMAIN_H
