
class CPilaEstatica {
private:
	float pila[5];
	int iIndiceInsercion;;

public:
	CPilaEstatica();
	~CPilaEstatica();

    void push(float nd);
    float pop();
    float tos();
    int size();
    bool isEmpty();
    bool isFull();
    void imprimir();

};
