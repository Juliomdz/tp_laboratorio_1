/*
 ============================================================================
 Name        : TP2.c
 Author      : Julio Mendez
 División    : 1° H
 Enunciado   : Una empresa requiere un sistema para administrar su nómina de
               empleados. Se sabe que dicha nómina bajo ninguna circunstancia
               superara los 1000 empleados.
               Datos:
El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el
 número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre
o Apellido o Salario o Sector.
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define SIZE_ARRAY_EMPLOYEES 1000
int main(void) {
  Employee arrayEmployees[SIZE_ARRAY_EMPLOYEES];
  int idEmployee=1;
  int menu=0;
  int subMenu=0;

  if(emp_init(arrayEmployees,SIZE_ARRAY_EMPLOYEES))
    {
      printf("Array de empleados inicializado correctamente.\n");
    }
  ////////////ALTA FORZADA PARA HARDCODEAR DATOS Y TESTEAR
  emp_ForceAdd(arrayEmployees,SIZE_ARRAY_EMPLOYEES,"Marcelo","Sand",30000,3,0,&idEmployee);
  emp_ForceAdd(arrayEmployees,SIZE_ARRAY_EMPLOYEES,"Hector","Fontana",24000,1,1,&idEmployee);
  emp_ForceAdd(arrayEmployees,SIZE_ARRAY_EMPLOYEES,"Franco","Ramirez",26000,2,2,&idEmployee);
  emp_ForceAdd(arrayEmployees,SIZE_ARRAY_EMPLOYEES,"Manuel","Delgado",40000,1,3,&idEmployee);
  emp_ForceAdd(arrayEmployees,SIZE_ARRAY_EMPLOYEES,"Ivan","Batistuta",20000,3,4,&idEmployee);
  emp_ForceAdd(arrayEmployees,SIZE_ARRAY_EMPLOYEES,"Hugo","Hernandez",15000,4,5,&idEmployee);
  emp_ForceAdd(arrayEmployees,SIZE_ARRAY_EMPLOYEES,"Jose","Gallardo",20000,4,6,&idEmployee);
  ///////////
  printf("\n\t\t*~SISTEMA DE ADMINISTRACION DE NOMINA DE EMPLEADOS~*\n");
  do
      {
      if(emp_validateList(arrayEmployees,SIZE_ARRAY_EMPLOYEES)==1)
        {
       printf("\nIngrese el numero de la opcion deseada:\n");
          if(utn_getNumero(&menu,"1.Dar de ALTA un empleado nuevo."
                           "\n2.MODIFICAR datos de un empleado existente."
                           "\n3.Dar de BAJA un empleado."
                           "\n4.INFORMES."
                           "\n5.Salir.\n",
                           "\nERROR-Opcion ingresada invalida.\n",1,5,1))
              switch(menu)
              {
              case 1:
                if(emp_add(arrayEmployees,SIZE_ARRAY_EMPLOYEES, &idEmployee))
                  {}
                  break;
              case 2:
                if(emp_modify(arrayEmployees, SIZE_ARRAY_EMPLOYEES))
                  {}
                  break;
              case 3:
                if(emp_remove (arrayEmployees,SIZE_ARRAY_EMPLOYEES)>=0)
                  {}
                  break;
              case 4:
                  do
                    {
                     printf("\nIngrese el numero de la opcion deseada:\n");
                        if(utn_getNumero(&subMenu,
                         "1.Listado de los empleados ordenados alfabéticamente"
                         " por Apellido."
                         "\n2.Listado de los empleados ordenados por sector."
                         "\n3.Total y promedio de los salarios, y cuántos "
                         "empleados superan el salario promedio."
                         "\n4.Salir al menu anterior.\n",
                         "\nERROR-Opcion ingresada invalida.\n",1,4,99))
                          {
                            switch(subMenu)
                            {
                            case 1:
                              emp_inform(arrayEmployees,SIZE_ARRAY_EMPLOYEES);
                                break;
                            case 2:
                              emp_informSector(arrayEmployees,SIZE_ARRAY_EMPLOYEES);
                                break;
                            case 3:
                              emp_SalaryInfo(arrayEmployees,
                                             SIZE_ARRAY_EMPLOYEES);
                                break;
                            case 4:
                              printf("\nRegresando al menu principal.\n");
                              break;
                             }
                          }
                    }while(subMenu != 4);
                  break;
              case 5:
                   printf("¡Adios!");
                  break;
            }
        }
      else
        {
          printf("\nIngrese el numero de la opcion deseada:\n");
                    if(utn_getNumero(&menu,"1.Dar de ALTA un empleado nuevo."
                                     "\n2.Salir.\n",
                                     "\nERROR-Opcion ingresada invalida.\n",
                                     1,2,99))
          switch(menu)
          {
          case 1:
            if(emp_add(arrayEmployees,SIZE_ARRAY_EMPLOYEES, &idEmployee))
              {}
          break;
          case 2:
            printf("¡Adios!");
            menu=5;
          break;
          }
        }
      }while(menu != 5);
      return 0;
return EXIT_SUCCESS;
}
