#include "NodoDepartamento.h"

using namespace std;

NodoDepartamento::NodoDepartamento(Departamento* dato, NodoDepartamento* siguiente) : dato(dato), siguiente(siguiente) {}

NodoDepartamento::~NodoDepartamento() {
if (dato != nullptr) {
delete dato;
dato = nullptr;
}
}

Departamento* NodoDepartamento::getDato() const {
return dato;
}

NodoDepartamento* NodoDepartamento::getSiguiente() const {
return siguiente;
}

void NodoDepartamento::setDato(Departamento* dato) {
this->dato = dato;
}

void NodoDepartamento::setSiguiente(NodoDepartamento* siguiente) {
this->siguiente = siguiente;
}
