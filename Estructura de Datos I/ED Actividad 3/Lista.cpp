#include <iostream>
#include <string>
#include <string.h>
#include "listexception.h"
#include "Lista.h"

using namespace std;


Lista::Lista() : cantidad(-1){}

bool Lista::vacia() {
	bool validation;

	if (cantidad == -1) {
		validation = true;
		return validation;
	}
	else {
		validation = false;
		return validation;
	}
}
bool Lista::llena() {
	bool validation;

	if (cantidad < 49 ) {
		validation = false;
		return validation;
	}else {
		validation = true;
		return validation;
	}
}
void Lista::inserta(int pos, Datos d) {
	
	for (int gps = cantidad; gps > pos; gps--) {
		MyData[gps + 1] = MyData[gps];
	}

	MyData[pos + 1] = d;
	cantidad++;
}
void Lista::elimina(int pos) {

	for (int gps = pos; gps < cantidad; gps++){
		MyData[gps] = MyData[gps + 1];
	}
	cantidad--;
}
Datos Lista::recupera(int pos) {
	if (!isValidacion(pos)) {
		throw ListException("La posicion que marcaste es invalida");
	}
	return MyData[pos];
}
int Lista::primero() {
	if (vacia()) {
		return -1;
	}
	return 0;
}
int Lista::ultimo() {
	return cantidad;
}
int Lista::anterior(int a) {
	if (ultimo()==a|| !isValidacion(a)) {
		return -1;
	}
	return a - 1;
}
int Lista::siguiente(int l) {
	if (llena() || !isValidacion(l)){
		return -1;
	}
	return l+1;
}
void Lista::anula() {
	cantidad = -1;
}
void Lista::imprime() {
	cout << "N de lista || Nombre de la Cancion || Nombre del Autor || Nombre del interprete || Ranking"<<endl;

	for (int i = 0; i <= cantidad; i++){
		cout << i+1  << "° " << MyData[i].toString() << endl;
	}

}
int Lista::getCantidad(){
	return cantidad;
}
bool Lista::isValidacion(int v) {

	if (v >= 0 && v <= cantidad+1){
		return false;
	}
	
	return true;
}
