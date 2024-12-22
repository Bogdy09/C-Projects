//
// Created by lazab on 5/27/2024.
//

#include "domain.h"

task::task() {
    this->description="";
    this->duration=0;
    this->priority=0;
}

task::task(std::string &description, int duration, int priority):description{description}, duration{duration}, priority{priority} {
    this->description=description;
    this->duration=duration;
    this->priority=priority;
}

std::string task::get_description() {
    return this->description;
}

int task::get_duration() {
    return this->duration;
}

int task::get_priority() {
    return this->priority;
}
