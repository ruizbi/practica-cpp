//		Herencia multiple.

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


class Persona {
	private:
		int edad;
		string nombre;
	public:
		Persona(string, int);
		void mostrarPersona();
};
class Empleado:public Persona{ 
	private:
		float sueldo;
	public:
		Empleado(string, int, float);
		void mostrarEmpleado();
};
class Estudiante:public Persona{
	private:
		float notaFinal;
	public:
		Estudiante(string, int, float);
		void mostrarEstudiante();
};
class Universitario:public Estudiante{
	private:
		string carrera;
	public:
		Universitario(string, int, float, string);
		void mostrarUniversitario();
};


//		Desarrollo de class Persona.
Persona::Persona(string _nombre, int _edad) {
	nombre = _nombre;
	edad = _edad;
}
void Persona::mostrarPersona() {
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}


//		Desarrollo de class Empleado.
Empleado::Empleado(string _nombre, int _edad, float _sueldo):Persona(_nombre, _edad) {
	sueldo = _sueldo;
}
void Empleado::mostrarEmpleado() {
	mostrarPersona();
	cout<<"Sueldo: "<<sueldo<<endl;
}


//		Desarrollo de class Estudiante.
Estudiante::Estudiante(string _nombre, int _edad, float _notaFinal):Persona(_nombre, _edad) {
	notaFinal = _notaFinal;
}
void Estudiante::mostrarEstudiante() {
	mostrarPersona();
	cout<<"Nota final: "<<notaFinal<<endl;
}


//		Desarrollo de class Universitario.
Universitario::Universitario(string _nombre, int _edad, float _notaFinal, string _carrera):Estudiante(_nombre, _edad, _notaFinal) {
	carrera = _carrera;
}
void Universitario::mostrarUniversitario() {
	mostrarEstudiante();
	cout<<"Carrera: "<<carrera<<endl;
}


//		Main del programa.
int main() {
	Empleado empleado1("Bruno", 23, 20.500);
	cout<<"-Empleado-"<<endl;
	empleado1.mostrarEmpleado();
	cout<<"\n\n";
	cout<<"-Alumno universitario-"<<endl;
	Universitario u1("Ruiz", 23, 9.50, "Ing. en Sistemas");
	u1.mostrarUniversitario();
	cout<<"\n\n";
	system("pause");
	return 0;
}
