/*
 * utn.c
 *
 *  Created on: 16 mar. 2021
 *      Author: julio Méndez
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"


/**
* \brief Recorre el string y verifica que no quede un '\n' antes de la penultima posición
* \param char* string: Puntero al espacio de memoria donde se copiará la cadena obtenida
* \param limite: Define el tamaño del string
* \return Retorna 0 si se valida el string y -1 si no es valido
*/
int utn_myGets(char* string, int limite)
{
  int retorno = -1;

  if(string != NULL && limite > 0 && fgets(string, limite, stdin) == string)
  {
    __fpurge(stdin);
    if(string[strnlen(string,sizeof(string)) - 1] == '\n')
    {
      string[strnlen(string,sizeof(string)) - 1] = '\0';
    }

    retorno = 0;
  }
  return retorno;
}

/**
 * \brief Transforma una cadena de caractéres a números si es posible
 * \param int* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si se obtiene un número entero o -1 (ERROR) si no
*/
int utn_getInt(int* pResultado)
{
  int retorno = -1;
  char buffer[64];

  if(pResultado != NULL)
  {
    if(utn_myGets(buffer, sizeof(buffer)) == 0 && utn_esNumerica(buffer))
    {
      *pResultado = atoi(buffer);
      retorno = 0;
    }
  }

  return retorno;
}

/**
 * \brief Transforma una cadena de caractéres a números decimales si es posible
 * \param float* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si se obtiene un número decimal o -1 (ERROR) si no
*/
int getFloat(float* pResultado)
{
  int retorno = -1;
  char buffer[64];

  if(pResultado != NULL)
  {
    if(utn_myGets(buffer, sizeof(buffer)) == 0 && utn_esDecimal(buffer))
    {
      *pResultado = atof(buffer);
      retorno = 0;
    }
  }

  return retorno;
}

/**
 * \brief Verifica que la cadena recibida contenga solamente números positivos o negativos
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numérica, 0 (falso) si no o -1 si hubo algún error con los argumentos
*/
int utn_esNumerica(char* cadena)
{
  int retorno = -1;
  int i = 0;

  if(cadena != NULL && strlen(cadena) > 0)
  {
    retorno = 0;
    if(cadena[0] == '-')
    {
        i=1;
    }
    for( ; cadena[i] != '\0'; i++)
    {
      if(cadena[i] >= '0' && cadena[i] <= '9')
      {
        retorno = 1;
      }
    }
  }

  return retorno;
}

/**
 * \brief Verifica que la cadena recibida contenga solamente números decimales positivos o negativos
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es decimal, 0 (falso) si no o -1 si hubo algún error con los argumentos
*/
int utn_esDecimal(char* cadena)
{
  int retorno = -1;
  int punto = 1;
  int signo = 1;

  if(cadena != NULL && strlen(cadena) > 0)
  {
    retorno = 0;
    for(int i = 0; cadena[i] != '\0'; i++)
    {
      if(cadena[i] >= '0' && cadena[i] <= '9')
      {
        if(i == 0 && cadena[i] == '-' && signo)
        {
          signo = 0;
        }
        if(cadena[i] == '.' && punto)
        {
          punto = 0;
        }
        retorno = 1;
      }
    }
  }

  return retorno;
}

/**
 * \brief Le pide al usuario un número entero entre un rango
 * \param int* pNumero: Puntero donde se almacena el número ingresado por el usuario
 * \param const char* mensaje: Texto para que el usuario sepa que ingresar
 * \param const char* mensajeError: Texto que nos indica que hubo un error
 * \param int min: El rango mínimo para ingresar un número
 * \param int max: El rango máximo para ingresar un número
 * \param int reintentos: cantidad de veces que, en caso de error, se volverá a iterar
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_getNumero(int* pNumero, const char* mensaje, const char* mensajeError, int min, int max,int reintentos)
{
  int retorno = -1;
  int bufferInt;

  if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && min <= max)
  {
    do
    {
      printf(mensaje);
      __fpurge(stdin);
      if(utn_getInt(&bufferInt) == 0)
      {
        if(bufferInt >= min && bufferInt <= max)
        {
          retorno = 0;
          *pNumero = bufferInt;
          break;
        }
        else
        {
            printf(mensajeError);
            reintentos--;
        }
      }
    }while(reintentos);
    if(reintentos==0)
    {
    printf("¡vaya a tomarle el pelo al codigo de su abuela!");
    }
  }
  else
  {
    printf("hay parametros invalidos en la funcion");
  }

  return retorno;
}

/**
 * \brief Le pide al usuario un número racional
 * \param float* pNumero: Puntero donde se almacena el número ingresado por el usuario
 * \param const char* pTexto: Texto para que el usuario sepa que ingresar
 * \param const char* sError: Texto que nos indica que hubo un error
 * \param int reintentos: cantidad de veces que, en caso de error, se volverá a iterar
 * \return Retorna 0 (EXITO) si se obtiene un número racional o -1 (ERROR) si no
*/
int utn_getFloat(float* pNumero, const char* pTexto, const char* mensajeError, int reintentos)
{
  int retorno = -1;
  float buffer;

  if(pNumero != NULL && pTexto != NULL && mensajeError != NULL)
  {
    while(reintentos)
    {
      printf(pTexto);
      __fpurge(stdin);
      if(getFloat(&buffer) == 0)
      {
        retorno = 0;
        *pNumero = buffer;
        break;
      }
      else
      {
        printf(mensajeError);
        reintentos--;
      }
    }
    if(reintentos==0)
    {
    printf("¡vaya a tomarle el pelo al codigo de su abuela!");
    }
  }
  else
  {
    printf("hay parametros invalidos en la funcion");
  }

  return retorno;
}


/**
 * \brief Suma dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la suma, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la suma o -1 (ERROR) si no
*/
int utn_sumar(float numeroA, float numeroB, float* pResultado)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    resultado = numeroA + numeroB;
    retorno = 0;
  }

  *pResultado = resultado;
  return retorno;
}

/**
 * \brief Resta dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la resta, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la resta o -1 (ERROR) si no
*/
int utn_restar(float numeroA, float numeroB, float* pResultado)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    resultado = numeroA - numeroB;
    retorno = 0;
  }

  *pResultado = resultado;
  return retorno;
}

/**
 * \brief Divide dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la división, que va a llegar al main mediante un puntero
 * \param const char* pDivisionPorCero: Mensaje de error si el divisor es cero
 * \return Retorna 0 (EXITO) si se pudo completar la division o -1 (ERROR) si no o si el divisor es 0
*/
int utn_dividir(float dividendo, float divisor, float* pResultado, const char* pDivisionPorCero)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    if(divisor != 0)
    {
      resultado = dividendo / divisor;
      retorno = 0;
    }
    else
    {
      printf(pDivisionPorCero);
    }
  }

  *pResultado = resultado;
  return retorno;
}

/**
 * \brief Multiplica dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la multiplicación, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la multiplicación o -1 (ERROR) si no
*/
int utn_multiplicar(float dividendo, float divisor, float* pResultado)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    resultado = dividendo * divisor;
    retorno = 0;
  }

  *pResultado = resultado;
  return retorno;
}

/**
 * \brief Factorisa un número ingresado y lo devuelve mediante un puntero
 * \param float numero: Número a ser factoriado
 * \param float* pResultado: El resultado de la factorización, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la factorisación o -1 (ERROR) si no
*/
int utn_factorial(float numero, float* pResultado)
{
  int retorno = -1;
  int acumulador = 1;

  if(pResultado != NULL)
  {
    if(numero <0)
    {
        retorno= -2;
        *pResultado=0;
    }
    else
    {
      if(numero==0)
      {
          *pResultado=1;
          retorno =0;
      }
      else
      {
        for(int i = 1; i <= numero; i++)
        {
          acumulador *= i;
        }
      }
      *pResultado = acumulador;
      retorno = 0;
    }
  }

  return retorno;
}

/**
 * \brief EN DESARROLLO Le pide al usuario un número entero entre un rango EN DESARROLLO
 * \param int* pNumero: Puntero donde se almacena el número ingresado por el usuario
 * \param const char* pTexto: Texto para que el usuario sepa que ingresar
 * \param const char* mensajeError: Texto que nos indica que hubo un error
 * \param int min: El rango mínimo para ingresar un número
 * \param int max: El rango máximo para ingresar un número
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_getCharacter(char* pResultado, char* pMensaje, char* mensajeError, int limite, int reintentos)
{
  int retorno = -1;
  char buffer[limite];

  if(pResultado != NULL && pMensaje != NULL && mensajeError != NULL && limite >= 0 && reintentos >=0)
  {
    do
    {
      printf(pMensaje);
      __fpurge(stdin);
      fgets(buffer,limite, stdin);

        if(utn_myGets(buffer,limite)==0)
        {
          retorno = 0;
          strncpy(pResultado, buffer,limite);
          break;
        }
        else
          {
            printf(mensajeError);
            reintentos--;
          }


    }while(reintentos);
  }
  return retorno;
}
