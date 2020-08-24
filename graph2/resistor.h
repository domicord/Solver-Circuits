#ifndef RESISTOR_H
#define RESISTOR_H
#include <elemento.h>

class Resistor:public Elemento{
protected:
    char* name;
    double resistance;
public:
    Resistor(char*,double);
    virtual int getType()const{return 0;};
    virtual double getValue()const{return resistance;};
};


#endif // RESISTOR_H
