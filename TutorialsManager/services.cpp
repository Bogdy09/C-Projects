//
// Created by lazab on 3/23/2024.
//

#include "services.h"
#include "domain.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
services::services() {
    this->Repository=repository();
}


vector<domain::Tutorial> services::get_all_services(){
    return this->Repository.get_all_repo();
}

vector<domain::Tutorial> services::get_all_services1(){
    return this->Repository.get_all_repo1();
}

int services::get_size_services() {
    return this->Repository.get_size_repo();
}

int services::get_size_services1() {
    return this->Repository.get_size_repo1();
}

int services::add_services(const std::string &title, const std::string &presenter, domain::time duration, int nr_likes,
                            const std::string &link) {
    vector<domain::Tutorial> all_tutorials=get_all_services();
    auto i=all_tutorials.begin();
    for(;i!=all_tutorials.end();++i){
        if(i->get_link()==link)
            return 1;
    }
    domain::Tutorial t=domain::Tutorial(title, presenter, duration, nr_likes, link);
    this->Repository.add_repo(t);
    return 0;
}

int services::delete_services(const std::string &link){
    vector<domain::Tutorial> all_tutorials=get_all_services();
    auto i=all_tutorials.begin();
    int pos=0;
    for(;i!=all_tutorials.end();i++){
        if(i->get_link()==link){
            this->Repository.delete_repo(pos);
            return 0;
        }
        pos++;
    }
    return 1;
}


int services::find_services(const std::string &link) {
    vector<domain::Tutorial> all_tutorials = get_all_services();

    auto it = std::find_if(all_tutorials.begin(), all_tutorials.end(),
                           [&](domain::Tutorial tutorial) {
                               return tutorial.get_link() == link;
                           });

    if (it != all_tutorials.end()) {
        return std::distance(all_tutorials.begin(), it);
    } else {
        return -1; // Link not found
    }
}

int services::delete_services1(const std::string &link){
    vector<domain::Tutorial> all_tutorials=get_all_services1();
    int index=-1;
    int pos=0;
    auto i=all_tutorials.begin();
    for (;i!=all_tutorials.end();i++) {
        if(i->get_link()==link){
            index=pos;
            break;
        }
        pos++;
    }
    if(index!=-1) {
        this->Repository.delete_repo1(index);
        return 0;
    }
    else
        return 1;
}

int services::update_services(std::string &link, std::string &title, std::string &presenter, domain::time duration, int nr_of_likes,
                              std::string &new_link){
    vector<domain::Tutorial> all_tutorials=get_all_services();
    int index=-1;
    int pos=0;
    auto i=all_tutorials.begin();
    for (;i!=all_tutorials.end();i++) {
        if(i->get_link()==link){
            index=pos;
            break;
        }
        pos++;
    }
    if(index!=-1) {
        domain::Tutorial t=domain::Tutorial(title, presenter, duration, nr_of_likes, new_link);
        this->Repository.update_repo(index, t);
        return 0;
    }
    else
        return 1;
}

vector<domain::Tutorial> services::find_by_presenter(std::string &presenter) {
    auto all_tutorials = get_all_services();
    vector<domain::Tutorial> t1;

    std::find_if(all_tutorials.begin(), all_tutorials.end(), [&](const domain::Tutorial& tutorial) {
        if (tutorial.get_presenter() == presenter) {
            t1.push_back(tutorial);
        }
        return false;
    });

    return t1;
}

int services::find_by_presenter1(std::string &presenter){
    auto t=get_all_services();
    auto *t1=new domain::Tutorial[100];
    int k=0;
    int size=get_size_services();
    for(int i=0;i<size;i++){
        if(t[i].get_presenter()==presenter)
            t1[k++]=t[i];
    }
    return k;
}

int services::add_services1(domain::Tutorial t) {
    vector<domain::Tutorial> all_tutorials=get_all_services1();
    auto i=all_tutorials.begin();
    for (;i!=all_tutorials.end();i++) {
        if(i->get_link()==t.get_link())
            return 1;
    }
    this->Repository.add_repo1(t);
    return 0;
}





void services::saveProgress()
{
    this->Repository.writeToFile();
}

void services::loadFromFile()
{
    this->Repository.readFromFile();
}
