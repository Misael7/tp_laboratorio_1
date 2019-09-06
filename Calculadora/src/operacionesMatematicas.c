/*
 * operacionesMatematicas.c
 *
 *  Created on: Aug 31, 2019
 *      Author: Misael Emmanuel Cortes
 */
#include <stdio.h>
#include <stdlib.h>

int operacionSuma(float* operaA, float* operaB, float* result) //Suma operandos ingresados por usuario, retorna resultado.
{
	//Verificacion de datos pasados por la funcion principal
	if(*operaA==*operaA*2/2 && *operaB==*operaB*2/2)//verifica que los operandos ingresados sean numeros
	{
		*result=*operaA+*operaB;
		return 0;
	}
	else
	{
		printf("Los valores ingresados no son validos para operar");
		return 1;
	}
}

int operacionResta(float* operaA, float* operaB, float* result) //Resta operandos ingresados por usuario, retorna resultado.
{
	//Verificacion de datos pasados por la funcion principal
		if(*operaA==*operaA*2/2 && *operaB==*operaB*2/2)//verifica que los operandos ingresados sean numeros
		{
			*result=*operaA-*operaB;
			return 0;
		}
		else
		{
			printf("Los valores ingresados no son validos para operar");
			return 1;
		}
}

int operacionDiv(float* operaA, float* operaB, float* result) //Divide operandos ingresados por usuario, retorna resultado.
{

	if(*operaB==0)
	{
		printf("ERROR MATEMATICO, NO PODES DIVIDIR POR %f",*operaB);
	}
	else
		//Verificacion de datos pasados por la funcion principal
			if(*operaA==*operaA*2/2 && *operaB==*operaB*2/2)//verifica que los operandos ingresados sean numeros
			{
				*result=*operaA / *operaB;

			}
			else
			{
				printf("Los valores ingresados no son validos para operar");
				return 1;
			}
	return 0;
}

int operacionMult(float* operaA, float* operaB, float* result) //Multiplica operandos ingresados por usuario, retorna resultado.
{
	if(*operaA==*operaA*2/2 && *operaB==*operaB*2/2)//verifica que los operandos ingresados sean numeros
		{
			*result=*operaA * *operaB;
			return 0;
		}
		else
		{
			printf("Los valores ingresados no son validos para operar");
			return 1;
		}
	return 0;
}
int operacionFact(float* operaA, float* operaB,long*resultA,long*resultB) //Retorna factorial de los numeros ingresados por usuario.
{
	//Setteo valores iniciales para los acumuladores de cada factorial, de lo contrario multiplican por 0.
	*resultA = 1;
	*resultB = 1;
	//Comprobación del valor a obtener factorial

	if(*operaA < 0 || *operaB < 0)
	{
		printf("No se puede hacer factorial de un negativo");
		return -1;
	}
	else
	{
	//las variables a y b multiplican avanzando hasta llegar al valor ingresado por el usuario, obteniendo un factorial.
	for(int a=1;a<=*operaA;a++)
	{
		*resultA= *resultA * a;
	}
	for(int b=1;b<=*operaB;b++)
	{
		*resultB=* resultB * b;
	}
	return 0;
	}
}


