//
// Created by lazab on 4/21/2024.
//

#include "HospitalDepartment.h"

bool HospitalDepartment::isEfficient() {
    return false;
}

std::string HospitalDepartment::toString() {
    return "Hospital name: "+this->name+" Number of doctors: "+std::to_string(this->nr_doctors);
}

bool NeonatalUnit::isEfficient() {
    return this->grade>8.5 && this->nr_newborns>=this->nr_mothers;
}

std::string NeonatalUnit::toString() {
    return "Hospital name: "+this->name+" Number of doctors: "+std::to_string(this->nr_doctors)+" Number of mothers: "+std::to_string(this->nr_mothers)+" Number of newborns: "+std::to_string(this->nr_newborns)+" Grade: "+std::to_string(this->grade);
}

bool Surgery::isEfficient() {
    double result;
    result=this->nr_patients/this->nr_doctors;
    return result>=2;
}

std::string Surgery::toString() {
    return "Hospital name: "+this->name+" Number of doctors: "+std::to_string(this->nr_doctors)+" Number of patients: "+std::to_string(this->nr_patients);
}
