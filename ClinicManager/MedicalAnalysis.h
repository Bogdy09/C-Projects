//
// Created by lazab on 4/20/2024.
//

#ifndef EX_T2_MEDICALANALYSIS_H
#define EX_T2_MEDICALANALYSIS_H


#include <string>

class MedicalAnalysis {
protected:
    std::string date;

public:
    virtual bool isResultOK()=0;
    virtual std::string toString();
    explicit MedicalAnalysis(const std::string &date=""):date{date}{}
    virtual ~MedicalAnalysis()= default;
    std::string getDate();
};

class BMI:public MedicalAnalysis{
private:
    double value;

public:
    bool isResultOK() override;
    explicit BMI(const std::string &date="", double value=0): MedicalAnalysis(date), value{value}{}
    ~BMI(){}
    std::string toString() override;
};

class BP:public MedicalAnalysis{
private:
    int sys_value;
    int dia_value;

public:
    explicit BP(const std::string &date="", int sys=0, int dia=0): MedicalAnalysis(date), sys_value{sys}, dia_value{dia}{}
    ~BP(){}
    bool isResultOK() override;
    std::string toString() override;
};


#endif //EX_T2_MEDICALANALYSIS_H
