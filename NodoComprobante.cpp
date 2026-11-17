#include "NodoComprobante.h"

using namespace std;

NodoComprobante::NodoComprobante(ComprobantePago* dato, NodoComprobante* siguiente) : dato(dato), siguiente(siguiente) {}

NodoComprobante::~NodoComprobante() {
if (dato != nullptr) {
delete dato;
dato = nullptr;
}
}

ComprobantePago* NodoComprobante::getDato() const {
return dato;
}

NodoComprobante* NodoComprobante::getSiguiente() const {
return siguiente;
}

void NodoComprobante::setDato(ComprobantePago* dato) {
this->dato = dato;
}

void NodoComprobante::setSiguiente(NodoComprobante* siguiente) {
this->siguiente = siguiente;
}
