/*
 * tpEmpleadosRequests.c
 *
 *  Created on: Oct 2, 2019
 *      Author: misael
 */
#include "tpEmpleadosStruct.h"
#include "tpEmpleadosRequests.h"



int startEmployee(Employee listA[],int length)
{
	if(listA!=NULL)
	{
		for(int i=0; i < length;i++)
			{
				listA[i].isEmpty=1;
			}

	}
	return 0;
}

int addEmployee(Employee listA[], int length)
{
	for(int i = 0; i<length ; i++ )
	{
		if(listA[i].isEmpty == 1)
		{
			printf("Ingrese un nombre:\n");
			getStringNames(listA[i].name);
			FLUSH;
			printf("Ingrese un apellido:\n");
			getStringNames(listA[i].lastName);
			FLUSH;
			printf("Ingrese salario:\n");
			getFloat(&listA[i].salary);
			FLUSH;
			printf("Ingrese sector:\n");
			getInt(&listA[i].sector);
			FLUSH;
			listA[i].isEmpty=0;
			listA[i].empID=i;
			break;
		}
	}

	return 0;
}

int printEmployees(Employee listA[], int length)
{
	for(int i = 0; i<length ; i++ )
	{
		if(listA[i].isEmpty==0)
		{
			printf("Nombre: %s \n",listA[i].name);
			printf("Apellido: %s \n",listA[i].lastName);
			printf("Salario: %f \n", listA[i].salary);
			printf("Sector: %d \n", listA[i].sector);
			printf("ID de empleado: %d \n", listA[i].empID);
		}
	}

	return 0;
}

int findEmployeeById(Employee listA[], int length,int idSearch)
{
	printf("\n Introduzca ID de empleado a localizar \n");
	getInt(&idSearch);
	listA[idSearch];
	printf("\nLa ID buscada corresponde a:\n");
	printEmployees(listA,length);
	return 0;
}

int removeEmployee(Employee listA[], int length,int idSearch)
{
	printf("\n Introduzca ID de empleado a dar de baja \n");
	getInt(&idSearch);
	listA[idSearch].isEmpty=1;
	return 0;
}

int modEmployee(Employee listA[],int length, int idSearch)
{
	printf("\n Introduzca ID de empleado a modificar\n");
	getInt(&idSearch);
	listA[idSearch].isEmpty=1;
	addEmployee(listA,length);
	return 0;
}

int sortEmployee(Employee listA[],int length)
{
	int i,j;
	Employee auxEmp1;
	Employee auxEmp2;

	for(i=0; i < length;i++)
	{
		for(j=i+1; j< length ; j++)
		{
			if(strcmp(listA[i].lastName,listA[j].lastName)>0)
			{
				auxEmp1 = listA[i];
				auxEmp2 = listA[j];
				listA[i] = auxEmp2;
				listA[j] = auxEmp1;
			}

			if(listA[i].sector>listA[j].sector)
			{
				auxEmp1 = listA[i];
				auxEmp2 = listA[j];
				listA[i] = auxEmp2;
				listA[j] = auxEmp1;
			}
		}

	}
	return 0;
}

int totalAverageSalary(Employee listA[],int length)
{
	float salaryAux1=0;
	float totalSalary=0;
	float salaryAverage=0;
	int salaryCounter=0;
	int aboveAverage=0;

	for(int i=0; i < length;i++)
	{
		if(listA[i].isEmpty!=1)
		{
			salaryAux1=listA[i].salary;
			totalSalary=salaryAux1 + totalSalary;
			salaryCounter++;
		}
	}
	salaryAverage=totalSalary/salaryCounter;
	for	(int i=0; i < length;i++)
	{
		if(listA[i].isEmpty!=1)
		{
			if(listA[i].salary>salaryAverage)
			{
				aboveAverage++;
			}
		}
	}
	printf("\n Salario total: %f \n Salario promedio: %f \n Empleados que superan el promedio: %d \n",totalSalary,salaryAverage,aboveAverage);
	return 0;
}
