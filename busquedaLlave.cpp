#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 100

int busquedaLLave(int b[], int llave, int tamanio);

int main()
{
	int a[TAMANIO];
	int x;
	int llaveBusqueda;
	int elemento;
	
	for (x=0;x<TAMANIO;x++)
	{
		a[TAMANIO]=2*x;
	}
	
	printf("Introduzca la llave:");
	scanf("%d",&llaveBusqueda);
	elemento=busquedaLLave(a, llaveBusqueda, TAMANIO);
	if (elemento!=-1)
	{
		printf("Se encontro en el elemnto %d.",elemento);
	}
	else
	{
		printf("El elemento no se encontro.");
	}
	return 0;
}

int busquedaLLave(int b[], int llave, int tamanio)
{
	int i;
	for (i=0;i<tamanio;i++)
	{
		if (b[i]==llave)
		{
			return i;
		}
	}
	return -1;
}
