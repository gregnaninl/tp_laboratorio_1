#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"




int main()
{
    EMovie* movie;
    EMovie* auxMovie;
    char leer[50];
    int x,i;
    int tam=0;



    char seguir='s';
    int opcion=0;

    movie=malloc(sizeof(EMovie));

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                  auxMovie = (EMovie*)realloc( movie, sizeof(EMovie)*(tam+1));
                   if (auxMovie == NULL)
                   {
                   printf("\nNo hay lugar en memoria\n");
                   break;
                   }
                   movie = auxMovie;
                   x=agregarPelicula(movie);
                   tam++;//Incremento el contador de peliculas
                     if(x==1){
                        printf("\n\nSe Agrego exitosamente la Pelicula\n\n");
                    }
                    else
                    {
                        printf("\n\nSe genero un error al cargar la Pelicula\n\n") ;
                    }

                    system("pause");
                    system("cls");

               break;
            case 2:

                    printf("\t\tBORRAR PELICULA\n\n");
                    imprimirPeliculas(movie);
                    printf("\n\nIngrese el titulo a Borrar: ");
                    fflush(stdin);
                    gets(leer);
                    x=buscarPelicula(leer);

                    if(x==1)
                    {
                    i=borrarPelicula(leer);
                    }
                    else
                    {
                        printf("\n\nSe Cancelo la operacion\n\n");
                    }

                    system("pause");
                    system("cls");
                break;
            case 3:
                    printf("\t\tMODIFICAR PELICULA\n\n");
                    imprimirPeliculas(movie);
                    printf("\n\nIngrese el titulo a modificar: ");
                    fflush(stdin);
                    gets(leer);
                    x=buscarPelicula(leer);
                    if(x==1)
                    {
                    i=modificarPelicula(leer);
                    }
                    else
                    {
                        printf("\n\nSe Cancelo la operacion\n\n");
                    }

                    system("pause");
                    system("cls");
               break;
            case 4:
                    x=generarPagina();
                    if(x==0){
                        printf("\n\nSe creo correctamente la Pagina WEB!!!\n\n");
                    }
                    else
                    {
                        printf("\n\nSe genero un error al escribir el archivo\n\n") ;
                    }
                    system("pause");
                    system("cls");
                break;
            case 5:

                free(movie);
                seguir = 'n';
                break;
        }
    }

    return 0;
}




