#include "Superheroe.h"


string Superheroes::getNombre() {
	return nombre;
}

string Superheroes::getPoder() {
	return poder;
}

string Superheroes::getDebilidad() {
	return debilidad;
}

void Superheroes::setNombre(string a) {
	nombre = a;
}

void Superheroes::setPoder(string a) {
	poder = a;
}

void Superheroes::setDebilidad(string a) {
	debilidad = a;
}

string Superheroes::toString() {
	string MyString;

	MyString = nombre;
	MyString += "|";
	MyString += poder;
	MyString += "|";
	MyString += debilidad;

	return MyString;
}

bool Superheroes::operator!=(string& c) {
	return nombre != c;
}

bool Superheroes::operator <(string& c) {
	return nombre < c;
}

bool Superheroes::operator >(string& c) {
	return nombre > c;
}

bool Superheroes::operator ==(string& c) {
	return nombre == c;
}