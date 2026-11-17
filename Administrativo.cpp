#include "Administrativo.h"

using namespace std;

Administrativo::Administrativo(const string& cedula, const string& nombre, double salarioBase, int horasExtra, Departamento* departamento, const string& cargoAdministrativo, double bonoProductividad) : Empleado(cedula, nombre, salarioBase, horasExtra, departamento), cargoAdministrativo(cargoAdministrativo), bonoProductividad(bonoProductividad) {}

Administrativo::~Administrativo() {}

string Administrativo::getCargoAdministrativo() const {
return cargoAdministrativo;
}

double Administrativo::getBonoProductividad() const {
return bonoProductividad;
}

void Administrativo::setCargoAdministrativo(const string& cargoAdministrativo) {
this->cargoAdministrativo = cargoAdministrativo;
}

void Administrativo::setBonoProductividad(double bonoProductividad) {
this->bonoProductividad = bonoProductividad;
}

double Administrativo::calcularBonificaciones() const {
return bonoProductividad;
}

string Administrativo::obtenerTipo() const {
return "Administrativo";
}

string Administrativo::toString() const {
stringstream ss;
ss << Empleado::toString() << "\n";
ss << "Cargo Administrativo: " << cargoAdministrativo;
return ss.str();
}

string Administrativo::toStringArchivo() const {
stringstream ss;
ss << fixed << setprecision(2);
string codDept = (departamento != nullptr) ? departamento->getCodigo() : "NONE";
ss << "ADMIN;" << cedula << ";" << nombre << ";" << salarioBase << ";" << horasExtra << ";" << codDept << ";" << cargoAdministrativo << ";" << bonoProductividad;
return ss.str();
}
