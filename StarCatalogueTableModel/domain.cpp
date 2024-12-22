//
// Created by lazab on 6/23/2024.
//

#include "domain.h"
#include "sstream"

std::istream &operator>>(std::istream &cin, Astronomer &astronomer) {
    std::string line;
    std::getline(cin, line);
    if(line.empty())
        return cin;
    std::stringstream ss(line);
    std::getline(ss, astronomer.name, ';');
    std::getline(ss, astronomer.constelation, ';');
    return cin;
}

std::istream &operator>>(std::istream &cin, Star &star) {
    std::string line;
    std::getline(cin, line);
    if(line.empty())
        return cin;
    std::stringstream ss(line);
    std::getline(ss, star.name, ';');
    std::getline(ss, star.constelation, ';');
    std::string nr;
    std::getline(ss, nr, ';');
    star.ra=atoi(nr.c_str());
    std::getline(ss, nr, ';');
    star.dec=atoi(nr.c_str());
    std::getline(ss, nr, ';');
    star.diameter=atoi(nr.c_str());
    return cin;
}
