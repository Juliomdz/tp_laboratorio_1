#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pAuxEmpleado;
    char id[10];
    char nombre[128];
    char horasTrabajo[10];
    char sueldo[10];
    int retorno=-1;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajo,sueldo);
    if(pFile != NULL){
        while(!feof(pFile))
          {
            if(feof(pFile))
            {
                break;
            }

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajo,sueldo);
            pAuxEmpleado = employee_newParametros(id,nombre,horasTrabajo,sueldo);
            if(pAuxEmpleado != NULL){
                ll_add(pArrayListEmployee,pAuxEmpleado);
            }
        }
        fclose(pFile);
        retorno=0;
    }

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado=NULL;
    int retorno=-1;

    if(pFile != NULL){

        do{
            pEmpleado=employee_new();
            if(pEmpleado != NULL){
                if(fread(pEmpleado,sizeof(Employee),1,pFile)==1){
                    ll_add(pArrayListEmployee,pEmpleado);
                }
            }
        }while(feof(pFile)==0);
        retorno = 0;
        fclose(pFile);
    }
    return retorno;
}
