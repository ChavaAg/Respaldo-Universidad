#pragma once
#include "lista.h"

class CPila
{
private:
    CLista lista;
public:
    void push(float nd);
    float pop();
    float tos();
    int size();
    bool isEmpty();
    bool isFull();
    void imprimir();
};