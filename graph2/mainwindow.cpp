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
    connect(ui->actionAddResistor,SIGNAL(triggered()),this,SLOT(count()));
    //connect(ui->actionAddResistor,SIGNAL(triggered()),this,SLOT(DatNewResistor()));
    connect(ui->actionAddSource,SIGNAL(triggered()),this,SLOT(newSource()));
    connect(ui->actionAddSource,SIGNAL(triggered()),this,SLOT(count()));
    //connect(ui->actionAddSource,SIGNAL(triggered()),this,SLOT(DatNewSource()));

}

int contador1=0;
void MainWindow::newResistor(){
    elemento= new Element(true);
    scene->addItem(elemento);
     ++contador1;

}

int contador=0;
void MainWindow::newSource(){
    elemento= new Element(false);
    scene->addItem(elemento);
    ++contador;

}
int* Resistencias;
int* MainWindow::DatNewResistor(){
    Resistencias= new int[contador1];
    for (int i=0;i<contador1;i++) {
      Resistencias[i]=QInputDialog::getInt(this,"Entrada","Ingrese resistencia");


  }
  return Resistencias;
    }
int* Fuentes;
int* MainWindow::DatNewSource() {
     Fuentes= new int[contador];
    for (int i=0;i<contador;i++) {
      Fuentes[i]=QInputDialog::getInt(this,"Entrada","Ingrese el voltaje");


  }
    return Fuentes;
}



void MainWindow::on_pushButton_clicked()
{

    ArrayElements arreglo(contador+contador1);
    int* a= DatNewSource();
    int* b= DatNewResistor();
    arreglo.addElement(b,a,contador1,contador);
    double n=arreglo.getCurrent();
    double m=arreglo.getVoltage(0);
    ui->label->setText(QString::number(n));
    ui->label_2->setText(QString::number(m));


}
