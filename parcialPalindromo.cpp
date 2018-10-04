#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

//Estructuras de datos.
struct tCola {
	char dato;
	tCola *pSgte;
};
struct tPila {
	char dato;
	tPila *pSgte;
};

//Prototipo de funciones.
void ingresarValores(tPila *, tCola *, tCola *);
void agregarCola(char , tCola *&, tCola *&);
void agregarPila(char , tPila *&);
bool comparar(tPila *, tCola *);
//Main.
int main() {
	tPila *pila1;
	tCola *cInicio, *cFin;
	cInicio = NULL;
	cFin = NULL;
	pila1 = NULL;
	
	ingresarValores(pila1, cInicio, cFin);
	
	return 0;
}

//Desarrollo de funciones.
void ingresarValores(tPila *pila, tCola *cI, tCola *cF) { //Despues reemplazar por cargarValores().
	char c;
	cout<<"Ingresar una palabra caracter por caracter (0 Fin): ";
	cin>>c;
	while(c!='0') {
		agregarCola(c, cI, cF);
		agregarPila(c, pila);
		cout<<"Ingresar una palabra caracter por caracter (0 Fin): ";
		cin>>c;
	}
	if (comparar(pila, cI)) {
		cout<<"Son iguales."<<endl;
	}
	else {
		cout<<"Son distintas."<<endl;
	}
}
void agregarCola(char d, tCola *&frente, tCola *&final) {
	tCola *nuevo_dato = new tCola();
	nuevo_dato->dato = d;
	nuevo_dato->pSgte = NULL;
	if (frente == NULL) {
		frente = nuevo_dato;
	}
	else {
		final->pSgte = nuevo_dato;
	}
	final = nuevo_dato;
}
void agregarPila(char d, tPila *&pila) {
	tPila *nuevo_dato = new tPila();
	nuevo_dato->dato = d;
	nuevo_dato->pSgte = pila;
	pila = nuevo_dato;
}
bool comparar(tPila *pila, tCola *frente) {
	while((pila!=NULL) || (frente!=NULL)) {
		if (pila->dato==frente->dato) {
			pila = pila->pSgte;
			frente = frente->pSgte;
		}
		else {
			return false;
		}
	}
	return true;
}
