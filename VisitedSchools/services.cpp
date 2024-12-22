//
// Created by lazab on 3/31/2024.
//

#include "services.h"
#include <iostream>
using namespace std;
services::services(class repository *repo1) {
    this->repo=repo1;
}

int services::get_size(){
    return this->repo->get_size();
}

domain::school* services::get_all(){
    return this->repo->get_vector();
}

int services::remove_services(std::string &name, std::string &coordinates){
    int index=-1;
    int size=this->repo->get_size();
    domain::school* all_schools=this->repo->get_vector();
    for(int i=0;i<size;i++){
        if(all_schools[i].get_name()==name && all_schools[i].get_coordinates()==coordinates) {
            index = i;
            break;
        }
    }
    if(index==-1)
        return 0;
    this->repo->remove_repo(index);
    return 1;
}

domain::school* services::sort_by_name(){
    auto * arr=new domain::school[100];
    domain::school* all_schools=this->repo->get_vector();
    int size=this->repo->get_size();
    arr=all_schools;
    for(int i=0;i<size-1;i++){
        for(int j=i;j<size;j++){
            if(arr[i].get_name()>arr[j].get_name()) {
                domain::school aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    return arr;
}

bool services::isDateLess(const domain::date& date1, const domain::date& date2){
    if (date1.year < date2.year)
        return true;
    else if (date1.year > date2.year)
        return false;
    else {
        if (date1.month < date2.month)
            return true;
        else if (date1.month > date2.month)
            return false;
        else {
            if (date1.day < date2.day)
                return true;
            else
                return false;
        }
    }
}

