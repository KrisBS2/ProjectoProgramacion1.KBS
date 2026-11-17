#include "ListaEmpleados.h"

using namespace std;

ListaEmpleados::ListaEmpleados() : primero(nullptr), cantidad(0) {}

ListaEmpleados::~ListaEmpleados() {
NodoEmpleado* actual = primero;
while (actual != nullptr) {
NodoEmpleado* siguiente = actual->getSiguiente();
delete actual;
actual = siguiente;
}
primero = nullptr;
cantidad = 0;
}

bool ListaEmpleados::estaVacia() const {
return primero == nullptr;
}

int ListaEmpleados::getCantidad() const {
return cantidad;
}

NodoEmpleado* ListaEmpleados::getPrimero() const {
return primero;
}

void ListaEmpleados::insertarFinal(Empleado* empleado) {
if (empleado == nullptr) return;
NodoEmpleado* nuevo = new NodoEmpleado(empleado, nullptr);
if (estaVacia()) {
primero = nuevo;
} else {
NodoEmpleado* actual = primero;
while (actual->getSiguiente() != nullptr) {
actual = actual->getSiguiente();
}
actual->setSiguiente(nuevo);
}
cantidad++;
}

Empleado* ListaEmpleados::buscarPorCedula(const string& cedula) const {
NodoEmpleado* actual = primero;
while (actual != nullptr) {
if (actual->getDato()->getCedula() == cedula) {
return actual->getDato();
}
actual = actual->getSiguiente();
}
return nullptr;
}

bool ListaEmpleados::eliminarPorCedula(const string& cedula) {
if (estaVacia()) return false;
NodoEmpleado* actual = primero;
NodoEmpleado* anterior = nullptr;
while (actual != nullptr) {
if (actual->getDato()->getCedula() == cedula) {
if (anterior == nullptr) {
primero = actual->getSiguiente();
} else {
anterior->setSiguiente(actual->getSiguiente());
}
delete actual;
cantidad--;
return true;
}
anterior = actual;
actual = actual->getSiguiente();
}
return false;
}

string ListaEmpleados::toString() const {
stringstream ss;
if (estaVacia()) {
ss << "No hay empleados registrados.\n";
return ss.str();
}
NodoEmpleado* actual = primero;
while (actual != nullptr) {
ss << "========================================\n";
ss << actual->getDato()->toString() << "\n";
actual = actual->getSiguiente();
}
ss << "========================================\n";
return ss.str();
}
