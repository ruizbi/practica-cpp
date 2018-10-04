//		Polimorfismo.

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Persona {
	private:
		string nombre;
		int edad;
	public:
		Persona(string, int);
		virtual void mostrar();
};
class Alumno:public Persona {
	private:
		float nota;
	public:
		Alumno(string, int, float);
		void mostrar();
};
class Profesor:public Persona {
	private:
		string materia;
	public:
		Profesor(string, int, string);
		void mostrar();
};

Persona::Persona(string _nombre, int _edad) {
	edad = _edad;
	nombre = _nombre;
}
void Persona::mostrar() {
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}
Alumno::Alumno(string _nombre, int _edad, float _nota):Persona(_nombre, _edad) {
	nota = _nota;
}
void Alumno::mostrar() {
	Persona::mostrar();
	cout<<"Nota: "<<nota<<endl;
}
Profesor::Profesor(string _nombre, int _edad, string _materia):Persona(_nombre, _edad) {
	materia = _materia;
}
void Profesor::mostrar() {
	Persona::mostrar();
	cout<<"Materia: "<<materia<<endl;
}

int main() {
	Persona *vector[3];
	vector[0] = new Persona("Ruiz Bruno", 23);
	vector[1] = new Alumno("Ruiz Bruno", 23, 9.75);
	vector[2] = new Profesor("Ruiz Bruno", 23, "Algoritmos");
	cout<<"-Persona-\n";
	vector[0]->mostrar();
	cout<<"\n-Alumno-\n";
	vector[1]->mostrar();
	cout<<"\n-Profesor-\n";
	vector[2]->mostrar();
	cout<<"\n";
	system("pause");
	return 0;
}
