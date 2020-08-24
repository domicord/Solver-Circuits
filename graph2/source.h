#ifndef SOURCE_H
#define SOURCE_H
#include<elemento.h>

class Source:public Elemento{
protected:
    double voltage;
public:
    Source(char*,double);
    virtual int getType()const{return 1;};
    virtual double getValue()const{return voltage;};
};

#endif // SOURCE_H
