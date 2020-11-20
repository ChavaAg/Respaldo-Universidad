#ifndef CPILAESTATICA_H_INCLUDED
#define CPILAESTATICA_H_INCLUDED

#include "CPilaoCola.h"

class CPilaEstatica :public CPilaoCola {
private:
    float pila[5];
    int iIndiceInsercion;;

public:
    CPilaEstatica();
    ~CPilaEstatica();

    virtual void push(float nd);
    virtual float pop();
    float tos();
    virtual int size();
    bool isEmpty();
    bool isFull();
    virtual void imprimir();
};


#endif // !CPILAESTATICA_H_INCLUDED
