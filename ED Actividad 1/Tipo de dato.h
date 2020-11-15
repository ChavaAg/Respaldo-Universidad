#include <string>

using namespace std;

class TipoDato {
private:
	string nombre;
	int bits;
	double valorMin;
	double valorMax;
public:
	TipoDato(string, int, double, double);
	void tabla();
};