/*
 * ingresoInt.c
 *
 *  Created on: 5 sep. 2019
 *      Author: Misael Emmanuel Cortes
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define FLUSH __fpurge(stdin);


int getFloatUTN(float * floatInput)
{
	float buffer = 0; //Valor para verificar ingresos previo a mandar al puntero
	//Recibe ingreso del usuario por scanf y verifica que se haya ingresado un valor valido por la funcion
	while (!(scanf("%f",&buffer)==1))
	{
		printf("Error, debe ingresar un numero\n");
		FLUSH;
	}
	*floatInput = buffer;
	return 0;
}



