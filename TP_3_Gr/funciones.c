#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"




int  agregarPelicula(EMovie* p )
{
   int x=0;
   FILE* f;

    printf("Ingrese Titulo:\n");
    fflush(stdin);
    gets(p->titulo);
    printf("Ingrese genero:\n");
    fflush(stdin);
    gets(p->genero);
    printf("Ingrese duracion:\n");
    scanf("%d",&(p->duracion));
    printf("Ingrese descripcion:\n");
    fflush(stdin);
    gets(p->descripcion);
    printf("Ingrese puntaje:\n");
    scanf("%d",&(p->puntaje));
    printf("Ingrese el link de la imagen:\n");
    fflush(stdin);
    gets(p->linkImagen);
    p->estado=1;

    f=fopen("peliculas.dat","ab+"); // append binario, lo crea si no existe
    if(f==NULL)
    {

        printf("No se pudo abrir el archivo");
        exit(1);
    }

    x=fwrite(p,sizeof(EMovie),1,f);


    fclose(f);




    return x;

}

int borrarPelicula(char leer[])
{
   int x=2;
   int i;
   FILE* arch;
   FILE* auxArch;
   EMovie auxMovi;


    arch=fopen("peliculas.dat","rb+");
     if(arch==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        exit(1);
    }

    auxArch=fopen("auxPeliculas.dat","wb+");
     if(arch==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        exit(1);
    }

    while(!feof(arch))
    {
        i=fread(&auxMovi,sizeof(EMovie),1,arch);
        if(i==1)
        {
        if(stricmp(leer,auxMovi.titulo)!=0)
        {
        x=fwrite(&auxMovi,sizeof(EMovie),1,auxArch);
        }
        }

    }
    fclose(arch);
    fclose(auxArch);

    copiarArchivo(arch,auxArch);
    if(x==0)
    {
        printf("\n\nSe Borro correctamente el Titulo pedido\n\n");
    }


    return x;
}

int buscarPelicula(char titulo[])
{
    FILE* arch;
    EMovie auxMovi;
    int resp;
    int i;
    int x=0;
    arch=fopen("peliculas.dat","rb+");
     if(arch==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        exit(1);
    }

    while(!feof(arch))
    {
        i=fread(&auxMovi,sizeof(EMovie),1,arch);
        if(i==1)
        {
        if(stricmp(titulo,auxMovi.titulo)==0)
        {
            x=1;
            printf("\n\nEsta Seguro que quiere seleccionar esta Pelicula: %s\n\n",auxMovi.titulo);
            printf("Ingrese 1 para Si o 0 para NO:");
            scanf("%d",&resp);

        }
        }
    }

    if(x==0)
    {
        printf("\n\nEl Titulo no Existe\n\n");
    }

    fclose(arch);
    return resp;
}


int  generarPagina()
{
    FILE* f;
    FILE* arch;
    int i;
    EMovie auxMovi;



    f=fopen("index.html","wb+"); // append binario, lo crea si no existe
    if(f==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        exit(1);
    }

    arch=fopen("peliculas.dat","rb+");
     if(arch==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        exit(1);
    }

    while(!feof(arch))
    {
        i=fread(&auxMovi,sizeof(EMovie),1,arch);
        if(i==1)
        {
         fprintf(f,"<article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src='%s'alt=''>\n</a>\n<h3>\n<a href='#'>%s</a>\n</h3>\n<ul>\n<li>Género:%s</li>\n<li>Puntaje:%d</li>\n<li>Duración:%d</li>\n</ul>\n<p>%s<p>\n</article>\n\n",auxMovi.linkImagen,auxMovi.titulo,auxMovi.genero,auxMovi.puntaje,auxMovi.duracion,auxMovi.descripcion);
        }
    }

    fclose(f);
    fclose(arch);
    return i;
}

void imprimirPeliculas(EMovie* p)
{
   int x=0;
   FILE* arch;
   EMovie auxMovi;

    arch=fopen("peliculas.dat","rb+");
     if(arch==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        exit(1);
    }
       printf("*********************************************************\n");
       printf("*Titulo\t\tGenero\t\tDuracion\tPuntaje *\n");
       printf("*********************************************************\n\n");

    while(!feof(arch))
    {
        x=fread(&auxMovi,sizeof(EMovie),1,arch);
        if(x==1)
        {
        printf("%s\t%s\t%d\t\t%d\n",auxMovi.titulo,auxMovi.genero,auxMovi.duracion,auxMovi.puntaje);
        }
    }
     printf("*********************************************************\n\n");
    fclose(arch);

}

void copiarArchivo(FILE* arch, FILE* auxArch)
{


   int x=2;
   int i;
   EMovie auxMovi;


    arch=fopen("peliculas.dat","wb+");
     if(arch==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        exit(1);
    }

    auxArch=fopen("auxPeliculas.dat","rb+");
     if(auxArch==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        exit(1);
    }

    while(!feof(auxArch))
    {
        i=fread(&auxMovi,sizeof(EMovie),1,auxArch);
        if(i==1)
        {
        x=fwrite(&auxMovi,sizeof(EMovie),1,arch);
        }

    }
    fclose(arch);
    fclose(auxArch);

}

int modificarPelicula(char leer[])
{
   int x=2;
   int i;
   FILE* arch;
   FILE* auxArch;
   EMovie auxMovi;
   EMovie modMovie;


    arch=fopen("peliculas.dat","rb+");
     if(arch==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        exit(1);
    }

    auxArch=fopen("auxPeliculas.dat","wb+");
     if(arch==NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        exit(1);
    }

    while(!feof(arch))
    {
        i=fread(&auxMovi,sizeof(EMovie),1,arch);
        if(i==1)
        {
        if(stricmp(leer,auxMovi.titulo)!=0)
        {
        x=fwrite(&auxMovi,sizeof(EMovie),1,auxArch);
        }
        else
        {
            printf("Ingrese Titulo:\n");
            fflush(stdin);
            gets(modMovie.titulo);
            printf("Ingrese genero:\n");
            fflush(stdin);
            gets(modMovie.genero);
            printf("Ingrese duracion:\n");
            scanf("%d",&modMovie.duracion);
            printf("Ingrese descripcion:\n");
            fflush(stdin);
            gets(modMovie.descripcion);
            printf("Ingrese puntaje:\n");
            scanf("%d",& modMovie.puntaje);
            printf("Ingrese el link de la imagen:\n");
            fflush(stdin);
            gets(modMovie.linkImagen);
            modMovie.estado=1;

         x=fwrite(&modMovie,sizeof(EMovie),1,auxArch);

        }
        }

    }
    fclose(arch);
    fclose(auxArch);

    copiarArchivo(arch,auxArch);
    if(x==0)
    {
        printf("\n\nSe Modifico correctamente el Titulo pedido\n\n");
    }


    return x;
}
