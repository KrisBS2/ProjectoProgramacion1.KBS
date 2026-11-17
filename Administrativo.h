#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include "Empleado.h"

using namespace std;

class Administrativo : public Empleado {
private:
string cargoAdministrativo;
double bonoProductividad;

public:
Administrativo(const string& cedula, const string& nombre, double salarioBase, int horasExtra, Departamento* departamento, const string& cargoAdministrativo, double bonoProductividad);
virtual ~Administrativo();

string getCargoAdministrativo() const;
double getBonoProductividad() const;

void setCargoAdministrativo(const string& cargoAdministrativo);
void setBonoProductividad(double bonoProductividad);

double calcularBonificaciones() const override;
string obtenerTipo() const override;
string toString() const override;
string toStringArchivo() const override;
};

#endif
