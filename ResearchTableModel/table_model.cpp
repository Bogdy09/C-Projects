//
// Created by lazab on 6/25/2024.
//

#include "table_model.h"
#include "iostream"
using namespace std;

int table_model::rowCount(const QModelIndex &parent) const {
    return this->i.size();
}

int table_model::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant table_model::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    auto cur = this->i[row];
    if (role == Qt::DisplayRole) {
        switch (column) {
            case 0:
                return QString::fromStdString(cur.title);
            case 1:
                return QString::fromStdString(cur.status);
            case 2:
                return QString::fromStdString(cur.creator);
            case 3:
                return QString::number(cur.duration);
            default:
                break;
        }
    }
    return {};
}

void table_model::sort(std::vector<Idea> i1) {
    beginResetModel();
    this->i=i1;
    endResetModel();
}

//

Qt::ItemFlags table_model::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

bool table_model::setData(const QModelIndex &index, const QVariant &value, int role) {
    return QAbstractItemModel::setData(index, value, role);
}

