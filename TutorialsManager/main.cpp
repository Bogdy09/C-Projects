//
// Created by lazab on 3/22/2024.
//
#include <iostream>
#include "domain.h"
#include "repository.h"
#include "Dynamicvector.h"
#include "services.h"
#include "UI.h"
#include "tests.h"
#include "fstream"
using namespace std;

/*void tests(){
    class tests t;
    t.test_tutorial_constructor();
    t.test_tutorial_setters_getters();
    t.test_tutorial_watched();
    t.test_tutorial_to_string();
    t.test_tutorial_equality_operator();
    t.test_dynamic_vector_constructor();
    t.test_dynamic_vector_add_and_get();
    t.test_dynamic_vector_delete();
    t.test_dynamic_vector_update();
    t.test_dynamic_vector_assignment_operator();
    t.test_dynamic_vector_resize();
    t.test_dynamic_vector_get_vector1_and_add_vector1();
    t.test_dynamic_vector_delete1();
    t.test_dynamic_vector_resize1();
    t.test_repository_constructor();
    t.test_repository_add_and_get_all_repo();
    t.test_repository_add_and_get_all_repo1();
    t.test_repository_delete_repo();
    t.test_repository_delete_repo1();
    t.test_repository_update_repo();
    t.test_services_get_all_services();
    t.test_services_get_all_services1();
    t.test_services_get_size_services();
    t.test_services_get_size_services1();
    t.test_services_add_services();
    t.test_services_delete_services();
    t.test_services_find_services();
    t.test_services_delete_services1();
    t.test_services_update_services();
    t.test_services_find_by_presenter();
    t.test_services_find_by_presenter1();
    t.test_services_add_services1();
    cout<<"All tests passed!\n";
}*/

int main(){
    //tests();
    //std::ifstream file("smth.txt");
    //file.close();
    repository repo;
    services Services;
    UI ui;
    ui.start();
    return 0;
}