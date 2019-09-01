/*
 * operacionesMatematicas.c
 *
 *  Created on: Aug 31, 2019
 *      Author: misael
 */
#include <stdio.h>
#include <stdlib.h>

int operacionSuma(float* operaA, float* operaB, float* result) //Suma operandos ingresados por usuario, retorna resultado.
{
	float sumaA = *operaA;
	float sumaB = *operaB;
	float resultSuma = *result;
	resultSuma=sumaA+sumaB;
	//printf("El resultado de A: %f + B: %f es %f ",sumaA,sumaB,resultSuma);
	*result = resultSuma;
	return 0;
}

int operacionResta(float* operaA, float* operaB, float* result) //Resta operandos ingresados por usuario, retorna resultado.
{
	float restaA = *operaA;
	float restaB = *operaB;
	float resultResta = *result;
	resultResta=restaA-restaB;
	//printf("El resultado de A: %f - B: %f es %f ",restaA,restaB,resultResta);
	*result = resultResta;
	return 0;
}

int operacionDiv(float* operaA, float* operaB, float* result) //Divide operandos ingresados por usuario, retorna resultado.
{
	float divideA = *operaA;
	float divideB = *operaB;
	float resultDivide = *result;
	if(divideB == 0)
	{
		printf("ERROR MATEMATICO, NO PODES DIVIDIR POR %f",divideB);
	}
	else
	{
		resultDivide=divideA/divideB;
		//printf("El resultado de A: %f / B: %f es %f ",divideA,divideB,resultDivide);
		*result = resultDivide;
		return 0;
	}
	return -1;
}

int operacionMult(float* operaA, float* operaB, float* result) //Multiplica operandos ingresados por usuario, retorna resultado.
{
	float multA = *operaA;
	float multB = *operaB;
	float resultMult = *result;
	resultMult=multA-multB;
	//printf("El resultado de A: %f * B: %f es %f ",multA,multB,resultMult);
	*result = resultMult;
	return 0;
}
int operacionFact(float* operaA, float* operaB,long*resultA,long*resultB) //Retorna factorial de los numeros ingresados por usuario.
{
	long factA = *operaA;
	long factB = *operaB;
	//Setteo valores iniciales para los acumuladores de cada factorial, de lo contrario multiplican por 0.
	long resultFactA = 1;
	long resultFactB = 1;
	//Comprobación del valor a obtener factorial

	if(factA < 0 || factB < 0)
	{
		printf("No se puede hacer factorial de un negativo");
		return -1;
	}
	else
	{
	//las variables a y b multiplican avanzando hasta llegar al valor ingresado por el usuario, obteniendo un factorial.
	for(int a=1;a<=factA;a++)
	{
		resultFactA=resultFactA*a;
	}
	for(int b=1;b<=factB;b++)
	{
		resultFactB=resultFactB*b;
	}
	*resultA=resultFactA;
	*resultB=resultFactB;
	//printf("El factorial de %f es: %f \nEl factorial de %f es: %f ",factA,resultFactA,factB,resultFactB);

	return 0;
	}
}


