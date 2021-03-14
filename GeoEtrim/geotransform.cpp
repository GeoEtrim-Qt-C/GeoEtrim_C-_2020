#include "geotransform.h"
#include "ui_geotransform.h"

GeoTransform::GeoTransform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GeoTransform)
{
    ui->setupUi(this);
}

GeoTransform::~GeoTransform()
{
    delete ui;
}
