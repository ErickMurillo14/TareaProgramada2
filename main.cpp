#pragma once

#include<stdio.h>
#include <tchar.h>

#include<iostream>
#include <Windows.h>
#include "immintrin.h"


using namespace std; 


extern "C" float* SumProc(float * puntero);


int main()
{
  float* numero = new float;

  numero = SumProc(numero);

  for (int i = 0; i < 4; i++) {
    cout << numero[i] << endl;
  }
 

    
 /// cout << numero << endl;
  

	int arreglo[5] = { 1,2,3,4,5 };

	int cantidadDeElementos = sizeof(arreglo) / sizeof(INT);

	//cout << sumArr(arreglo, cantidadDeElementos) << endl; 
	return 0; 
}