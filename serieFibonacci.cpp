#include <stdio.h>

long fibonacci(long n); //Prototipo de funcion.

int main()
{
	long resultado;
	long numero;
	printf("Introduzca numero:");
	scanf("%d",&numero);
	resultado=fibonacci(numero);
	printf("Fibonacci(%d) = %d\n", numero, resultado);
	return 0;
}

long fibonacci(long n)
{
	if (n==1 ||n==0)
	{
		return n;
	}
	else
	{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}
