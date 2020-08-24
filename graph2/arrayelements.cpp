#include "arrayelements.h"
#include <elemento.h>
#include<resistor.h>
#include<source.h>




ArrayElements::ArrayElements(int n){
    size=n;
    cant=0;
    Array=new Elemento*[n];
}


void ArrayElements::addElement(int* resistor,int* sources,int r,int s){
    int size=s+r;
    char nelement[9]={"sinmobre"};

    for (int i=0;i<r;i++) {
            Array[i]=new Resistor(nelement,resistor[i]);}
    for (int j=r;j<size;j++) {
        Array[j]=new Source(nelement,sources[j-r]);}
};



double ArrayElements::getCurrent(){
    double sumaResistor=0;
    double sumaSource=0;
    double Current;
    for (int i=0;i<size;i++) {
        switch (Array[i]->getType()) {
        case 0:
            sumaResistor+=Array[i]->getValue();
            break;
        case 1:
            sumaSource+=Array[i]->getValue();
            break;
        }
    }
    Current=sumaSource/sumaResistor;
    return Current;
};


double ArrayElements::getVoltage(int n){
    int ArrayVoltages[size];

    for (int i=0;i<size;i++) {
        switch (Array[i]->getType()) {
        case 0:
            ArrayVoltages[i]=Array[i]->getValue()*getCurrent();
            break;
        case 1:
            ArrayVoltages[i]=Array[i]->getValue();
            break;
        }
    }
    return ArrayVoltages[n];
};
