//		Herencia.

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Persona {
	private:	//Atributos.
		string nombre;
		int edad;
	public:		//Metodos.
		Persona(string, int);
		void mostrarPersona();
		~Persona();
};
class Alumno : public Persona{
	private:	//Atributos.
		string codigoAlumno;
		float notaFinal;
	public:		//Metodos.
		Alumno(string, int, string, float);
		void mostrarAlumno();
		~Alumno();
};

Persona::Persona(string _nombre, int _edad) {
	nombre = _nombre;
	edad = _edad;
}

Persona::~Persona(){
}

Alumno::Alumno(string _nombre, int _edad, string _codigoAlumno, float _notaFinal):Persona(_nombre, _edad) {
	codigoAlumno = _codigoAlumno;
	notaFinal = _notaFinal;
}

Alumno::~Alumno(){
}
void Persona::mostrarPersona() {
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

void Alumno::mostrarAlumno() {
	mostrarPersona();
	cout<<"Codigo de alumno: "<<codigoAlumno<<endl;
	cout<<"Nota final: "<<notaFinal<<endl;
}

int main() {
	Alumno alumno1("Bruno", 23, "1631639-9", 8);
	alumno1.mostrarAlumno();
	
	return 0;
}
