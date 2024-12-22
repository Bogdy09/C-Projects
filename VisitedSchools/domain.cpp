//
// Created by lazab on 3/31/2024.
//

#include "domain.h"

domain::school::school(){
    this->name="";
    this->coordinates="";
    this->date={0, 0, 0};
    this->visit=false;
}

domain::school::school(const std::string &name, const std::string &coordinates, struct date date, bool visit):name(name), coordinates(coordinates), date(date), visit(visit) {
    this->name=name;
    this->coordinates=coordinates;
    this->date=date;
    this->visit=visit;
}

std::string domain::school::get_name(){
    return this->name;
}

domain::date domain::school::get_date(){
    return this->date;
}

bool domain::school::get_visit(){
    return this->visit;
}

std::string domain::school::get_coordinates(){
    return this->coordinates;
}

void domain::school::set_visit(){
    this->visit=true;
}

bool domain::school::operator==(const domain::school &other){
    if(this->name==other.name && this->coordinates==other.coordinates && this->date==other.date && this->visit==other.visit)
        return true;
    return false;
}

std::string domain::school::to_string(){
    auto day=std::to_string(this->date.day);
    auto month=std::to_string(this->date.month);
    auto year=std::to_string(this->date.year);
    auto visit1=std::to_string(this->visit);
    return "Name: "+this->name+" Coordinates: "+this->coordinates+" Date: "+day+"."+month+"."+year+" Visited: "+visit1;
}