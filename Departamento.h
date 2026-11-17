#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "ListaPuestos.h"
#include <string>
#include <sstream>

using namespace std;

class Departamento {
private:
string codigo;
string nombre;
ListaPuestos* puestos; // Composición: Departamento es dueño exclusivo

public:
Departamento(const string& codigo, const string& nombre);
~Departamento();

string getCodigo() const;
string getNombre() const;
ListaPuestos* getPuestos() const;

void setNombre(const string& nombre);

bool agregarPuesto(Puesto* puesto);
bool eliminarPuesto(const string& codigoPuesto);
Puesto* buscarPuesto(const string& codigoPuesto) const;

string toString() const;
string toStringArchivo() const;
};

#endif
