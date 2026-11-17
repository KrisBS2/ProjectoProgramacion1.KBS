#ifndef LISTADEPARTAMENTOS_H
#define LISTADEPARTAMENTOS_H

#include "NodoDepartamento.h"
#include <string>
#include <sstream>

using namespace std;

class ListaDepartamentos {
private:
NodoDepartamento* primero;
int cantidad;

public:
ListaDepartamentos();
~ListaDepartamentos();

bool estaVacia() const;
int getCantidad() const;
NodoDepartamento* getPrimero() const;

void insertarFinal(Departamento* departamento);
Departamento* buscarPorCodigo(const string& codigo) const;
bool eliminarPorCodigo(const string& codigo);

string toString() const;
};

#endif
