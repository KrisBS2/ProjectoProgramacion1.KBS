#include "ListaDepartamentos.h"

using namespace std;

ListaDepartamentos::ListaDepartamentos() : primero(nullptr), cantidad(0) {}

ListaDepartamentos::~ListaDepartamentos() {
NodoDepartamento* actual = primero;
while (actual != nullptr) {
NodoDepartamento* siguiente = actual->getSiguiente();
delete actual;
actual = siguiente;
}
primero = nullptr;
cantidad = 0;
}

bool ListaDepartamentos::estaVacia() const {
return primero == nullptr;
}

int ListaDepartamentos::getCantidad() const {
return cantidad;
}

NodoDepartamento* ListaDepartamentos::getPrimero() const {
return primero;
}

void ListaDepartamentos::insertarFinal(Departamento* departamento) {
if (departamento == nullptr) return;
NodoDepartamento* nuevo = new NodoDepartamento(departamento, nullptr);
if (estaVacia()) {
primero = nuevo;
} else {
NodoDepartamento* actual = primero;
while (actual->getSiguiente() != nullptr) {
actual = actual->getSiguiente();
}
actual->setSiguiente(nuevo);
}
cantidad++;
}

Departamento* ListaDepartamentos::buscarPorCodigo(const string& codigo) const {
NodoDepartamento* actual = primero;
while (actual != nullptr) {
if (actual->getDato()->getCodigo() == codigo) {
return actual->getDato();
}
actual = actual->getSiguiente();
}
return nullptr;
}

bool ListaDepartamentos::eliminarPorCodigo(const string& codigo) {
if (estaVacia()) return false;
NodoDepartamento* actual = primero;
NodoDepartamento* anterior = nullptr;
while (actual != nullptr) {
if (actual->getDato()->getCodigo() == codigo) {
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

string ListaDepartamentos::toString() const {
stringstream ss;
if (estaVacia()) {
ss << "No hay departamentos registrados.\n";
return ss.str();
}
NodoDepartamento* actual = primero;
while (actual != nullptr) {
ss << actual->getDato()->toString() << "\n";
actual = actual->getSiguiente();
}
return ss.str();
}
