/*
 * handyFunctions.h
 *
 *  Created on: Sep 24, 2019
 *      Author: misael
 */

#ifndef HANDYFUNCTIONS_H_
#define HANDYFUNCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handyFunctions.h"
#include <stdio_ext.h>
#define FLUSH __fpurge(stdin);

int getString(char*obtString);
int minMax(int* minNum, int* maxNum);
int getStringNames(char*obtStringNames);
int getInt(int*obtInt);
int getUnsignedInt(int*obtInt);
int getFloat(float*obtFloat);


#endif /* HANDYFUNCTIONS_H_ */
