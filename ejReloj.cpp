#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Hora {
	public:
		Hora();
		void establecerHora();
		void imprimirMilitar(int, int);
		void impirmirStandar(int, int, int);
	private:
		int hora; //0 - 23
		int minutos; //0 - 59
		int segundos; //0 - 59
};

Hora::Hora() {
	hora = minutos = segundos = 0;
}
void Hora::imprimirMilitar(int _h, int _m) {
	cout<<(_h < 10 ? "0":"")<<_h<<":"<<(_m < 10) ? "0":""<<_m;
}
void Hora::imprimirStandar(int _h, int _m, int _s) {
	cout<<((_h == 0 || _h ) ? "12":12%hora)<<":"<<(_m < 10) ? "0":""<<_m<<":"<<(_s < 10) ? "0":""<<_s<<" "<<(_h < 12 ? "AM":"PM");
}
int main() {
	Hora h;
	cout<<"La hora militar es "<<h.imprimirMilitar()<<"\n\n";
	cout<<"La hoora estandar es "<<h.impirmirStandar()<<"\n";
	h.establecerHora(13, 27, 6);
	cout<<"La hora militar es "<<h.imprimirMilitar()<<"\n\n";
	cout<<"La hoora estandar es "<<h.impirmirStandar()<<"\n";
	h.establecerHora(99, 99, 99);
	cout<<"La hora militar es "<<h.imprimirMilitar()<<"\n\n";
	cout<<"La hoora estandar es "<<h.impirmirStandar()<<"\n";
	return 0;
}
