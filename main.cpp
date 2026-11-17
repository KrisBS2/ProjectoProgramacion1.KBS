#include "SistemaHospital.h"
#include "InterfazConsola.h"

using namespace std;

int main() {
SistemaHospital* sistema = new SistemaHospital();
sistema->cargarDatos();

InterfazConsola* consola = new InterfazConsola(sistema);
consola->iniciar();

delete consola;
delete sistema;

return 0;
}
