//
// Created by lazab on 6/24/2024.
//

#ifndef FINAL_QUIZ_OBSERVER_PARTICIPANTSGUI_H
#define FINAL_QUIZ_OBSERVER_PARTICIPANTSGUI_H

#include <QWidget>
#include "repository.h"


QT_BEGIN_NAMESPACE
namespace Ui { class participantsgui; }
QT_END_NAMESPACE

class participantsgui : public QWidget, public Observer {
Q_OBJECT

public:
    explicit participantsgui(Repository *repo, std::string name, QWidget *parent = nullptr);

    ~participantsgui() override;

    void populate();

    void update() override;

private:
    Ui::participantsgui *ui;
    Repository *repo;
    std::string name;
};


#endif //FINAL_QUIZ_OBSERVER_PARTICIPANTSGUI_H
