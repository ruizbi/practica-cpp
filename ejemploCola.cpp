#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct Nodo {
	Nodo *siguiente;
	int dato;
};

void insertarCola(Nodo *&, Nodo *&, int);
void eliminarCola(Nodo *&, Nodo*& ,int &);
void menu(void);
bool cola_vacia(Nodo *);

int main()
{
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	int opc;
	int dato;
	do
	{
		menu();
		cin>>opc;
		switch (opc)
		{
			case 1:
				cout<<"Ingrese un valor:";
				cin>>dato;
				insertarCola(frente, fin, dato);
				system("pause");
				break;
			case 2:
				eliminarCola(frente, fin, dato);
				system("pause");
				break;
			case 3:
				while(frente!=NULL)
				{
					eliminarCola(frente, fin, dato);
				}
				system("pause");
				break;
				
		}
		system("cls");
	}	while(opc!=4);
	
	return 0;
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n)
{
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if (cola_vacia(frente))
	{
		frente = nuevo_nodo;
	}
	else
	{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
	
	cout<<"\n\tElemento "<<n<<" agregado a la cola.\n\n";
}

bool cola_vacia(Nodo *frente)
{
	return (frente == NULL)? true:false; /* condicion ? v : f */
}

void eliminarCola(Nodo *&frente, Nodo *&fin, int &n)
{
	n = frente->dato;
	Nodo *aux = frente;
	
	if (frente == fin)
	{
		frente = NULL;
		fin = NULL;
	}
	else
	{
		frente = frente->siguiente;
	}
	
	delete aux;

	cout<<"\n\tElemento "<<n<<" eliminado de la cola.\n\n";
}

void menu()
{
	cout<<"\t.:Menu:.\n";
	cout<<"1. Insertar en cola.\n";
	cout<<"2. Eliminar de cola.\n";
	cout<<"3. Eliminar total.\n";
	cout<<"4. Fin.\n?";
}
