#include "Validador.h"

using namespace std;

void Validador::limpiarBuffer() {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Validador::leerEntero(const string& mensaje) {
int valor;
while (true) {
cout << mensaje;
if (cin >> valor) {
limpiarBuffer();
return valor;
}
cout << "Error: Debe ingresar un numero entero valido.\n";
limpiarBuffer();
}
}

int Validador::leerEnteroPositivo(const string& mensaje) {
int valor;
while (true) {
valor = leerEntero(mensaje);
if (valor >= 0) return valor;
cout << "Error: El numero no puede ser negativo.\n";
}
}

double Validador::leerDoublePositivo(const string& mensaje) {
double valor;
while (true) {
cout << mensaje;
if (cin >> valor && valor >= 0.0) {
limpiarBuffer();
return valor;
}
cout << "Error: Debe ingresar un monto numerico valido (mayor o igual a 0).\n";
limpiarBuffer();
}
}

string Validador::leerTextoNoVacio(const string& mensaje) {
string texto;
while (true) {
cout << mensaje;
getline(cin, texto);
if (!texto.empty() && texto.find(';') == string::npos && texto.find('|') == string::npos && texto.find(':') == string::npos) {
return texto;
}
cout << "Error: El texto no puede estar vacio ni contener los caracteres ';', '|' o ':'.\n";
}
}
