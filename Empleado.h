#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Departamento.h"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Empleado {
protected:
string cedula;
string nombre;
double salarioBase;
int horasExtra;
Departamento* departamento; 

public:
Empleado(const string& cedula, const string& nombre, double salarioBase, int horasExtra, Departamento* departamento);
virtual ~Empleado();

string getCedula() const;
string getNombre() const;
double getSalarioBase() const;
int getHorasExtra() const;
Departamento* getDepartamento() const;

void setNombre(const string& nombre);
void setSalarioBase(double salarioBase);
void setHorasExtra(int horasExtra);
void setDepartamento(Departamento* departamento);


double calcularPagoHorasExtra() const;
virtual double calcularBonificaciones() const = 0;
double calcularSalarioBruto() const;
double calcularDeducciones() const;
double calcularSalarioNeto() const;

virtual string obtenerTipo() const = 0;
virtual string toString() const;
virtual string toStringArchivo() const = 0;
};

#endif
