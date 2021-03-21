#include "geotransform.h"
#include "ui_geotransform.h"

GeoTransform::GeoTransform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GeoTransform)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(11);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setStyleSheet("QTableView {selection-background-color: blue;}");
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Point ID"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Point Type"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Image Col"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Image Row"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Ground X"));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Ground Y"));
    ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("Ground Z"));
    ui->tableWidget->setHorizontalHeaderItem(7, new QTableWidgetItem("Outliner"));
    ui->tableWidget->setHorizontalHeaderItem(8, new QTableWidgetItem("+/- Vr"));
    ui->tableWidget->setHorizontalHeaderItem(9, new QTableWidgetItem("+/- Vc"));
    ui->tableWidget->setHorizontalHeaderItem(10, new QTableWidgetItem("veri11"));
    ui->tableWidget->setColumnWidth(0,100);
    ui->tableWidget->setColumnWidth(1,100);
    ui->tableWidget->setColumnWidth(2,100);
    ui->tableWidget->setColumnWidth(3,100);
    ui->tableWidget->setColumnWidth(4,100);
    ui->tableWidget->setColumnWidth(5,100);
    ui->tableWidget->setColumnWidth(6,100);
    ui->tableWidget->setColumnWidth(7,100);
    ui->tableWidget->setColumnWidth(8,100);
    ui->tableWidget->setColumnWidth(9,100);
    ui->tableWidget->setColumnWidth(10,100);

    ListFill();
}

void GeoTransform::ListFill()
{
    list =txt.Read("C:/Users/Casper/Desktop/GeoEtrim_C-_2020-master/Gokturk_2_Karaman_L1_0.txt");

    int columnS = 0;
    int lineS = list.count();
    ui->tableWidget->setRowCount(lineS);

    for(columnS =0;columnS<lineS;columnS++)
    {
        ui->tableWidget->setItem(columnS, 0,new QTableWidgetItem(list[columnS][0]));
        ui->tableWidget->setItem(columnS, 1,new QTableWidgetItem(list[columnS][1]));
        ui->tableWidget->setItem(columnS, 2,new QTableWidgetItem(list[columnS][2]));
        ui->tableWidget->setItem(columnS, 3,new QTableWidgetItem(list[columnS][3]));
        ui->tableWidget->setItem(columnS, 4,new QTableWidgetItem(list[columnS][4]));
        ui->tableWidget->setItem(columnS, 5,new QTableWidgetItem(list[columnS][5]));
        ui->tableWidget->setItem(columnS, 6,new QTableWidgetItem(list[columnS][6]));
        ui->tableWidget->setItem(columnS, 7,new QTableWidgetItem(list[columnS][7]));
        ui->tableWidget->setItem(columnS, 8,new QTableWidgetItem(list[columnS][8]));
        ui->tableWidget->setItem(columnS, 9,new QTableWidgetItem(list[columnS][9]));
        ui->tableWidget->setItem(columnS, 10,new QTableWidgetItem(list[columnS][10]));

        ui->tableWidget->item(columnS,0)->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->item(columnS,1)->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->item(columnS,2)->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->item(columnS,3)->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->item(columnS,4)->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->item(columnS,5)->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->item(columnS,6)->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->item(columnS,7)->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->item(columnS,8)->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->item(columnS,9)->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidget->item(columnS,10)->setTextAlignment(Qt::AlignHCenter);
    }
}

GeoTransform::~GeoTransform()
{
    delete ui;
}
