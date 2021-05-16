/*
 * employee.c
 *
 *  Created on: 15 may. 2021
 *      Author: julio
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

/** \brief To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int emp_init (Employee *list, int len)
{
  int retorno = -1;
  int i;
  if (len > 0 && list != NULL)
    {
      retorno = 1;
      for (i = 0; i < len; i++)
        {
          list[i].isEmpty = 1;
        }
    }
  return retorno;
}
/** \brief add in a existing list of employees the values entered by the user
*          in the first empty position
 * \param Employee* list: list of employees received where new values are saved
 * \param int len: length of the list received.
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (1) if Ok
 */
int emp_add (Employee *list, int len, int *id)
{
  int retorno = -1;
  int indiceObtenido;
  Employee bufferEmployee;
  if (len > 0 && list != NULL)
    {
      if (emp_searchEmptyIndex (list, &indiceObtenido,
                                len) && indiceObtenido <len &&
                                len > 0 && indiceObtenido >=0 && id != NULL)
        {
          printf ("Se va a dar de alta un nuevo empleado.");
          if (!utn_getNombre (bufferEmployee.name,
                              "\nIngrese el NOMBRE del nuevo empleado: ",
                              "\nEso no es un NOMBRE.", SIZE_NAME, 2)
              && !utn_getNombre (bufferEmployee.lastName,
                                 "\nIngrese el APELLIDO del nuevo empleado: ",
                                 "\nEso no es un APELLIDO.", SIZE_NAME, 2)
              && utn_getNumero(&bufferEmployee.sector,
                                "Ingrese el numero correspondiente al sector:\n"
                                "1-administrativo\n2-Contable\n3-IT\n4-RRHH\n",
                                "SECTOR INVALIDO.", 1, 4, 3)
              && !utn_getFloat(&bufferEmployee.salary,
                  "\nIngrese el SALARIO del nuevo empleado: ",
                  "\nEso no es SALARIO VALIDO.\n", 2))
            {
              bufferEmployee.idEmployee = *id;
              bufferEmployee.isEmpty = 0;
              list[indiceObtenido] = bufferEmployee;
              retorno = 1;
              printf ("\nempleado dado de alta satisfactoriamente. ID:%d\n",
                      *id);
              *id=*id+1;

            }
        }
    }
  return retorno;
}
/** \brief Asks for confirmation then Removes an Employee by Index (isEmpty=1)
* \param list Employee*: Pointer to array of employees
* \param len int Array: length
* \param indexReceived : index to delete
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (1) if successfully deleted -(0) if not deleted.
*/
int emp_remove (Employee *list, int len)
{
  int retorno = -1;
  char continuar;
  int bufferId=0;
  int indexReceived=0;
  if (len > 0 && list != NULL)
    {
      printf("Se van a ELIMINAR los datos de un empleado existente.");
      if (utn_getNumero (&bufferId, "\nIngrese el ID del empleado: ",
                         "\nEso no es un ID valido.", 0, len, 2)
          && emp_searchID(list, len, bufferId, &indexReceived) == 1)
        {
      utn_getContinue (
          &continuar,
          "\n¿Esta seguro que desea ELIMINAR a este empleado?\n",
          "\nOpcion de confirmacion ingresada invalida.\n", 5);
      if (continuar == 'y' || continuar == 'Y')
        {
          retorno = 1;
          list[indexReceived].isEmpty = 1;
          printf ("Se elimino correctamente el empleado ID:%d.\n",
                  list[indexReceived].idEmployee);
        }
      else if (continuar == 'n' || continuar == 'N')
        {
          printf ("No se elimino ni modifico nada.\n");
          retorno = 0;
        }
        }
    }
  return retorno;
}
/**
 * \brief Ask the user to modified the data selected of one employee
 * \param Employee* list: list of employees received where new values are saved
 * \param int len: length of the list received.
 * \return Retrns 1 (SUCCESS) if data was modified or -1 (ERROR) if not
 */

int emp_modify (Employee *list, int len)
{
  int retorno = -1;
  Employee bufferEmployee;
  int indexObtained = 0;
  char continuar = 'n';
  int option;
  if (len > 0 && list != NULL)
    {
      printf ("Se van a modificar datos de un empleado existente.");
      if (emp_findById (list, len, &indexObtained) == 1)
        {
          bufferEmployee.idEmployee = list[indexObtained].idEmployee;
          bufferEmployee.isEmpty = 0;
          printf ("\nEmpleado seleccionado:\n");
          emp_print(&list[indexObtained]);
          do
            {
            if(utn_getNumero(&option,
                "\n1.Ingrese la opcion acorde a lo que desea modificar:"
                "\n1.Modificar NOMBRE."
                "\n2.Modificar APELLIDO."
                "\n3.Modificar SALARIO."
                "\n4.Modificar SECTOR."
                "\n5.Salir.",
                "\nOpcion ingresada invalida.\n", 1, 5, 1))
              {
              switch (option)
                {
                case 1:
                  if (!utn_getNombre (
                      bufferEmployee.name,
                      "\nIngrese el NOMBRE del empleado: ",
                      "\nEso no es un nombre.", SIZE_NAME, 2))
                    {
                      printf ("\nSe modificó satisfactoriamente el nombre.");
                      strncpy (list[indexObtained].name,
                               bufferEmployee.name, SIZE_NAME);
                    }
                  break;
                case 2:
                  if (!utn_getNombre (
                      bufferEmployee.lastName,
                      "\nIngrese el APELLIDO del empleado: ",
                      "\nEso no es un apellido.", SIZE_NAME, 2))
                    {
                      printf (
                          "\nSe modificó satisfactoriamente el Apellido.");
                      strncpy (list[indexObtained].lastName,
                               bufferEmployee.lastName, SIZE_NAME);
                    }
                  break;
                case 3:
                  if (!utn_getFloat(&bufferEmployee.salary,
                      "\nIngrese el SALARIO del empleado: ",
                      "\nEso no es SALARIO valido.\n", 2))
                    {
                      printf ("\nSe modificó satisfactoriamente el salario.");
                      list[indexObtained].salary=bufferEmployee.salary;
                    }
                  break;
                case 4:
                  if (utn_getNumero(&bufferEmployee.sector,
                      "Ingrese el numero correspondiente al sector:\n"
                      "1-administrativo\n2-Contable\n3-IT\n4-RRHH\n",
                      "SECTOR INVALIDO.", 1, 4, 3))
                        {
                        printf ("\nSe modificó satisfactoriamente el sector.");
                        list[indexObtained].sector=bufferEmployee.sector;
                        }
                  break;
                case 5:
                  continuar = 'N';
                  break;
                }
              utn_getContinue(&continuar,
                  "\n¿Desea modificar otro valor del mismo empleado?",
                  "\nERROR. respuesta invalida.", 2);
            }
            }
          while (continuar == 'y' || continuar == 'Y');
          retorno = 1;

        }
    }
  return retorno;
}
/** \brief find an Employee by Id en returns the index position in array.
* \param Employee* list: list of employees received
* \param int len: length of the list received.
* \param int indexObtained: Index position of the wanted ID
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int emp_findById(Employee *list, int len, int *indexObtained)
{
  int retorno = -1;
  int bufferId = 0;
  int bufferIndice;
  if (len > 0 && list != NULL)
    {
      if (utn_getNumero (&bufferId, "\nIngrese el ID del empleado: ",
                         "\nEso no es un ID valido.", 0, len, 2)==1
          && emp_searchID(list, len, bufferId, &bufferIndice) == 1)
        {
          if ((emp_isEmptyIndex(&list[bufferIndice])==0)
              && bufferIndice < len && len > 0 && bufferIndice >= 0)
            {
              *indexObtained = bufferIndice;
              retorno = 1;
            }
          else
            {
              printf ("\nERROR:Ese ID no existe.\n");
            }
        }
    }
  return retorno;
}

/**
* \brief prints the content of employee received
* \param Employee* pEmployee: Pointer of the employee to pront
* \return Retrns 1 (SUCCESS) if data was printed or -1 (ERROR) if not
*/
int emp_print (Employee* pEmployee)
{
  int retorno = -1;
  char auxSector[50];
  if (pEmployee != NULL && !pEmployee->isEmpty)
    {
      switch(pEmployee->sector)
      {
        case 1:
        strncpy(auxSector,"ADMIN.\t",50);
        break;
        case 2:
          strncpy(auxSector,"CONTABLE",50);
        break;
        case 3:
          strncpy(auxSector,"IT\t",50);
        break;
        case 4:
          strncpy(auxSector,"RRHH\t",50);
        break;
      }
      printf ("[EMPLEADO ID:%d] Nombre: %s %s.\t\t"
              " SECTOR:%s \t SALARIO: %.2f \n",
              pEmployee->idEmployee, pEmployee->name, pEmployee->lastName,
              auxSector, pEmployee->salary);
      retorno = 1;
    }
  return retorno;
}
/**
 * \brief Prints the whole array of employees
* \param Employee* list: list of employees received
* \param int len: length of the list received.
 * \return Returns 1 (SUCCESS) if printing, -1 (ERROR) if not
 */
int emp_printArray (Employee *list, int len)
{
  int retorno = -1;
  int i;
  if (len > 0 && list != NULL)
    {
      retorno = 1;
      for (i = 0; i < len; i++)
        {
          emp_print (&list[i]);

        }
    }
  return retorno;
}

/**
 * \brief Searches in the list for an empty index
* \param Employee* list: list of employees received
 * \param int* emptyIndex: pointer to return the emptyIndex assigned
* \param int len: length of the list received.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (1) if Ok
 */
int emp_searchEmptyIndex(Employee *list, int *emptyIndex, int len)
{
  int retorno = -1;
  int i;
  if (len > 0 && list != NULL)
    {
      for (i = 0; i < len; i++)
        {
          if (emp_isEmptyIndex (&list[i]))
            {
              retorno = 1;
              *emptyIndex = i;
              break;
            }
        }
      if (*emptyIndex != i)
        {
          retorno = -2;
        }
    }
  return retorno;
}
/**
 * \brief checks if the Employee entered is empty
 * \param Employee *pEmployee: pointer of an employee
* \return int Return (-1) if Error [Invalid length or NULL pointer]
*         -(0)if not empty (1) if empty
 */
int emp_isEmptyIndex (Employee *pEmployee)
{
  int retorno = -1;

  if (pEmployee != NULL)
    {
      if (pEmployee->isEmpty == 1)
        {
          retorno = 1;
        }
      if (pEmployee->isEmpty == 0)
        {
          retorno = 0;
        }
    }
  return retorno;
}
/**
 * \brief Searches in the list of for the ID entered and returns his index
* \param Employee* list: list of employees received
* \param int len: length of the list received.
 * \param int IdEntered: ID that will be searched for his index
 * \param  int *indexObtained: Index found returned
 * \return Returns 1 (SUCCESS) if the ID was found,
 *         (-1) if list is null or len<=0 (-2) (ERROR) if it doesnt exist
 */
int emp_searchID (Employee *list, int len, int IdEntered, int *indexObtained)
{
  int retorno = -1;
  int i;
  if (len > 0 && list != NULL)
    {
      retorno = 0;
      for (i = 0; i < len; i++)
        {
          if (list[i].idEmployee == IdEntered)
            {
              *indexObtained = i;
              retorno = 1;
              break;
            }
        }
      if (list[i].idEmployee != IdEntered)
        {
          printf ("\nERROR:Ese ID aun no ha sido asignado a nadie.\n");
          retorno = -2;
        }
    }
  return retorno;
}

/**
* brief Searches in the list for a minimum of one valid employee
* \param Employee* list: list of employees received
* \param int len: length of the list received.
* \return int Returns (-1) if Error [Invalid length or NULL pointer]
*        - (1) if there's at least 1 employee, (-2) if there is not.
*/
int emp_validateList(Employee *list, int len)
{
  int retorno = -1;

  if(list != NULL && len > 0)
  {
    for(int i = 0; i < len; i ++)
    {
      if(list[i].isEmpty==0)
      {
          retorno = 1;
        break;
      }
      retorno = -2;
    }
  }

  return retorno;
}

/**
 * brief Prints the list of empleoyees sorted by name, if there's at least one
* \param Employee* list: list of employees received
* \param int len: length of the list received.
* \return int Returns (-1) if Error [Invalid length or NULL pointer]
*        - (1) if there's at least 1 employee, (-2) if there is not.
*/
int emp_inform(Employee* list, int len)
{
  int retorno = -1;

  if(list != NULL && len > 0)
  {
    if(emp_validateList(list, len) == 1)
    {
      emp_sortByLastName(list, len);
      emp_printArray(list, len);
    }
    else
    {
      printf("\nERROR. No se han cargado empleados todavia.");
      retorno=-2;
    }
  }

  return retorno;
}
/**
 * brief Prints the list sorted by name and sector, if there are empleoyees
* \param Employee* list: list of employees received
* \param int len: length of the list received.
* \return int Returns (-1) if Error [Invalid length or NULL pointer]
*        - (1) if there's at least 1 employee, (-2) if there is not.
*/
int emp_informSector(Employee* list, int len)
{
  int retorno = -1;

  if(list != NULL && len > 0)
  {
    if(emp_validateList(list, len) == 1)
    {
      emp_sortByLastName(list, len);
      emp_sortBySector(list, len);
      emp_printArray(list, len);
    }
    else
    {
      printf("\nERROR. No se han cargado empleados todavia.");
      retorno=-2;
    }
  }

  return retorno;
}
/**
 * brief Sorts the employees alphabetically by last name
* \param Employee* list: list of employees received
* \param int len: length of the list received.
 * \return 1 (SUCCESS) if it could to sort the values or
 *        (-1) if Error [Invalid length or NULL pointer]
 */
int emp_sortByLastName(Employee* list, int len)
{
  int retorno = -1;
  int flagSwap = 0;
  Employee auxiliar;

  if(list != NULL && len > 0)
  {
    do
    {
      flagSwap = 0;
      for(int i = 0; i < len - 1; i++)
      {
        if(strcmp(list[i].lastName, list[i + 1].lastName) > 0)
        {
          auxiliar = list[i];
          list[i] = list[i + 1];
          list[i + 1] = auxiliar;
          flagSwap = 1;
        }
      }
    }while(flagSwap);
    retorno = 1;
  }

  return retorno;
}

/**
 * brief Sorts the employees alphabetically by sector
* \param Employee* list: list of employees received
* \param int len: length of the list received.
 * \return 1 (SUCCESS) if it could to sort the values or
 *        (-1) if Error [Invalid length or NULL pointer]
 */
int emp_sortBySector(Employee* list, int len)
{
  int retorno = -1;
  int flagSwap = 0;
  Employee auxiliar;

  if(list != NULL && len > 0)
  {
    do
    {
      flagSwap = 0;
      for(int i = 0; i < len - 1; i++)
      {
        if(list[i].sector > list[i + 1].sector)
        {
          auxiliar = list[i];
          list[i] = list[i + 1];
          list[i + 1] = auxiliar;
          flagSwap = 1;
        }
      }
    }while(flagSwap);
    retorno = 1;
  }
  return retorno;
}

/**
 * brief  prints the total amount of salaries and the salary average,
 *        and shows how many employees surpass it
* \param Employee* list: list of employees received
* \param int len: length of the list received.
 * \return 1 (SUCCESS) if it could show all the information or
 *        (-1) if Error [Invalid length or NULL pointer]
 */
int emp_SalaryInfo(Employee* pEmployee, int length)
{
  int retorno = -1;
  float totalSalary = 0;
  int validEmployees = 0;
  float average=0;
  int surpassAverage = 0;

  if(pEmployee != NULL && length > 0)
  {
    for(int i = 0; i < length; i++)
    {
      if(!pEmployee[i].isEmpty)
      {
        totalSalary += pEmployee[i].salary;
        validEmployees++;
      }
    }
    average = totalSalary / validEmployees;
    for(int i = 0; i < length; i++)
    {
      if(pEmployee[i].salary > average)
      {
          surpassAverage++;
      }
    }
    printf("\n\n\nTotal gastado en salarios: %.2f\nSalario Promedio: %.2f"
        "\nEmpleados que cobran mas que el promedio: %d\n",
        totalSalary, average,surpassAverage);
    retorno = 0;
  }
  return retorno;
}
/**
 * \brief Forces a new client in the main function
* \param Employee* list: list of employees received
* \param int len: length of the list received.
 * \param every parameter hardcoded in the structure.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (1) if Ok
 */
int emp_ForceAdd (Employee *list, int len, char *name, char *lastName,
                  float salary,int sector, int index, int *id)
{
  int retorno = -1;

  if (emp_isEmptyIndex (&list[index]) == 1 && len > 0
      && list != NULL && index >= 0)
    {

      retorno = 1;
      strncpy (list[index].name, name, SIZE_NAME);
      strncpy (list[index].lastName, lastName, SIZE_NAME);
      list[index].salary=salary;
      list[index].isEmpty = 0;
      list[index].sector = sector;
      list[index].idEmployee = *id;
      *id=*id+1;
    }
  return retorno;
}

