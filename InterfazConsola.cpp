#include "InterfazConsola.h"

using namespace std;

InterfazConsola::InterfazConsola(SistemaHospital* sistema) : sistema(sistema) {}

InterfazConsola::~InterfazConsola() {
sistema = nullptr;
}

void InterfazConsola::iniciar() {
int opcion = -1;
while (opcion != 0) {
cout << "\n=============================================\n";
cout << "   SISTEMA DE GESTION DE PLANILLA HOSPITAL   \n";
cout << "=============================================\n";
cout << "1. Gestion de Departamentos y Puestos\n";
cout << "2. Gestion de Personal (Empleados)\n";
cout << "3. Gestion de Planilla y Pagos\n";
cout << "0. Guardar y Salir\n";
cout << "=============================================\n";
opcion = Validador::leerEntero("Seleccione una opcion: ");

switch (opcion) {
case 1:
menuDepartamentos();
break;
case 2:
menuEmpleados();
break;
case 3:
menuPlanilla();
break;
case 0:
sistema->guardarDatos();
cout << "Datos guardados correctamente. Saliendo del sistema...\n";
break;
default:
cout << "Opcion invalida. Intente nuevamente.\n";
break;
}
}
}

void InterfazConsola::menuDepartamentos() {
int opcion = -1;
while (opcion != 0) {
cout << "\n--- GESTION DE DEPARTAMENTOS Y PUESTOS ---\n";
cout << "1. Registrar nuevo departamento\n";
cout << "2. Agregar puesto a un departamento\n";
cout << "3. Listar departamentos y sus puestos\n";
cout << "4. Eliminar puesto de un departamento\n";
cout << "5. Eliminar departamento\n";
cout << "0. Volver al menu principal\n";
opcion = Validador::leerEntero("Seleccione una opcion: ");

switch (opcion) {
case 1:
registrarDepartamentoUI();
break;
case 2:
agregarPuestoUI();
break;
case 3:
cout << "\n" << sistema->getDepartamentos()->toString();
break;
case 4: {
string codDept = Validador::leerTextoNoVacio("Codigo del departamento: ");
string codPuesto = Validador::leerTextoNoVacio("Codigo del puesto a eliminar: ");
if (sistema->eliminarPuestoDeDepartamento(codDept, codPuesto)) {
cout << "Puesto eliminado exitosamente.\n";
} else {
cout << "No se encontro el departamento o el puesto.\n";
}
break;
}
case 5: {
string codDept = Validador::leerTextoNoVacio("Codigo del departamento a eliminar: ");
if (sistema->eliminarDepartamento(codDept)) {
cout << "Departamento y sus puestos eliminados exitosamente.\n";
} else {
cout << "No se encontro un departamento con ese codigo.\n";
}
break;
}
case 0:
break;
default:
cout << "Opcion invalida.\n";
break;
}
}
}

void InterfazConsola::registrarDepartamentoUI() {
string codigo = Validador::leerTextoNoVacio("Ingrese codigo del departamento (ej. D01): ");
string nombre = Validador::leerTextoNoVacio("Ingrese nombre del departamento: ");
if (sistema->registrarDepartamento(codigo, nombre)) {
cout << "Departamento registrado y guardado correctamente.\n";
} else {
cout << "Error: Ya existe un departamento con el codigo " << codigo << ".\n";
}
}

void InterfazConsola::agregarPuestoUI() {
string codDept = Validador::leerTextoNoVacio("Codigo del departamento: ");
Departamento* dept = sistema->buscarDepartamento(codDept);
if (dept == nullptr) {
cout << "Error: Departamento no encontrado.\n";
return;
}
string codPuesto = Validador::leerTextoNoVacio("Codigo del nuevo puesto (ej. P01): ");
string cargo = Validador::leerTextoNoVacio("Nombre del cargo: ");
double salario = Validador::leerDoublePositivo("Salario base sugerido: ");
if (sistema->agregarPuestoADepartamento(codDept, codPuesto, cargo, salario)) {
cout << "Puesto agregado al departamento " << dept->getNombre() << ".\n";
} else {
cout << "Error: Ya existe un puesto con ese codigo en este departamento.\n";
}
}

void InterfazConsola::menuEmpleados() {
int opcion = -1;
while (opcion != 0) {
cout << "\n--- GESTION DE PERSONAL ---\n";
cout << "1. Registrar nuevo empleado\n";
cout << "2. Listar todos los empleados\n";
cout << "3. Buscar empleado por cedula\n";
cout << "4. Actualizar horas extra de un empleado\n";
cout << "5. Eliminar empleado\n";
cout << "0. Volver al menu principal\n";
opcion = Validador::leerEntero("Seleccione una opcion: ");

switch (opcion) {
case 1:
registrarEmpleadoUI();
break;
case 2:
cout << "\n" << sistema->getEmpleados()->toString();
break;
case 3: {
string ced = Validador::leerTextoNoVacio("Ingrese la cedula a buscar: ");
Empleado* emp = sistema->buscarEmpleado(ced);
if (emp != nullptr) {
cout << "\n" << emp->toString() << "\n";
} else {
cout << "Empleado no encontrado.\n";
}
break;
}
case 4:
actualizarHorasUI();
break;
case 5: {
string ced = Validador::leerTextoNoVacio("Ingrese la cedula del empleado a eliminar: ");
if (sistema->eliminarEmpleado(ced)) {
cout << "Empleado eliminado correctamente.\n";
} else {
cout << "No se encontro ningun empleado con esa cedula.\n";
}
break;
}
case 0:
break;
default:
cout << "Opcion invalida.\n";
break;
}
}
}

void InterfazConsola::registrarEmpleadoUI() {
cout << "\nSeleccione el tipo de empleado:\n";
cout << "1. Medico\n";
cout << "2. Enfermero\n";
cout << "3. Administrativo\n";
int tipo = Validador::leerEntero("Tipo: ");
if (tipo < 1 || tipo > 3) {
cout << "Tipo de empleado invalido.\n";
return;
}

string cedula = Validador::leerTextoNoVacio("Cedula: ");
if (sistema->buscarEmpleado(cedula) != nullptr) {
cout << "Error: Ya existe un empleado con esa cedula.\n";
return;
}

string nombre = Validador::leerTextoNoVacio("Nombre completo: ");
string codDept = Validador::leerTextoNoVacio("Codigo del departamento asignado: ");
Departamento* dept = sistema->buscarDepartamento(codDept);
if (dept == nullptr) {
cout << "Error: El departamento " << codDept << " no existe. Creelo primero.\n";
return;
}

double salarioBase = Validador::leerDoublePositivo("Salario base: ");
int horasExtra = Validador::leerEnteroPositivo("Horas extra trabajadas: ");

Empleado* nuevo = nullptr;
if (tipo == 1) {
string especialidad = Validador::leerTextoNoVacio("Especialidad medica: ");
int guardias = Validador::leerEnteroPositivo("Cantidad de guardias: ");
nuevo = new Medico(cedula, nombre, salarioBase, horasExtra, dept, especialidad, guardias);
} else if (tipo == 2) {
int turnos = Validador::leerEnteroPositivo("Cantidad de turnos nocturnos: ");
string area = Validador::leerTextoNoVacio("Area asignada: ");
nuevo = new Enfermero(cedula, nombre, salarioBase, horasExtra, dept, turnos, area);
} else if (tipo == 3) {
string cargo = Validador::leerTextoNoVacio("Cargo administrativo: ");
double bono = Validador::leerDoublePositivo("Bono de productividad: ");
nuevo = new Administrativo(cedula, nombre, salarioBase, horasExtra, dept, cargo, bono);
}

if (sistema->registrarEmpleado(nuevo)) {
cout << "Empleado registrado y guardado exitosamente.\n";
} else {
cout << "No se pudo registrar el empleado.\n";
}
}

void InterfazConsola::actualizarHorasUI() {
string cedula = Validador::leerTextoNoVacio("Cedula del empleado: ");
int horas = Validador::leerEnteroPositivo("Nueva cantidad de horas extra: ");
if (sistema->actualizarHorasExtra(cedula, horas)) {
cout << "Horas extra actualizadas correctamente.\n";
} else {
cout << "No se encontro el empleado.\n";
}
}

void InterfazConsola::menuPlanilla() {
int opcion = -1;
while (opcion != 0) {
cout << "\n--- GESTION DE PLANILLA Y PAGOS ---\n";
cout << "1. Procesar pago individual (Generar comprobante)\n";
cout << "2. Procesar planilla general de todo el hospital\n";
cout << "3. Ver historial de comprobantes de pago\n";
cout << "0. Volver al menu principal\n";
opcion = Validador::leerEntero("Seleccione una opcion: ");

switch (opcion) {
case 1: {
string cedula = Validador::leerTextoNoVacio("Cedula del empleado a pagar: ");
string fecha = Validador::leerTextoNoVacio("Fecha de pago (DD/MM/AAAA): ");
ComprobantePago* comp = sistema->procesarPagoIndividual(cedula, fecha);
if (comp != nullptr) {
cout << "\nPago procesado exitosamente:\n" << comp->toString() << "\n";
} else {
cout << "Error: Empleado no encontrado.\n";
}
break;
}
case 2: {
string fecha = Validador::leerTextoNoVacio("Fecha de pago general (DD/MM/AAAA): ");
int total = sistema->procesarPlanillaGeneral(fecha);
if (total > 0) {
cout << "Planilla procesada exitosamente. Comprobantes generados: " << total << "\n";
} else {
cout << "No hay empleados registrados para procesar planilla.\n";
}
break;
}
case 3:
cout << "\n" << sistema->getPlanilla()->toString();
break;
case 0:
break;
default:
cout << "Opcion invalida.\n";
break;
}
}
}
