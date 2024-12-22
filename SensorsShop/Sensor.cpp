//
// Created by lazab on 4/22/2024.
//

#include "Sensor.h"

bool Sensor::sendAlert() {
    return false;
}

double Sensor::getPrice() {
    return 0;
}

std::string Sensor::toString() {
    std::string result="Producer: " + this->producer + " Recordings: ";
    for(auto i:this->rec) {
        result+= std::to_string(i)+", ";
    }
    return result;
}

bool TemperatureSensor::sendAlert() {
    int k=0;
    for(auto i:this->rec){
        if(i<10 || i>35)
            k++;
    }
    if(k>=2)
        return true;
    return false;
}

double TemperatureSensor::getPrice() {
    if(this->diameter<3 && this->length<50)
        return 17;
    else
        return 9;
}

std::string TemperatureSensor::toString() {
    std::string result="Producer: " + this->producer + " Type: Temperature Sensor "+" Recordings: ";
    for(auto i:this->rec) {
        result+= std::to_string(i)+", ";
    }
    result+=std::to_string(getPrice());
    result+=" Diameter: "+std::to_string(this->diameter)+" Length: "+std::to_string(this->length)+" Price: "+std::to_string(getPrice());
    return result;
}

std::string TemperatureSensor::getProducer() {
    return this->producer;
}

bool HumiditySensor::sendAlert() {
    int k=0;
    for(auto i:this->rec){
        if(i<30 || i>85)
            k++;
    }
    if(k>=2)
        return true;
    return false;
}

double HumiditySensor::getPrice() {
    return 4;
}

std::string HumiditySensor::toString() {
    std::string result="Producer: " + this->producer + " Type: Humidity Sensor "+" Recordings: ";
    for(auto i:this->rec) {
        result+= std::to_string(i)+", ";
    }
    result+=" Price: "+std::to_string(getPrice());
    return result;
}

std::string HumiditySensor::getProducer() {
    return this->producer;
}

bool SmokeSensor::sendAlert() {
    int k=0;
    for(auto i:this->rec){
        if(i>1600)
            k++;
    }
    if(k>=1)
        return true;
    return false;
}

double SmokeSensor::getPrice() {
    return 25;
}

std::string SmokeSensor::toString() {
    std::string result="Producer: " + this->producer + " Type: Smoke Sensor "+" Recordings: ";
    for(auto i:this->rec) {
        result+= std::to_string(i)+", ";
    }
    result+=" Price: "+std::to_string(getPrice());
    return result;
}

std::string SmokeSensor::getProducer() {
    return this->producer;
}
