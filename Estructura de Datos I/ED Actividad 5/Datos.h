#pragma once
#include <iostream>
#include <string>

using namespace std;

class Datos {
private:
	std::string cancion;
	std::string autor;
	std::string interprete;
	std::string mp3;
	int rank;
public:

	//Setters
	void setCancion(string);
	void setAutor(string);
	void setInteprete(string);
	void setMp3(string);
	void setRank(int);

	//Getters
	std::string getCancion();
	std::string getAutor();
	std::string getInterprete();
	std::string getMp3();
	int getRank();

	std::string toString();

	bool operator == (Datos&);
};
