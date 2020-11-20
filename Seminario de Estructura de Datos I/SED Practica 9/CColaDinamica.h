#ifndef CCOLADINAMICA_H_INCLUDED
#define CCOLADINAMICA_H_INCLUDED

#include "CLista.h"
#include "CPilaoCola.h"

class CColaDinamica : public CPilaoCola {
private:
    CLista lista;
public:
    virtual void push(float nd);
    virtual float pop();
    virtual int size();
    bool isEmpty();
    bool isFull();
    virtual void imprimir();
};

#endif // !CCOLADINAMICA_H_INCLUDED