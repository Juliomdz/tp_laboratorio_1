/*
 * utn.h
 *
 *  Created on: 16 abr. 2021
 *      Author: julio
 */

#ifndef UTN_H_
#define UTN_H_

int getFloat(float *pResultado);
int utn_esNumerica(char* cadena);
int utn_esDecimal(char* cadena);
int utn_myGets(char* string, int limite);
int utn_getNumero(int* pNumero, const char* mensaje, const char* mensajeError, int min, int max,int reintentos);
int utn_getFloat(float* pNumero, const char* pTexto, const char* mensajeError, int reintentos);
int utn_getInt(int *pResultado);
int utn_sumar(float numeroA, float numeroB, float* pResultado);
int utn_restar(float numeroA, float numeroB, float* pResultado);
int utn_dividir(float dividendo, float divisor, float* pResultado, const char* pDivisionPorCero);
int utn_multiplicar(float dividendo, float divisor, float* pResultado);
int utn_factorial(float numero, float* pResultado);
int utn_getCharacter(char* pResultado, char* pMensaje, char* mensajeError, int limite, int reintentos);

#endif /* UTN_H_ */

