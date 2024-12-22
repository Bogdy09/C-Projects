#include <iostream>
#include <QApplication>
#include "gui.h"
#include <fstream>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    repository repo;
    gui gui(repo);
    gui.populate();
    gui.show();
    std::cout << "Hello, World!" << std::endl;
    return a.exec();
}
