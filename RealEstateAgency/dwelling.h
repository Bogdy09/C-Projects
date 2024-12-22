//
// Created by lazab on 4/22/2024.
//

#ifndef T2_REAL_ESTATE_AGENCY_DWELLING_H
#define T2_REAL_ESTATE_AGENCY_DWELLING_H
#include <string>

class Dwelling {
private:
    double price;
    bool profitable;

public:
    explicit Dwelling(double price=0, bool profitable=false):price{price}, profitable{profitable}{}
    ~Dwelling()=default;
    double getPrice();
    std::string toString();
    bool isProfitable();

};


#endif //T2_REAL_ESTATE_AGENCY_DWELLING_H
