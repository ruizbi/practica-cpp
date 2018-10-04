#include <iostream>
#include <stdio.h>

using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};

void insertarLista(Nodo *&,int);
void menu(void);
void mostrarLista(Nodo *);
void eliminarNodo(Nodo *&, int);
void buscarLista(Nodo*, int);
void eliminarLista(Nodo *&, int&);

Nodo *lista = NULL;

int main()
{
	Nodo *lista = NULL;
	menu();
	return 0;
}

void menu()
{
	int op;
	int dato;
	do 
	{	
		cout<<"\t.:Menu:."<<endl;
		cout<<"1. Ingresar dato."<<endl;
		cout<<"2. Mostrar datos."<<endl;
		cout<<"3. Buscar dato."<<endl;
		cout<<"4. Eliminar dato."<<endl;
		cout<<"5. Eliminar lista."<<endl;
		cout<<"6 .Fin."<<endl<<"?";
		cin>>op;
		switch (op)
		{
			case 1:
				cout<<"Ingrese un valor:";
				cin>>dato;
				insertarLista(lista,dato);
				break;
			case 2:
				cout<<"\n------------\n";
				mostrarLista(lista);
				cout<<"------------\n";
				system("pause");
				break;
			case 3:
				cout<<"Ingresar un valor:";
				cin>>dato;
				buscarLista(lista,dato);
				system("pause");
				break;
			case 4:
				cout<<"Ingrese un valor:";
				cin>>dato;
				eliminarNodo(lista,dato);
				system("pause");
				break;
			case 5:
				while (lista!=NULL)
				{
				eliminarLista(lista,dato);
				cout<<dato<<"->";
				}
				cout<<"\n";
				system("pause");
			default:
				cout<<"Error de ingreso, intente nuevamente.";
				break;
		}
		system("cls");
	}	while(op!=6);
}

void mostrarLista(Nodo *lista)
{
	Nodo *actual = new Nodo();
	actual = lista;
	while (actual!=NULL)
	{
		cout<<actual->dato<<"->";
		actual=actual->siguiente;
	}
	cout<<"NULL\n";
}

void insertarLista(Nodo *&lista,int n)
{
	
	Nodo *nuevo_nodo =  new Nodo();
	nuevo_nodo->dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while ((aux1!=NULL)&&(aux1->dato<n))
	{
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if (lista == aux1)
	{
		lista = nuevo_nodo;
	}
	else
	{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
}

void buscarLista(Nodo*, int n)
{
	bool band = false;
	Nodo *actual = new Nodo();
	actual = lista;
	while((actual!=NULL) && (actual->dato <= n))
	{
		if (actual->dato==n)
		{
			band = true;
		}
		actual=actual->siguiente;
	}
	if (band==true)
	{
		cout<<"El elemento "<<n<<" Si existe en la lista\n";
	}
	else
	{
		cout<<"El elemento "<<n<<" No existe en la lista\n";
	}
}

void eliminarNodo(Nodo *&lista, int n)
{
	if (lista!=NULL)
	{
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		aux_borrar = lista;
		while ((aux_borrar!=NULL)&&(aux_borrar->dato!=n))
		{
			anterior=aux_borrar;
			aux_borrar=aux_borrar->siguiente;
		}
		if (aux_borrar==NULL)
		{
			cout<<"El elemento no existe.\n";	
		} 
		
		else if (anterior==NULL)
		{
			lista=lista->siguiente;
			delete aux_borrar;
		}
		else
		{
			anterior->siguiente=aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}

void eliminarLista(Nodo *&, int &n)
{
	Nodo *aux = lista;
	n = aux->dato;
	lista = aux->siguiente;
	delete aux;
}
