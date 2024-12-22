//
// Created by lazab on 4/22/2024.
//

#include "Device.h"
#include <fstream>

void Device::addSensor(Sensor *a) {
    this->s.push_back(a);
}

std::vector<Sensor *> Device::getAllSensors() {
    std::vector<Sensor*> all;
    for(auto i:this->s){
        all.push_back(i);
    }
    return all;
}

std::vector<Sensor *> Device::getAllertingSensors() {
    std::vector<Sensor*> all;
    for(auto i:getAllSensors()){
        if(i->sendAlert())
            all.push_back(i);
    }
    return all;
}

void Device::writeToFile(std::vector<Sensor*> all) {
    std::ofstream file("sensors.txt", std::ios::trunc);
    for(auto a:all)
        file<<a->toString()<<'\n';
}
