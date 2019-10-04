/*
 * tpEmpleadosStruct.h
 *
 *  Created on: Oct 2, 2019
 *      Author: misael
 */

#ifndef TPEMPLEADOSSTRUCT_H_
#define TPEMPLEADOSSTRUCT_H_
#include "handyFunctions.h"

typedef struct {
	int empID;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;



#endif /* TPEMPLEADOSSTRUCT_H_ */
