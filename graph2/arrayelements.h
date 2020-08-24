#ifndef ARRAYELEMENTS_H
#define ARRAYELEMENTS_H
#include <elemento.h>
#include<resistor.h>
#include<source.h>

class ArrayElements{
protected:
    Elemento** Array;
    int size;
    int cant;
public:
    ArrayElements(int);
    void addElement(int*,int*,int,int);
    double getCurrent();
    double getVoltage(int);

};


#endif // ARRAYELEMENTS_H
