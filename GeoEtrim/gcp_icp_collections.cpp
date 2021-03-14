#include "gcp_icp_collections.h"
#include "ui_gcp_icp_collections.h"

GCP_ICP_collections::GCP_ICP_collections(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GCP_ICP_collections)
{
    ui->setupUi(this);
}

GCP_ICP_collections::~GCP_ICP_collections()
{
    delete ui;
}
