//
// Created by lazab on 4/21/2024.
//

#ifndef T2_HOSPITAL_DEPARTMENT_HOSPITALDEPARTMENT_H
#define T2_HOSPITAL_DEPARTMENT_HOSPITALDEPARTMENT_H
#include <string>
#include <utility>

class HospitalDepartment {
protected:
    std::string name;
    int nr_doctors;

public:
    virtual bool isEfficient();
    virtual std::string toString();
    explicit HospitalDepartment(std::string name="", int nr_doctors=0):name{std::move(name)}, nr_doctors{nr_doctors}{}
    virtual ~HospitalDepartment()=default;
};

class NeonatalUnit:public HospitalDepartment{
private:
    int nr_mothers;
    int nr_newborns;
    double grade;

public:
    bool isEfficient() override;
    std::string toString() override;
    explicit NeonatalUnit(std::string name="", int nr_doctors=0, int nr_mothers=0, int nr_newborns=0, double grade=0.0): HospitalDepartment(name, nr_doctors), nr_mothers{nr_mothers}, nr_newborns{nr_newborns}, grade{grade}{}
    ~NeonatalUnit() override= default;
};

class Surgery:public HospitalDepartment{
private:
    int nr_patients;

public:
    bool isEfficient() override;
    std::string toString() override;
    explicit Surgery(std::string name="", int nr_doctors=0, int nr_patients=0):HospitalDepartment(name, nr_doctors), nr_patients{nr_patients}{}
    ~Surgery() override=default;
};

#endif //T2_HOSPITAL_DEPARTMENT_HOSPITALDEPARTMENT_H
