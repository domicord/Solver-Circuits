#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QGraphicsScene>
#include <QtCore>
#include<QtGui>
#include <element.h>
#include <QGraphicsPixmapItem>
#include <string.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("Solver Circuits");
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
    connect(ui->actionAddSource,SIGNAL(triggered()),this,SLOT(newSource()));



}


void MainWindow::newResistor(){
    int n= QInputDialog::getInt(this,"Entrada","Ingrese el numero de resistencias");
    int Resistencias[n];
    for (int i=0;i<n;i++) {
      Resistencias[i]=QInputDialog::getInt(this,"Entrada","Ingrese resistencia");
      elemento= new Element(true);
      scene->addItem(elemento);
  }
    }
    //int d= QInputDialog::getInt(this,"Entrada","Ingrese resistencia");
    //QString s= QInputDialog::getText(this,"Entrada","Ingrese Nombre");

void MainWindow::newSource() {
    int n= QInputDialog::getInt(this,"Entrada","Ingrese el numero de Fuentes");
    int Fuentes[n];
    for (int i=0;i<n;i++) {
      Fuentes[i]=QInputDialog::getInt(this,"Entrada","Ingrese resistencia");
      elemento= new Element(false);
      scene->addItem(elemento);
  }
}
