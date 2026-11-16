#include "NodoPuesto.h"

using namespace std;

NodoPuesto::NodoPuesto(Puesto* dato, NodoPuesto* siguiente): dato(dato), siguiente(siguiente) {}

NodoPuesto::~NodoPuesto() {

if (dato != nullptr) {
delete dato;
dato = nullptr;
}
}

Puesto* NodoPuesto::getDato() const {
return dato;
}

NodoPuesto* NodoPuesto::getSiguiente() const {
return siguiente;
}

void NodoPuesto::setDato(Puesto* dato) {
this->dato = dato;
}

void NodoPuesto::setSiguiente(NodoPuesto* siguiente) {
this->siguiente = siguiente;
}
