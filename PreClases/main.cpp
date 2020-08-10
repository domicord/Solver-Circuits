#include <iostream>
#include<string.h>
using namespace std;


//Clase base


class Element{
protected:
    char* name;
public:
    Element(char* );
    const char* getName()const{return name;};
    virtual double getValue() const=0;
    virtual int getType() const=0;
};


Element::Element(char* ename){
    name= new char[strlen(ename)+1];
    strcpy(name,ename);
};

//Clases derivadas

class Resistor:public Element{
protected:
    char* name;
    double resistance;
public:
    Resistor(char*,double);
    virtual int getType()const{return 0;};
    virtual double getValue()const{return resistance;};
};
Resistor::Resistor(char* rname,double R):Element(rname){
    resistance=R;
};


class Source:public Element{
protected:
    double voltage;
public:
    Source(char*,double);
    virtual int getType()const{return 1;};
    virtual double getValue()const{return voltage;};
};
Source::Source(char* sname,double S):Element(sname){
    voltage=S;
};

//IDK

class ArrayElements{
protected:
    Element** Array;
    int size;
    int cant;
public:
    ArrayElements(int);
    void addElement(int,char*);
    double getCurrent();
    double getVoltage(int);

};
//Costructor
ArrayElements::ArrayElements(int n){
    size=n;
    cant=0;
    Array=new Element*[n];
}



void ArrayElements::addElement(int tipo,char* nelement){
    double value;
    if (cant<size) {
        switch (tipo) {
        case 1:
            cout<<"Ingrese el valor de la resistencia en ohmios:"<<endl;
            cin>>value;
            Array[cant]=new Resistor(nelement,value);
            break;
        case 2:
            cout<<"Ingrese el valor del voltaje de la fuente en voltios:"<<endl;
            cin>>value;
            Array[cant]=new Source(nelement,value);
            break;
        }
       cant++;
    }

   else cout<<"F"<<endl;

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

//En teoria n representa la posicion del elemento en el arreglo
double ArrayElements::getVoltage(int n){
    int ArrayVoltages[size];

    for (int i=0;i<3;i++) {
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
