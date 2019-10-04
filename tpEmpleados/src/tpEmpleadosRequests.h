/*
 * tpEmpleadosRequests.h
 *
 *  Created on: Oct 2, 2019
 *      Author: misael
 */

#ifndef TPEMPLEADOSREQUESTS_H_
#define TPEMPLEADOSREQUESTS_H_
#include "tpEmpleadosStruct.h"
#include "handyFunctions.h"
#include <stdio_ext.h>

/* \brief: Set isEmpty value in TRUE(1) to indicate the array is empty in every slot.
 * \param Employee listA to array struct of employees
 * \param length value for length of the struct array
 * \return 0 for no errors met in runtime.
 */
int startEmployee(Employee listA[],int length);
/* \brief: Load variables of Employee listA struct in a set isEmpty=1 array position.
 * \param Employee listA to array struct of employees
 * \param length value for length of the struct array
 * \return 0 for no errors met in runtime. */
int addEmployee(Employee listA[],int length);
/* \brief: Print every employee loaded with isEmpty=0 in struct ListA
 * \param Employee listA to array struct of employees
 * \param length value for length of the struct array
 * \return 0 for no errors met in runtime. *
 */
int printEmployees(Employee* list, int length);
/* \brief: Locate Employee by ID searching by array position and prints it.
 * \param Employee listA to array struct of employees
 * \param length value for length of the struct array
 * \param idSearch for desired ID to be found
 * \return 0 for no errors met in runtime. *
 */
int findEmployeeById(Employee listA[], int length,int idSearch);
/* \brief: Locate Employee by ID searching by array position,
 *  writes isEmpty=1, making the array position available again thus "deleting" the employee data
 * \param Employee listA to array struct of employees
 * \param length value for length of the struct array
 * \param idSearch for desired ID to be "deleted"
 * \return 0 for no errors met in runtime. *
 */
int removeEmployee(Employee listA[], int length,int idSearch);
/* \brief: Locate Employee by ID searching by array position,
 *  writes isEmpty=1, making the array position available again thus "deleting" the employee data
 *  aftewards it calls for the add function, allowing to edit the data for that Employee ID.
 * \param Employee listA to array struct of employees
 * \param length value for length of the struct array
 * \param idSearch for desired ID to be "deleted"
 * \return 0 for no errors met in runtime. *
 */
int modEmployee(Employee listA[],int length, int idSearch);
/* \brief: Sort employees by sector and lastName, takes sector as priority *
 * \param Employee listA to array struct of employees
 * \param length value for length of the struct array *
 * \return 0 for no errors met in runtime. *
 */
int sortEmployee(Employee listA[],int length);
/* \brief: Calculates total salary, average salary and ammount of employees above average salary *
 * \param Employee listA to array struct of employees
 * \param length value for length of the struct array *
 * \return 0 for no errors met in runtime. *
 */
int totalAverageSalary(Employee listA[],int length);


#endif /* TPEMPLEADOSREQUESTS_H_ */
