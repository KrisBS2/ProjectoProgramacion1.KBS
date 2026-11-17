#include "ListaComprobantes.h"

using namespace std;

ListaComprobantes::ListaComprobantes() : primero(nullptr), cantidad(0) {}

ListaComprobantes::~ListaComprobantes() {
NodoComprobante* actual = primero;
while (actual != nullptr) {
NodoComprobante* siguiente = actual->getSiguiente();
delete actual;
actual = siguiente;
}
primero = nullptr;
cantidad = 0;
}

bool ListaComprobantes::estaVacia() const {
return primero == nullptr;
}

int ListaComprobantes::getCantidad() const {
return cantidad;
}

NodoComprobante* ListaComprobantes::getPrimero() const {
return primero;
}

void ListaComprobantes::insertarFinal(ComprobantePago* comprobante) {
if (comprobante == nullptr) return;
NodoComprobante* nuevo = new NodoComprobante(comprobante, nullptr);
if (estaVacia()) {
primero = nuevo;
} else {
NodoComprobante* actual = primero;
while (actual->getSiguiente() != nullptr) {
actual = actual->getSiguiente();
}
actual->setSiguiente(nuevo);
}
cantidad++;
}

ComprobantePago* ListaComprobantes::buscarPorId(const string& id) const {
NodoComprobante* actual = primero;
while (actual != nullptr) {
if (actual->getDato()->getIdComprobante() == id) {
return actual->getDato();
}
actual = actual->getSiguiente();
}
return nullptr;
}

string ListaComprobantes::toString() const {
stringstream ss;
if (estaVacia()) {
ss << "No hay comprobantes de planilla registrados.\n";
return ss.str();
}
NodoComprobante* actual = primero;
while (actual != nullptr) {
ss << actual->getDato()->toString() << "\n";
actual = actual->getSiguiente();
}
return ss.str();
}
