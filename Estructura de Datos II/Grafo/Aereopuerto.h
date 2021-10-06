#ifndef AEREOPUERTO_H_INCLUDED
#define AEREOPUERTO_H_INCLUDED

#include<string>
#include <sstream>
using namespace std;

class Aereopuerto {
private:
	string nombre;
	string lugar;
	int vuelos;
public:

	string getNombre();
	string getLugar();
	int getVuelos();

	void setNombre(string);
	void setLugar(string);
	void setVuelos(int);

	string toString();
};


#endif // !AEREOPUERTO_H_INCLUDED
