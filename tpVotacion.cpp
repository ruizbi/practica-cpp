#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct tDatoVoto {
	int numLista;
	char sexo[1];
	int hora;
};	//Dato de los votos.
struct tDatoLista {
	int numLista;
	char nombre[20];
	int bancas;
	int vIndividual;
	float porcent;
	int vPorcentual;
};	//Dato de las listas.
struct pDatoVoto {
	tDatoVoto d;
	pDatoVoto *sgte;
};	//Apuntador a la sublista voto.
struct pDatoLista {
	tDatoLista d;
	pDatoLista *sgte;
	pDatoVoto *v;
};	//Apuntador a la lista principal.

struct tVoto {
	int vBlanco;
	int vNulo;
	int vFemenino;
	int vMasculino;
	int vTotal;	
}t = {0,0,0,0,0};

//Prototipo de funciones.
void mostrarMenu(void);
void nuevaLista(pDatoLista *&, int);
void mostrarDatos(pDatoLista *);

void votar(pDatoLista *&, tVoto &);
void votoNuevo(pDatoVoto *&, int, tVoto &);
pDatoLista * buscarLista(pDatoLista *, int);
//----------------------

pDatoLista *lista = new pDatoLista();

int main()
{
	lista = NULL;
	mostrarMenu();
	return 0;
}

void mostrarMenu()
{
	/*Variables locales a utilizar*/
	int op;
	int i = 1;
	bool ready = true;
	/* -------------------------- */
	do
	{
		cout<<"   :Menu:"<<endl;
		cout<<"1. Crear Listas."<<endl;
		cout<<"2. Ingresar Votos."<<endl;
		cout<<"3. Mostrar dato de listas."<<endl;
		cout<<"4. Salir."<<endl;
		cout<<"   Opc: ";cin>>op;
		cout<<"------------"<<endl;	
		switch (op)
		{
			case 1:
				if (ready)
				{					
					while (i<=7)
					{
						cout<<"Ingrese el nombre de la lista Nro "<<i<<": ";
						nuevaLista(lista, i);
						i++;
					}
					ready = false;				
				}
				else
				{
					cout<<"Ya se han ingresado las listas."<<endl;
					cout<<"------------"<<endl;
				}
				system("pause");
				break;
			case 2:
				votar(lista, t);
				system("pause");
				break;
			case 3:
				mostrarDatos(lista);
				system("pause");
				break;
		}	
		system("cls");
	}while(op!=4);
	cout<<"------------"<<endl<<endl;
	cout<<"Acaba de salir."<<endl;
}
void nuevaLista(pDatoLista *&lista, int i)
{
	pDatoLista *p = new pDatoLista();
	pDatoLista *aux1 = lista;
	pDatoLista *aux2;
	
	scanf("%s",p->d.nombre);
	p->d.vIndividual = 0;
	p->d.porcent = 0.0;
	p->d.numLista = i;	
	p->sgte = NULL;
	p->v = NULL;

	while (aux1!=NULL)
	{
		aux2 = aux1;
		aux1 = aux1->sgte;
	}
	if (lista == NULL)
	{
		lista = p;
	}
	else
	{
		aux2->sgte = p;
	}
	p->sgte = aux1;
}

void mostrarDatos(pDatoLista *lista)
{
	pDatoLista *actual = new pDatoLista();
	pDatoVoto *q;
	actual = lista;
	if (actual==NULL) cout<<"No hay listas."<<endl<<"------------"<<endl;
	
	while (actual!= NULL)
	{
		cout<<"Nombre: "<<actual->d.nombre<<endl;
		cout<<"Numero de lista: "<<actual->d.numLista<<endl;
		cout<<"Total de votos: "<<actual->d.vIndividual<<endl;
		cout<<"Porcentaje: "<<actual->d.porcent<<endl;
		cout<<"------------"<<endl;
		q = actual->v;
		cout<<"Votos: "<<endl<<endl;
		while (q!=NULL)
		{
			cout<<"Sexo: "<<q->d.sexo<<endl;
			cout<<"Hora: "<<q->d.hora<<endl;
			cout<<"		"<<endl;
			q = q->sgte;
		}
		cout<<"------------"<<endl;
		actual= actual->sgte;
	}
	cout<<"Votos genero femenino: "<<t.vFemenino<<endl;
	cout<<"Votos genero masculino: "<<t.vMasculino<<endl;
	cout<<"Voto total: "<<t.vTotal<<endl;
	cout<<"Voto blanco: "<<t.vBlanco<<endl;
	cout<<"Voto nulo: "<<t.vNulo<<endl;
	cout<<"------------"<<endl;
}

// -----------------

void votar(pDatoLista *&lista, tVoto &t)
{
	tDatoVoto p;
	pDatoLista *q;
	cout<<"Ingrese la lista que desee votar (-1 Para finalizar): ";
	cin>>p.numLista;
	while(p.numLista != -1)
	{
		switch (p.numLista)
		{
			case 0:
				t.vBlanco++;
				break;
			case 1:
				q = buscarLista(lista, p.numLista);
				votoNuevo(q->v, p.numLista, t);
				q->d.vIndividual++;
				break;
			case 2:
				q = buscarLista(lista, p.numLista);
				votoNuevo(q->v, p.numLista, t);
				q->d.vIndividual++;
				break;
			case 3:
				q = buscarLista(lista, p.numLista);
				votoNuevo(q->v, p.numLista, t);
				q->d.vIndividual++;
				break;
			case 4:
				q = buscarLista(lista, p.numLista);
				votoNuevo(q->v, p.numLista, t);
				q->d.vIndividual++;
				break;
			case 5:
				q = buscarLista(lista, p.numLista);
				votoNuevo(q->v, p.numLista, t);
				q->d.vIndividual++;
				break;
			case 6:
				q = buscarLista(lista, p.numLista);
				votoNuevo(q->v, p.numLista, t);
				q->d.vIndividual++;
				break;
			case 7:
				q = buscarLista(lista, p.numLista);
				votoNuevo(q->v, p.numLista, t);
				q->d.vIndividual++;
				break;
			default:
				t.vNulo++;
				break;
		}
		t.vTotal++;
		cout<<"Ingrese la lista que desee votar (-1 Para finalizar): ";
		cin>>p.numLista;
	}
}

void votoNuevo(pDatoVoto *&lista, int numLista, tVoto &t)
{
	pDatoVoto *p = new pDatoVoto();
	p->sgte = NULL;
	pDatoVoto *aux1 = lista;
	pDatoVoto *aux2;
	p->d.numLista = numLista;
	cout<<"Ingrese la hora (HHMM): "; cin>>p->d.hora;
	cout<<"Ingrese el sexo del votante (F/M): ";scanf("%s",p->d.sexo);
	if (strcmp(p->d.sexo,"M")!= 0)
	{
		t.vMasculino++;
	}
	else if (strcmp(p->d.sexo,"F")!= 0)
	{
		t.vFemenino++;
	}
	while ((aux1 != NULL) && (aux1->d.hora < p->d.hora))
	{
		aux2 = aux1;
		aux1 = aux1->sgte;
	}
	
	if (lista == aux1)
	{
		lista = p;
	}
	else
	{
		aux2->sgte = p;
	}
	
	p->sgte = aux1;
}
pDatoLista * buscarLista(pDatoLista *lista, int numLista)
{
	pDatoLista *p = lista;
	while ((p!=NULL) && (p->d.numLista!=numLista))
	{
		p = p->sgte;
	}
	return p;
}
