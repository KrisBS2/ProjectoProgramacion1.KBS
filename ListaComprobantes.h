#ifndef LISTACOMPROBANTES_H
#define LISTACOMPROBANTES_H

#include "NodoComprobante.h"
#include <string>
#include <sstream>

using namespace std;

class ListaComprobantes {
private:
NodoComprobante* primero;
int cantidad;

public:
ListaComprobantes();
~ListaComprobantes();

bool estaVacia() const;
int getCantidad() const;
NodoComprobante* getPrimero() const;

void insertarFinal(ComprobantePago* comprobante);
ComprobantePago* buscarPorId(const string& id) const;

string toString() const;
};

#endif
