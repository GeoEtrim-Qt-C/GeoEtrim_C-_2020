#include "canvasnew.h"
#include "ui_canvasnew.h"
#include "QtXml/qxml.h"
#include "QtXml/qdom.h"
#include "QtXml/QDomDocument"
#include "QtCore"
#include "QTextStream"
#include "QFileDialog"
#include "QMessageBox"
#include "mainwindow.h"
#include "QObject"

canvasnew::canvasnew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::canvasnew)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Location");
    ui->lineEdit_2->setPlaceholderText("Name");
    ui->textEdit->setPlaceholderText("Information");



}

canvasnew::~canvasnew()
{
    delete ui;
}

void canvasnew::on_pushButton_2_clicked()
{
    QDomDocument document;

       // Making the root element
        QString filename = ui->lineEdit_2->text();
       QDomElement root = document.createElement("Project");

       // Adding the root element to the docuemnt
       root.setAttribute("Project_name",filename);
       root.setAttribute("Information",ui->textEdit->toPlainText());
       document.appendChild(root);


       // Writing to a file
       QString loc = ui->lineEdit->text();
       QFile file(loc+"/"+filename+".gpr");
       if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           qDebug() << "Open the file for writing failed";
           QMessageBox qmes;
           qmes.setText("olmadı");
           qmes.exec();
       }
       else
       {
           QTextStream stream(&file);
           stream << document.toString();
           file.close();
           qDebug() << "Writing is done";
           this->close();
       }
}


void canvasnew::on_pushButton_clicked()
{
   QString filename  = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                "/home",
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);
    ui->lineEdit->setText(filename);

}
