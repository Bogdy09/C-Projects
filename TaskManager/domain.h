//
// Created by lazab on 5/27/2024.
//

#ifndef TEST3_TASK_MANAGER_DOMAIN_H
#define TEST3_TASK_MANAGER_DOMAIN_H
#include <string>
#include <iostream>
#include <sstream>

class task {
private:
    std::string description;
    int duration;
    int priority;

public:
    task();

    task(std::string &description, int duration, int priority);

    std::string get_description();

    int get_duration();

    int get_priority();

    friend std::istream& operator>>(std::istream& is, task &t) {
        std::string line;
        if (std::getline(is, line)) {
            std::istringstream lineStream(line);
            std::string description1, duration1, priority1;

            if (std::getline(lineStream, description1, ';') &&
                std::getline(lineStream, duration1, ';') &&
                std::getline(lineStream, priority1, ';')) {

                // Remove leading and trailing whitespace from extracted strings
                auto trim = [](std::string& str) {
                    str.erase(0, str.find_first_not_of(" \t"));
                    str.erase(str.find_last_not_of(" \t") + 1);
                };

                trim(description1);
                trim(duration1);
                trim(priority1);

                int duration2, priority2;
                std::istringstream(duration1) >> duration2;
                std::istringstream(priority1) >> priority2;

                t = task(description1, duration2, priority2);
            }
        }
        return is;
    }
};


#endif //TEST3_TASK_MANAGER_DOMAIN_H
