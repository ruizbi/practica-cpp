#include <iostream>
#include <stdio.h>

using namespace std;

template <class T>

T maximo(T valor1, T valor2, T valor3) {
	T maximo = valor1;
	if (maximo < valor2) {
		maximo = valor2;
	}
	if (maximo < valor3) {
		maximo = valor3;
	}
	return maximo;
}

int main() {
	int valor1, valor2, valor3;
	float valor4, valor5, valor6;
	cout<<"Ingrese 3 valores\n";
	cout<<"Primer valor: ";cin>>valor1;
	cout<<"Segundo valor: ";cin>>valor2;
	cout<<"Tercer valor: ";cin>>valor3;
	cout<<"El valor maximo es "<<maximo(valor1, valor2, valor3)<<endl;
	cout<<"Ingrese 3 valores decimales\n";
	cout<<"Primer valor: ";cin>>valor4;
	cout<<"Segundo valor: ";cin>>valor5;
	cout<<"Tercer valor: ";cin>>valor6;
	cout<<"El valor maximo es "<<maximo(valor4, valor5, valor6)<<endl;
	return 0;
}
