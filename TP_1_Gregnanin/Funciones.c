# include "funciones.h"



float sumar(float x, float y)
{

    float resultado;
    resultado=(float) x + y;
    return resultado;
}


float restar (float x, float y)
{
    float rta;
    rta= (float)x - y;
    return rta;

}

float dividir (float x, float y)
{
    float  rta;
    rta= (float)x / y;
    return rta;

}


float multiplicar (float x, float y)
{
    float rta;
    rta= (float)x * y;
    return rta;

}


int factorial(int x)
{
    int rta;
    if(x==1)
    {
        rta=1;
    }
    else
    {
        rta= x * factorial(x-1);
    }
    return rta;
}




