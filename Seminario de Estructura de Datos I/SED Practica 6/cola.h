#pragma once
#include "lista.h"

class CCola {
private:
    CLista lista;
public:   
      void push(float nd);
      float pop();
      int size();
      bool isEmpty();
      bool isFull();
      void imprimir();
};