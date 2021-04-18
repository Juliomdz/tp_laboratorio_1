/*
 ============================================================================
 Name        : TP1.c
 Author      : Julio Mendez
 División    : 1° H
 Enunciado   : Hacer una calculadora.
Para ello el programa iniciará y contará con un menú de opciones:

1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)

4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
2
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca
 aparte,que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y
 B(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"

#define REINTENTOS 9999999

int main(void)
{
  int opcionMenu;
  float numeroA;
  float numeroB;
  float resultado;
  char continuar;
  int flagExit = 0;
  int flagPrimerOperando=0;
  int flagSegundoOperando=0;
  int flagMenuB=0;

  printf("¡Bienvenido a la calculadora!\n");
  do
  {
      if(flagMenuB<2)
      {
        do
        {
        printf("\nIngrese el número correspondiente a la opcion deseada:");
        printf("\n1) Ingresar el operando A(x)");
        printf("\n2) Ingresar el operando B(y)");
        printf("\n3) Sumar (%0.2f + %0.2f)", numeroA, numeroB);
        printf("\n4) Restar (%0.2f - %0.2f)", numeroA, numeroB);
        printf("\n5) Dividir x/y (%0.2f / %0.2f)", numeroA, numeroB);
        printf("\n6) Multiplicar (%0.2f * %0.2f)", numeroA, numeroB);
        printf("\n7) Obtener el factorial de ambos (%0.0f!) (%0.0f!)", numeroA, numeroB);
        printf("\n8) Realizar todas las operaciones.");
        printf("\n9) Salir de la calculadora\n");
        utn_getNumero(&opcionMenu,"Ingrese su opcion:", "OPCION INGRESADA INVALIDA",1,9,REINTENTOS);
        switch(opcionMenu)
        {
          case 1:
                {
                  utn_getFloat(&numeroA,"\nIngrese AHORA el operando A(x): ", "Entrada invalida, ingrese un numero",REINTENTOS);
                      flagPrimerOperando=1;
                  break;
                }
          case 2:
                {
    utn_getFloat(&numeroB,"\nIngrese AHORA el operando B(y): ", "Entrada invalida, ingrese un numero",REINTENTOS);
                      flagSegundoOperando=1;
                  break;
                }
          case 3:
          case 4:
          case 5:
          case 6:
          case 8:
                printf("\nERROR! Debe ingresar primero AMBOS operandos antes de realizar una operacion.");
                break;
          case 7:
                {
                  if(flagPrimerOperando==0 && flagSegundoOperando==0)
                    {
                      printf("\n¡ERROR! Debe ingresar al menos un operando valido para calcular su factorial.");
                    }
                  else
                  {
                    if(flagPrimerOperando==1)
                  {
                    if(utn_factorial(numeroA, &resultado)==-2)
                    {
                      printf("\nFactorial es una propiedad de numeros naturales y usted ingresó un negativo en A(x).");
                    }
                    else
                    {
                    printf("\nEl factorial de %0.0f es: %0.0f", numeroA, resultado);
                    }
                  }
                  else
                  {
                    printf("\nNo se ha ingresado ningun valor para A(x).");
                  }
                  if(flagSegundoOperando==1)
                  {
                    if(utn_factorial(numeroB, &resultado)==-2)
                    {
                       printf("\nFactorial es una propiedad de numeros naturales y usted ingresó un negativo en B(y).");
                    }
                    else
                    {
                      printf("\nEl factorial de %0.0f es: %0.0f", numeroB, resultado);
                    }
                  }
                  else
                  {
                      printf("\nNo se ha ingresado ningun valor para B(y).");
                  }
                  }
                  break;
                }
          case 9:
                {
                  flagExit = 1;
                  flagMenuB=1;
                  printf("¡Gracias por utilizar la calculadora!");
                  break;
                }
        }
        flagMenuB=flagPrimerOperando+flagSegundoOperando;
        }
        while(opcionMenu!=9 && flagMenuB<2);
      }
    if( flagExit != 1)
    {
       printf("\nIngrese el número correspondiente a la opcion deseada:");
       printf("\n1) Ingrese ahora el operando A(x)");
       printf("\n2) Ingrese ahora el operando B(y)");
       printf("\n3) Sumar (%0.2f + %0.2f)", numeroA, numeroB);
       printf("\n4) Restar (%0.2f - %0.2f)", numeroA, numeroB);
       printf("\n5) Dividir x/y (%0.2f / %0.2f)", numeroA, numeroB);
       printf("\n6) Multiplicar (%0.2f * %0.2f)", numeroA, numeroB);
       printf("\n7) Obtener el factorial de ambos (%0.0f!) (%0.0f!)", numeroA, numeroB);
       printf("\n8) Realizar todas las operaciones.");
       printf("\n9) Salir de la calculadora\n");
       utn_getNumero(&opcionMenu,"Ingrese su opcion:", "OPCION INGRESADA INVALIDA",1,9,REINTENTOS);
     switch(opcionMenu)
    {
      case 1:
            {
              utn_getFloat(&numeroA,"\nIngrese ahora el operando A(x): ", "Entrada invalida, ingrese un numero",REINTENTOS);
              break;
            }
      case 2:
            {
              utn_getFloat(&numeroB,"\nIngrese ahora el operando B(y): ", "Entrada invalida, ingrese un numero",REINTENTOS);
              break;
            }
      case 3:
      {
        utn_sumar(numeroA, numeroB, &resultado);
        printf("El resultado de %0.2f + %0.2f es: %0.2f", numeroA, numeroB, resultado);
        break;
      }
      case 4:
      {
        utn_restar(numeroA, numeroB, &resultado);
        printf("El resultado de %0.2f - %0.2f es: %0.2f", numeroA, numeroB, resultado);
        break;
      }
      case 5:
      {
        if(utn_dividir(numeroA, numeroB, &resultado, "Error. No se puede dividir por cero\n") == 0)
        {
          printf("El resultado de %0.2f / %0.2f es: %0.2f", numeroA, numeroB, resultado);
        }
        break;
      }
      case 6:
      {
        utn_multiplicar(numeroA, numeroB, &resultado);
        printf("El resultado de %0.2f * %0.2f es: %0.2f", numeroA, numeroB, resultado);
        break;
      }
      case 7:
      {
        if(utn_factorial(numeroA, &resultado)==-2)
        {
          printf("\nFactorial es una propiedad de numeros naturales y usted ingresó un negativo en A(x).");
        }
        else
        {
        printf("\nEl factorial de %0.0f es: %0.0f", numeroA, resultado);
        }
        if(utn_factorial(numeroB, &resultado)==-2)
        {
           printf("\nFactorial es una propiedad de numeros naturales y usted ingresó un negativo en B(y).");
        }
        else
          {
        printf(" y el factorial de %0.0f es: %0.0f", numeroB, resultado);
          }
        break;
      }
      case 8:
           {
             //suma
             utn_sumar(numeroA, numeroB, &resultado);
             printf("La suma de %0.2f + %0.2f es: %0.2f\n", numeroA, numeroB, resultado);
             //resta
             utn_restar(numeroA, numeroB, &resultado);
             printf("La resta de %0.2f - %0.2f es: %0.2f\n", numeroA, numeroB, resultado);
             //division
             if(utn_dividir(numeroA, numeroB, &resultado, "Error. No se puede dividir por cero\n") == 0)
             {
               printf("La division de %0.2f / %0.2f es: %0.2f\n", numeroA, numeroB, resultado);
             }
             //multiplicación
             utn_multiplicar(numeroA, numeroB, &resultado);
             printf("La multiplicacion de %0.2f * %0.2f es: %0.2f\n", numeroA, numeroB, resultado);
             //factoriales
             if(utn_factorial(numeroA, &resultado)==-2)
             {
               printf("Factorial es una propiedad de numeros naturales y usted ingresó un negativo en A(x).\n");
             }
             else
             {
             printf("El factorial de %0.0f es: %0.0f\n", numeroA, resultado);
             }
             if(utn_factorial(numeroB, &resultado)==-2)
             {
                printf("Factorial es una propiedad de numeros naturales y usted ingresó un negativo en B(y).\n");
             }
             else
               {
             printf(" y el factorial de %0.0f es: %0.0f\n", numeroB, resultado);
               }
             break;
           }
      case 9:
      {
        flagExit = 1;
        printf("¡Gracias por utilizar la calculadora!");
        break;
      }
    }
    }
    flagExit=0;
    do
      {
    printf("\n¿Desea realizar otro calculo?[S/N]:");
    __fpurge(stdin);
    scanf("%c",&continuar);
    if(continuar=='N' || continuar=='n')
      {
        flagExit =1;
        break;
      }
    else if(continuar!='S' && continuar!='s')
    {
        printf("\nOpción ingresada invalida.");
    }
    }
    while(continuar!='S' && continuar!='s');
  }while(flagExit == 0);

  printf("\n ¡Adiós!\n");

  return EXIT_SUCCESS;
}
