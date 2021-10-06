#ifndef SUPERHEROE_H_INCLUDED
#define SUPERHEROE_H_INCLUDED

#include <iostream>
#include <string>


using namespace std;

class Superheroes {
private:
	string nombre;
	string poder;
	string debilidad;
public:
	string getNombre();
	string getPoder();
	string getDebilidad();

	void setNombre(string);
	void setPoder(string);
	void setDebilidad(string);

	string toString();

	bool operator !=(string&);
	bool operator <(string&);
	bool operator >(string&);
	bool operator ==(string&);
};


#endif // !SUPERHEROE_H_INCLUDED


