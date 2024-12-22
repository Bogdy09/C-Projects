#include <iostream>
#include "dynamic_array.h"
#include "domain.h"
#include "services.h"
#include "repository.h"
#include "UI.h"
#include <assert.h>

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

