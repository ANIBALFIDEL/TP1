#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MIN_OVERFLOW_INT -32768
#define MAX_OVERFLOW_INT 32767


static int esNumerica(char *cadena)
{
	int ret = -1;
	int i = 0;
	if(cadena != NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]<'0' || cadena[i]>'9')//Si se ingresa un caracter erróneo la condición es verdadera
			{
				break;
			}
			i++;
		}
		if(cadena[i]=='\0')
		{
			ret = 1;
		}
	}
	return ret;
}

static int getInt (int *pResultado)
{
	char buffer[64];
	int ret = -1;
	fflush(stdin);
	//scanf("%s",buffer); Es reemplazado por fgets
	fgets(buffer,sizeof(buffer),stdin);
	buffer[strlen(buffer)-1] = '\0';
	/*FUNCION QUE VALIDE LA CADENA SEGUN CRITERIO ESTABLECIDO*/
	if(esNumerica(buffer) == 1)
	{
		*pResultado = atoi(buffer);
		ret = 1;
	}
	return ret;
}


/**
 * @brief Solicita al usuario ingresar un número dentro de un rango
 * @param pResultado Guardará el num ingresado al pasar todas las validaciones
 * @param mensaje Mensaje a mostrar
 * @param mensajeError Mensaje a mostrar en caso de error
 * @param minimo Es el menor número que se puede ingresar
 * @param maximo Es el mayor número que se puede ingresar
 * @param reintentos Cantidad de reintentos en caso de error
 * @return devuelve 0 si se ingresó un número válido y -1 en caso de error
 * scanf devuelve 1 cuando pudo guardar correctamente lo ingresado
 */
int utn_getNumero(int *pResultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
{
	 int ret;
	 int num;
	 while(reintentos>0)
	 {
	   printf("%s",mensaje);
	   if(getInt(&num)==1)
	   {
		   if(num>=minimo && num<=maximo)
			{
			   break;
			}
	   }
	   reintentos--;
	   printf("%s. Le quedan %d intentos",mensajeError,reintentos);
	 }
	if(reintentos==0)
	{
	 ret=-1;
	}
	else
	{
	 ret=0;
	 *pResultado = num;
	}
	return ret;
}


/**
 * \brief Solicita un numero flotante y devuelve un resultado
 * \param mensaje es el mensaje a mostrar
 * \return devuelte el numero flotante ingresado
 */
float getFoat(char mensaje[])
{
	float aux;
	printf("%s",mensaje);
	scanf("%f",&aux);
	return aux;
}

/**
 * \brief Solicita que el usuario ingrese una letra
 * \param mensaje es el mensaje a mostrar
 * \return Devuelve la letra ingresada
 */
char getChar(char mensaje[])
{
	char aux;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&aux);
	return aux;
}

/**
 * @brief La función devuelve un número aleatorio
 * @param desde Es el número mínimo que puede devolver
 * @param hasta Es el número máximo que puede devolver
 * @param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * @return Retorna el número aleatorio generado
 */
char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
	if(iniciar)
	{
		srand(time(NULL));
	}
	return desde + (rand() % (hasta + 1 - desde));
}

/**
 * Funcion usada para verificar el ingreso de caracteres.Chequea para que solo sean admitidas las letras S o N.
Se ingresa void y devuelve un entero sin signo
0 si se ingreso la N
1 si se ingreso la S
*/
unsigned int verifica(void)
{
	char letra;
	printf("\nIngrese opcion...S/N?");
	letra=toupper(getchar());
	while(!((letra=='S')||(letra=='N')))
	{
		printf("\nHa ingresado opcion no valida...Reintente el ingreso(S/N)... ");
		letra=toupper(getchar());
	}
	return (letra=='S');
}

int ordenarArray(int pArray[],int size)
{
	int retorno = -1;
	int i;
	int buffer;
	int flagSwap = 1;
	if(pArray != NULL && size > 0)
	{
		while(flagSwap)
		{
			flagSwap = 0;
			for(i = 0; i < size-1; i++)
			{
				flagSwap = 1;
				buffer = pArray[i];
				pArray[i] = pArray [i+1];
				pArray[i] = buffer;
			}
		}
		if(flagSwap == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * @brief Recibe 2 numeros enteros y los suma
 * @param num1 Pimer operando
 * @param num2 Segundo operando
 * @param resultado Guarda resultado de la suma
 * @return Devuelve -2 desborde de variable; -1 otro error; 0 si salió bien;
 */
int suma (int num1, int num2, int *resultado)
{
	int retorno = -1;
	int aux;
	aux = num1 + num2;
	if (aux < MIN_OVERFLOW_INT || aux > MAX_OVERFLOW_INT)
	{
		retorno = -2;
	}
	else
	{
		*resultado = aux;
		retorno = 0;
	}
	return retorno;
}


/**
 * @brief Recibe 2 numeros enteros y los resta
 * @param num1 Pimer operando
 * @param num2 Segundo operando
 * @param resultado Guarda resultado de la resta
 * @return Devuelve -2 desborde de variable; -1 otro error; 0 si salió bien;
 */
int resta (int num1, int num2, int *resultado)
{
	int retorno = -1;
	int aux;
	aux = num1 - num2;
	if (aux < MIN_OVERFLOW_INT || aux > MAX_OVERFLOW_INT)
	{
		retorno = -2;
	}
	else
	{
		*resultado = aux;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Recibe dos numeros y guarda el resultado
 * @param num1 Primer operando
 * @param num2 Segundo operando
 * @param resultado Guarda resultado de la división si se pudo realizar
 * @return Devuelve -1 divisor igual a cero; 0 si salió bien
 */
int division(int num1, int num2, float *resultado)
{
	int retorno;
	float aux;
	if (num2 != '0')
	{
		aux = (float)num1 / num2;
		*resultado = aux;
		retorno = 0;
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

/**
 * @brief Recibe 2 numeros enteros y los multiplica
 * @param num1 Pimer operando
 * @param num2 Segundo operando
 * @param resultado Guarda resultado de la multiplicacion
 * @return Devuelve -2 desborde de variable; -1 otro error; 0 si salió bien;
 */

int multiplicacion (int num1, int num2, int *resultado)
{
	int retorno = -1;
	int aux;
	aux = num1 * num2;
	if (aux < MIN_OVERFLOW_INT || aux > MAX_OVERFLOW_INT)
	{
		retorno = -2;
	}
	else
	{
		*resultado = aux;
		retorno = 0;
	}
	return retorno;
}


/**
 * @brief Recibe un número y calcula su factorial
 * @param num Número a calcular
 * @param resultado Guarda el resultado
 * @return Devuelve -2 si el número es menor a cero; -1 desborde de variable; 0 si salio bien
 */
int factorial(int num, int *resultado)
{
	int retorno = -1;
	long double aux = num;
	int i;
	if (aux > 0)
	{
		for (i=1; i<num; i++)
		{
			aux = aux * i;
		}
		if (aux < MIN_OVERFLOW_INT || aux > MAX_OVERFLOW_INT)
		{
			retorno = -1;
		}
		else
		{
			*resultado = aux;
			retorno = 0;
		}
	}
	else
	{
		retorno = -2;
	}
	return retorno;
}







