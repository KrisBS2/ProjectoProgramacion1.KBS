#include "Enfermero.h"

using namespace std;

Enfermero::Enfermero(const string& cedula, const string& nombre, double salarioBase, int horasExtra, Departamento* departamento, int turnosNocturnos, const string& areaAsignada)
: Empleado(cedula, nombre, salarioBase, horasExtra, departamento), turnosNocturnos(turnosNocturnos), areaAsignada(areaAsignada) {}

Enfermero::~Enfermero() {}

int Enfermero::getTurnosNocturnos() const {
return turnosNocturnos;
}

string Enfermero::getAreaAsignada() const {
return areaAsignada;
}

void Enfermero::setTurnosNocturnos(int turnosNocturnos) {
this->turnosNocturnos = turnosNocturnos;
}

void Enfermero::setAreaAsignada(const string& areaAsignada) {
this->areaAsignada = areaAsignada;
}

double Enfermero::calcularBonificaciones() const {
return turnosNocturnos * 15000.0;
}

string Enfermero::obtenerTipo() const {
return "Enfermero";
}

string Enfermero::toString() const {
stringstream ss;
ss << Empleado::toString() << "\n";
ss << "Area Asignada: " << areaAsignada << " | Turnos Nocturnos: " << turnosNocturnos;
return ss.str();
}

string Enfermero::toStringArchivo() const {
stringstream ss;
ss << fixed << setprecision(2);
string codDept = (departamento != nullptr) ? departamento->getCodigo() : "NONE";
ss << "ENFERMERO;" << cedula << ";" << nombre << ";" << salarioBase << ";" << horasExtra << ";" << codDept << ";" << turnosNocturnos << ";" << areaAsignada;
return ss.str();
}
