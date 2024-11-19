//
// Created by lazab on 3/23/2024.
//
/*
#include "tests.h"
#include "domain.h"
#include "Dynamicvector.h"
#include "repository.h"
#include "services.h"
#include <cassert>
#include <stdexcept>
#include <cstring>
#include <string>
#include "DynamicVector.h"

void tests::test_tutorial_constructor() {
    domain::Tutorial tutorial;
    assert(tutorial.get_title() == "");
    assert(tutorial.get_presenter() == "");
    assert(tutorial.get_duration().minutes == 0);
    assert(tutorial.get_duration().seconds == 0);
    assert(tutorial.get_nr_likes() == 0);
    assert(tutorial.get_link() == "");
}

void tests::test_tutorial_setters_getters() {
    domain::Tutorial tutorial;
    tutorial.set_title("Title");
    tutorial.set_presenter("Presenter");
    tutorial.set_duration(10, 30);
    tutorial.set_nr_likes(100);
    tutorial.set_link("https://example.com");

    assert(tutorial.get_title() == "Title");
    assert(tutorial.get_presenter() == "Presenter");
    assert(tutorial.get_duration().minutes == 10);
    assert(tutorial.get_duration().seconds == 30);
    assert(tutorial.get_nr_likes() == 100);
    assert(tutorial.get_link() == "https://example.com");
}

void tests::test_tutorial_watched() {
    domain::Tutorial tutorial;
    tutorial.set_watched();
    assert(tutorial.get_watched() == true);
}

void tests::test_tutorial_to_string() {
    domain::Tutorial tutorial("Title", "Presenter", {15, 45}, 200, "https://example.com");
    std::string expected = "Title: Title Presenter: Presenter Duration: 15 45 Likes: 200 Link: https://example.com";
    assert(tutorial.to_string() == expected);
}

void tests::test_tutorial_equality_operator() {
    domain::Tutorial tutorial1("Title1", "Presenter1", {15, 45}, 200, "https://example.com");
    domain::Tutorial tutorial2("Title2", "Presenter2", {10, 30}, 150, "https://example.com");

    assert(!(tutorial1 == tutorial2));

    tutorial2.set_title("Title1");
    tutorial2.set_presenter("Presenter1");
    tutorial2.set_duration(15, 45);
    tutorial2.set_nr_likes(200);

    assert(tutorial1 == tutorial2);
}


void tests::test_dynamic_vector_constructor() {
    Dynamic_vector<domain::Tutorial> vector;
    assert(vector.get_size() == 0);
    assert(vector.get_cap() == 10); // Assuming default capacity is 10
}

void tests::test_dynamic_vector_add_and_get() {
    Dynamic_vector<domain::Tutorial> vector;
    domain::Tutorial t1("Best of C++", "Arthur Chad", {23, 21}, 123, "www.ubbcluj.ro");
    domain::Tutorial t2("Data Structures", "John Doe", {30, 15}, 200, "www.example.com");

    vector.add_vector(t1);
    vector.add_vector(t2);

    assert(vector.get_size() == 2);
    assert(vector.get_vector()[0] == t1);
    assert(vector.get_vector()[1] == t2);
}

void tests::test_dynamic_vector_delete() {
    Dynamic_vector<domain::Tutorial> vector;
    domain::Tutorial t1("Best of C++", "Arthur Chad", {23, 21}, 123, "www.ubbcluj.ro");
    domain::Tutorial t2("Data Structures", "John Doe", {30, 15}, 200, "www.example.com");

    vector.add_vector(t1);
    vector.add_vector(t2);

    vector.delete_vector(0);
    assert(vector.get_size() == 1);
    assert(vector.get_vector()[0] == t2);
}

void tests::test_dynamic_vector_update() {
    Dynamic_vector<domain::Tutorial> vector;
    domain::Tutorial t1("Best of C++", "Arthur Chad", {23, 21}, 123, "www.ubbcluj.ro");

    vector.add_vector(t1);
    domain::Tutorial updated_tutorial("Updated Title", "Updated Presenter", {10, 10}, 50, "www.updated.com");
    vector.update_vector(0, updated_tutorial);
    assert(vector.get_vector()[0] == updated_tutorial);
}

void tests::test_dynamic_vector_assignment_operator() {
    Dynamic_vector<domain::Tutorial> vector1;
    domain::Tutorial t1("Best of C++", "Arthur Chad", {23, 21}, 123, "www.ubbcluj.ro");
    domain::Tutorial t2("Data Structures", "John Doe", {30, 15}, 200, "www.example.com");

    vector1.add_vector(t1);
    vector1.add_vector(t2);

    Dynamic_vector<domain::Tutorial> vector2;
    vector2 = vector1;

    assert(vector2.get_size() == 2);
    assert(vector2.get_vector()[0] == t1);
    assert(vector2.get_vector()[1] == t2);
}

void tests::test_dynamic_vector_resize() {
    Dynamic_vector<domain::Tutorial> vector;
    for (int i = 0; i < 20; ++i) {
        domain::Tutorial t("Title" + std::to_string(i), "Presenter" + std::to_string(i), {i, i}, i * 10, "www.example.com");
        vector.add_vector(t);
    }

    assert(vector.get_size() == 20);
    assert(vector.get_cap() == 20); // Assuming default capacity is doubled
}

void tests::test_repository_constructor() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);

    assert(repo.get_size_repo() == 0);
    assert(repo.get_size_repo1() == 0);
    assert(repo.get_cap_repo() == 10); // Assuming default capacity is 10
}

void tests::test_repository_add_and_get_all_repo() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);

    domain::Tutorial t1("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    domain::Tutorial t2("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    repo.add_repo(t1);
    repo.add_repo(t2);

    assert(repo.get_size_repo() == 2);

    domain::Tutorial* all_tutorials = repo.get_all_repo();
    assert(all_tutorials[0] == t1);
    assert(all_tutorials[1] == t2);
}

void tests::test_repository_add_and_get_all_repo1() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);

    domain::Tutorial t1("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    domain::Tutorial t2("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    repo.add_repo1(t1);
    repo.add_repo1(t2);

    assert(repo.get_size_repo1() == 2);

    domain::Tutorial* all_watch_list = repo.get_all_repo1();
    assert(all_watch_list[0] == t1);
    assert(all_watch_list[1] == t2);
}

void tests::test_repository_delete_repo() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);

    domain::Tutorial t1("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    domain::Tutorial t2("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    repo.add_repo(t1);
    repo.add_repo(t2);

    repo.delete_repo(0);

    assert(repo.get_size_repo() == 1);
    assert(repo.get_all_repo()[0] == t2);
}

void tests::test_repository_delete_repo1() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);

    domain::Tutorial t1("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    domain::Tutorial t2("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    repo.add_repo1(t1);
    repo.add_repo1(t2);

    repo.delete_repo1(0);

    assert(repo.get_size_repo1() == 1);
    assert(repo.get_all_repo1()[0] == t2);
}

void tests::test_repository_update_repo() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);

    domain::Tutorial t1("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    domain::Tutorial updated_tutorial("Updated Title", "Updated Presenter", {10, 10}, 50, "www.updated.com");

    repo.add_repo(t1);
    repo.update_repo(0, updated_tutorial);

    assert(repo.get_all_repo()[0] == updated_tutorial);
}

void tests::test_services_get_all_services() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    domain::Tutorial t1("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    domain::Tutorial t2("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    repo.add_repo(t1);
    repo.add_repo(t2);

    domain::Tutorial* all_services = srv.get_all_services();

    assert(all_services[0] == t1);
    assert(all_services[1] == t2);
}

void tests::test_services_get_all_services1() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    domain::Tutorial t1("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    domain::Tutorial t2("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    repo.add_repo1(t1);
    repo.add_repo1(t2);

    domain::Tutorial* all_services1 = srv.get_all_services1();

    assert(all_services1[0] == t1);
    assert(all_services1[1] == t2);
}

void tests::test_services_get_size_services() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    domain::Tutorial t1("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    domain::Tutorial t2("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    repo.add_repo(t1);
    repo.add_repo(t2);

    assert(srv.get_size_services() == 2);
}

void tests::test_services_get_size_services1() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    domain::Tutorial t1("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    domain::Tutorial t2("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    repo.add_repo1(t1);
    repo.add_repo1(t2);

    assert(srv.get_size_services1() == 2);
}

void tests::test_services_add_services() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    assert(srv.add_services("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com") == 0);
    assert(srv.add_services("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com") == 0);

    // Adding a tutorial with the same link should return 1 (indicating failure)
    assert(srv.add_services("Template Metaprogramming", "Sophia Davis", {30, 50}, 11000, "www.cppintro.com") == 1);

    assert(srv.get_size_services() == 2);
}

void tests::test_services_delete_services() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    srv.add_services("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    srv.add_services("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    assert(srv.delete_services("www.cppintro.com") == 0);
    assert(srv.delete_services("www.oopcpp.com") == 0);
    // Deleting a non-existing tutorial should return 1 (indicating failure)
    assert(srv.delete_services("www.nonexistent.com") == 1);

    assert(srv.get_size_services() == 0);
}

void tests::test_services_find_services() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    srv.add_services("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    srv.add_services("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    assert(srv.find_services("www.cppintro.com") == 0);
    assert(srv.find_services("www.oopcpp.com") == 1);
    // Finding a non-existing tutorial should return -1
    assert(srv.find_services("www.nonexistent.com") == -1);
}

void tests::test_services_delete_services1() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    // Adding tutorials to the watch list
    domain::Tutorial t1("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    domain::Tutorial t2("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");
    srv.add_services1(t1);
    srv.add_services1(t2);

    // Deleting a tutorial that exists in the watch list
    assert(srv.delete_services1("www.cppintro.com") == 0);
    assert(srv.get_size_services1() == 1); // One tutorial should be deleted

    // Deleting a tutorial that doesn't exist in the watch list
    assert(srv.delete_services1("www.nonexistent.com") == 1);
    assert(srv.get_size_services1() == 1);
}

void tests::test_services_update_services() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    srv.add_services("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");

    std::string link = "www.cppintro.com";
    std::string new_link = "www.updated.com";
    std::string title = "Updated Tutorial";
    std::string presenter = "Updated Presenter";
    domain::time duration = {25, 30};
    int nr_of_likes = 15000;

    assert(srv.update_services(link, title, presenter, duration, nr_of_likes, new_link) == 0);

    domain::Tutorial* updated_tutorial = srv.get_all_services();
    assert(updated_tutorial[0].get_link() == new_link);
    assert(updated_tutorial[0].get_title() == title);
    assert(updated_tutorial[0].get_presenter() == presenter);
    assert(updated_tutorial[0].get_duration().minutes == 25);
    assert(updated_tutorial[0].get_duration().seconds == 30);
    assert(updated_tutorial[0].get_nr_likes() == nr_of_likes);
}

void tests::test_services_find_by_presenter() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    srv.add_services("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    srv.add_services("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    std::string presenter = "John Smith";
    domain::Tutorial* tutorials_by_presenter = srv.find_by_presenter(presenter);

    assert(tutorials_by_presenter[0].get_presenter() == presenter);
}

void tests::test_services_find_by_presenter1() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    srv.add_services("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    srv.add_services("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    std::string presenter = "John Smith";
    int count = srv.find_by_presenter1(presenter);

    assert(count == 1);
}

void tests::test_services_add_services1() {
    Dynamic_vector<domain::Tutorial> repo_vector;
    repository repo(&repo_vector);
    services srv(&repo);

    domain::Tutorial t1("Introduction to C++", "John Smith", {20, 30}, 12000, "www.cppintro.com");
    domain::Tutorial t2("Object-Oriented Programming in C++", "Alice Johnson", {25, 45}, 10500, "www.oopcpp.com");

    srv.add_services1(t1);
    srv.add_services1(t2);

    // Adding a tutorial with the same link should return 1 (indicating failure)
    assert(srv.add_services1(t1) == 1);

    assert(srv.get_size_services1() == 2);
}


void tests::test_dynamic_vector_get_vector1_and_add_vector1() {
    Dynamic_vector<domain::Tutorial> vector;
    domain::Tutorial t1("Best of C++", "Arthur Chad", {23, 21}, 123, "www.ubbcluj.ro");
    domain::Tutorial t2("Data Structures", "John Doe", {30, 15}, 200, "www.example.com");

    vector.add_vector1(t1);
    vector.add_vector1(t2);

    assert(vector.get_size1() == 2);
    assert(vector.get_vector1()[0] == t1);
    assert(vector.get_vector1()[1] == t2);
}

void tests::test_dynamic_vector_delete1() {
    Dynamic_vector<domain::Tutorial> vector;
    domain::Tutorial t1("Best of C++", "Arthur Chad", {23, 21}, 123, "www.ubbcluj.ro");
    domain::Tutorial t2("Data Structures", "John Doe", {30, 15}, 200, "www.example.com");

    vector.add_vector1(t1);
    vector.add_vector1(t2);

    vector.delete_vector1(0);
    assert(vector.get_size1() == 1);
    assert(vector.get_vector1()[0] == t2);
}

void tests::test_dynamic_vector_resize1() {
    // Create a Dynamic_vector with initial capacity 5
    Dynamic_vector<int> vector(5);

    // Add some elements to the vector
    vector.add_vector1(1);
    vector.add_vector1(2);
    vector.add_vector1(3);

    // Resize the vector
    vector.resize1();

    // Check if capacity is doubled
    assert(vector.get_cap() == 5);

    // Check if all elements are preserved after resizing
    assert(vector.get_vector1()[0] == 1);
    assert(vector.get_vector1()[1] == 2);
    assert(vector.get_vector1()[2] == 3);
}

*/