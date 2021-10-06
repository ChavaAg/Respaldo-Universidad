#include "Aereopuerto.h"

string Aereopuerto::getNombre() {
    return nombre;
}

string Aereopuerto::getLugar() {
    return lugar;
}

int Aereopuerto::getVuelos() {
    return vuelos;
}

void Aereopuerto::setNombre(string x) {
    nombre = x;
}

void Aereopuerto::setLugar(string y) {
    lugar = y;
}

void Aereopuerto::setVuelos(int z) {
    vuelos = z;
}

string Aereopuerto::toString() {
    stringstream ss;

    ss << nombre << "|" << lugar << "|" << vuelos<<"|";

    return ss.str();
}


