#include "Producto.h"
#include <iostream>
#include <string>

using namespace std;


	//Getters
string Producto::getCodigo() {
	return codigo;
}
string Producto::getNombre() {
	return nombre;
}
float Producto::getPeso() {
	return peso;
}
Fecha Producto::getEntrada() {
	return entrada;
}
float Producto::getMayoreo() {
	return precioMayoreo;
}
float Producto::getMenudeo() {
	return precioMenudeo;
}
int Producto::getExistencia() {
	return existencia;
}

	//Setters
void Producto::setCodigo(string c) {
	codigo = c;
}
void Producto::setNombre(string cl) {
	nombre = cl;
}
void Producto::setPeso(float f) {
	peso = f;
}
void Producto::setEntrada(Fecha& m) {
	entrada = m;
}
void Producto::setMenudeo(float w) {
	precioMenudeo = w;
}
void Producto::setMayoreo(float r) {
	precioMayoreo = r;
}
void Producto::setExistencia(int i) {
	existencia = i;
}


void Producto::decremento(int menos) {
	
	if (existencia < menos) {
		cout << "No tenemos la cantidad a retirar" << endl;
	}
	else	{
		existencia -= menos;
		cout << "Retirada de producto con exito" << endl;
	}
}
void Producto::incremento(int mas) {

	existencia += mas;

	if (existencia > 500) {
		existencia -= mas;
		cout << "Pasa de los 500 productos perminidos" << endl;
	}
	
}
