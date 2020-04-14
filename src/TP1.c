/*
 ============================================================================
 Name        : Temporal.c
 Author      : Anibal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#define MIN_OVERFLOW_INT -32768
#define MAX_OVERFLOW_INT 32767
#define REINTENTOS 3

int main(void) {
	setbuf(stdout, NULL);
	int operandoA;
	int operandoB;
	char msjVacio[6] = "Vacio";
	int opcion=0;
	int flagOperA = 0;
	int flagOperB = 0;
	char teclaIngresada;
	int resultadoSuma;
	int retornoSuma;
	int retornoResta;
	int resultadoResta;
	int retornoDivision;
	float resultadoDivision;
	int resultadoMultiplicacion;
	int retornoMultiplicacion;
	int retornoFactorialA;
	int resultadoFactorialA;
	int retornoFactorialB;
	int resultadoFactorialB;
	int flagCalculos = 0;

	do
	{
		//system("cls");
		fflush(stdin);
		printf("\n\t====================\n\t\tMENU\n\t====================\n");
		if (flagOperA == 0)
		{
			printf("\n1 - Ingrese el 1er operando (A = %s)",msjVacio);
		}
		else
		{
			printf("\n1 - Ingrese el 1er operando (A = %d)",operandoA);
		}
		if (flagOperB == 0)
		{
			printf("\n2 - Ingrese el 2do operando (B = %s)",msjVacio);
		}
		else
		{
			printf("\n2 - Ingrese el 2do operando (B = %d)",operandoB);
		}
		printf("\n3 - Calcular todas las operaciones:"
				"\n\t-Suma\n\t-Resta\n\t-Division\n\t-Multiplicacion\n\t-Factorial"
				"\n4 - Informar los resultados"
				"\n5 - Salir");
		if (utn_getNumero(&opcion,"\n\nIngrese una opcion: ","\nERROR. Debe ingresar una opcion valida",1,5,REINTENTOS) == 0)
		{
			switch (opcion)
			{
				case 1:
					if(utn_getNumero(&operandoA,"\nIngrese el 1er operando: ","\nERROR.\nDebe ingresar un numero entero entre -32768 y 32767"
							"",MIN_OVERFLOW_INT,MAX_OVERFLOW_INT,REINTENTOS) == 0)
					{
						flagOperA = 1;
					}
					break;
				case 2:
					if(utn_getNumero(&operandoB,"\nIngrese el 2do operando: ","\nERROR.\nDebe ingresar un numero entero entre -32768 y 32767"
							"",MIN_OVERFLOW_INT,MAX_OVERFLOW_INT,REINTENTOS) == 0)
					{
						flagOperB = 1;
					}
					break;
				case 3:
					if (flagOperA == 1 && flagOperB == 1)
					{
						flagCalculos = 1;
						retornoSuma = suma(operandoA, operandoB, &resultadoSuma);
						retornoResta = resta(operandoA, operandoB, &resultadoResta);
						retornoDivision = division(operandoA, operandoB, &resultadoDivision);
						retornoMultiplicacion = multiplicacion(operandoA, operandoB, &resultadoMultiplicacion);
						retornoFactorialA = factorial(operandoA, &resultadoFactorialA);
						retornoFactorialB = factorial(operandoB, &resultadoFactorialB);
						printf("\nSe ejecutaron todos los calculos\n");
						//system("pause");
						fflush(stdin);

					}
					else
					{
						printf("\nNo se pueden calcular las operaciones porque no se han ingresado los 2 operandos");
					}
					break;
				case 4:
					if (flagCalculos == 1)
					{
						if(retornoSuma == 0)
						{
							printf("\nSUMA = %d",resultadoSuma);
						}
						else if(retornoSuma == -2)
						{
							printf("\nSUMA = OVERFLOW - No es posible almacenar el resultado de la operacion");
						}
						else
						{
							printf("\nSUMA = Error. No se pudo realizar el calculo");
						}

						if(retornoResta == 0)
						{
							printf("\nRESTA = %d",resultadoResta);
						}
						else if (retornoResta == -2)
						{
							printf("\nRESTA = OVERFLOW - No es posible almacenar el resultado de la operacion");
						}
						else
						{
							printf("\nRESTA = Error. No se pudo realizar el calculo");
						}

						if(retornoDivision == 0)
						{
							printf("\nDIVISION = %.2f",resultadoDivision);
						}
						else if(retornoDivision == -2)
						{
							printf("\nDIVISION = Error. No es posible dividir por cero");
						}
						else
						{
							printf("\nDIVISION = Error. No se pudo realizar el calculo");
						}

						if(retornoMultiplicacion == 0)
						{
							printf("\nMULTIPLICACION = %d",resultadoMultiplicacion);
						}
						else if(retornoMultiplicacion == -2)
						{
							printf("\nMULTIPLICACION = OVERFLOW - No es posible almacenar el resultado de la operacion");
						}
						else
						{
							printf("\nMULTIPLICACION = Error. No se pudo realizar el calculo");
						}

						if(retornoFactorialA == 0)
						{
							printf("\nFACTORIAL A = %d",resultadoFactorialA);
						}
						else if(retornoFactorialA == -2)
						{
							printf("\nFACTORIAL A = Error. No se puede calcular el factorial de un numero negativo");
						}
						else
						{
							printf("\nFACTORIAL A = OVERFLOW - No es posible almacenar el resultado de la operacion");
						}

						if(retornoFactorialB == 0)
						{
							printf("\nFACTORIAL B = %d\n",resultadoFactorialB);
						}
						else if(retornoFactorialB == -2)
						{
							printf("\nFACTORIAL B = Error. No se puede calcular el factorial de un numero negativo");
						}
						else
						{
							printf("\nFACTORIAL B = OVERFLOW - No es posible almacenar el resultado de la operacion");
						}
						teclaIngresada = getChar("\nDesea continuar usando la aplicacion? (s/n)");
						if (toupper(teclaIngresada) == 'S')
						{
							flagCalculos = 0;
						}
						else
						{
							opcion = 5;
						}
					}
					else
					{
						printf("\nNo se puede informar los resultados porque no se han calculado las operaciones (Opcion 3)");
					}
					break;
			}
		}
		else
		{
			teclaIngresada = getChar("\nHa agotado la cantidad de reintentos\nDesea volver a usar la aplicacion? (s/n)");
			if (toupper(teclaIngresada) == 'S')
			{
				flagOperA = 0;
				flagOperB = 0;
			}
			else
			{
				opcion = 5;
			}
		}
	}while(opcion!=5);
	printf("\n===================\nPROGRAMA FINALIZADO\n===================\n");
	//system("pause");
	return 0;
}

