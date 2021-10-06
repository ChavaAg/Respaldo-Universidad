#ifndef NODO_H
#define NODO_H

#include "Superheroe.h"

class Nodo {
private:
    Superheroes contenido;
    Nodo* Izda;
    Nodo* Dcha;

public:
    Nodo();

    Superheroes getContenido();
    Nodo* getIzda();
    Nodo* getDcha();

    void setContenido(Superheroes);
    void setIzda(Nodo*);
    void setDcha(Nodo*);

    int cuantosHijos();
};

#endif // NODO _H
