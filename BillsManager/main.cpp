#include <QApplication>
#include <QMainWindow>
#include "repository.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto repo=new repository;
    GUI gui(*repo);
    gui.show();
    return a.exec();
}
