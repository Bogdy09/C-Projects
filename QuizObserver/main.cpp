#include <iostream>
#include <QApplication>
#include "repository.h"
#include "gui.h"
#include "participantsgui.h"
using namespace std;

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    auto repository= new Repository();
    auto* window=new gui(repository);
    window->show();
    for(const Participant& participant:repository->get_participants()){
        auto* window1=new participantsgui(repository, participant.name);
        repository->register_observer(window1);
        window1->show();
    }
    std::cout << "Hello, World!" << std::endl;
    return a.exec();
}
