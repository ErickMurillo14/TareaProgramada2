// TareaProgramada2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#pragma once

#include<iostream>

#include <string>

using namespace std;


extern "C" float* SumProc(float* vector1, float* vector2, float* punteroResultado);
extern "C" float* MultiScalarProc(float escalar, float* vector, float* punteroResultado);
extern "C" float* RestProc(float* vector1, float* vector2, float* punteroResultado);
extern "C" float* DivProc(float* vector1, float* vector2, float* punteroResultado);
extern "C" float* MultiProc(float* vector1, float* vector2, float* punteroResultado);
extern "C" float* SquareProc(float* vector1, float* punteroResultado);

// Muestra los dos vectores que recibe por parametros
void mostrarVectores(float vector1[], float vector2[]) {
	cout << "\nPrimer vector: { ";
	for (int i = 0; i < 4; i++) {
		cout << vector1[i] << ", ";
	}
	cout << "}\n\n";
	cout << "Segundo vector: { ";
	for (int i = 0; i < 4; i++) {
		cout << vector2[i] << ", ";
	}
	cout << "}\n\n";
}

/*Muestra el resultado de las operaciones, recibe por parametro el resultado, el tama�o de los vectores
* ,un string para describir cual operacion se hizo y los 2 vectores
*/
void imprimirResultado(float* resultado, int size, string operacion, float* vector1, float* vector2) {
	mostrarVectores(vector1, vector2);
	cout << operacion << endl;
	std::string salida;
	cout << "{";
	for (int i = 0; i < size - 1; i++) {
		salida += to_string(resultado[i]);
		salida += ',';
	}
	salida += to_string(resultado[size - 1]);
	cout << salida << "}";

	cout << "\n";
}

// Comprueba si el string recibido por parametro es numero o no
bool esNumero(std::string numero) {
	bool esNumero = true;
	size_t index = 0;
	while (index < numero.size() && esNumero != false) {
		if (std::isdigit(numero[index]) != 0) {
			index++;
		}
		else {
			if (numero[index] == '.') {
				index++;
			}
			else {
				esNumero = false;
			}

		}
	}
	return esNumero;
}

// Pide al usuario que ingrese nuevos valores para los vectores recibidos por parametros
void cambiarValores(float vector1[], float vector2[]) {
	string numero = "";
	int enteredCounter = 0;
	cout << "\nIngrese los valores del primer vector, ingrese una letra para pasar al siguiente vector: \n";
	while (enteredCounter < 4) {
		cin >> numero;
		if (esNumero(numero)) {
			vector1[enteredCounter] = stof(numero);
			enteredCounter++;
		}
		else {
			break;
		}
	}
	enteredCounter = 0;
	cout << "\nIngrese los valores del segundo vector, ingrese una letra para pasar al siguiente vector: \n";
	while (enteredCounter < 4) {
		cin >> numero;
		if (esNumero(numero)) {
			vector2[enteredCounter] = stof(numero);
			enteredCounter++;
		}
		else {
			break;
		}
	}
}

// Muestra al usuario el menu, y a su vez le hace elegir la operacion que desea realizar
int pedirOperacion() {
	string operation = "";
	cout << "\n0.Sumar vectores\n1.Restar vectores\n2.Multiplicar vectores\n3.Dividir vectores\n4.Multiplicacion por un escalar";
	cout << "\n5.Elevar al cuadrado\n6.Cambiar valores de los vectores\n7.Ver vectores actuales\n8.Salir\nIntroduzca el numero de la opcion:";
	cin >> operation;
	while (!esNumero(operation)) {
		cout << "Introduzca una operacion valida!!!\n";
		cout << "\n0.Sumar vectores\n1.Restar vectores\n2.Multiplicar vectores\n3.Dividir vectores\n4.Multiplicacion por un escalar(vector1)";
		cout << "\n5.Elevar al cuadrado(vector1)\n6.Cambiar valores de los vectores\n7.Ver vectores actuales\n8.Salir\nIntroduzca el numero de la opcion:";
		cin >> operation;
	}
	return stoi(operation);
}

// Pide al usuario un numero escalar, para la operacion de multiplicar un vector por un escalar
float pedirEscalar() {
	string escalar = "0.0";
	cout << "Introduzca el escalar: ";
	cin >> escalar;
	while (!esNumero(escalar)) {
		cout << "!!Introduzca un numero valido: ";
		cin >> escalar;
	}
	return stof(escalar);
}

// Pide al usuario que elija un vector para realizar una operacion
float* elegirVector(float* vector1, float* vector2) {
	string opcion = "";
	cout << "Elija a que vector desea realizarle dicha operacion: ";
	cout << "\nPrimer vector(oprima 1)";
	cout << "\nSegundo vector(oprima2)";
	cout << "\nOpcion: ";
	cin >> opcion;
	while (opcion != "1" && opcion != "2") {
		cout << "Elija una opcion valida!!!\n";
		cout << "Elija a que vector desea realizarle dicha operacion: ";
		cout << "\nPrimer vector(oprima 1)";
		cout << "\nSegundo vector(oprima2)";
		cout << "\nOpcion: ";
		cin >> opcion;
	}
	if (opcion == "1") {
		cout << "\nElegido el primer vector" << endl;
		return vector1;
	}
	else {
		cout << "\nElegido el segundo vector" << endl;
		return vector2;
	}
}

int main()
{
	float vector1[4] = { 0.0,0.0,0.0,0.0 };
	float vector2[4] = { 0.0,0.0,0.0,0.0 };
	float* resultado = new float;
	float escalar;
	std::cout << "Operador de vectores" << std::endl;
	int validOperation = 0;
	do {
		validOperation = pedirOperacion();
		switch (validOperation) {
		case 0:
			SumProc(vector1, vector2, resultado);
			imprimirResultado(resultado, 4, "Suma", vector1, vector2);
			break;
		case 1:
			RestProc(vector1, vector2, resultado);
			imprimirResultado(resultado, 4, "Resta", vector1, vector2);
			break;
		case 2:
			MultiProc(vector1, vector2, resultado);
			imprimirResultado(resultado, 4, "Multiplicacion", vector1, vector2);
			break;
		case 3:
			DivProc(vector1, vector2, resultado);
			imprimirResultado(resultado, 4, "Division", vector1, vector2);
			break;
		case 4:
			escalar = pedirEscalar();
			MultiScalarProc(escalar, elegirVector(vector1, vector2), resultado);
			cout << "Escalar = " << escalar << endl;
			imprimirResultado(resultado, 4, "Multipliacion por escalar", vector1, vector2);
			break;
		case 5:
			SquareProc(elegirVector(vector1, vector2), resultado);
			imprimirResultado(resultado, 4, "Elevar al cuadrado", vector1, vector2);
			break;
		case 6:
			cambiarValores(vector1, vector2);
			break;
		case 7:
			mostrarVectores(vector1, vector2);
			break;
		}
	} while (validOperation != 8);
}
