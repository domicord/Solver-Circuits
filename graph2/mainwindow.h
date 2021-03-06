#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDialog>
#include <QGraphicsScene>
#include <QtCore>
#include<QtGui>
#include <element.h>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createToolBars();
    void connectActions();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Element *elemento;
public slots:
    void newResistor();
    int* DatNewResistor();
    void newSource();
    int* DatNewSource();

signals:
    void ResistorPulsado(int);
    void SourcePulsado(int);
private slots:
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
