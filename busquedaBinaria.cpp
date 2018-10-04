#include <iostream>
#include <stdio.h>
#define TAMANIO 15

int busquedaBinaria(const int b[], int claveBusqueda, int baja, int alta);	/*Prototipo Busqueda Binaria*/
void imprimirEncabezado(void);	/* Prototipo impresion del encabezado*/
void imprimirLinea(const int b[], int medio, int alta, int baja);	/*Prototipo impresion arreglo con bb*/

int main()
{
	int a[TAMANIO];
	int i;
	int llave;
	int elemento;
	
	for (i=0;i<TAMANIO;i++)
	{	/*Inicia el vector*/
		a[i]=2*i;
	}	/*Fin de inicio vec*/
	
	printf("Introduzca una llave:");
	scanf("%d",&llave);
	
	imprimirEncabezado();
	elemento=busquedaBinaria(a, llave, 0, TAMANIO);
	
	if (elemento!=-1)
	{
		printf("%d se encontro en el elemento %d.",llave, elemento);
	}
	
}

void imprimirEncabezado(void)
{
	int i;
	
	for (i=1;i<=TAMANIO;i++)
	{
		printf("%3d",i);
	}	printf("\n");
	for (i=1;i<=4*TAMANIO;i++)
	{
		printf("-");
	}	printf("\n");
	
}

int busquedaBinaria(const int b[], int claveBusqueda, int baja, int alta)
{
	int centro;
	
	while(baja<=alta)
	{
		centro=(alta+baja)/2;
		
		imprimirLinea(b, centro, alta, baja);
		
		if (claveBusqueda==b[centro])
		{
			return centro;
		}
		else if (claveBusqueda<b[centro])
		{
			alta=centro-1;
		}
		else
		{
			baja=centro+1;
		}
		
	}
	
	return -1;
}

void imprimirLinea(const int b[], int medio, int alta, int baja)
{
	int i;
	for (i=0;i<TAMANIO;i++)
	{
		if(i<baja || i>alta)
		{
			printf("\t");
		}
		else if (i==medio)
		{
			printf("%3d*",b[i]);
		}
		else
		{
			printf("%3d",b[i]);
		}
	}
	printf("\n");
}
