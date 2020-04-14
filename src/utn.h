/*
 * utn.h
 *
 *  Created on: 1 abr. 2020
 *      Author: PAVILIONDV
 */

#ifndef UTN_H_
#define UTN_H_





//static int esNumerica(char *cadena);
//static int getInt (int *pResultado);
int utn_getNumero(int *pResultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos);
float getFoat(char mensaje[]);
char getChar(char mensaje[]);
int suma (int num1, int num2, int *resultado);
int resta(int num1, int num2, int *resultado);
int division(int num1, int num2, float *resultado);
int multiplicacion (int num1, int num2, int *resultado);
int factorial(int num, int *resultado);

char getNumeroAleatorio(int desde, int hasta, int iniciar);




#endif /* UTN_H_ */
