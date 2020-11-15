#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Cancion {
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

	bool operator !=(string&);
};


#endif // !CANCION_H_INCLUDED



