#include "Nodo.h"

class Lista {
private:
	Nodo* inicio;
	bool isValidPos(Nodo*);
public:

	typedef Nodo* Position;

	Lista();
	~Lista();

	bool vacia();
	void inserta(Nodo*, Cancion&j);
	void elimina(Nodo*);

	Nodo* getPrimero();
	Nodo* getUltimo();
	Nodo* getAntes(Nodo*);
	Nodo* getDespues(Nodo*);

	Nodo* busquedaCancion(string);
	Nodo* busquedaInterprete(string);

	Cancion recupera(Nodo*);

	void borradorHD();
	string toString();
};
