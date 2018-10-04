#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{	//Inicio de la main.
	unsigned semilla;	//Semilla del srand.
	
	cout<<"Ingrese la semilla:";
	cin>>semilla;
	srand(semilla);
	for (int i=1;i<=10;i++)
	{	//Inicio del for.
		printf("%10d", 1+(rand()%6));
		if (i % 5 == 0) 
		{	//Inicio del if.
			cout<<"\n";
		}	//Fin del if.
	}	//Fin del for.
	return 0;	//Terminacion exitosa.
}	//Fin de la main.
