#include <iostream>
#include <QApplication>
#include "domain.h"
#include "repository.h"
#include "gui.h"
#include "stars_table_model.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    Repository<Astronomer> astronomers("astronomers.txt");
    Repository<Star> stars("stars.txt");
    auto* model=new stars_table_model(stars);
    for(auto each:astronomers.get_all()){
        auto* window=new GUI(astronomers, stars, each.name, model);
        window->show();
    }
    std::cout << "Hello, World!" << std::endl;
    return a.exec();
}
