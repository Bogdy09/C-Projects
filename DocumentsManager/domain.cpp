//
// Created by lazab on 5/25/2024.
//

#include "domain.h"

search::search() {
    this->name="";
    this->keywords={""};
    this->content="";
}

search::search(std::string &name, std::vector<std::string> keywords, std::string &content):name{name}, keywords{keywords}, content{content} {
    this->name=name;
    this->keywords=keywords;
    this->content=content;
}

std::string search::get_name() {
    return this->name;
}

std::vector<std::string> search::get_keywords() {
    return this->keywords;
}

std::string search::get_content() {
    return this->content;
}

search &search::operator=(const search &search) {
    if (this == &search)
        return *this;

    this->name = search.name;
    this->keywords=search.keywords;
    this->content=search.content;

    return *this;
}


