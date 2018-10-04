#include  <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>	//new

using namespace std;

struct Nodo	{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&, int);
void eliminarPila(Nodo *&, int&);
void menu(void);

int main()
{
	Nodo *pila = NULL;
	int dato;
	int opc;
	do
	{
		menu();
		cin>>opc;
		switch (opc)
		{
			case 1:
				cout<<"Ingrese un valor:";
				cin>>dato;
				agregarPila(pila,dato);
				system("pause");
				break;
			case 2:
				eliminarPila(pila,dato);
				system("pause");
				break;
			case 3:
				while(pila!=NULL)
				{
					eliminarPila(pila,dato);
				}
				system("pause");
				break;
		}
		system("cls");
	}	while(opc!=4);
	return 0;
}

void agregarPila(Nodo *&pila, int n)
{
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\n\tElemento "<<n<<" agregado a la pila.\n\n";
}

void eliminarPila(Nodo *&pila,int &n)
{
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
	
	cout<<"\tElemento "<<n<<" eliminado de la pila.\n\n";
}

void menu()
{
	cout<<"\t.:Menu:.\n";
	cout<<"1. Agregar nodo.\n";
	cout<<"2. Borrar nodo.\n";
	cout<<"3. Borrar todo.\n";
	cout<<"4. Salir\n?";
}
