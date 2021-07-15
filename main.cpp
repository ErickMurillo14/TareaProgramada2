#pragma once

#include<stdio.h>
#include <tchar.h>
#include <string>
#include<iostream>
#include <Windows.h>
#include "immintrin.h"


using namespace std; 

extern "C" float* SumProc(float* vector1, float* vector2, float* punteroResultado);
extern "C" float* MultiScalarProc(float escalar, float* vector, float* punteroResultado);
extern "C" float* RestProc(float* vector1, float* vector2, float* punteroResultado);
extern "C" float* DivProc(float* vector1, float* vector2, float* punteroResultado);
extern "C" float* MultiProc(float* vector1, float* vector2, float* punteroResultado);

//extern "C" float* ADICIONALPROC(float * vector1, float* vector2, float* punteroResultado);

void imprimirResultado(float* resultado, int size, string operacion) {
	cout << operacion << endl;

	std::string salida;
	cout << "{";
	for (int i = 0; i < size - 1; i++) {
		salida += to_string(resultado[i]);
		salida += ',';
	}
	salida += to_string(resultado[size - 1]);
	cout << salida << "}";

	cout << "\n\n";
}

/*
* Checks wether a string is a number or not, recieves the string as a parameter.
* Returns a boolean true if the string is a number, false if not.
*/
bool isNumber(std::string number) {
	bool isNumber = true;
	size_t index = 0;
	while (index < number.size() && isNumber != false) { // Traverse de string 
		if (std::isdigit(number[index]) != 0) { // checks if the char is a number
			index++;
		}
		else {
			if (number[index] == '.') {
				index++;
			}
			else {
				isNumber = false;
			}
			
		}
	}
	return isNumber;
}


void cambiarValores(float vector1[],float vector2[]) {
	string inNumber = "";
	int enteredCounter = 0;
	cout << "\nIngrese los valores del primer vector, ingrese una letra para pasar al siguiente vector: \n";
	while (enteredCounter < 4) {
		cin >> inNumber;
		if (isNumber(inNumber)) {
			vector1[enteredCounter] = stof(inNumber);
			enteredCounter++;
		}
		else {
			break;
		}
	}
	enteredCounter = 0;
	cout << "\nIngrese los valores del segundo vector, ingrese una letra para pasar al siguiente vector: \n";
	while (enteredCounter < 4) {
		cin >> inNumber;
		if (isNumber(inNumber)) {
			vector2[enteredCounter] = stof(inNumber);
			enteredCounter++;
		}
		else {
			break;
		}
	}
}

/*
* Asks the user to introduce the number of operation wanted
*/
int askForOperation() {
	string operation = "";
	cout << "\n0.Sumar vectores\n1.Restar vectores\n2.Multiplicar vectores\n3.Dividir vectrores\n4.Cambiar valores de los vectores\n5.Ver vectores actuales\n6.Salir\nIntroduzca el numero de la opcion:";
	cin >> operation;
	while (!isNumber(operation)) { //  if the given string is not a number asks for it again
		cout << "Introduzca una operacion valida!!!\n";
		cout << "\n0.Sumar vectores\n1.Restar vectores\n2.Multiplicar vectores\n3.Dividir vectrores\n4.Cambiar valores de los vectores\n5.Ver vectores actuales\n6.Salir\nIntroduzca el numero de la opcion:";
		cin >> operation;
	}
	return stoi(operation); // returns the resulting string transformed into integer
}

void mostrarVectores(float vector1[],float vector2[]) {
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

int main()
{
	float vector1[4] = {0.0,0.0,0.0,0.0};
	float vector2[4] = { 0.0,0.0,0.0,0.0 };
	
	std::cout << "Operador de vectores" << std::endl;
	int validOperation = 0;
	do {
		// shows the console menu and asks the user for the operation number
		validOperation = askForOperation();
		switch (validOperation) {
		case 0:  

			break;
		case 1: 
			
			break;
		case 2: 
			
			break;
		case 3: 
			
			break;
		case 4:
			cambiarValores(vector1, vector2);
			break;
		case 5:
			mostrarVectores(vector1, vector2);
			break;
		}
	} while (validOperation != 6);

  

	//cout << sumArr(arreglo, cantidadDeElementos) << endl; 
	return 0; 
}