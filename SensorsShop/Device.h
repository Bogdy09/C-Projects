//
// Created by lazab on 4/22/2024.
//

#ifndef IOT_DEVICE_H
#define IOT_DEVICE_H
#include "Sensor.h"

class Device {
private:
    bool wf;
    std::vector<Sensor*> s;

public:
    explicit Device(bool wf=false):wf{wf}{}
    ~Device(){
        for(auto i=this->s.begin();i!=this->s.end();i++)
            delete *i;
    }
    void addSensor(Sensor *a);
    std::vector<Sensor*> getAllSensors();
    std::vector<Sensor*> getAllertingSensors();
    void writeToFile(std::vector<Sensor*> all);

};


#endif //IOT_DEVICE_H
