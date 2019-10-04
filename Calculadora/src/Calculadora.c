/*
 ============================================================================
 Name        : TP1.c
 Author      : Misael Emmanuel Cortes
 Version     :
 Copyright   : Contact info misael.ec7@gmail.com
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "operacionesMatematicas.h"
#include "getNumValue.h"


#define FLUSH __fpurge(stdin); //Para no escribir la funcion entera


int main(void)
{
	//Declaracion de variables
	float operaA=0;
	float operaB=0;
	float result=0;
	long resultA=0;
	long resultB=0;
	int operacionMat=0;

	//Ingresar operandos
	printf("Ingrese primer operando:\t");
	getFloatUTN(&operaA);
	printf("Ingrese segundo operando:\t");
	getFloatUTN(&operaB);

	//Mensaje menu
	printf("Los operadores ingresados son %f y %f para A y B respectivamente.\n ",operaA,operaB);
	printf("Ingrese la operación matemática a realizar:\n 1=Suma \n 2=Resta \n 3=Division \n 4=Multiplicacion"
			" \n 5=Factorial.\n ");

	//Menu operaciones
	scanf("%d",&operacionMat);
	switch(operacionMat)
	{
		//sumar
		case 1:
			operacionSuma(&operaA,&operaB,&result);
			printf("El resultado de A: %f + B: %f es %f ",operaA,operaB,result);
			break;
		//restar
		case 2:
			operacionResta(&operaA,&operaB,&result);
			printf("El resultado de A: %f - B: %f es %f ",operaA,operaB,result);
			break;
		//dividir
		case 3:
			if(operacionDiv(&operaA,&operaB,&result)==0)
			{
				printf("El resultado de A: %f / B: %f es %f ",operaA,operaB,result);
				break;
			}
			else
			{
				printf("\n Saliendo del programa");
				break;
			}
		//multiplicar
		case 4:
			operacionMult(&operaA,&operaB,&result);
			printf("El resultado de A: %f * B: %f es %f ",operaA,operaB,result);
			break;
		//factorial
		case 5:
			operacionFact(&operaA,&operaB,&resultA,&resultB);
			//Comprobacion vectorial positivo
			if(!(resultA==0 || resultB==0))
			{
				printf("El factorial de %f es: %ld \nEl factorial de %f es: %ld ",operaA,resultA,operaB,resultB);
			}
			break;
		//opcion incorrecta
		default:
			printf("Opcion invalida, saliendo del programa");
			break;

	}
	return 0;

}
