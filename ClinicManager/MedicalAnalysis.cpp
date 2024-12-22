//
// Created by lazab on 4/20/2024.
//

#include <regex>
#include "MedicalAnalysis.h"



std::string MedicalAnalysis::toString() {
    return this->date+'\n';
}

std::string MedicalAnalysis::getDate() {
    return this->date;
}

std::string BMI::toString(){
    std::string date = MedicalAnalysis::toString();
    date = std::regex_replace(date, std::regex("^\\s+|\\s+$"), "");
    return "BMI: "+date+" "+std::to_string(this->value)+'\n';
}

bool BMI::isResultOK() {
    return this->value>=18.5 && this->value<=25.0;
}

bool BP::isResultOK() {
    return this->sys_value>=90 && this->sys_value<=119 && this->dia_value>=60 &&this->dia_value<=79;
}

std::string BP::toString() {
    std::string date = MedicalAnalysis::toString();
    date = std::regex_replace(date, std::regex("^\\s+|\\s+$"), "");
    return "BP: "+date+" "+std::to_string(this->sys_value)+" "+std::to_string(this->dia_value)+'\n';
}
