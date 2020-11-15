#include <iostream>
#include <string>
#include "Datos.h"

using namespace std;


//Setters
void Datos::setCancion(string c) {
	cancion = c;
}
void Datos::setAutor(string a) {
	autor = a;
}
void Datos::setInteprete(string i) {
	interprete = i;
}
void Datos::setRank(int r) {
	rank = r;
}

//Getters
string Datos::getCancion() {
	return cancion;
}
string Datos::getAutor() {
	return autor;
}
std::string Datos::getInterprete() {
	return interprete;
}
int Datos::getRank() {
	return rank;
}


//To string
std::string Datos::toString() {
	string MyString;

	MyString = cancion;
	MyString += " || ";
	MyString += autor;
	MyString += " || ";
	MyString += interprete;
	MyString += " || ";
	MyString += to_string(rank);

	return MyString;
}