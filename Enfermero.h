#ifndef ENFERMERO_H
#define ENFERMERO_H

#include "Empleado.h"

using namespace std;

class Enfermero : public Empleado {
private:
int turnosNocturnos;
string areaAsignada;

public:
Enfermero(const string& cedula, const string& nombre, double salarioBase, int horasExtra, Departamento* departamento, int turnosNocturnos, const string& areaAsignada);
virtual ~Enfermero();

int getTurnosNocturnos() const;
string getAreaAsignada() const;

void setTurnosNocturnos(int turnosNocturnos);
void setAreaAsignada(const string& areaAsignada);

double calcularBonificaciones() const override;
string obtenerTipo() const override;
string toString() const override;
string toStringArchivo() const override;
};

#endif
