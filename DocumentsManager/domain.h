//
// Created by lazab on 5/25/2024.
//

#ifndef TEST3_SEARCH_ENGINE_DOMAIN_H
#define TEST3_SEARCH_ENGINE_DOMAIN_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class search {
private:
    std::string name;
    std::vector<std::string> keywords;
    std::string content;

public:
    search();

    search(std::string &name, std::vector<std::string> keywords, std::string &content);

    std::string get_name();

    std::vector<std::string> get_keywords();

    std::string get_content();

    search &operator=(const search &search);

    friend std::istream& operator>>(std::istream& is, search& s) {
        std::string line;
        if (std::getline(is, line)) {
            std::istringstream lineStream(line);
            std::string name1, keywords1, content1;

            if (std::getline(lineStream, name1, ';') &&
                std::getline(lineStream, keywords1, ';')) {
                // Read the rest of the line as content1
                if (std::getline(lineStream, content1)) {

                    // Remove leading and trailing whitespace from extracted strings
                    auto trim = [](std::string& str) {
                        str.erase(0, str.find_first_not_of(" \t"));
                        str.erase(str.find_last_not_of(" \t") + 1);
                    };

                    trim(name1);
                    trim(keywords1);
                    trim(content1);

                    // Split keywords1 into individual keywords
                    std::vector<std::string> keywords;
                    std::istringstream iss(keywords1);
                    std::string keyword;
                    while (std::getline(iss, keyword, ',')) {
                        trim(keyword);  // Trim whitespace around each keyword
                        if (!keyword.empty()) {
                            keywords.push_back(keyword);
                        }
                    }

                    s = search(name1, keywords, content1);
                }
            }
        }
        return is;
    }

};


#endif //TEST3_SEARCH_ENGINE_DOMAIN_H
