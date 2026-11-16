#include "Puesto.h"

using namespace std;

Puesto::Puesto(const string& codigo, const string& nombreCargo, double salarioBaseSugerido): codigo(codigo), nombreCargo(nombreCargo), salarioBaseSugerido(salarioBaseSugerido) {}

Puesto::~Puesto() {}

string Puesto::getCodigo() const {
return codigo;
}

string Puesto::getNombreCargo() const {
return nombreCargo;
}

double Puesto::getSalarioBaseSugerido() const {
return salarioBaseSugerido;
}

void Puesto::setNombreCargo(const string& nombreCargo) {
this->nombreCargo = nombreCargo;
}

void Puesto::setSalarioBaseSugerido(double salarioBaseSugerido) {
this->salarioBaseSugerido = salarioBaseSugerido;
}

string Puesto::toString() const {
stringstream ss;
ss << fixed << setprecision(2);
ss << "  - [" << codigo << "] " << nombreCargo << " | Salario Base Sugerido: " << salarioBaseSugerido;
return ss.str();
}

string Puesto::toStringArchivo() const {
stringstream ss;
ss << fixed << setprecision(2);
ss << codigo << ":" << nombreCargo << ":" << salarioBaseSugerido;
return ss.str();
}
