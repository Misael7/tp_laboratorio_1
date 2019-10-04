/*
 * handyFunctions.c
 *
 *  Created on: Sep 24, 2019
 *      Author: misael
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handyFunctions.h"
#include <stdio_ext.h>
#define FLUSH __fpurge(stdin);
/*************************
using \0 to check last array value.
***************************/
/*---------------------min/max setter---------------------*/
int minMax(int* minNum, int* maxNum)//Base code only, must reinvent target function to implement it.
{
   int minBuffer=0;
   int maxBuffer=0;
   printf("Set min value \0");
   FLUSH;
   scanf("%d",&minBuffer);
   printf("Set max value \0");
   FLUSH;
   scanf("%d",&maxBuffer);
   if (minBuffer<=maxBuffer)
   {
	   *minNum=minBuffer;
	   *maxNum=maxBuffer;
   }
   return 0;
}
/*----------------------Multi purpose String-----------------------------*/
int getString(char* obtString)
{
	int errorReturn=1;
    char stringBuffer[50];

    FLUSH; //
    fgets(stringBuffer,sizeof(stringBuffer),stdin);
    stringBuffer[strlen(stringBuffer)-1]='\0'; //Removes 'enter' character.
     if(obtString!=NULL)
    	{
    	 	strncpy(obtString,stringBuffer,sizeof(obtString));
    		errorReturn=0;
    	}
    return errorReturn;
}
/*-----------------------------Name only string---------------------------*/
int getStringNames(char* obtStringNames)
{
	int errorReturn=1;
    char stringBuffer[50];
    FLUSH;
    getString(stringBuffer);
    if(stringBuffer!=NULL)
    	{
    	 for(int i=0;stringBuffer[i]!='\0';i++)
    	 {
    		 if(!(stringBuffer[i]>='0' && stringBuffer[i]<='9'))
    	 	 {
    			 errorReturn=0;
    	 	 }
    	 }
    	 if(errorReturn==0)
    	 {
    		 strncpy(obtStringNames,stringBuffer,sizeof(obtStringNames));
    	 }
    	}
    return errorReturn;
}
/*-----------------------------Common INT type value---------------------------*/
int getInt(int* obtInt)
{
    int errorReturn=1;
    char bufferStr[50]="";
    FLUSH;
    getString(bufferStr);
    if(bufferStr!=NULL)
    {
    	for(int i=0;bufferStr[i]!='\0';i++)
    	{
    		if((bufferStr[i]>='0' && bufferStr[i]<='9') || (bufferStr[i]=='-') || (bufferStr[i]==',') || (bufferStr[i]=='.'))
				{
    				errorReturn=0;
				}
    	}
    	if(errorReturn==0)
    	{
    		*obtInt=atoi(bufferStr);
    	}
    }
    return errorReturn;
}
/*-----------------------------Unsigned INT type value---------------------------*/
int getUnsignedInt(int* obtInt)
{
    int errorReturn=1;
    char bufferStr[50];
    FLUSH;
    getString(bufferStr);
    if(bufferStr!=NULL)
    {
    	for(int i=0;bufferStr[i]!='\0';i++)
    	{
    	if((bufferStr[i]>='0' && bufferStr[i]<='9') ||(bufferStr[i]==',') || (bufferStr[i]=='.') )
			{
    			errorReturn=0;
			}
    	}
    	if(errorReturn==0)
    	{
    		*obtInt=atoi(bufferStr);
    	}
    }
    return errorReturn;
}
/*-----------------------------Float type value---------------------------*/
int getFloat(float* obtFloat)
{
    int errorReturn=1;
    char bufferStr[50];
    FLUSH;
    getString(bufferStr);
    if(bufferStr!=NULL)
    {
    	for(int i=0;bufferStr[i]!='\0';i++)
    	{
    		if((bufferStr[i]>='0' && bufferStr[i]<='9') || (bufferStr[i]=='-') || (bufferStr[i]==',') || (bufferStr[i]=='.'))
				{
    				errorReturn=0;
				}
    	}
    	if(errorReturn==0)
    	{

    		*obtFloat=atof(bufferStr);

    	}
    }
    return errorReturn;
}
