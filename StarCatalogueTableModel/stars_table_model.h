//
// Created by lazab on 6/23/2024.
//

#ifndef FINAL_STAR_CATALOGUE_TABLEMODEL__STARS_TABLE_MODEL_H
#define FINAL_STAR_CATALOGUE_TABLEMODEL__STARS_TABLE_MODEL_H
#include "QAbstractTableModel"
#include "repository.h"

class stars_table_model : public QAbstractTableModel{
private:
    Repository<Star>& stars;
    std::vector<Star> stars1;

public:
    explicit stars_table_model(Repository<Star>& stars1, QObject* parent=nullptr):stars{stars1}, stars1{stars1.get_all()}{};

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void filtered_stars(const std::vector<Star>& _stars);

    void reset();

    void add(Star _star);

};


#endif //FINAL_STAR_CATALOGUE_TABLEMODEL__STARS_TABLE_MODEL_H
