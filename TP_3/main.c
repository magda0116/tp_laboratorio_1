#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#define PELIS 3

int main()
{
    EMovie E_peli;

    FILE *pFile;

    int opcion=0;

    if((pFile = fopen("Pelicula.bin", "rb+"))== NULL)

        if((pFile = fopen("pelicula.bin", "wb+"))==NULL)
        {
            printf("ERROR. No se puede abrir el archivo binario...\n");
            exit(1);
        }
    while (opcion !=5)
    {
        Menu();

        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1: system("cls");
                    Agregar(&E_peli, pFile);
                    break;

            case 2: system("cls");
                    Borrar(&E_peli, pFile);
                    break;

            case 3: system("cls");
                    Modificar(&E_peli, pFile);
                    break;

            case 4: system("cls");
                    Generar_PWeb(&E_peli, pFile);
                    break;

            case 5: system("cls");
                    printf("Salir del programa....\n");
                    break;

          default : system("cls");
                    Val_Menu(&opcion,"Error opcion invalida. Vuelva al menu\n","");
                    break;
        }
    }

    fclose(pFile);

    return 0;
}
