#include "Lista.h"
#include "listexception.h"

Lista::Lista() : inicio(nullptr) {}

bool Lista::vacia() {
	return inicio == nullptr;
}

Lista::~Lista() {
	borradorHD();
}

void Lista::inserta(Nodo* p, Cancion& j) {
	if (p != nullptr && !isValidPos(p)) {
		throw ListException("Posicion invalida en la insercion");
	}

	Nodo* aux = new Nodo(j);

	if (aux == nullptr) {
		throw ListException("No hay mas memoria");
	}

	if (p == nullptr) {
		aux->setSig(inicio);
		if (inicio != nullptr) {
			inicio->setAnt(aux);
		}
		inicio = aux;
	} else {
		aux->setAnt(p);
		aux->setSig(p->getSig());

		if (p->getSig()!=nullptr) {
			p->getSig()->setAnt(aux);
		}
		p->setSig(aux);
	}
}

void Lista::elimina(Nodo* p) {
	if (!isValidPos(p)) {
		throw ListException("Posicion invalida en la insercion");
	}

	if (p->getAnt() != nullptr) {
		p->getAnt()->setSig(p->getSig());
	}

	if (p->getSig() != nullptr) {
		p->getSig()->setAnt(p->getAnt());
	}

	if (p == inicio) {
		inicio = inicio->getSig();
	}

	delete p;
}

Nodo* Lista::getPrimero() {
	return inicio;
}

Nodo* Lista::getUltimo() {
	if (vacia()) {
		return nullptr;
	}

	Nodo* aux = inicio;

	while (aux->getSig() != nullptr) {
		aux = aux->getSig();
	}

	return aux;
}

Nodo* Lista::getAntes(Nodo* p) {
	if (!isValidPos(p)) {
		return nullptr;
	}
	
	return p->getAnt();
}

Nodo* Lista::getDespues(Nodo* p) {
	if (!isValidPos(p)) {
		return nullptr;
	}
	return p->getSig();
}


Nodo* Lista::busquedaCancion(string e) {
	Nodo* aux = inicio;

	while (aux != nullptr && aux->getContenido() != e) {
		aux = aux->getSig();
	}

	return aux;
}

Nodo* Lista::busquedaInterprete(string e) {
	Nodo* aux = inicio;

	while (aux != nullptr && aux->getContenido().getInterprete() != e) {
		aux = aux->getSig();
	}

	return aux;
}

Cancion Lista::recupera(Nodo* e) {
	if (!isValidPos(e)) {
		throw ListException("Posicion invalida");
	}
	return e->getContenido();
}

string Lista::toString() {
	int cont = 1;
	Nodo* aux = inicio;
	string cadena;

	cout << "Lista de canciones en la disquera" << endl << endl;
	cout << "||Nombre de la cancion||Nombre del interprete||Nombre del autor||Ranking||" << endl;

	while (aux != nullptr) {
		cadena += to_string(cont++);
		cadena += aux->getContenido().toString() + "\n";
		aux = aux->getSig();
	}

	return cadena;
}

void Lista::borradorHD() {
	Nodo* aux;

	while (inicio != nullptr) {
		aux = inicio;
		inicio = inicio->getSig();

		delete aux;
	}

}

bool Lista::isValidPos(Nodo* p) {
	Nodo* aux(inicio);

	while (aux != nullptr) {
		if (aux == p) {
			return true;
		}
		aux = aux->getSig();
	}
	return false;
}