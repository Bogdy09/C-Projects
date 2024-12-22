//
// Created by lazab on 4/22/2024.
//

#ifndef T2_REAL_ESTATE_AGENCY_REAL_ESTATE_AGENCY_H
#define T2_REAL_ESTATE_AGENCY_REAL_ESTATE_AGENCY_H
#include <vector>
#include "dwelling.h"
#include "client.h"

class real_estate_agency {
private:
    std::vector<client*> c;
    std::vector<Dwelling*> d;

public:
    real_estate_agency(){}

    ~real_estate_agency(){
        for(auto i:c)
            delete i;

    }

    void addDwelling(double price, bool profitable);
    void removeClient(std::string name);
    std::vector<client*> getInterestedClients(Dwelling d);
    void writeToFile(std::string filename);
    std::vector<client*> getAllClients();
    void add_client();
    std::vector<Dwelling*> getAllDwellings();
};


#endif //T2_REAL_ESTATE_AGENCY_REAL_ESTATE_AGENCY_H
