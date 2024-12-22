//
// Created by lazab on 6/23/2024.
//

#include "stars_table_model.h"
#include <iostream>
using namespace std;

int stars_table_model::rowCount(const QModelIndex &parent) const {
    return stars1.size();
}

int stars_table_model::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant stars_table_model::data(const QModelIndex &index, int role) const {
    int row=index.row();
    int column=index.column();
    auto star=stars1[row];
    if(role==Qt::DisplayRole){
        switch(column){
            case 0:
                return QString::fromStdString(star.name);
            case 1:
                return QString::fromStdString((star.constelation));
            case 2:
                return QString::number(star.ra);
            case 3:
                return QString::number(star.dec);
            case 4:
                return QString::number(star.diameter);
            default:
                break;
        }
    }
    return QVariant();
}

void stars_table_model::filtered_stars(const vector<Star> &_stars) {
    beginResetModel();
    stars1=_stars;
    endResetModel();
}

void stars_table_model::reset() {
    beginResetModel();
    stars1=this->stars.get_all();
    endResetModel();
}

void stars_table_model::add(Star _star) {
    beginResetModel();
    stars1.push_back(_star);
    endResetModel();
}
