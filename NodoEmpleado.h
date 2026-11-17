#ifndef NODOEMPLEADO_H
#define NODOEMPLEADO_H

#include "Empleado.h"
using namespace std;

class NodoEmpleado {
private:
Empleado* dato;
NodoEmpleado* siguiente;

public:
NodoEmpleado(Empleado* dato, NodoEmpleado* siguiente = nullptr);
~NodoEmpleado();

Empleado* getDato() const;
NodoEmpleado* getSiguiente() const;

void setDato(Empleado* dato);
void setSiguiente(NodoEmpleado* siguiente);
};

#endif
