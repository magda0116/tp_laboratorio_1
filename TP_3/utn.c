#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#define PELIS 3

/** \brief Muestra por pantalla un menu de opcion.
 * \return Void.
 */

void Menu()
{
    printf("\t\t\tMENU\n\n");
    printf("\t\t\t----\n\n");
    printf("1.AGREGAR PELICULA\n2.BORRAR PELICULA\n3.MODIFICAR PELICULA\n4.GENERAR PAGINA WEB\n5.SALIR\n\nIngrese una opcion valida del menu:\n");
}


/** \brief Valida la opcion Menu.
 * \param  int *opc. Es el puntero de un entero
 * \param  char mensaje[]. Es el mensaje a mostrar
 * \param  char mensajeError[]. Es el mensaje de error a mostrar
 * \return Retorna -1 Error. Retorna 0 Ok
 */

int Val_Menu(int *opc,char mensaje[],char mensajeError[])
{
    char aux_menu[256];
    int a_menu;

    system("cls");
    printf("%s",mensaje);
    gets(aux_menu);
    a_menu = atoi (aux_menu);

    if(a_menu <1 && a_menu >5)
    {
        system("cls");
        printf("%s",mensajeError);
        gets(aux_menu);
        return -1;
    }
    else
    {
         *opc = a_menu;
         return 0;
    }
}

/** \brief Agrega pelicula al archivo.
 * \param  EMovie *E_peli. Es el puntero de la estructura.
 * \param  FILE *pFile. Es el puntero de archivo.
 * \return void.
 */

void Agregar(EMovie *E_peli, FILE *pFile)
{
    int estado;

    int Aux_Duracion, Aux_Puntaje;

    estado = 0;

    printf("\t\t\tALTA\n\n");
    printf("\t\t\t----\n\n");

    printf("\nIngrese Titulo de la pelicula:\n");
    fflush(stdin);
    gets(E_peli->ETitulo);
    strupr(E_peli->ETitulo);
//    Val_Cadena(E_peli->ETitulo);

    printf("\nIngrese Genero de la pelicula:\n");
    fflush(stdin);
    gets(E_peli->EGenero);
    strupr(E_peli->EGenero);
  //  Val_Cadena(E_peli->EGenero);

    printf("\nIngrese Duracion de la pelicula:\n");
    scanf("%d",&Aux_Duracion);
 //   Aux_Duracion= Val_Entero(Aux_Duracion,1,999);

    printf("\nIngrese Descripcion de la pelicula:\n");
    fflush(stdin);
    gets(E_peli->EDescripcion);
    strupr(E_peli->EDescripcion);
 //   Val_Cadena(E_peli->EDescripcion);

    printf("\nIngrese Puntaje de la pelicula:\n");;
    scanf("%d", &Aux_Puntaje);
 //   Aux_Puntaje= Val_Entero(Aux_Puntaje,1,10);

    printf("\nIngrese Link de Imagen de la pelicula:\n");
    fflush(stdin);
    gets(E_peli->ELImagen);
    strupr(E_peli->ELImagen);
//    Val_Cadena(E_peli->ELImagen);

    estado = 1;

    fseek(pFile,0L,SEEK_END);

    fwrite(&E_peli, sizeof(EMovie), 1, pFile);

    if(estado == 0)
    {
        printf("ERROR. No se pudo guardar la pelicula\n");
        system("pause");
    }
    else
    {
        printf("La pelicula se guardo con exito.....\n");
        system("pause");
        system("cls");
    }
}

/** \brief Borra pelicula al archivo.
 * \param  Emovie *E_peli. Es el puntero de la estructura.
 * \param  FILE *pFile. Es el puntero de archivo.
 * \return void.
 */

void Borrar(EMovie *E_peli, FILE *pFile)
{
    int estado;
    char Aux_Borrar[256];

    estado = 0;

    printf("\t\t\tBAJA\n\n");
    printf("\t\t\t----\n\n");

    printf("Ingrese el Titulo de la pelicula que desea dar de Baja Logica:\n");
    fflush(stdin);
    gets(Aux_Borrar);

    rewind(pFile);

    while(!feof(pFile))
    {
        fread(&E_peli,sizeof(EMovie),1,pFile);

        if(stricmp(Aux_Borrar, E_peli->ETitulo)==0)
        {
            fseek(pFile,(-1)*sizeof(EMovie),SEEK_CUR);

            fwrite(&E_peli, sizeof(EMovie), 1, pFile);
            printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de Imagen: %s\n\n",E_peli->ETitulo,E_peli->EGenero,E_peli->EDuracion,E_peli->EDescripcion,E_peli->EPuntaje,E_peli->ELImagen);
            printf("\n\nLa Pelicula se borro con exito.....\n");
            estado=1;
            system("pause");
            system("cls");
            return 0;
         }
    }
    if(estado==0)
    {
        printf("ERROR. No se pudo borrar la pelicula.....\n");
        system("pause");
        system("cls");
    }
}


/** \brief Valida la Cadena de caracteres. Funcion generica
 * \param  char opc[]. Lee cadena de caracteres
 * \return void.
 */

void Val_Cadena (char opc[])
{
    char aux_cadena[256];
    fflush(stdin);
    gets(aux_cadena);

    while(strlen(aux_cadena) < 1 || strlen(aux_cadena) >81)
    {
        printf("Error, reingrese....\n");
        gets(aux_cadena);
    }
        strcpy(opc,aux_cadena);
        return;

}

/** \brief Valida numeros enteros. Funcion generica.
 * \param  int opc. Entero de opcion ingresada.
 * \param  int desde. Valor limite minimo.
 * \param  int hasta. Valor limite maximo.
 * \return opc- Retorna valor de opcion.
 */

int Val_Entero(int opc, int desde, int hasta)
{
  while (opc< desde || opc > hasta)
  {
        printf("Error, reingrese  puntaje de la pelicula:\n");
        scanf("%d", &opc);
  }
  return opc;
}

/** \brief Modifica pelicula al archivo.
 * \param  EMovie *E_peli. Es el puntero de la estructura
 * \param  FILE *pFile .Es el puntero del archivo
 * \return void.
 */

void Modificar(EMovie *E_peli, FILE *pFile)
{
    int estado;

    int Aux_EntModificar;
    char Aux_Modificar[256];

    int opcion=0;

    estado=0;

    printf("\t\t\tMODIFICAR\n\n");
    printf("\t\t\t---------\n\n");

    printf("Ingrese el Titulo de la pelicula que desea modificar:\n");
    fflush(stdin);
    gets(Aux_Modificar);

    rewind(pFile);

    while(!feof(pFile))
    {
        fread(&E_peli,sizeof(EMovie),1,pFile);

        if(stricmp(Aux_Modificar, E_peli->ETitulo)==0)
        {

            printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de Imagen: %s\n\n",E_peli->ETitulo,E_peli->EGenero,E_peli->EDuracion,E_peli->EDescripcion,E_peli->EPuntaje,E_peli->ELImagen);

            while (opcion!=7)
            {
                printf("\t\t\tMENU A MODIFICAR\n\n");
                printf("1.Titulo a modificar\n2.Genero a modificar\n3.Duracion a modificar\n4.Descripcion a modificar\n5.Puntaje a modificar\n6.Link de imagen a modificar\n\nElija opcion:\n\n");
                scanf("%d", &opcion);

            switch(opcion)
            {
            case 1: system("cls");
            printf("Ingrese Titulo a modificar:\n");
            fflush(stdin);
            gets(Aux_Modificar);
  //          Val_Cadena(Aux_Modificar);
            strcpy(E_peli->ETitulo, Aux_Modificar);
            break;

            case 2: system("cls");
            printf("Ingrese Genero a modificar:\n");
            fflush(stdin);
            gets(Aux_Modificar);
   //         Val_Cadena(Aux_Modificar);
            strcpy(E_peli->EGenero, Aux_Modificar);
            break;

            case 3: system("cls");
            printf("Ingrese Duracion a modificar:\n");
            scanf("%d", &Aux_EntModificar);
            E_peli->EDuracion = Aux_EntModificar;
  //          Aux_EntModificar= Val_Entero(Aux_EntModificar,1,999);
            break;

            case 4: system("cls");
            printf("Ingrese Descripcion a modificar:\n");
            fflush(stdin);
            gets(Aux_Modificar);
  //          Val_Cadena(Aux_Modificar);
            strcpy(E_peli->EDescripcion, Aux_Modificar);
            break;

            case 5: system("cls");
            printf("Ingrese Puntaje a modificar:\n");
            scanf("%d", &Aux_EntModificar);
            E_peli->EPuntaje = Aux_EntModificar;
 //           Aux_EntModificar= Val_Entero(Aux_EntModificar,1,999);
            break;

            case 6: system("cls");
            printf("Ingrese Link de Imagen a modificar:\n");
            fflush(stdin);
            gets(Aux_Modificar);
   //         Val_Cadena(Aux_Modificar);
            strcpy(E_peli->ELImagen, Aux_Modificar);
            break;

            case 7: system("cls");
                    printf("Salir del menu a modificar");
                    break;
            }
            }
            fseek(pFile,(-1)*sizeof(EMovie),SEEK_CUR);
            fwrite(&E_peli, sizeof(EMovie), 1, pFile);

            printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de Imagen: %s\n\n",E_peli->ETitulo,E_peli->EGenero,E_peli->EDuracion,E_peli->EDescripcion,E_peli->EPuntaje,E_peli->ELImagen);

            printf("\n\nLa Pelicula se modifico con exito.....\n");

            estado=1;
            system("pause");
            system("cls");
            return 0;
        }
    }
    if(estado==0)
    {
        printf("ERROR. No se pudo modificar la pelicula.....\n");
        system("pause");
        system("cls");
    }
}

/** \brief Genera pagina web al archivo
 * \param  EMovie *E_peli. Es el puntero de la estructura
 * \param  FILE *pFile .Es el puntero del archivo
 * \return void.
 */

int Generar_PWeb(EMovie *E_peli,FILE *pFile)
{
    int i;

    FILE*f;

    printf("\t\t\tGENERAR PAGINA WEB\n\n");
    printf("\t\t\t------------------\n\n");

    f=fopen("index.html","w");

    int retorno=-1;

    if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {

        fprintf(f,"\n<html>");
        fprintf(f,"\n<head>");
        fprintf(f,"\n<title>Listado de  peliculas</title>");
        fprintf(f,"\n</head>");
        fprintf(f,"\n<body>");

        fprintf(f,"\n<h4> Titulo : </h4>");

         for(i=0; i<PELIS; i++)
         {
            if(E_peli->Eestado !=0)
            {
                fprintf(f,"\n<!-- Repetir cada pelicula -->");
                fprintf(f,"\n<article class='col-md-4 article-intro'>");
                fprintf(f,"\n<a href='#'>");
                fprintf(f,"\n<img class='img-responsive img-rounded' src='%s' alt=''>",E_peli->ELImagen);
                fprintf(f,"\n</a>");
                fprintf(f,"\n<h3>");
                fprintf(f,"\n<a href='#'>%s</a>",E_peli->ETitulo);
                fprintf(f,"\n</h3>");
                fprintf(f,"\n<ul>");
                fprintf(f,"\n<li>Género:%s</li>",E_peli->EGenero);
                fprintf(f,"\n<li>Puntaje:%d</li>",E_peli->EPuntaje);
                fprintf(f,"\n<li>Duración:%d</li>	",E_peli->EDuracion);
                fprintf(f,"\n</ul>");
                fprintf(f,"\n<p>%s</p>",E_peli->EDescripcion);
                fprintf(f," \n</article>");
                fprintf(f,"	\n<!-- Repetir cada pelicula -->");
            }
         }
        fprintf(f,"</body>");
        fprintf(f,"</html>");
        retorno=0;
    }
    fclose(f);
    printf("PAGINA CREADA\n");
    system("pause");
    return retorno;
}


