#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int tiraDado( void ); //Prototipo de funcion tiroDado.

enum Estatus {CONTINUA, GANA, PIERDE}; //Constante de enumeracion que representa el juego.

int main()
{	//Inicio de la main.

	int punto;
	int suma;
	
	enum Estatus estatusJuego;
	
	srand( time( NULL ) );
	suma = tiraDado();
	
	switch (suma)
	{	//Inicio switch.
		case 7:
		case 11:
			estatusJuego=GANA;
			break;
		case 2:
		case 3:
		case 12:
			estatusJuego=PIERDE;
			break;
		default:
			estatusJuego=CONTINUA;
			punto=suma;
			printf("La suma de los dados fue de %d\n", suma);
			break;
	}	//Fin switch
	while (estatusJuego==CONTINUA)
	{	//Inicio while.
		suma=tiraDado();
		if (suma==punto)
		{	//Inicio if.
			estatusJuego=GANA;
		}	//Fin if.
		else if (suma==7)
		{	//Inicio else if.
			estatusJuego=PIERDE;
		}	//Fin else if.
		
	}	//Fin while.
	if (estatusJuego==GANA)
	
	{	//Inicio if.
		printf("El jugador gana.");
	}	//Fin if.
	else if (estatusJuego==PIERDE)
	{	//Inicio else if.
		printf("El jugador pierde");
	}	//Fin else if.
	return 0;	//Finaliza con exito.
}	//Fin de la main.

int tiraDado( void )
{	//Inicio de tiraDado.
	int dado1;
	int dado2;
	int sumaDado;
	dado1=1+(rand()%6);
	dado2=1+(rand()%6);
	sumaDado=dado1+dado2;
	printf("El jugador saco %d y %d = %d.\n",dado1, dado2, sumaDado);
	return sumaDado;
}	//Fin de tiroDado.
