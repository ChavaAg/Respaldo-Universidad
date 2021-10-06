#include "Arbol.h"
#include <iostream>


using namespace std;

Arbol::Arbol() {
    root = nullptr;
}

Arbol::~Arbol() {
    anular();
}

bool Arbol::vacia() {
    return root == nullptr;
}

string Arbol::preOderGuardar(Nodo* act) {
    if(act == nullptr) {
        return "";
    }

    string texto = act->getContenido().toString() + "*";
    texto += preOderGuardar(act->getIzda());
    texto += preOderGuardar(act->getDcha());
    
    return texto;
}

void Arbol::preOrder(Nodo* act) {
    if(act == nullptr) {
        return;
    }

    cout<< act->getContenido().toString()<<endl;
    preOrder(act->getIzda());
    preOrder(act->getDcha());
}

void Arbol::inOrder(Nodo* act) {
    if(act == nullptr) {
        return;
    }

    inOrder(act->getIzda());
    cout << act->getContenido().toString() << endl;
    inOrder(act->getDcha());
}

void Arbol::posOrder(Nodo* act) {
    if(act == nullptr) {
        return;
    }

    posOrder(act->getIzda());
    posOrder(act->getDcha());
    cout << act->getContenido().toString() << endl;
}

void Arbol::inserta(Nodo* act, Superheroes d) {

    Nodo* aux = act;

    if(root == nullptr) {
        Nodo* tmp = new Nodo;
        tmp->setContenido(d);
        root = tmp;
    }
    else {
        if(d.getNombre() < aux->getContenido().getNombre()) {
            if(aux->getIzda() != nullptr)
                inserta(aux->getIzda(), d);
            else {
                Nodo* tmp = new Nodo;
                tmp->setContenido(d);
                aux->setIzda(tmp);
            }
        }
        else {
            if(aux->getDcha() != nullptr)
                inserta(aux->getDcha(), d);
            else {
                Nodo* tmp = new Nodo;
                tmp->setContenido(d);
                aux->setDcha(tmp);
            }
        }
    }

}

void Arbol::elimina(string elemento) {
    Nodo* unicHijo;
    Nodo* hijoIzda;
    Nodo* hijoDcha;
    Nodo* ExtremaDerecha;
    int cuantosHijos;


    if(vacia()) {
        cout << "No se puede eliminar ya que el arbol esta vacio" << endl;
        return;
    }

    if(root->getContenido() == elemento) {
        cuantosHijos = root->cuantosHijos();
        switch(cuantosHijos) {
        case 0:
            delete root;
            root = nullptr;
            break;
        case 1:
            unicHijo = unicoHijo(root);
            delete root;
            root = unicHijo;
            break;
        case 2:
            hijoDcha = root->getDcha();
            hijoIzda = root->getIzda();

            delete root;

            root = hijoIzda;

            ExtremaDerecha = extremaDerecha(hijoIzda);
            ExtremaDerecha->setDcha(hijoDcha);
            break;
        default:
            break;
        }
        return;
    }

    Nodo* malpadre = buscarMalPadre(elemento);

    if(malpadre == nullptr) {
        return;
    }

    if(elemento < malpadre->getContenido().getNombre()) {
        cuantosHijos = malpadre->getIzda()->cuantosHijos();
        switch(cuantosHijos) {
        case 0:
            delete malpadre->getIzda();
            malpadre->setIzda(nullptr);
            break;
        case 1:
            unicHijo = unicoHijo(malpadre->getIzda());
            delete malpadre->getIzda();
            malpadre->setIzda(unicHijo);
            break;
        case 2:
            hijoDcha = malpadre->getIzda()->getDcha();
            hijoIzda = malpadre->getIzda()->getIzda();

            delete malpadre->getIzda();

            malpadre->setIzda(hijoIzda);

            ExtremaDerecha = extremaDerecha(hijoIzda);
            ExtremaDerecha->setDcha(hijoDcha);
            break;
        default:
            break;
        }
    }
    else {
        cuantosHijos = malpadre->getDcha()->cuantosHijos();
        switch(cuantosHijos) {
        case 0:
            delete malpadre->getDcha();
            malpadre->setDcha(nullptr);
            break;
        case 1:
            unicHijo = unicoHijo(malpadre->getDcha());
            delete malpadre->getDcha();
            malpadre->setDcha(unicHijo);
            break;
        case 2:
            hijoDcha = malpadre->getDcha()->getDcha();
            hijoIzda = malpadre->getDcha()->getIzda();

            delete malpadre->getDcha();

            malpadre->setDcha(hijoIzda);

            ExtremaDerecha = extremaDerecha(hijoIzda);
            ExtremaDerecha->setDcha(hijoDcha);
            break;
        default:
            break;
        }
    }
}

Nodo* Arbol::unicoHijo(Nodo* puntero) {

    if(puntero->cuantosHijos() == 1) {

        if(puntero->getIzda() != nullptr) {
            return puntero->getIzda();
        }
        else if(puntero->getDcha() != nullptr) {
            return puntero->getDcha();
        }

    }

    return nullptr;
}

Nodo* Arbol::extremaDerecha(Nodo* puntero) {
    Nodo* aux = puntero;


    while(true) {
        if(aux->getDcha() == nullptr) {
            return aux;
        }
        else {
            aux = aux->getDcha();
        }
    }

    return nullptr;
}

Nodo* Arbol::buscarMalPadre(string dato) {
    Nodo* aux = root;


    while(true) {

        if(dato < aux->getContenido().getNombre()) {

            if(aux->getIzda() == nullptr) {
                
                return nullptr;
            }

            if(aux->getIzda()->getContenido() == dato) {
                return aux;
            }
            else {
                aux = aux->getIzda();
            }
        }
        else {
            if(aux->getDcha() == nullptr) {
                return nullptr;
            }
            if(aux->getDcha()->getContenido() == dato) {
                return aux;
            }
            else {
                aux = aux->getDcha();
            }
        }

    }


    return nullptr;
}


void Arbol::guardar() {
    ofstream Salida;

    Salida.open("file01.txt", ios::out);

    if(Salida.fail()) {
        cout << "El archivo no se pudo abrir";
        exit(1);
    }

    Salida << preOderGuardar(root);

    Salida.close();
}

void Arbol::cargar() {
   ifstream entrada;
	string ingresar;
	Superheroes copia;

	entrada.open("file01.txt", ios::in);

    if(entrada.fail()) {
        cout << "El archivo no se pudo abrir";
        exit(1);
    }

	while(true) {
		getline(entrada,ingresar,'|');
		copia.setNombre(ingresar);
		getline(entrada, ingresar, '|');
		copia.setPoder(ingresar);
		getline(entrada, ingresar, '*');
		copia.setDebilidad(ingresar);

		if(entrada.eof()) {
			break;
		}
		
		inserta(root, copia);
	}
	entrada.close();
}

void Arbol::anular() {
    anular(root);
    root = nullptr;
}

void Arbol::anular(Nodo* dato) {
    if(dato == nullptr) {
        return;
    }
    anular(dato->getIzda());
    anular(dato->getDcha());
    delete dato;
}
