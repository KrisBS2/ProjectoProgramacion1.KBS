#ifndef MEDICO_H
#define MEDICO_H

#include "Empleado.h"

using namespace std;

class Medico : public Empleado {
private:
string especialidad;
int cantidadGuardias;

public:
Medico(const string& cedula, const string& nombre, double salarioBase, int horasExtra, Departamento* departamento, const string& especialidad, int cantidadGuardias);
virtual ~Medico();

string getEspecialidad() const;
int getCantidadGuardias() const;

void setEspecialidad(const string& especialidad);
void setCantidadGuardias(int cantidadGuardias);

double calcularBonificaciones() const override;
string obtenerTipo() const override;
string toString() const override;
string toStringArchivo() const override;
};

#endif
