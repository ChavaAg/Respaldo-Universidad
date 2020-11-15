#pragma once

#include <iostream>
#include <string>
#include "Fecha.h"

using namespace std;

class Producto{
private:

	string codigo;
	string nombre;
	float peso;
	Fecha entrada;
	float precioMayoreo;
	float precioMenudeo;
	int existencia;
public:
		//Setters
	void setCodigo(string);
	void setNombre(string);
	void setPeso(float);
	void setEntrada(Fecha& m );
	void setMayoreo(float);
	void setMenudeo(float);
	void setExistencia(int);

	//Getters
	std::string getCodigo();
	std::string getNombre();
	float getPeso();
	Fecha getEntrada();
	float getMayoreo();
	float getMenudeo();
	int getExistencia();

	void incremento(int);
	void decremento(int);

	string convertidor() {
		string ora;

		ora = nombre;
		ora += " || ";
		ora += codigo;
		ora += " || ";
		ora += entrada.toString();
		ora += " || ";
		ora += to_string(peso);
		ora += " || ";
		ora += to_string(precioMayoreo);
		ora += " || ";
		ora += to_string(precioMenudeo);
		ora += " || ";
		ora += to_string(existencia);

		return ora;
	}
};

