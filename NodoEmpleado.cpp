#include "NodoEmpleado.h"

using namespace std;

NodoEmpleado::NodoEmpleado(Empleado* dato, NodoEmpleado* siguiente) : dato(dato), siguiente(siguiente) {}

NodoEmpleado::~NodoEmpleado() {
if (dato != nullptr) {
delete dato;
dato = nullptr;
}
}

Empleado* NodoEmpleado::getDato() const {
return dato;
}

NodoEmpleado* NodoEmpleado::getSiguiente() const {
return siguiente;
}

void NodoEmpleado::setDato(Empleado* dato) {
this->dato = dato;
}

void NodoEmpleado::setSiguiente(NodoEmpleado* siguiente) {
this->siguiente = siguiente;
}
