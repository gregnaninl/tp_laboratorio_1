#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define A 20



int main()
{
    EPersona datos[A] ;


    int edades[3], auxEdades [3];
    int  i,x,auxInt,auxDni;
    int  conta1=0,conta2=0,conta3=0;
    char seguir='s';
    char respuesta='s';
    int opcion=0;


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                auxInt =obtenerEspacioLibre(datos);

                    if(auxInt>=0 )
                    {

                        printf("ingrese Nombre:");
                        fflush(stdin);
                        gets(datos[auxInt].nombre);
                        printf("ingrese DNI: ");
                        fflush(stdin);
                        scanf("%d",&datos[auxInt].dni);
                        printf("Ingrese edad: ");
                        fflush(stdin);
                        scanf("%d",&datos[auxInt].edad);
                        datos[auxInt].estado=1;
                        printf("\n\n");
                    }
                    else
                    {
                        printf("no hay espacio disponible!!!\n\n");
                        break;
                    }



                break;
            case 2:
                    system("cls");
                    printf("Ingrese numero de Dni:\n\n");
                    scanf("%d", &auxDni);

                    auxInt=buscarPorDni(datos,auxDni);


                    if(auxInt>=0)
                    {
                        printf("\nEsta seguro que quiere borrar el registro de:\n\n");
                        printf("Nombre:%s\nDni:%d\nEdad:%d\n\n",datos[auxInt].nombre,datos[auxInt].dni,datos[auxInt].edad);

                        respuesta= getche();
                        printf("\n\n");
                        if(respuesta=='s')
                        {
                            datos[auxInt].estado=0;
                            system("cls");

                        }
                        else
                        {
                            printf("El usuario cancelo la operacion\n\n");
                            system("cls");
                        }

                    }


                   if(auxInt<0)
                   {
                      printf("No existe el dni que esta buscando!!\n\n");
                   }


                break;
            case 3:
                system("cls");
                ordenarPorNombre(datos,A);

                 printf("Nombre\t\tDNI\t\t\tEdad\n\n");
                for(i=0; i<A ; i++)
                {
                    if(datos[i].estado==1)
                    {

                    printf("%s\t\t%d\t\t%d\t\n",datos[i].nombre,datos[i].dni,datos[i].edad);
                    }
                }
                 printf("\n\n");

                break;
            case 4:

                system("cls");
                for(i=0; i<A ; i++)
                {
                if(datos[i].estado==1)
                {
                    if(datos[i].edad<18 )
                    {
                       {
                       conta1++;
                       }
                    }
                    else
                    {

                   if(datos[i].edad>18 && datos[i].edad<35)
                    {
                    conta2++;
                    }
                     else
                    {

                    if(datos[i].edad>34)
                    {
                     conta3++;
                    }
                    }

                    }

                }
                }
                edades[0]=conta1;
                edades[1]=conta2;
                edades[2]=conta3;

                auxEdades[0]=conta1;
                auxEdades[1]=conta2;
                auxEdades[2]=conta3;

                x=edades[0];

                for(i=0 ; i<3; i++)
                {

                    if(edades[i]>x)
                    {
                        x= edades[i];
                    }

                }

            printf("<18\tentre 19-35\t>35\n");

            for(i=0; i<x ; i++)
            {

               if(edades[0]>0)
               {
                   printf(" *\t\t");
                   edades[0] = edades[0] - 1;
               }
               else
                printf(" \t\t");

                if(edades[1]>0)
               {
                   printf("*\t");
                   edades[1]=edades[1]-1;
               }
               else
                printf(" \t");

                if(edades[2]>0)
               {
                   printf(" *\n");
                   edades[2]=edades[2]-1;
               }
               else
                printf(" \n");

               }

                conta1=0;
                conta2=0;
                conta3=0;
                printf(" \n");





                break;
            case 5:
                seguir = 'n';
                break;

        }
    }



    return 0;
}
