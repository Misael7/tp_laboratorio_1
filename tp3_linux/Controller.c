#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "handyFunctions.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	pFile = fopen(path,"r");
		if(pFile == NULL)
		{
				printf("El archivo no existe");
				exit(EXIT_FAILURE);
		}
		else
		{
			parser_EmployeeFromText(pFile, pArrayListEmployee);
		}
		fclose(pFile);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
		pFile = fopen(path,"rb");
			if(pFile == NULL)
			{
					printf("El archivo no existe");
					exit(EXIT_FAILURE);
			}
			else
			{
				parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			}
			fclose(pFile);

	return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int max = maxId(pArrayListEmployee,max);
	Employee* this=NULL;
	this = /*(Employee*)malloc(sizeof(Employee*));*/ employee_new();
	int id=0;
	char nombreStr[50];
	int horasTrabajadas=0;
	int sueldo=0;

	if(this!=NULL)
	{

		this->id = max+1;
		//Ejemplo de como cambiar set_nombre(this, auxnombre);
		printf("Ingrese Nombre: \n");
		scanf("%s",this->nombre);
		printf("Ingrese Horas Trabajadas: \n");
		scanf("%d",&this->horasTrabajadas);
		printf("Ingrese Sueldo: \n");
		scanf("%d",&this->sueldo);

		ll_add(pArrayListEmployee, this);
	}

	return this;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int index=0;
	Employee* this;
	printf("Introducir ID de empleado \n");
	FLUSH;
	scanf("%d",&index);
	FLUSH;

	for(int i =0 ; i <ll_len(pArrayListEmployee); i++)
	{
		this=ll_get(pArrayListEmployee, i);
		if(index == this->id)
		{
			printf("Ingrese Nombre: \n");
			scanf("%s",this->nombre);
			//Ejemplo de como cambiar set_nombre(this, auxnombre);
			printf("Ingrese Horas Trabajadas: \n");
			scanf("%d",&this->horasTrabajadas);
			//Ejemplo de como cambiar set_nombre(this, auxtrabajadas);
			printf("Ingrese Sueldo: \n");
			scanf("%d",&this->sueldo);
			break;
		}
	}
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int index=0;
		Employee* this;
		printf("Introducir ID de empleado \n");
		FLUSH;
		scanf("%d",&index);
		FLUSH;

		for(int i =0 ; i <ll_len(pArrayListEmployee); i++)
		{
			this=ll_get(pArrayListEmployee, i);
			if(index == this->id)
			{
				ll_remove(pArrayListEmployee,i);
				break;
			}
		}
	    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	for(int i =0 ; i <ll_len(pArrayListEmployee); i++)
	{
	Employee* empleado;
	empleado=ll_get(pArrayListEmployee, i); // equivalente empleado = array[i]
	printf("\nID Empleado %d\nNombre Empleado  %s\nHoras Trabajadas %d\nSueldo %d\n", empleado->id , empleado->nombre , empleado->horasTrabajadas , empleado->sueldo);
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

	ll_sort(pArrayListEmployee,employeeSortCondition,0);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;
	Employee* empleado;
	int length = ll_len(pArrayListEmployee);
	pFile=fopen(/*"data.csv"*/path,"w");
	if(pFile==NULL)
	{
	printf("\nEl archivo no puede ser abierto");
	exit (1);
	}
	for(int i=0 ; i <length; i++)
	{
		//empleado=ll_get(pArrayListEmployee, i);
		empleado=ll_get(pArrayListEmployee, i); // equivalente empleado = array[i]
		fprintf(pFile,"%d , %s , %d , %d \n", empleado->id , empleado->nombre , empleado->horasTrabajadas , empleado->sueldo);
	}//get_blabla(empleado/this, id)

	fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;
	Employee* empleado;
	int length = ll_len(pArrayListEmployee);
	pFile=fopen(path,"wb");
	if(pFile==NULL)
	{
		printf("\nEl archivo no puede ser abierto");
		exit (1);
	}
	for(int i=0 ; i <length; i++)
	{
		empleado=ll_get(pArrayListEmployee, i);
		fwrite(empleado,sizeof(Employee),1,pFile);
	}

		fclose(pFile);
	    return 1;
}

