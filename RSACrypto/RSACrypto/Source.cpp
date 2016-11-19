#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>

#define p 31
#define q 23
#define e 43

using namespace std;

typedef struct {
	int a;
	int b;
}AparB;

int d, m, flg;
int nP, nQ, nE, nD;
AparB ult, penU;

string Encriptar(string);
string Desencriptar(string);

int Euclides(int a, int b) {
	if (b == 0) {
		return a;
	}
	return Euclides(b, (a%b));
}

void setValues() {
	m = (p - 1) * (q - 1);
	penU.a = 1;
	penU.b = 0;
	ult.a = 0;
	ult.b = 1;



}

int main() {
	
	string msgE, msgD;
	int opc;

	do {

		cout << "Que desesa hacer?" << endl;
		cout << "1) Encriptar\n";
		cout << "2) Desencriptar\n";
		cout << "0) Salir" << endl;

		cin >> opc;
		setValues(flg);

		switch (opc) {
		case 1:
			cout << "Ingrese el texto\n";
			getline(cin, msgD);
			msgE = Encriptar(msgD);
			break;
		case 2:
			cout << "Ingrese el texto codificado\n";
			getline(cin, msgE);
			msgD = Desencriptar(msgE);
			break;
		case 3:
			cout << "Adios\n";
			break;
		default:
			cout << "Opcion no encontrada intente de nuevo\n";
			break;
		}

	} while (opc != 0);

	return 0;
}

string Encriptar(string msg) {
	string aux;

	return aux;
}

string Desencriptar(string msg) {
	string aux;

	return aux;
}