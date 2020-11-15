#include <iostream>
#include <string>

using namespace std;

class Fecha {
private:
	int dia;
	int mes;
	int ano;
public:
	int getDia() {
		return dia;
	}
	int getMes() {
		return mes;
	}
	int getAno() {
		return ano;
	}

	std::string toString(){
		return to_string(ano) + "/" + to_string(mes) + "/" + to_string(dia);
	}
	int toInt() {
		return ano * 10000 + mes * 100 + dia;
	}
	void setDia(int x) {
		dia = x;
	}
	void setMes(int y) {
		mes = y;
	}
	void setAno(int z) {
		ano = z;
	}
};
