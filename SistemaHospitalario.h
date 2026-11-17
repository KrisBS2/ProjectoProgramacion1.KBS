#ifndef SISTEMAHOSPITAL_H
#define SISTEMAHOSPITAL_H

#include "ListaDepartamentos.h"
#include "ListaEmpleados.h"
#include "ListaComprobantes.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class SistemaHospital {
private:
ListaDepartamentos* departamentos;
ListaEmpleados* empleados;
ListaComprobantes* planilla;

void guardarDepartamentos();
void cargarDepartamentos();
void guardarEmpleados();
void cargarEmpleados();
void guardarPlanilla();
void cargarPlanilla();

public:
SistemaHospital();
~SistemaHospital();

void cargarDatos();
void guardarDatos();


bool registrarDepartamento(const string& codigo, const string& nombre);
bool eliminarDepartamento(const string& codigo);
Departamento* buscarDepartamento(const string& codigo) const;
bool agregarPuestoADepartamento(const string& codDept, const string& codPuesto, const string& cargo, double salario);
bool eliminarPuestoDeDepartamento(const string& codDept, const string& codPuesto);


bool registrarEmpleado(Empleado* emp);
bool eliminarEmpleado(const string& cedula);
Empleado* buscarEmpleado(const string& cedula) const;
bool actualizarHorasExtra(const string& cedula, int nuevasHoras);


ComprobantePago* procesarPagoIndividual(const string& cedula, const string& fecha);
int procesarPlanillaGeneral(const string& fecha);

ListaDepartamentos* getDepartamentos() const;
ListaEmpleados* getEmpleados() const;
ListaComprobantes* getPlanilla() const;
};

#endif
