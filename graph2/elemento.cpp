#include "elemento.h"

#include <iostream>
#include<string.h>
using namespace std;




Elemento::Elemento(char* ename){
    name= new char[strlen(ename)+1];
    strcpy(name,ename);
};


