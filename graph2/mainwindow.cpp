#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QGraphicsScene>
#include <QtCore>
#include<QtGui>
#include <element.h>
#include <QGraphicsPixmapItem>
#include <string.h>
#include <elemento.h>
#include <arrayelements.h>
#include<resistor.h>
#include<source.h>
#include<QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("");
    ui->label_2->setText("");
    ui->label_3->setText("Voltaje");
    ui->label_4->setText("Corriente");
    createToolBars();
    scene= new QGraphicsScene(this);
    ui->Scene->setScene(scene);
    connectActions();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createToolBars()
{

    ui->menubar->addAction(ui->actionAddResistor);
    ui->menubar->addAction(ui->actionAddSource);

}

void MainWindow::connectActions(){
    connect(ui->actionAddResistor,SIGNAL(triggered()),this,SLOT(newResistor()));
    connect(ui->actionAddResistor,SIGNAL(triggered()),this,SLOT(DatNewResistor()));
    connect(ui->actionAddSource,SIGNAL(triggered()),this,SLOT(newSource()));
    connect(ui->actionAddSource,SIGNAL(triggered()),this,SLOT(DatNewSource()));
}


void MainWindow::newResistor(){

}
void MainWindow::newSource(){
 ;
}

int* MainWindow::DatNewResistor(){
    int n= QInputDialog::getInt(this,"Entrada","Ingrese el numero de resistencias");
    int Resistencias[n];
    for (int i=0;i<n;i++) {
      Resistencias[i]=QInputDialog::getInt(this,"Entrada","Ingrese resistencia");
      elemento= new Element(true);
      scene->addItem(elemento);

  }
    return Resistencias;
    }

int* MainWindow::DatNewSource() {
    int n= QInputDialog::getInt(this,"Entrada","Ingrese el numero de Fuentes");
    int Fuentes[n];
    for (int i=0;i<n;i++) {
      Fuentes[i]=QInputDialog::getInt(this,"Entrada","Ingrese el voltaje");
      elemento= new Element(false);
      scene->addItem(elemento);

  }
    return Fuentes;
}

void MainWindow::resutado()
{
    ArrayElements arreglo(5);
    int* ares=DatNewResistor();
    int* asou=DatNewSource();
    arreglo.addElement(ares,asou,3,2);
    ui->label->setText(QString::number(arreglo.getCurrent()));
    ui->label->setText("F");

}


void MainWindow::on_pushButton_clicked()
{
    ArrayElements arreglo(5);
    int ares[3]={2,2,2};
    int asou[2]={3,3};
    arreglo.addElement(ares,asou,3,2);
    double n=arreglo.getCurrent();
    double m=arreglo.getVoltage(3);
    ui->label->setText(QString::number(n));
    ui->label_2->setText(QString::number(m));


}
