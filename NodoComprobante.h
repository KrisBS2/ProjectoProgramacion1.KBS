#ifndef NODOCOMPROBANTE_H
#define NODOCOMPROBANTE_H

#include "ComprobantePago.h"

using namespace std;

class NodoComprobante {
private:
ComprobantePago* dato;
NodoComprobante* siguiente;

public:
NodoComprobante(ComprobantePago* dato, NodoComprobante* siguiente = nullptr);
~NodoComprobante();

ComprobantePago* getDato() const;
NodoComprobante* getSiguiente() const;

void setDato(ComprobantePago* dato);
void setSiguiente(NodoComprobante* siguiente);
};

#endif
