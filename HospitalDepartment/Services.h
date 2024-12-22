//
// Created by lazab on 4/21/2024.
//

#ifndef T2_HOSPITAL_DEPARTMENT_SERVICES_H
#define T2_HOSPITAL_DEPARTMENT_SERVICES_H
#include "HospitalDepartment.h"
#include <vector>

class Services {
private:
    std::vector<HospitalDepartment*> dep;

public:
    Services()= default;
    ~Services(){
        for(auto i=this->dep.begin();i!=this->dep.end();i++)
            delete *i;
    }
    void addDepartment(HospitalDepartment* d);
    std::vector<HospitalDepartment*> getAllDepartments();
    std::vector<HospitalDepartment*> getAllEfficientDepartments();
    void writeToFile();
};


#endif //T2_HOSPITAL_DEPARTMENT_SERVICES_H
