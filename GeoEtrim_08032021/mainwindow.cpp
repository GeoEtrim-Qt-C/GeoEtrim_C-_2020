#include "mainwindow.h"
#include "canvasnew.h"
#include "ui_mainwindow.h"
#include "canvasnew.h"
#include <QMessageBox>
#include <QWidget>
#include <QStandardItemModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    uigeotransform = new GeoTransform();
    gcpicpform = new GCP_ICP_collections();

}



void MainWindow::resizeEvent(QResizeEvent*)
{
  ui->label_img->setFixedHeight(this->height()-50);
  int sol = ui->label_img->logicalDpiY()+180;
  ui->label_img->setFixedWidth(this->width()-sol);
  ui->treeView->setFixedHeight(this->height()-50);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setnodeadd(QString file_name)
{


    QStandardItemModel* model = new QStandardItemModel();

    QWidget ww;

    QStandardItem* item0 = new QStandardItem(QIcon(ww.style()->standardIcon(QStyle::SP_FileIcon)), file_name);
    /*
    QStandardItem* item1 = new QStandardItem(QIcon("movietape_mini.png"), "2 second item");
    QStandardItem* item3 = new QStandardItem(QIcon("movietape_mini.png"), "3 third item");
    QStandardItem* item4 = new QStandardItem("4 forth item");
    */

    model->appendRow(item0);
    /*
    item0->appendRow(item3);
    item0->appendRow(item4);
    model->appendRow(item1);
    */

    ui->treeView->setModel(model);

}

void MainWindow::on_action_new_triggered()
{

    canvas.show();

}


void MainWindow::on_actionOpen_Project_triggered()
{
setnodeadd("yunus");
}

void MainWindow::on_actionGeoTransform_triggered()
{
    uigeotransform->show();
}

void MainWindow::on_actionGCP_ICP_Collection_triggered()
{
    gcpicpform->show();
}
