#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Conversion.h"

using namespace std;

int main() {
	Convertidor myConverter;
	string expresion;
	cout<<"Ingresa la expresion infija: ";
	cin>>expresion;
	myConverter.trasExpresion(expresion);
	cout<<"============================================"<<endl;
	cout<<"Expresion posfija es: "<<myConverter.toString();
	cout<<endl;
	return 0;
}