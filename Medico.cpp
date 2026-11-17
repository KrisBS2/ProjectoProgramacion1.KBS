#include "Medico.h"

using namespace std;

Medico::Medico(const string& cedula, const string& nombre, double salarioBase, int horasExtra, Departamento* departamento, const string& especialidad, int cantidadGuardias) : Empleado(cedula, nombre, salarioBase, horasExtra, departamento), especialidad(especialidad), cantidadGuardias(cantidadGuardias) {}

Medico::~Medico() {}

string Medico::getEspecialidad() const {
return especialidad;
}

int Medico::getCantidadGuardias() const {
return cantidadGuardias;
}

void Medico::setEspecialidad(const string& especialidad) {
this->especialidad = especialidad;
}

void Medico::setCantidadGuardias(int cantidadGuardias) {
this->cantidadGuardias = cantidadGuardias;
}

double Medico::calcularBonificaciones() const {
return cantidadGuardias * 25000.0;
}

string Medico::obtenerTipo() const {
return "Medico";
}

string Medico::toString() const {
stringstream ss;
ss << Empleado::toString() << "\n";
ss << "Especialidad: " << especialidad << " | Guardias realizadas: " << cantidadGuardias;
return ss.str();
}

string Medico::toStringArchivo() const {
stringstream ss;
ss << fixed << setprecision(2);
string codDept = (departamento != nullptr) ? departamento->getCodigo() : "NONE";
ss << "MEDICO;" << cedula << ";" << nombre << ";" << salarioBase << ";" << horasExtra << ";" << codDept << ";" << especialidad << ";" << cantidadGuardias;
return ss.str();
}
