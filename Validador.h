#ifndef VALIDADOR_H
#define VALIDADOR_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Validador {
public:
static int leerEntero(const string& mensaje);
static int leerEnteroPositivo(const string& mensaje);
static double leerDoublePositivo(const string& mensaje);
static string leerTextoNoVacio(const string& mensaje);
static void limpiarBuffer();
};

#endif
