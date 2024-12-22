//
// Created by lazab on 3/31/2024.
//

#include "dynamic_array.h"

void Test_remove(){
    auto *repo=new dynamic_array<domain::school>();
    repository repository(repo);
    repository.input();
    assert(repository.get_size()==5);

    repository.remove_repo(4);
    assert(repository.get_size()==4);
}

int main() {
    Test_remove();
    auto* dyn_array=new dynamic_array<domain::school>();
    auto* repo=new repository(dyn_array);
    auto* services=new class services(repo);
    auto* UI=new class UI(services);
    repo->input();
    UI->start();
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
void repository::input(){
    domain::school s1=domain::school("Avram_Iancu", "46.77,23.60", domain::date{15, 4, 2022}, true);
    domain::school s2=domain::school("George_Cosbuc", "46.77,23.58", domain::date{18, 4, 2022}, false);
    domain::school s3=domain::school("Alexandru_Vaida_Voievod", "46.77,23.63", domain::date{23, 4, 2022}, false);
    domain::school s4=domain::school("Romulus_Guga", "46.53,24.57", domain::date{4, 5, 2022}, false);
    domain::school s5=domain::school("Colegiul_Transilvania", "46.54,24.57", domain::date{3, 5, 2022}, false);

    add_repo(s1);
    add_repo(s2);
    add_repo(s3);
    add_repo(s4);
    add_repo(s5);
}
