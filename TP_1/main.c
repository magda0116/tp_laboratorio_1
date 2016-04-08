#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "utn.h"
/** \brief Solicitar la suma de dos numeros
 * \param float sumar (float a , float b);
 * \param
 * \return returna totalsumar;
 */
/** \brief Solicitar la resta de dos numeros
 * \param float restar (float c, float d);
 * \param
 * \return returna totalrestar;
 */
/** \brief Solicitar la multiplicacion de dos numeros
 * \param float multiplicar (float e, float f);
 * \param
 * \return returna totalmultiplicar;
 */
/** \brief Solicitar la division de dos numeros
 * \param float division (float g, float h);
 * \return returnatotaldivision;
 */
/** \brief Solicitar el factorial del primer numero
 * \param float factorial (float i);
 * \return returna totalfactorial;
 /** \brief
  * \param  Solicitar todos los totales
  * \param  float totales (float i, float j);
  * \return returna 0;
  */
int main()
{
    float A=0.0;
    float B=0.0;
    float tot;
    int fact;
    int nfactor;
    int opcion=0;
                while(opcion <9)
                {
                printf("\tMenu de una Calculadora\n\n");
                printf("1.Calcular primer operando (A=%.2f)\n\n",A);
                printf("2.Calcular segundo operando (B=%.2f)\n\n",B);
                printf("3.Calcular suma (A+B)\n\n");
                printf("4.Calcular resta (A-B)\n\n");
                printf("5.Calcular multiplicacion (A*B)\n\n");
                printf("6.Calcular division (A/B)\n\n");
                printf("7.Calcular factorial (A!)\n\n");
                printf("8.Calcular todas las operaciones\n\n");
                printf("9.Salir\n\n");

                printf("Ingrese un opcion:");
                fflush(stdin);
                scanf("%d",&opcion);
                system("cls");
                             switch(opcion)
                            {
                                case 1: printf("\nIngrese primer operando:\n");
                                        scanf("%f",&A);
                                        break;
                                case 2: printf("\nIngrese segundo operando:\n");
                                        scanf("%f",&B);
                                        break;
                                case 3: tot = sumar(A,B);
                                        printf("La suma es %.2f \n\n",tot);
                                        break;
                                case 4: tot = restar(A, B);
                                        printf("La resta es %.2f \n\n",tot);
                                        break;
                                case 5: tot = multiplicar(A,B);
                                        printf("La multiplicacion es %.2f \n\n",tot);
                                        break;
                                case 6: tot = division(A,B);
                                        if (tot !=0)
                                        {
                                        printf("La division es %.2f \n\n",tot);
                                        }
                                        break;
                                case 7: nfactor = (int)A;
                                        fact = factorial(nfactor);
                                        if(fact !=0)
                                        {
                                        printf("El factorial de: %d es %d \n\n",nfactor,fact);
                                        }
                                        break;
                                case 8: tot= totales(A,B);
                                        break;
                                case 9: printf("Salir del Sistema\n");
                                        break;
                            }
                    }
	return 0;
}

