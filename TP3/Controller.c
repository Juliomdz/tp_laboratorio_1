#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"

#define SIZE_NAME 128

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pArchivoTexto;
    pArchivoTexto = fopen(path,"r");

    if(pArchivoTexto == NULL)
    {
        retorno=-1;
        printf("\nError al cargar los datos del archivo.\n");
    }else if(ll_isEmpty(pArrayListEmployee) == 0){
        retorno=1;
        printf("\nYa cargo los datos del archivo anteriormente.\n");
    }else{
        parser_EmployeeFromText(pArchivoTexto,pArrayListEmployee);
        retorno=0;
        printf("\nDatos cargados correctamente.\n");
    }

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivoTexto;
    pArchivoTexto = fopen(path,"rb");
    int retorno;
    if(pArchivoTexto == NULL)
    {
        printf("\nERROR. El archivo no existe o esta dañado.\n");
        retorno=-1;
    }else if(ll_isEmpty(pArrayListEmployee) == 0){
        printf("\nYa cargo los datos del archivo anteriomente.\n");
        retorno=1;
    }else{
        parser_EmployeeFromBinary(pArchivoTexto,pArrayListEmployee);
        printf("\nDatos cargados correctamente.\n");
        retorno=0;
    }
    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char nombre[SIZE_NAME];
    int horasTrabajo;
    int sueldo;
    int nuevoId;
    Employee* pEmpleado;
    int retorno;
    char respuesta;

    if(pArrayListEmployee == NULL)
      {
        printf("ERROR. No se puede acceder a la lista de empleados o la misma esta vacia.\n");
        retorno=-1;
    }
    else if(ll_isEmpty(pArrayListEmployee)!= 0)
      {
        retorno=1;
        printf("Debe cargar los datos a memoria para operar.\n");
    }
    else if(employee_loadNew(&nuevoId,nombre,&horasTrabajo,&sueldo,pArrayListEmployee) == 0)
      {
        pEmpleado = employee_newParametrosNumerico(nuevoId,nombre,horasTrabajo,sueldo);
        if(pEmpleado != NULL)
        {
            employee_printEmpleado(pEmpleado);
            if(utn_getContinue(&respuesta,"Desea dar de alta este empleado?(y/n)","Incorrecto.\n",2)== 0 && (respuesta == 'y' || respuesta=='Y')){
                ll_add(pArrayListEmployee,pEmpleado);
                printf("Empleado guardado correctamente.\n");
                retorno=0;
            }
        }
    }
    else
    {
        printf("ERROR. No se pudo dar de alta al empleado .\n");
        retorno=-1;
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int idElegido;
    int indiceId;
    Employee* pEmpleado;
    char respuesta;
    int opcion;
    char nombre[SIZE_NAME];
    int horas;
    int sueldo;
    char nombreNuevo[SIZE_NAME];
    int horasNuevo;
    int sueldoNuevo;
    int retorno=-1;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
    {
        if(utn_getNumero(&idElegido,"Ingrese ID del empleado a modificar:","Valor incorrecto.\n",1,2000,2)==1)
        {
            indiceId = employee_searchById(&idElegido,pArrayListEmployee);
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,indiceId);
            printf("  ID\t      Nombre\t   Horas  Salario\n");
            employee_printEmpleado(pEmpleado);
            if(utn_getContinue(&respuesta,"Desea modificar este empleado?(y/n)","Incorrecto.\n",2)== 0 && (respuesta == 'y' || respuesta=='Y'))
            {
                employee_getNombre(pEmpleado,nombre);
                employee_getHorasTrabajadas(pEmpleado,&horas);
                employee_getSueldo(pEmpleado,&sueldo);
                do
                {
                    if(utn_getNumero(&opcion,"\nElija el campo a modificar:\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Salir\nElija una opcion:","Opcion ncorrecta.\n",1,4,2)==1)
                    {
                        switch(opcion)
                        {
                        case 1:
                            if(utn_getNombre(nombreNuevo,"Ingrese nuevo nombre:","Valor incorrecto.\n",SIZE_NAME,2) == 0)
                            {
                                employee_setNombre(pEmpleado,nombreNuevo);
                            }
                            break;
                        case 2:
                            if(utn_getNumero(&horasNuevo,"Ingrese horas trabajadas:","Valor incorrecto.\n",1,2000,2) == 1)
                            {
                                employee_setHorasTrabajadas(pEmpleado,horasNuevo);
                            }
                            break;
                        case 3:
                            if(utn_getNumero(&sueldoNuevo,"Ingrese nuevo sueldo:","Valor incorrecto.\n",1,200000,2) == 1)
                            {
                                employee_setSueldo(pEmpleado,sueldoNuevo);
                            }
                            break;
                        }
                    }
                }
                while(opcion != 4);
                printf("  ID\t      Nombre\t   Horas  Salario\n");
                employee_printEmpleado(pEmpleado);
                if(utn_getContinue(&respuesta,"Confirma la modificacion?(y/n)","Respuesta incorrecta",2)== 0 && (respuesta == 'y' || respuesta== 'Y'))
                {
                    ll_set(pArrayListEmployee,indiceId,pEmpleado);
                    printf("\nEmpleado modificado correctamente.\n");
                    retorno=0;
                }
                else
                {
                    employee_setNombre(pEmpleado,nombre);
                    employee_setHorasTrabajadas(pEmpleado,horas);
                    employee_setSueldo(pEmpleado,sueldo);
                    printf("\nNo se hizo la modificacion de empleado.\n");
                    retorno=1;
                }
            }else{
                retorno = 1;
                printf("\nNo se modifico el empleado.\n");
            }
        }
        else
          {
            printf("\nNo existe empleado con la ID ingresada.\n");
          }

    }
    else
      {
        printf("\nERROR. No se puede hacer la operacion.\n");
      }
    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int idElegido;
    int indiceId;
    Employee* pEmpleado;
    char respuesta;
    int retorno=-1;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
    {
        if(utn_getNumero(&idElegido,"Ingrese ID del empleado a borrar:","Valor incorrecto.\n",1,2000,2)==1)
        {
            indiceId = employee_searchById(&idElegido,pArrayListEmployee);
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,indiceId);
            employee_printEmpleado(pEmpleado);

            if(utn_getContinue(&respuesta,"Desea eliminar este empleado?(y/n)","Incorrecto.\n",2)== 0 && (respuesta=='y' || respuesta == 'Y'))
            {
                ll_remove(pArrayListEmployee,indiceId);
                employee_delete(pEmpleado);
                printf("\nEmpleado eliminado correctamente.\n");
                retorno=0;
            }
            else
            {
                printf("\nNo se elimino el empleado .\n");
                retorno = 1;
            }
        }
    }
    else
      {
        printf("ERROR. No se puede hacer la operacion.\n");
      }

    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int longitud;
    int i;
    int retorno=-1;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
    {
        longitud = ll_len(pArrayListEmployee);
        printf("  ID\t      Nombre\t   Horas  Salario\n");
        for(i=0; i < longitud; i++)
        {
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
            employee_printEmpleado(pEmpleado);
        }
        printf("Cantidad de empleados:%d\n",longitud);
        retorno=0;
    }
    else
      {
        printf("La lista esta vacia o no ha sido cargada.\n");
      }

    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int opcion;
    int orden;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0){
        if(utn_getNumero(&opcion,
                         "\nElija un criterio de ordenamiento:\n"
                         "1.ID.\n"
                         "2.Nombre.\n"
                         "3.Horas trabajadas.\n"
                         "4.Sueldo.\nOpcion:","Opcion Incorrecta.\n",1,4,2)==1 &&
                            utn_getNumero(&orden,"\nElija el orden:\n0.Descendente\n1.Ascendente\n2.Salir\nOpcion:","\nOpcion Incorrecta.\n",0,2,2)==1 && orden != 2)
          {
            switch(opcion){
                case 1:
                  printf("\nSe esta realizando el ordenamiento. Aguarde un instante...\n");
                    ll_sort(pArrayListEmployee,employee_CompareById,orden);
                    break;
                case 2:
                  printf("\nSe esta realizando el ordenamiento. Aguarde un instante...\n");
                    ll_sort(pArrayListEmployee,employee_CompareByName,orden);
                    break;
                case 3:
                  printf("\nSe esta realizando el ordenamiento. Aguarde un instante...\n");
                    ll_sort(pArrayListEmployee,employee_CompareByHours,orden);
                    break;
                case 4:
                  printf("\nSe esta realizando el ordenamiento. Aguarde un instante...\n");
                    ll_sort(pArrayListEmployee,employee_CompareBySalary,orden);
                    break;
                default:
                    printf("No se hicieron cambios.\n");
                    retorno=1;
                    break;
            }
            printf("\nLa lista fue ordenada correctamente.\n");
            retorno=0;
          }
        else {
              printf("\nNO se modificó el ordenamiento.\n");
             }
    }
    else {
          printf("\nNo hay datos cargados.\n");
         }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int longitud;
    int i;
    int id;
    char nombre[SIZE_NAME];
    int horasTrabajo;
    int sueldo;
    int retorno=-1;
    FILE* pFile = NULL;
    Employee* pEmpleado;

    longitud = ll_len(pArrayListEmployee);
    pFile= fopen(path,"w");

    if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
    {
        fprintf(pFile,"id,nombre,horasTrabajo,sueldo\n");
        for(i=0; i< longitud; i++)
        {
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&id);
            employee_getNombre(pEmpleado,nombre);
            employee_getHorasTrabajadas(pEmpleado,&horasTrabajo);
            employee_getSueldo(pEmpleado,&sueldo);
            fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajo,sueldo);
        }
        printf("\nDatos guardados en archivo de texto.\n");
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int longitud;
    FILE* pFile = NULL;
    int i;
    Employee* pEmpleado;
    int retorno=-1;

    longitud = ll_len(pArrayListEmployee);
    pFile= fopen(path,"wb");

    if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
    {
        for(i=0; i < longitud; i++)
        {
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
            fwrite(pEmpleado,sizeof(Employee),1,pFile);
        }
        printf("\nDatos guardados en archivo de binario.\n");
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

    int controller_close(LinkedList* pArrayListEmployee)
    {
        int retorno=-1;
        printf("Cerrando el programa...\n");
        if(pArrayListEmployee !=NULL){
        ll_clear(pArrayListEmployee);
        ll_deleteLinkedList(pArrayListEmployee);
        retorno=0;
        }
        printf("\t ADIOS!.\n");
        return retorno;
}
