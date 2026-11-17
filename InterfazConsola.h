#ifndef INTERFAZCONSOLA_H
#define INTERFAZCONSOLA_H

#include "SistemaHospital.h"
#include "Validador.h"
#include <iostream>

using namespace std;

class InterfazConsola {
private:
SistemaHospital* sistema;

void menuDepartamentos();
void menuEmpleados();
void menuPlanilla();

void registrarDepartamentoUI();
void agregarPuestoUI();
void registrarEmpleadoUI();
void actualizarHorasUI();

public:
InterfazConsola(SistemaHospital* sistema);
~InterfazConsola();

void iniciar();
};

#endif
