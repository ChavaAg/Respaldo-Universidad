#pragma once

#include <iostream>
#include <string>

using namespace std;

class Datos {
private:
	int numero;
public:

	//Setters
	void setNumero(int);

	//Getters
	int getNumero();

	std::string toString();

	bool operator < (Datos&);
	bool operator > (Datos&);
	bool operator <= (Datos&);
	bool operator >= (Datos&);
};