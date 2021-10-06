#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <string>
#include "Nodo.h"
#include <fstream>

class Arbol {
private:
    void anular(Nodo*);
public:
    Arbol();
    ~Arbol();
    Nodo* root;

    bool vacia();

    std::string preOderGuardar(Nodo *);
   
    void inserta(Nodo*, Superheroes);
    void elimina(string);
    Nodo* unicoHijo(Nodo*);
    Nodo* buscarMalPadre(string);

    Nodo* extremaDerecha(Nodo*);

    void preOrder(Nodo*);
    void inOrder(Nodo*);
    void posOrder(Nodo*);
    
    void guardar();
    void cargar();

    void anular();
  
};

#endif // !ARBOL_H_INCLUDED
