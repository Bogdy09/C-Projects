//
// Created by lazab on 3/31/2024.
//

#ifndef SCHOOL_TEST1_DOMAIN_H
#define SCHOOL_TEST1_DOMAIN_H
#include <string>

namespace domain {
    struct date{
        int day;
        int month;
        int year;

        bool operator==(date other){
            return this->day==other.day&&this->month==other.month&&this->year==other.year;
        }
    };
    class school {
    private:
        std::string name;
        std::string coordinates;
        date date{};
        bool visit;

    public:
        school();
        school(const std::string &name, const std::string &coordinates, struct date date, bool visit);
        std::string get_name();
        domain::date get_date();
        bool get_visit();
        std::string to_string();
        bool operator==(const domain::school &other);
        std::string get_coordinates();
        void set_visit();
    };
}


#endif //SCHOOL_TEST1_DOMAIN_H
