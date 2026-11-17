#include "ComprobantePago.h"

using namespace std;

ComprobantePago::ComprobantePago(const string& idComprobante, const string& fecha, Empleado* empleado, Departamento* departamento, double salarioBruto, double bonificaciones, double deducciones, double salarioNeto) 
: idComprobante(idComprobante), fecha(fecha), empleado(empleado), departamento(departamento), salarioBruto(salarioBruto), bonificaciones(bonificaciones), deducciones(deducciones), salarioNeto(salarioNeto) {}

ComprobantePago::~ComprobantePago() {
empleado = nullptr;
departamento = nullptr;
}

string ComprobantePago::getIdComprobante() const {
return idComprobante;
}

string ComprobantePago::getFecha() const {
return fecha;
}

Empleado* ComprobantePago::getEmpleado() const {
return empleado;
}

Departamento* ComprobantePago::getDepartamento() const {
return departamento;
}

double ComprobantePago::getSalarioBruto() const {
return salarioBruto;
}

double ComprobantePago::getBonificaciones() const {
return bonificaciones;
}

double ComprobantePago::getDeducciones() const {
return deducciones;
}

double ComprobantePago::getSalarioNeto() const {
return salarioNeto;
}

string ComprobantePago::toString() const {
stringstream ss;
ss << fixed << setprecision(2);
ss << "----------------------------------------\n";
ss << "COMPROBANTE DE PAGO: " << idComprobante << " | Fecha: " << fecha << "\n";
ss << "Empleado: " << (empleado != nullptr ? empleado->getNombre() + " (" + empleado->getCedula() + ")" : "N/A") << "\n";
ss << "Departamento: " << (departamento != nullptr ? departamento->getNombre() : "N/A") << "\n";
ss << "Salario Bruto:  " << salarioBruto << "\n";
ss << "Bonificaciones: " << bonificaciones << "\n";
ss << "Deducciones:   -" << deducciones << "\n";
ss << "SALARIO NETO:   " << salarioNeto << "\n";
ss << "----------------------------------------";
return ss.str();
}

string ComprobantePago::toStringArchivo() const {
stringstream ss;
ss << fixed << setprecision(2);
string cedEmp = (empleado != nullptr) ? empleado->getCedula() : "NONE";
string codDept = (departamento != nullptr) ? departamento->getCodigo() : "NONE";
ss << idComprobante << ";" << fecha << ";" << cedEmp << ";" << codDept << ";" << salarioBruto << ";" << bonificaciones << ";" << deducciones << ";" << salarioNeto;
return ss.str();
}
