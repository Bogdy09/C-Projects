#include <iostream>
#include <QApplication>
#include "repository.h"
#include "table_model.h"
#include "gui.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    Repository repo;
    auto *model=new table_model(repo);
    for(const auto& each:repo.get_researchers()){
        auto *window=new gui(repo, model, each.name, each.position);
        window->show();
    }
    std::cout << "Hello, World!" << std::endl;
    return a.exec();
}
