//
// Created by lazab on 3/23/2024.
//

#ifndef OOP_A4_5_BOGDY09_SERVICES_H
#define OOP_A4_5_BOGDY09_SERVICES_H
#include "repository.h"

class services {
    repository Repository;

public:
    explicit services();
    std::vector<domain::Tutorial> get_all_services();
    int get_size_services();
    int add_services(const std::string &title, const std::string &presenter, domain::time duration, int nr_likes,
                                const std::string &link);
    int delete_services(const std::string &link);
    int update_services(std::string &link, std::string &title, std::string &presenter, domain::time duration, int nr_of_likes,
                                  std::string &new_link);
    std::vector<domain::Tutorial> find_by_presenter(std::string &presenter);
    int find_by_presenter1(std::string &presenter);
    int add_services1(domain::Tutorial t);
    int get_size_services1();
    std::vector<domain::Tutorial> get_all_services1();
    int delete_services1(const std::string &link);
    int find_services(const std::string &link);
    void setFileName(std::string newFileName);
    std::string getFileName() const;
    void saveProgress();
    void loadFromFile();
};


#endif //OOP_A4_5_BOGDY09_SERVICES_H
