#ifndef NODODEPARTAMENTO_H
#define NODODEPARTAMENTO_H

#include "Departamento.h"

using namespace std;

class NodoDepartamento {
private:
Departamento* dato;
NodoDepartamento* siguiente;

public:
NodoDepartamento(Departamento* dato, NodoDepartamento* siguiente = nullptr);
~NodoDepartamento();

Departamento* getDato() const;
NodoDepartamento* getSiguiente() const;

void setDato(Departamento* dato);
void setSiguiente(NodoDepartamento* siguiente);
};

#endif
