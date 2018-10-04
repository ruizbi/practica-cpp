#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//										Estructura de datos.
struct tArbol {
	int numero;
	tArbol *izq;
	tArbol *der;
	tArbol *padre;
};

//										Prototipo de funciones.
tArbol *nuevoArbol(int ,tArbol *);
tArbol *minimo(tArbol *);
void insertarArbol(tArbol *&, int ,tArbol *);
void mostrarArbol(tArbol *, int);
void preOrden(tArbol *);
void inOrden(tArbol *);
void posOrden(tArbol *);
void eliminar(int ,tArbol *);
void eliminarArbol(tArbol *);
void reemplazar(tArbol *, tArbol *);
void destruir(tArbol *);
bool busqueda(tArbol *, int);

//										Main.
int main() {
	tArbol *arbolBinario1 = NULL;
	int dato, opc, contador = 0;
	do {
		cout<<"1. Ingresar valor\n";
		cout<<"2. Mostrar arbol\n";
		cout<<"3. Buscar valor\n";
		cout<<"4. Recorrer en preOrden\n";
		cout<<"5. Recorrer en inOrden\n";
		cout<<"6. Recorres en posOrden\n";
		cout<<"7. Eliminar valor en arbol\n";
		cout<<"0. Salir\n";
		cout<<"?. ";
		cin>>opc;
		switch (opc) {
			case 1:
				cout<<"Ingrese el valor que desea ingresar: ";
				cin>>dato;
				insertarArbol(arbolBinario1, dato, NULL);
				cout<<"\n";
				system("pause");
				break;
			case 2:
				cout<<"Mostrando arbol completo\n\n";
				mostrarArbol(arbolBinario1, contador);
				system("pause");
				break;
			case 3:
				cout<<"Valor que desee buscar: ";
				cin>>dato;
				if (busqueda(arbolBinario1, dato) == true) {
					cout<<"Se encontro el elemento "<<dato<<" dentro del arbol.\n";
				}
				else {
					cout<<"El elemento no se ha encontrado.\n";
				}
				system("pause");
				break;
			case 4:
				cout<<"Recorrido en preOrden.\n";
				preOrden(arbolBinario1);
				cout<<"\n\n";
				system("pause");
				break;
			case 5:
				cout<<"Recorrido en inOrden.\n";
				inOrden(arbolBinario1);
				cout<<"\n\n";
				system("pause");
				break;
			case 6:
				cout<<"Recorrido en posOrden. \n";
				posOrden(arbolBinario1);
				cout<<"\n\n";
				system("pause");
				break;
			case 7:
				cout<<"Ingrese valor a eliminar: ";
				cin>>dato;
				eliminar(dato ,arbolBinario1);
				cout<<"\n\n";
				system("pause");
				break;
		}
		system("cls");
	}	while(opc != 0);
	return 0;
}

//										Desarrollo de funciones.
void insertarArbol(tArbol *&arbol, int n, tArbol *_padre) {
	if (arbol == NULL) {
		tArbol *nuevo_arbol = nuevoArbol(n, _padre);
		arbol = nuevo_arbol;
	}
	else {
		int valorRaiz = arbol->numero;
		if (n < valorRaiz) {
			insertarArbol(arbol->izq, n, arbol);
		}
		else {
			insertarArbol(arbol->der, n, arbol);
		}
	}
}

tArbol *nuevoArbol(int n, tArbol *_padre) {
	tArbol *nuevo_arbol = new tArbol();
	
	nuevo_arbol->numero = n;
	nuevo_arbol->der = NULL;
	nuevo_arbol->izq = NULL;
	nuevo_arbol->padre = _padre;
	return nuevo_arbol;
}

void mostrarArbol(tArbol *arbol, int n) {
	if (arbol == NULL) {
		return;
	}
	else {
		mostrarArbol(arbol->der,n+1);
		for (int i=0; i<n;i++) {
			cout<<"   ";
		}
		cout<<arbol->numero<<endl;
		mostrarArbol(arbol->izq, n+1);
	}
}

bool busqueda(tArbol *arbol, int n) {
	if (arbol == NULL) {
		return false;
	}
	else if (arbol->numero == n){
		return true;
	}
	else if (arbol->numero > n){
		busqueda(arbol->izq, n);
	}
	else if (arbol->numero < n) {
		busqueda(arbol->der, n);
	}
}

void preOrden(tArbol *arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		cout<<arbol->numero<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inOrden(tArbol *arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		inOrden(arbol->izq);
		cout<<arbol->numero<<" - ";
		inOrden(arbol->der);
	}
}

void posOrden(tArbol *arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		posOrden(arbol->izq);
		posOrden(arbol->der);
		cout<<arbol->numero<<" - ";
	}
}

void eliminar(int n, tArbol *arbol) {
	if (arbol == NULL) {
		return;
	}
	else if (n < arbol->numero) {
		eliminar(n ,arbol->izq);
	}
	else if (n > arbol->numero) {
		eliminar(n ,arbol->der);
	}
	else {
		eliminarArbol(arbol);
	}
}

void eliminarArbol(tArbol *arbol) {
	if (arbol->der && arbol->izq) {
		tArbol *menor = minimo(arbol);
		arbol->numero = menor->numero;
		eliminarArbol(menor);
	}
	else if (arbol->izq) {
		reemplazar(arbol, arbol->izq);
		destruir(arbol);
	}
	else if (arbol->der) {
		reemplazar(arbol, arbol->der);
		destruir(arbol);
	}
	else {
		reemplazar(arbol, NULL);
		destruir(arbol);
	}
}
void reemplazar(tArbol *arbol, tArbol *reemplazo) {
	if (arbol->padre) {
		if (arbol->numero == arbol->padre->izq->numero) {
			arbol->padre->izq = reemplazo;
		}
		else if (arbol->numero == arbol->padre->der->numero) {
			arbol->padre->der = reemplazo;
		}
	}
	if (reemplazo) {
		reemplazo->padre = arbol->padre;
	}
	
}
tArbol *minimo(tArbol *arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	else if (arbol->izq) {
		return minimo(arbol->izq);
	}
	else {
		return arbol;
	}
}

void destruir(tArbol *arbol) {
	arbol->der = NULL;
	arbol->izq = NULL;
	
	delete arbol;
}
