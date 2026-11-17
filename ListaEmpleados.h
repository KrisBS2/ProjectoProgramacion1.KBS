#ifndef LISTAEMPLEADOS_H
#define LISTAEMPLEADOS_H

#include "NodoEmpleado.h"
#include <string>
#include <sstream>

using namespace std;

class ListaEmpleados {
private:
NodoEmpleado* primero;
int cantidad;

public:
ListaEmpleados();
~ListaEmpleados();

bool estaVacia() const;
int getCantidad() const;
NodoEmpleado* getPrimero() const;

void insertarFinal(Empleado* empleado);
Empleado* buscarPorCedula(const string& cedula) const;
bool eliminarPorCedula(const string& cedula);

string toString() const;
};

#endif
