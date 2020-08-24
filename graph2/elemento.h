#ifndef ELEMENTO_H
#define ELEMENTO_H



//Clase base


class Elemento{
protected:
    char* name;
public:
    Elemento(char* );
    const char* getName()const{return name;};
    virtual double getValue() const=0;
    virtual int getType() const=0;
};

//Clases derivadas





#endif // ELEMENTO_H
