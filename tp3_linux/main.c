#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "handyFunctions.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int f1(int *a, int b,int (*foo)(int,int)) {
	*a = *a * 2;
	*a = foo(*a,b);
	return (*a);
}

int f2(int a, int b) {
	 a = b*b;
	 return a;
}


/*enum colors {lets,find,course};
int main()
{
	printf("%d %d %d",course,lets,find);
	return 0;
}*/



int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    	printf("3. Alta de empleado\n");
    	printf("4. Modificar datos de empleado\n");
    	printf("5. Baja de empleado\n");
    	printf("6. Listar empleados\n");

    	printf("7. Ordenar empleados\n");
    	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    	printf("10. EXIT.\n");
    	FLUSH;
    	scanf("%d",&option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;

            case 2:
            	controller_loadFromBinary("data.bin",listaEmpleados);
            	break;

            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;

            case 8:
            	controller_saveAsText("data.csv",listaEmpleados);
            	break;

            case 9:
            	controller_saveAsBinary("data.bin",listaEmpleados);
            	break;

            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;

            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;

            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;

            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;

        }
    }while(option != 10);
    return 0;
}

