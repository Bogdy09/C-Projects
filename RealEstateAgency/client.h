//
// Created by lazab on 4/22/2024.
//

#ifndef T2_REAL_ESTATE_AGENCY_CLIENT_H
#define T2_REAL_ESTATE_AGENCY_CLIENT_H
#include <string>
#include "dwelling.h"

class client {
protected:
    std::string name;
    double income;

public:
    client( std::string name, double income):name{name}, income{income}{}
    virtual double totalIncome();
    virtual std::string toString();
    virtual bool isInterested(Dwelling d)=0;
    virtual std::string getName();
};

class Person:public client{
public:
    bool isInterested(Dwelling d) override;
    Person(std::string name, double income): client(name, income){}
    std::string getName() override;
    std::string toString();
};

class Company:public client{
private:
    double money;

public:
    Company(std::string name, double income, double money): client(name, income), money{money}{}
    double totalIncome() override;
    std::string toString() override;
    bool isInterested(Dwelling d) override;
    std::string getName() override;
};


#endif //T2_REAL_ESTATE_AGENCY_CLIENT_H
