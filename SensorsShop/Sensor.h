//
// Created by lazab on 4/22/2024.
//

#ifndef IOT_SENSOR_H
#define IOT_SENSOR_H
#include <string>
#include <utility>
#include <vector>

class Sensor {
protected:
    std::string producer;
    std::vector<double> rec;

public:
    virtual bool sendAlert();
    virtual double getPrice();
    virtual std::string toString();
    explicit Sensor(std::string producer="", const std::string& type="", const std::vector<double>& rec={}, double price=0): producer{std::move(producer)}, rec{rec}{}
    ~Sensor()= default;
    virtual std::string getProducer()= 0;
};

class TemperatureSensor:public Sensor{
private:
    double diameter;
    double length;
public:
    explicit TemperatureSensor(std::string producer="", const std::string& type="Temperature Sensor", const std::vector<double>& rec={}, double price=9, double diameter=0, double length=0): Sensor(std::move(producer),"", rec, 0), diameter{diameter}, length{length}{}
    bool sendAlert() override;
    double getPrice() override;
    std::string toString() override;
    std::string getProducer() override;
    ~TemperatureSensor()= default;
};

class HumiditySensor:public Sensor{
public:
    explicit HumiditySensor(std::string producer="", const std::string& type="Temperature Sensor", const std::vector<double>& rec={}, double price=4): Sensor(std::move(producer),"", rec, 0){}
    bool sendAlert() override;
    double getPrice() override;
    std::string toString() override;
    std::string getProducer() override;
    ~HumiditySensor()= default;
};

class SmokeSensor:public Sensor{
public:
    explicit SmokeSensor(std::string producer="", const std::string& type="Smoke Sensor", const std::vector<double>& rec={}, double price=25): Sensor(std::move(producer),"", rec, 0){}
    bool sendAlert() override;
    double getPrice() override;
    std::string toString() override;
    std::string getProducer() override;
    ~SmokeSensor()= default;
};


#endif //IOT_SENSOR_H
