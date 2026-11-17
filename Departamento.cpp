#include "Departamento.h"

using namespace std;

Departamento::Departamento(const string& codigo, const string& nombre)
    : codigo(codigo), nombre(nombre) {
    puestos = new ListaPuestos();
}

Departamento::~Departamento() {
if (puestos != nullptr) {
delete puestos;
puestos = nullptr;
}
}

string Departamento::getCodigo() const {
return codigo;
}

string Departamento::getNombre() const {
return nombre;
}

ListaPuestos* Departamento::getPuestos() const {
return puestos;
}

void Departamento::setNombre(const string& nombre) {
this->nombre = nombre;
}

bool Departamento::agregarPuesto(Puesto* puesto) {
if (puesto == nullptr) return false;
if (puestos->buscarPorCodigo(puesto->getCodigo()) != nullptr) {
delete puesto; 
return false;
}
puestos->insertarFinal(puesto);
return true;
}

bool Departamento::eliminarPuesto(const string& codigoPuesto) {
return puestos->eliminarPorCodigo(codigoPuesto);
}

Puesto* Departamento::buscarPuesto(const string& codigoPuesto) const {
return puestos->buscarPorCodigo(codigoPuesto);
}

string Departamento::toString() const {
stringstream ss;
ss << "========================================\n";
ss << "Departamento [" << codigo << "]: " << nombre << "\n";
ss << "Puestos (" << puestos->getCantidad() << "):\n";
ss << puestos->toString();
ss << "========================================";
return ss.str();
}

string Departamento::toStringArchivo() const {
stringstream ss;
ss << codigo << ";" << nombre << ";" << puestos->toStringArchivo();
return ss.str();
}
