//
// Created by lazab on 5/26/2024.
//

#ifndef TEST3_SHOPPINGLIST_DOMAIN_H
#define TEST3_SHOPPINGLIST_DOMAIN_H
#include <string>
#include <iostream>
#include <sstream>

class item {
private:
    std::string category, name;
    int quantity;

public:
    item();

    item(std::string &category, std::string &name, int quantity);

    std::string get_category();

    std::string get_name();

    int get_quantity();

    friend std::istream& operator>>(std::istream& is, item& i) {
        std::string line;
        if (std::getline(is, line)) {
            std::istringstream lineStream(line);
            std::string category1, name1, quantity1;

            if (std::getline(lineStream, category1, ';') &&
                std::getline(lineStream, name1, ';') &&
                std::getline(lineStream, quantity1, ';')) {

                // Remove leading and trailing whitespace from extracted strings
                auto trim = [](std::string& str) {
                    str.erase(0, str.find_first_not_of(" \t"));
                    str.erase(str.find_last_not_of(" \t") + 1);
                };

                trim(category1);
                trim(name1);
                trim(quantity1);

                // Convert quantity1 to an integer
                int quantity;
                std::istringstream(quantity1) >> quantity;

                // Construct the item object
                i = item(category1, name1, quantity);
            }
        }
        return is;
    }

};


#endif //TEST3_SHOPPINGLIST_DOMAIN_H
