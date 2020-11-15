

class CColaEstatica {
private:
	float cola[5];
	int iIndiceInsercion;
	int iIndiceDersecion;
	int iTamano;
public:
	CColaEstatica();
	~CColaEstatica();

	void push(float nd);
	float pop();
	int size();
	bool isEmpty();
	bool isFull();
	void imprimir();
};
