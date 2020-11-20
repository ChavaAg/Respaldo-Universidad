#ifndef CPILAOCOLA_H_INCLUDED
#define CPILAOCOLA_H_INCLUDED


class CPilaoCola {
public:
	virtual void push(float nd) = 0;
	virtual float pop() = 0;
	virtual int size() = 0;
	virtual void imprimir() = 0;
};

#endif // !CPILAOCOLA_H_INCLUDED
