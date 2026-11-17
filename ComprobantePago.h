#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H

#include "Empleado.h"
#include "Departamento.h"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class ComprobantePago {
private:
string idComprobante;
string fecha;
Empleado* empleado;
Departamento* departamento;
double salarioBruto;
double bonificaciones;
double deducciones;
double salarioNeto;

public:
ComprobantePago(const string& idComprobante, const string& fecha, Empleado* empleado, Departamento* departamento, double salarioBruto, double bonificaciones, double deducciones, double salarioNeto);
~ComprobantePago();

string getIdComprobante() const;
string getFecha() const;
Empleado* getEmpleado() const;
Departamento* getDepartamento() const;
double getSalarioBruto() const;
double getBonificaciones() const;
double getDeducciones() const;
double getSalarioNeto() const;

string toString() const;
string toStringArchivo() const;
};

#endif
