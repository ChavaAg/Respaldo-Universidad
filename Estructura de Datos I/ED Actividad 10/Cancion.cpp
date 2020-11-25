#include <iostream>
#include "Cancion.h"

using namespace std;

//Setters
void Cancion::setCancion(string c) {
	cancion = c;
}
void Cancion::setAutor(string a) {
	autor = a;
}
void Cancion::setInteprete(string i) {
	interprete = i;
}
void Cancion::setMp3(string m) {
	mp3 = m;
}
void Cancion::setRank(int r) {
	rank = r;
}

//Getters
string Cancion::getCancion() {
	return cancion;
}
string Cancion::getAutor() {
	return autor;
}
string Cancion::getInterprete() {
	return interprete;
}
string Cancion::getMp3() {
	return mp3;
}
int Cancion::getRank() {
	return rank;
}

//To string
std::string Cancion::toString() {
	string MyString;

	MyString = " || ";
	MyString += cancion;
	MyString += " || ";
	MyString += interprete;
	MyString += " || ";
	MyString += autor;
	MyString += " || ";
	MyString += to_string(rank);

	return MyString;
}

bool Cancion::operator!=(string& c) {
	return cancion != c;
}