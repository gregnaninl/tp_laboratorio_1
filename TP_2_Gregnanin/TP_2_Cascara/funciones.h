#ifndef FUNCIONES_H_INCLUDED


#define FUNCIONES_H_INCLUDED

typedef struct {

    int dni,edad,estado;
      char nombre [20];

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona []);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona [], int );

/**
 * Organiza el array por nombre.
 * @param lista el array se pasa como parametro.
 * @param tamaño del array .
 * @return void
 */
void ordenarPorNombre(EPersona datos [], int tam);

#endif // FUNCIONES_H_INCLUDED
