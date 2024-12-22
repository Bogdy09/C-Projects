//
// Created by lazab on 6/25/2024.
//

#ifndef FINAL_RESEARCH_TABLE_MODEL_TABLE_MODEL_H
#define FINAL_RESEARCH_TABLE_MODEL_TABLE_MODEL_H
#include <QAbstractTableModel>
#include "repository.h"
#include "domain.h"

class table_model: public QAbstractTableModel{
private:
    Repository &repo;
    std::vector<Idea> i;

public:
    explicit table_model(Repository &repo, QObject* parent=nullptr):repo{repo}, i{repo.get_ideas()}{};

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void sort(std::vector<Idea> i1);

    void add(Idea i);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
};


#endif //FINAL_RESEARCH_TABLE_MODEL_TABLE_MODEL_H
