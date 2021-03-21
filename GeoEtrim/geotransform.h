#ifndef GEOTRANSFORM_H
#define GEOTRANSFORM_H

#include "txtread.h"

#include <QMainWindow>

namespace Ui {
class GeoTransform;
}

class GeoTransform : public QMainWindow
{
    Q_OBJECT

public:
    explicit GeoTransform(QWidget *parent = nullptr);
    ~GeoTransform();

private:
    Ui::GeoTransform *ui;
    void ListFill();

    txtRead txt;

    QList<QStringList>list;

};

#endif // GEOTRANSFORM_H
