#ifndef LISTAPUESTOS_H
#define LISTAPUESTOS_H

#include "NodoPuesto.h"
#include <string>
#include <sstream>

using namespace std;

class ListaPuestos {
private:
NodoPuesto* primero;
int cantidad;

public:
ListaPuestos();
~ListaPuestos();

bool estaVacia() const;
int getCantidad() const;
NodoPuesto* getPrimero() const;

void insertarFinal(Puesto* puesto);
Puesto* buscarPorCodigo(const string& codigo) const;
bool eliminarPorCodigo(const string& codigo);

string toString() const;
string toStringArchivo() const;
};

#endif
