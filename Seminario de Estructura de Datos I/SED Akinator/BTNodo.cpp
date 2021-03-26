#include "BTNodo.h"

BTNodo::BTNodo() {
	pIzda = nullptr;
	pDcha = nullptr;
}

void BTNodo::insertar(string szDato,string szPregunta) {
	this->pIzda = new BTNodo;
	this->pDcha = new BTNodo;

	this->pIzda->szOracion = szDato;
	this->pDcha->szOracion = this->szOracion;

	this->szOracion = szPregunta;
}

BTNodo* BTNodo::getIzda() {
	return pIzda;
}

BTNodo* BTNodo::getDcha() {
	return pDcha;
}

string BTNodo::preOrdenGuardar(BTNodo* pActual) {
	if (pActual == nullptr) {
		return "";
	}
	//Se salva el padre
	string szGuardarArbol = pActual->szOracion + "\n";

	if (pActual->pIzda!=nullptr) {
		szGuardarArbol += "1\n";
	} else {
		szGuardarArbol += "0\n";
	}
	if (pActual->pDcha != nullptr) {
		szGuardarArbol += "1\n";
	} else {
		szGuardarArbol += "0\n";
	}

	//Se salva el izquierdo
	szGuardarArbol += preOrdenGuardar(pActual->getIzda());
	//Por ultimo el hijo derecho	
	szGuardarArbol += preOrdenGuardar(pActual->getDcha());

	return szGuardarArbol;
}

string* BTNodo::ingresarArbol(string* pIndice) {
	// criterio de paro
	if (this == nullptr) {
		return pIndice;
	}

	//Inserta la pregunta y se incremenrta el apuntador
	this->szOracion = *pIndice++;
	
	// Se evalua la condicion y si entra crea un nuevo nodo
	//Aunque no entre se incrementa el apuntador
	if (*pIndice++ =="1") {
		this->pIzda = new BTNodo;			
	}

	// Se evalua la condicion y si entra crea un nuevo nodo
	//Aunque no entre se incrementa el apuntador
	if (*pIndice++ == "1") {
		this->pDcha = new BTNodo;
	}
	
	/* Se manda hacer lo mismo pero reorna lo que vale el apuntador para no 
	perder la informacion que se esta insertando*/
	pIndice = this->pIzda->ingresarArbol(pIndice);
	pIndice = this->pDcha->ingresarArbol(pIndice);

	return pIndice;
}
