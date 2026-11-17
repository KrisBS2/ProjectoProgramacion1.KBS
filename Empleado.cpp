#include "Empleado.h"

using namespace std;

Empleado::Empleado(const string& cedula, const string& nombre, double salarioBase, int horasExtra, Departamento* departamento): cedula(cedula), nombre(nombre), salarioBase(salarioBase), horasExtra(horasExtra), departamento(departamento) {}

Empleado::~Empleado() {
departamento = nullptr;
}

string Empleado::getCedula() const {
return cedula;
}

string Empleado::getNombre() const {
return nombre;
}

double Empleado::getSalarioBase() const {
return salarioBase;
}

int Empleado::getHorasExtra() const {
return horasExtra;
}

Departamento* Empleado::getDepartamento() const {
return departamento;
}

void Empleado::setNombre(const string& nombre) {
this->nombre = nombre;
}

void Empleado::setSalarioBase(double salarioBase) {
this->salarioBase = salarioBase;
}

void Empleado::setHorasExtra(int horasExtra) {
this->horasExtra = horasExtra;
}

void Empleado::setDepartamento(Departamento* departamento) {
this->departamento = departamento;
}

double Empleado::calcularPagoHorasExtra() const {
double valorHora = salarioBase / 240.0;
return horasExtra * (valorHora * 1.5);
}

double Empleado::calcularSalarioBruto() const {
return salarioBase + calcularPagoHorasExtra() + calcularBonificaciones();
}

double Empleado::calcularDeducciones() const {
 
return calcularSalarioBruto() * 0.1067;
}

double Empleado::calcularSalarioNeto() const {
return calcularSalarioBruto() - calcularDeducciones();
}

string Empleado::toString() const {
stringstream ss;
ss << fixed << setprecision(2);
ss << "Tipo: " << obtenerTipo() << "\n";
ss << "Cedula: " << cedula << " | Nombre: " << nombre << "\n";
ss << "Departamento: " << (departamento != nullptr ? departamento->getNombre() + " [" + departamento->getCodigo() + "]" : "Sin asignar") << "\n";
ss << "Salario Base: " << salarioBase << " | Horas Extra: " << horasExtra << " (+" << calcularPagoHorasExtra() << ")\n";
ss << "Bonificaciones: " << calcularBonificaciones() << " | Bruto: " << calcularSalarioBruto() << "\n";
ss << "Deducciones (10.67%): -" << calcularDeducciones() << " | Salario Neto: " << calcularSalarioNeto();
return ss.str();
}
