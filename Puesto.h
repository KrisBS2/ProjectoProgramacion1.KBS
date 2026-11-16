#ifndef PUESTO_H
#define PUESTO_H

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Puesto {
private:
string codigo;
string nombreCargo;
double salarioBaseSugerido;

public:
Puesto(const string& codigo, const string& nombreCargo, double salarioBaseSugerido);
~Puesto();

string getCodigo() const;
string getNombreCargo() const;
double getSalarioBaseSugerido() const;

void setNombreCargo(const string& nombreCargo);
void setSalarioBaseSugerido(double salarioBaseSugerido);

string toString() const;
string toStringArchivo() const;
};
#endif
