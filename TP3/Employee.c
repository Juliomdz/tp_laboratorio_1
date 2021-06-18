#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "utn.h"
static int employee_esNumeroText(char* string);
static int employee_validarNombre(char* cadena, int limite);

Employee* employee_new()
{
    Employee* pEmpleado=(Employee*) malloc(sizeof(Employee));
    return pEmpleado;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleado= NULL;
    pEmpleado= employee_new();

    if(pEmpleado != NULL &&
                            employee_setIdText(pEmpleado,idStr) ==0  &&
                            employee_setNombre(pEmpleado,nombreStr) == 0 &&
                            employee_setHorasTrabajadasText(pEmpleado,horasTrabajadasStr)==0 &&
                            employee_setSueldoText(pEmpleado,sueldoStr)==0){
         return pEmpleado;
    }else{
        return NULL;
    }
}


Employee* employee_newParametrosNumerico(int id,char* nombreStr,int horasTrabajadas,int sueldo)
{
    Employee* pEmpleado= NULL;
    pEmpleado= employee_new();

    if(pEmpleado != NULL &&
                            employee_setId(pEmpleado,id) ==0  &&
                            employee_setNombre(pEmpleado,nombreStr) == 0 &&
                            employee_setHorasTrabajadas(pEmpleado,horasTrabajadas)==0 &&
                            employee_setSueldo(pEmpleado,sueldo)==0){
         return pEmpleado;
    }else{
        return NULL;
    }
}


void employee_delete(Employee* pEmpleado){
    if(pEmpleado != NULL){
        free(pEmpleado);
    }
}


int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
  if(this != NULL && nombre != NULL){
    if(employee_isValidNombre(nombre)==1){
      strncpy(this->nombre,nombre,SIZE_NAME);
      retorno=0;
    }
  }
  return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
  if(this != NULL && nombre != NULL){
    strcpy(nombre,this->nombre);
    retorno=0;
  }
  return retorno;
}

int employee_isValidNombre(char* nombre)
{
  int retorno=-1;
  if(nombre != NULL && employee_validarNombre(nombre,SIZE_NAME)==1)
    {
      retorno = 1;
    }
  else
    {
      retorno =0;
    }
    return retorno;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;

  if(this!= NULL && employee_isValidSueldo(sueldo)){
    this->sueldo=sueldo;
    retorno = 0;
  }
  return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;

  if(this!= NULL && sueldo != NULL){
    *sueldo =this->sueldo;
    retorno = 0;
  }
  return retorno;
}

int employee_isValidSueldo(int sueldo)
{
  int retorno = -1;

  if(sueldo >= 0 && sueldo <= 1000000)
  {
    retorno = 1;
  }
  else
  {
    retorno = 0;
  }
  return retorno;
}

int employee_setSueldoText(Employee* this,char* sueldo){
    int retorno=-1;
  if(this!= NULL && sueldo != NULL){
    if(employee_isValidSueldoText(sueldo)==1){
      this->sueldo=atoi(sueldo);
      retorno = 0;
    }
  }
  return retorno;
}


int employee_getSueldoText(Employee* this){
    int retorno=-1;
    char sueldo[10];

  if(this!= NULL){
    retorno = 0;
    sprintf(sueldo,"%d",this->sueldo);
  }
  return retorno;
}

int employee_isValidSueldoText(char* sueldo)
{
  int retorno;
  retorno = employee_esNumeroText(sueldo);
return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;

  if(this!= NULL && employee_isValidId(id)==1){
    this->id=id;
    retorno = 0;
  }
  return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;

    if(this!= NULL && id != NULL){
    *id=this->id;
    retorno = 0;
  }
  return retorno;
}
int employee_isValidId(int id)
{
  int retorno = -1;
  if(id > 0)
  {
    retorno = 1;
  }
  else
  {
    retorno = 0;
  }
  return retorno;
}

int employee_setIdText(Employee* this,char* id){
  int retorno=-1;

  if(this!= NULL && id != NULL){
    if(employee_isValidIdText(id)==1){
      this->id=atoi(id);
      retorno = 0;
    }
  }
  return retorno;
}

int employee_getIdText(Employee* this){
  int retorno=-1;
  char id[10];

  if(this!= NULL){
    retorno = 0;
    sprintf(id,"%d",this->id);
  }
  return retorno;
}

int employee_isValidIdText(char* id)
{
  int retorno;
  retorno = employee_esNumeroText(id);
return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
  if(this!= NULL && employee_isValidHorasTrabajadas(horasTrabajadas)){
    this->horasTrabajadas=horasTrabajadas;
    retorno = 0;
  }
  return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajo)
{
    int retorno=-1;
  if(this!= NULL && horasTrabajo != NULL){
    *horasTrabajo = this->horasTrabajadas;
    retorno =0;
  }
  return retorno;
}


int employee_isValidHorasTrabajadas(int horasTrabajadas)
{
  int retorno = -1;

  if(horasTrabajadas >= 0 && horasTrabajadas <= 744)
  {
    retorno = 1;
  }
  else
  {
    retorno = 0;
  }
  return retorno;
}

int employee_setHorasTrabajadasText(Employee* this,char* horasTrabajadas){
    int retorno=-1;

  if(this!= NULL && horasTrabajadas != NULL){
    if(employee_isValidHorasTrabajadasText(horasTrabajadas)==1){
      this->horasTrabajadas=atof(horasTrabajadas);
      retorno = 0;
    }
  }
  return retorno;
}



int employee_getHorasTrabajadasText(Employee* this){
    int retorno=-1;
    char horasTrabajadas[10];

  if(this!= NULL){
    retorno = 0;
    sprintf(horasTrabajadas,"%d",this->horasTrabajadas);
  }
  return retorno;
}

int employee_isValidHorasTrabajadasText(char* horasTrabajadas)
{
  int retorno;
  retorno = employee_esNumeroText(horasTrabajadas);
return retorno;
}

int employee_CompareByName(void* pEmpleado1, void* pEmpleado2)
{
    int retorno;
    char nombre1[SIZE_NAME];
    char nombre2[SIZE_NAME];
    Employee* e1;
    Employee* e2;
    int aux;
    e1 = (Employee*) pEmpleado1;
    e2 = (Employee*) pEmpleado2;
    if(e1 != NULL && e2 != NULL){
        employee_getNombre(e1,nombre1);
        employee_getNombre(e2,nombre2);
        aux = strncmp(nombre1,nombre2,SIZE_NAME);
    }
    if(aux==0)
      {
        retorno=0;
      }
    else if(aux>0)
      {
        retorno=1;
      }
    else if(aux<0)
      {
        retorno=-1;
      }
    return retorno;
}

int employee_CompareById(void* pEmpleado1, void* pEmpleado2)
{
    int retorno;
    int idPrimero;
    int idSegundo;
    Employee* e1;
    Employee* e2;
    e1 = (Employee*) pEmpleado1;
    e2 = (Employee*) pEmpleado2;
    if(e1 != NULL && e2 != NULL){
        employee_getId(e1,&idPrimero);
        employee_getId(e2,&idSegundo);
        if(idPrimero > idSegundo){
            retorno=1;
        }else if(idPrimero < idSegundo){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}

int employee_CompareBySalary(void* pEmpleado1, void* pEmpleado2)
{
    int retorno;
    int salaryPrimero;
    int salarySegundo;
    Employee* e1;
    Employee* e2;
    e1 = (Employee*) pEmpleado1;
    e2 = (Employee*) pEmpleado2;
    if(e1 != NULL && e2 != NULL){
        employee_getSueldo(e1,&salaryPrimero);
        employee_getSueldo(e2,&salarySegundo);
        if(salaryPrimero > salarySegundo){
            retorno=1;
        }else if(salaryPrimero < salarySegundo){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}


int employee_CompareByHours(void* pEmpleado1, void* pEmpleado2)
{
    int retorno;
    int horasPrimero;
    int horasSegundo;
    Employee* e1;
    Employee* e2;
    e1 = (Employee*) pEmpleado1;
    e2 = (Employee*) pEmpleado2;
    if(e1 != NULL && e2 != NULL){
        employee_getHorasTrabajadas(e1,&horasPrimero);
        employee_getHorasTrabajadas(e2,&horasSegundo);
        if(horasPrimero > horasSegundo){
            retorno=1;
        }else if(horasPrimero < horasSegundo){
            retorno = -1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}


int employee_printEmpleado(Employee* pEmpleado){
    int retorno=-1;
    int id;
    char nombre[128];
    int horasTrabajo;
    int sueldo;

    if(pEmpleado != NULL && employee_getId(pEmpleado,&id)==0 && employee_getNombre(pEmpleado,nombre)==0 && employee_getHorasTrabajadas(pEmpleado,&horasTrabajo)==0 && employee_getSueldo(pEmpleado,&sueldo)==0){
        retorno=0;
        printf("%4d    %15s   %4d    %6d\n",id,nombre,horasTrabajo,sueldo);
    }
    return retorno;
}

int employee_loadNew(int* nuevoId,char* nombre,int* horasTrabajo,int* sueldo,LinkedList* pArrayListEmployee){
    int retorno=-1;

    if(pArrayListEmployee != NULL)
      {printf("\nSe va a dar de alta un nuevo empleado.\n");}
      if(utn_getNombre(nombre,"Ingrese un nombre:","Nombre invalido.\n",SIZE_NAME,2) == 0 &&
         utn_getNumero(horasTrabajo,"Ingrese las horas trabajadas:","Valor incorrecto.\n",1,744,2) == 1 &&
         utn_getNumero(sueldo,"Ingrese el sueldo:","Valor incorrecto.\n",1,1000000,2) == 1 &&
         employee_searchMaxIdEmployee(pArrayListEmployee,nuevoId) == 0){
        (*nuevoId)++;
        retorno =0;
    }
    return retorno;
}


int employee_searchById(int* id,LinkedList* pArrayListEmployee){
    int retorno=-1;
    Employee* pEmpleado;
    int longitud;
    int idAux;
    int i;

    if(id != NULL && pArrayListEmployee != NULL){
        longitud = ll_len(pArrayListEmployee);

        for(i=0; i < longitud;i++){
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&idAux);
            if(pEmpleado != NULL && idAux == *id){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int employee_searchMaxIdEmployee(LinkedList* pArrayListEmployee,int* maxId){
    int retorno=-1;
    int longitud;
    int i;
    int id;
    Employee* pEmpleado;


    if(pArrayListEmployee != NULL && maxId != NULL){
        longitud = ll_len(pArrayListEmployee);

        for(i=0; i< longitud;i++){
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&id);
            if(id > *maxId || i == 0){
                *maxId = id;
            }
        }
        retorno = 0;
    }

    return retorno;
}

////////////////////////////////////////////////////////////////////////////////
static int employee_esNumeroText(char* string)
{
  int retorno=-1;
  int i;
  if(string != NULL)
    {
      for( i=0;i<sizeof(string) && string[i] != '\0'; i++)
          {
            if(string[i] >= '0' && string[i] <= '9')
            {
              retorno = 1;
            }
            else if(string[i] < '0' || string[i] > '9')
              {
                retorno = 0;
                break;
              }
          }
    }
  else
    {
      retorno=0;
    }
return retorno;
}

static int employee_validarNombre(char* cadena, int limite)
{
  int retorno = -1;

  if(cadena != NULL && limite > 0)
  {
    retorno = 1;
    for(int i = 0; i < limite && cadena[i] != '\0'; i++)
    {
    if ((cadena[i] != ' ') && ((cadena[i] < 'A' || cadena[i] > 'z') || (cadena[i] < 'a' && cadena[i] > 'Z')) )
      {
    retorno = 0;
    break;
      }
    else{
        if((i == 0 || cadena[i - 1] == ' '))
        {
            if(cadena[i] >= 'A' && cadena[i] <= 'Z')
            {
                continue;
            }
            else if (cadena[i] >= 'a' && cadena[i] <= 'z')
            {
              cadena[i]=toupper(cadena[i]);
            }
        }
        else if((i != 0 || cadena[i - 1] != ' '))
        {
          if((cadena[i] >= 'a' && cadena[i] <= 'z') && cadena[i-1] != ' ')
          {
            continue;
          }
        else if(cadena[i] >= 'A' && cadena[i] <= 'Z')
          {
            cadena[i]=tolower(cadena[i]);
          }
        }
    }
    }
  }
  return retorno;
}

