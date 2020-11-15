#pragma once
#include <iostream>
#include <string>

using namespace std;

class Datos{
private:
	std::string cancion;
	std::string autor;
	std::string interprete;
	int rank;
public:
	
	//Setters
	void setCancion(string);
	void setAutor(string);
	void setInteprete(string);
	void setRank(int);

	//Getters
	std::string getCancion();
	std::string getAutor();
	std::string getInterprete();
	int getRank();

	std::string toString();
};
