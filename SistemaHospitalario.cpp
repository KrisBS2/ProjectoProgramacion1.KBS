#include "SistemaHospital.h"

using namespace std;

SistemaHospital::SistemaHospital() {
departamentos = new ListaDepartamentos();
empleados = new ListaEmpleados();
planilla = new ListaComprobantes();
}

SistemaHospital::~SistemaHospital() {
if (planilla != nullptr) {
delete planilla;
planilla = nullptr;
}
if (empleados != nullptr) {
delete empleados;
empleados = nullptr;
}
if (departamentos != nullptr) {
delete departamentos;
departamentos = nullptr;
}
}

void SistemaHospital::cargarDatos() {
cargarDepartamentos();
cargarEmpleados();
cargarPlanilla();
}

void SistemaHospital::guardarDatos() {
guardarDepartamentos();
guardarEmpleados();
guardarPlanilla();
}

void SistemaHospital::guardarDepartamentos() {
ofstream archivo("departamentos.txt");
if (!archivo.is_open()) return;
NodoDepartamento* actual = departamentos->getPrimero();
while (actual != nullptr) {
archivo << actual->getDato()->toStringArchivo() << "\n";
actual = actual->getSiguiente();
}
archivo.close();
}

void SistemaHospital::cargarDepartamentos() {
ifstream archivo("departamentos.txt");
if (!archivo.is_open()) return;
string linea;
while (getline(archivo, linea)) {
if (linea.empty()) continue;
stringstream ss(linea);
string codDept, nomDept, cadenaPuestos;
getline(ss, codDept, ';');
getline(ss, nomDept, ';');
getline(ss, cadenaPuestos);
Departamento* dept = new Departamento(codDept, nomDept);
if (!cadenaPuestos.empty()) {
stringstream ssPuestos(cadenaPuestos);
string itemPuesto;
while (getline(ssPuestos, itemPuesto, '|')) {
if (itemPuesto.empty()) continue;
stringstream ssDetalle(itemPuesto);
string codP, cargoP, salStr;
getline(ssDetalle, codP, ':');
getline(ssDetalle, cargoP, ':');
getline(ssDetalle, salStr, ':');
double sal = stod(salStr);
dept->agregarPuesto(new Puesto(codP, cargoP, sal));
}
}
departamentos->insertarFinal(dept);
}
archivo.close();
}

void SistemaHospital::guardarEmpleados() {
ofstream archivo("empleados.txt");
if (!archivo.is_open()) return;
NodoEmpleado* actual = empleados->getPrimero();
while (actual != nullptr) {
archivo << actual->getDato()->toStringArchivo() << "\n";
actual = actual->getSiguiente();
}
archivo.close();
}

void SistemaHospital::cargarEmpleados() {
ifstream archivo("empleados.txt");
if (!archivo.is_open()) return;
string linea;
while (getline(archivo, linea)) {
if (linea.empty()) continue;
stringstream ss(linea);
string tipo, cedula, nombre, salStr, hrsStr, codDept;
getline(ss, tipo, ';');
getline(ss, cedula, ';');
getline(ss, nombre, ';');
getline(ss, salStr, ';');
getline(ss, hrsStr, ';');
getline(ss, codDept, ';');
double salBase = stod(salStr);
int hrsExtra = stoi(hrsStr);
Departamento* dept = (codDept != "NONE") ? departamentos->buscarPorCodigo(codDept) : nullptr;
if (tipo == "MEDICO") {
string esp, guardiasStr;
getline(ss, esp, ';');
getline(ss, guardiasStr, ';');
int guardias = stoi(guardiasStr);
empleados->insertarFinal(new Medico(cedula, nombre, salBase, hrsExtra, dept, esp, guardias));
} else if (tipo == "ENFERMERO") {
string turnosStr, area;
getline(ss, turnosStr, ';');
getline(ss, area, ';');
int turnos = stoi(turnosStr);
empleados->insertarFinal(new Enfermero(cedula, nombre, salBase, hrsExtra, dept, turnos, area));
} else if (tipo == "ADMIN") {
string cargo, bonoStr;
getline(ss, cargo, ';');
getline(ss, bonoStr, ';');
double bono = stod(bonoStr);
empleados->insertarFinal(new Administrativo(cedula, nombre, salBase, hrsExtra, dept, cargo, bono));
}
}
archivo.close();
}

void SistemaHospital::guardarPlanilla() {
ofstream archivo("planilla.txt");
if (!archivo.is_open()) return;
NodoComprobante* actual = planilla->getPrimero();
while (actual != nullptr) {
archivo << actual->getDato()->toStringArchivo() << "\n";
actual = actual->getSiguiente();
}
archivo.close();
}

void SistemaHospital::cargarPlanilla() {
ifstream archivo("planilla.txt");
if (!archivo.is_open()) return;
string linea;
while (getline(archivo, linea)) {
if (linea.empty()) continue;
stringstream ss(linea);
string idComp, fecha, cedEmp, codDept, brutoStr, bonosStr, dedStr, netoStr;
getline(ss, idComp, ';');
getline(ss, fecha, ';');
getline(ss, cedEmp, ';');
getline(ss, codDept, ';');
getline(ss, brutoStr, ';');
getline(ss, bonosStr, ';');
getline(ss, dedStr, ';');
getline(ss, netoStr, ';');
Empleado* emp = empleados->buscarPorCedula(cedEmp);
Departamento* dept = departamentos->buscarPorCodigo(codDept);
double bruto = stod(brutoStr);
double bonos = stod(bonosStr);
double ded = stod(dedStr);
double neto = stod(netoStr);
planilla->insertarFinal(new ComprobantePago(idComp, fecha, emp, dept, bruto, bonos, ded, neto));
}
archivo.close();
}

bool SistemaHospital::registrarDepartamento(const string& codigo, const string& nombre) {
if (departamentos->buscarPorCodigo(codigo) != nullptr) return false;
departamentos->insertarFinal(new Departamento(codigo, nombre));
guardarDepartamentos();
return true;
}

bool SistemaHospital::eliminarDepartamento(const string& codigo) {
Departamento* dept = departamentos->buscarPorCodigo(codigo);
if (dept == nullptr) return false;
NodoEmpleado* actual = empleados->getPrimero();
while (actual != nullptr) {
if (actual->getDato()->getDepartamento() == dept) {
actual->getDato()->setDepartamento(nullptr);
}
actual = actual->getSiguiente();
}
bool eliminado = departamentos->eliminarPorCodigo(codigo);
if (eliminado) {
guardarDepartamentos();
guardarEmpleados();
}
return eliminado;
}

Departamento* SistemaHospital::buscarDepartamento(const string& codigo) const {
return departamentos->buscarPorCodigo(codigo);
}

bool SistemaHospital::agregarPuestoADepartamento(const string& codDept, const string& codPuesto, const string& cargo, double salario) {
Departamento* dept = departamentos->buscarPorCodigo(codDept);
if (dept == nullptr) return false;
bool agregado = dept->agregarPuesto(new Puesto(codPuesto, cargo, salario));
if (agregado) guardarDepartamentos();
return agregado;
}

bool SistemaHospital::eliminarPuestoDeDepartamento(const string& codDept, const string& codPuesto) {
Departamento* dept = departamentos->buscarPorCodigo(codDept);
if (dept == nullptr) return false;
bool eliminado = dept->eliminarPuesto(codPuesto);
if (eliminado) guardarDepartamentos();
return eliminado;
}

bool SistemaHospital::registrarEmpleado(Empleado* emp) {
if (emp == nullptr) return false;
if (empleados->buscarPorCedula(emp->getCedula()) != nullptr) {
delete emp;
return false;
}
empleados->insertarFinal(emp);
guardarEmpleados();
return true;
}

bool SistemaHospital::eliminarEmpleado(const string& cedula) {
bool eliminado = empleados->eliminarPorCedula(cedula);
if (eliminado) guardarEmpleados();
return eliminado;
}

Empleado* SistemaHospital::buscarEmpleado(const string& cedula) const {
return empleados->buscarPorCedula(cedula);
}

bool SistemaHospital::actualizarHorasExtra(const string& cedula, int nuevasHoras) {
Empleado* emp = empleados->buscarPorCedula(cedula);
if (emp == nullptr || nuevasHoras < 0) return false;
emp->setHorasExtra(nuevasHoras);
guardarEmpleados();
return true;
}

ComprobantePago* SistemaHospital::procesarPagoIndividual(const string& cedula, const string& fecha) {
Empleado* emp = empleados->buscarPorCedula(cedula);
if (emp == nullptr) return nullptr;
stringstream ssId;
ssId << "COMP-" << (planilla->getCantidad() + 1);
double bruto = emp->calcularSalarioBruto();
double bonos = emp->calcularBonificaciones();
double ded = emp->calcularDeducciones();
double neto = emp->calcularSalarioNeto();
ComprobantePago* comp = new ComprobantePago(ssId.str(), fecha, emp, emp->getDepartamento(), bruto, bonos, ded, neto);
planilla->insertarFinal(comp);
guardarPlanilla();
return comp;
}

int SistemaHospital::procesarPlanillaGeneral(const string& fecha) {
if (empleados->estaVacia()) return 0;
int procesados = 0;
NodoEmpleado* actual = empleados->getPrimero();
while (actual != nullptr) {
Empleado* emp = actual->getDato();
stringstream ssId;
ssId << "COMP-" << (planilla->getCantidad() + 1);
double bruto = emp->calcularSalarioBruto();
double bonos = emp->calcularBonificaciones();
double ded = emp->calcularDeducciones();
double neto = emp->calcularSalarioNeto();
ComprobantePago* comp = new ComprobantePago(ssId.str(), fecha, emp, emp->getDepartamento(), bruto, bonos, ded, neto);
planilla->insertarFinal(comp);
procesados++;
actual = actual->getSiguiente();
}
guardarPlanilla();
return procesados;
}

ListaDepartamentos* SistemaHospital::getDepartamentos() const {
return departamentos;
}

ListaEmpleados* SistemaHospital::getEmpleados() const {
return empleados;
}

ListaComprobantes* SistemaHospital::getPlanilla() const {
return planilla;
}
