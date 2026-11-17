#include "ListaPuestos.h"

using namespace std;

ListaPuestos::ListaPuestos() : primero(nullptr), cantidad(0) {}

ListaPuestos::~ListaPuestos() {
NodoPuesto* actual = primero;
while (actual != nullptr) {
NodoPuesto* siguiente = actual->getSiguiente();
delete actual; 
actual = siguiente;
}
primero = nullptr;
cantidad = 0;
}

bool ListaPuestos::estaVacia() const {
return primero == nullptr;
}

int ListaPuestos::getCantidad() const {
return cantidad;
}

NodoPuesto* ListaPuestos::getPrimero() const {
return primero;
}

void ListaPuestos::insertarFinal(Puesto* puesto) {
if (puesto == nullptr) return;

NodoPuesto* nuevo = new NodoPuesto(puesto, nullptr);
if (estaVacia()) {
primero = nuevo;
} else {
NodoPuesto* actual = primero;
while (actual->getSiguiente() != nullptr) {
actual = actual->getSiguiente();
}
actual->setSiguiente(nuevo);
}
cantidad++;
}

Puesto* ListaPuestos::buscarPorCodigo(const string& codigo) const {
NodoPuesto* actual = primero;
while (actual != nullptr) {
if (actual->getDato()->getCodigo() == codigo) {
return actual->getDato();
}
actual = actual->getSiguiente();
}
return nullptr;
}

bool ListaPuestos::eliminarPorCodigo(const string& codigo) {
if (estaVacia()) return false;
NodoPuesto* actual = primero;
NodoPuesto* anterior = nullptr;

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

string ListaPuestos::toString() const {
stringstream ss;
if (estaVacia()) {
ss << "  (Sin puestos registrados en este departamento)\n";
return ss.str();
}
NodoPuesto* actual = primero;
while (actual != nullptr) {
ss << actual->getDato()->toString() << "\n";
actual = actual->getSiguiente();
}
return ss.str();
}

string ListaPuestos::toStringArchivo() const {
stringstream ss;
NodoPuesto* actual = primero;
while (actual != nullptr) {
ss << actual->getDato()->toStringArchivo();
if (actual->getSiguiente() != nullptr) {
ss << "|";
}
actual = actual->getSiguiente();
}
return ss.str();
}
