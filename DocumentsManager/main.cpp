#include <iostream>
#include <QApplication>
#include "repository.h"
#include "gui.h"
int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    std::cout << "Hello, World!" << std::endl;
    repository repo;
    gui gui(repo);
    gui.populate();
    gui.show();
    return a.exec();
}
