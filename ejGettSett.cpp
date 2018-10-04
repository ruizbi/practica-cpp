//		Getters y Setters.

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Punto {
	private:	//Atributos.
		int x, y;
	public:		//Metodos.
		Punto();
		void setPunto(int , int);	//Establece valores.
		int getPuntoX();	//Muestra valores.
		int getPuntoY();	//Muestra valores.
};

Punto::Punto(){
}
//		Asignar valores a los atributos como un constructor (si son demasiados, y cuando yo quiera). 
void Punto::setPunto(int _x, int _y) {
	x = _x;
	y = _y;
}
//		Muestra los valores almacenados desde fuera de la clase.
int Punto::getPuntoX() {
	return x;
}
int Punto::getPuntoY() {
	return y;
}
int main(){
	Punto punto1;														//	1)Creo la clase.
	punto1.setPunto(10, 5);												//	2)Encapsulo valores.
	cout<<"Punto: ("<<punto1.getPuntoX()<<";"<<punto1.getPuntoY()<<")";	//	3)Muestro valores.
	return 0;
}
