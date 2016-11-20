#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <stack>


using namespace std;

typedef struct {
	int a;
	int b;
}AparB;

int p, q, e, d, m, mod;
AparB ult, penU;
int map[32];

string Encriptar(string);
string Desencriptar(string);
int get_ECode(int, int);
//int get_DCode(int);
void Euclides(int, int);
void get_Mods(int, int*, int);

void setValues() {

	cout << "Ingrese P: ";
	cin >> p;
	cout << "Ingrese Q: ";
	cin >> q;
	cout << "Ingrese E: ";
	cin >> e;

	m = (p - 1) * (q - 1);
	mod = p * q;
	penU.a = 1;
	penU.b = 0;
	ult.a = 0;
	ult.b = 1;
	Euclides(m, e);
	d = ult.b;

	return;
}

int main() {
	
	string msgE, msgD;
	int opc;

	setValues();
	
	do {

		cout << "Que desesa hacer?" << endl;
		cout << "1) Encriptar\n";
		cout << "2) Desencriptar\n";
		cout << "0) Salir" << endl;

		cin >> opc;

		switch (opc) {
		case 1:
			cout << "Ingrese el texto\n";
			getchar();
			getline(cin, msgD);
			msgE = Encriptar(msgD);
			cout << msgE << endl;
			break;
		case 2:
			cout << "Ingrese el texto codificado\n";
			getchar();
			getline(cin, msgE);
			msgD = Desencriptar(msgE);
			cout << msgD << endl;
			break;
		case 0:
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
	char c;
	int carD, i, menE, ax;
	stack<char> equis;
	
	i = 0;
	ax = mod;
	while (ax > 0) {
		i++; 
		ax /= 10;
	}


	for (int j = 0; j < msg.size(); j++) {
		c = toupper(msg[j]);
		carD = c % 64;
		menE = get_ECode(carD,e);
		while (menE > 0) {
			equis.push((menE % 10) + 48);
			menE /= 10;
		}
		for (int k = equis.size(); k < i; k++) {
			aux.push_back('0');
		}
		while (!equis.empty()) {
			aux.push_back(equis.top());
			equis.pop();
		}
		aux.push_back(' ');
	}

	return aux;
}

string Desencriptar(string msg) {
	string aux;
	int i, ax, code;

	i = 0;
	ax = mod;
	while (ax > 0) {
		i++;
		ax /= 10;
	}

	for (int j = 0; j < msg.size(); j += (i + 1)) {
		code = 0;
		for (int k = j; k < (j + i); k++) {
			code += (msg[k] - 48);
			code *= 10;
		}
		code /= 10;

		aux.push_back(get_ECode(code,d)+64);
	}

	return aux;
}

void Euclides(int a, int b) {
	AparB aux;

	if (b != 1) {
		aux.a = ult.a;
		aux.b = ult.b;

		ult.a = (penU.a + (-1 * ult.a * (a / b)));
		ult.b = (penU.b + (-1 * ult.b * (a / b)));

		penU.a = aux.a;
		penU.b = aux.b;

		Euclides(b, a%b);
	}

	return;
}

void get_Mods(int a, int *mapa, int md) {
	mapa[0] = a % md;
	for (int i = 1; i < 32; i++) {
		mapa[i] = (mapa[i - 1] * mapa[i - 1]) % md;
	}
}

int get_ECode(int a, int exp) {
	int aux = 1;
	int cont = 0;
	int i;
	get_Mods(a, map, mod);
	i = 0;
	while (i < 32 && cont < exp) {
		if ((1 << i)&exp) {
			aux = (aux * map[i]) % mod;
		}
		i++;
	}

	return aux;
}