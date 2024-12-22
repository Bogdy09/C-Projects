//
// Created by lazab on 5/24/2024.
//

#ifndef TEST3_BILLS_DOMAIN_H
#define TEST3_BILLS_DOMAIN_H
#include <string>
#include <iostream>
#include <sstream>

namespace domain {
    class bill {
    private:
        std::string name;
        std::string number;
        double sum;
        bool paid;

    public:
        bill();

        bill(std::string &name, std::string &number, double sum, bool paid);

        domain::bill &operator=(const domain::bill &bill);

        std::string get_name();

        std::string get_number();

        double get_sum() const;

        bool get_paid() const;

        friend std::istream& operator>>(std::istream& is, domain::bill& b){
            std::string name1, number1, sumStr, paidStr;
            if (std::getline(is, name1, ';') &&
                std::getline(is, number1, ';') &&
                std::getline(is, sumStr, ';') &&
                std::getline(is, paidStr)) {

                // Remove leading and trailing whitespace from extracted strings
                name1.erase(0, name1.find_first_not_of(" \t"));
                name1.erase(name1.find_last_not_of(" \t") + 1);
                number1.erase(0, number1.find_first_not_of(" \t"));
                number1.erase(number1.find_last_not_of(" \t") + 1);
                sumStr.erase(0, sumStr.find_first_not_of(" \t"));
                sumStr.erase(sumStr.find_last_not_of(" \t") + 1);
                paidStr.erase(0, paidStr.find_first_not_of(" \t"));
                paidStr.erase(paidStr.find_last_not_of(" \t") + 1);

                std::istringstream sumStream(sumStr);
                double sum1;
                sumStream >> sum1;

                bool paid1 = (paidStr == "true");

                b = domain::bill(name1, number1, sum1, paid1);
            }
            return is;
        };
        friend std::ostream& operator<<(std::ostream& os, domain::bill& b){
            os << b.get_name() << " " << b.get_number() << " " << b.get_sum()<<" "<<b.get_paid();
            return os;
        };
    };
}

#endif //TEST3_BILLS_DOMAIN_H
