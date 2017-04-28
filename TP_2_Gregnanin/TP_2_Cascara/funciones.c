#include "funciones.h"
#define A 20


int buscarPorDni(EPersona datos[], int dni)
   {

    int i,x, flag=0;

    for(i=0 ; i<A ; i++)
    {
        if(datos[i].dni==dni)
        {
            x=i;
            flag=1;
        }

    }
    if(flag==0)
    {
        x=-1;
    }
       return x;
   }

   int  obtenerEspacioLibre(EPersona datos [])
   {
       int i,x, flag=0;



       for(i=0; i<A ; i++)
       {
           if(datos[i].estado!=1)
           {
               x=i;
               flag=1;
           }

       }
       if(flag==0)
       {
           x=-1;
       }
   return x;
   }


   void ordenarPorNombre(EPersona datos [], int tam)
   {
    int i;
    int j;
    EPersona auxPersona;

        for(i=0; i<A-1;i++)
                    {
                        for(j=i+1; j<A ; j++)
                        {

                            if(stricmp( datos[i].nombre, datos[j].nombre)>0)
                            {

                               auxPersona = datos[i];
                               datos[i] = datos[j];
                               datos[j] = auxPersona;

                            }
                        }

                    }

        return 0;
   }
