#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[100];
    int estado;
}EMovie;


int agregarPelicula(EMovie* );

int generarPagina();

int borrarPelicula(char leer[]);

int buscarPelicula(char titulo[]);

void imprimirPeliculas(EMovie* p);

void copiarArchivo(FILE* arch, FILE* auxArch);

int modificarPelicula(char leer[]);





/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */


/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */


#endif // FUNCIONES_H_INCLUDED
