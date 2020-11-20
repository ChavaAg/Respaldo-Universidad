#ifndef CPILADINAMICA_H_INCLUDED
#define CPILADINAMICA_H_INCLUDED

#include "CLista.h"
#include "CPilaoCola.h"

class CPilaDinamica : public CPilaoCola {
private:
    CLista lista;
public:
    virtual void push(float nd);
    virtual float pop();
    float tos();
    virtual int size();
    bool isEmpty();
    bool isFull();
    virtual void imprimir();
};

#endif // !CPILADINAMICA_H_INCLUDED