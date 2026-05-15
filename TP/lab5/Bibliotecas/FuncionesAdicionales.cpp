//
// Created by carlo on 5/10/2025.
//
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "FuncionesAdicionales.h"

///cargar datos
///imprimir
///buscar
///buscar max y min
///invertir
///ordenamiento burbuja
///ordenar por indices
//eliminar duplicados

void cargarDatos(int *arr, int &cantDatos)
{
    ifstream arch("ArchivosDeDatos/entrada.txt", ios::in);
    if (not arch.is_open())
    {
        cout << "Error al abrir archivo de entrada.txt" << endl;
        exit(1);
    }

    cantDatos = 0;

    while (not arch.eof())
    {
        arch >> arr[cantDatos];
        cantDatos++;
    }
}

void imprimirArreglo(int *arr, int cantDatos)
{
    for (int i = 0; i < cantDatos; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int buscarPosNumero(int numeroBuscado, int *arr, int cantDatos)
{
    for (int i = 0; i < cantDatos; i++)
    {
        if (arr[i] == numeroBuscado)
        {
            return i;
        }
    }
}

void hallarMinYMax(int &min, int &max, int *arr, int cantDatos)
{
    min = INT_MAX;
    max = 0;

    for (int i = 0; i < cantDatos; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
}

void invertirOrden(int *arr, int cantDatos)
{
    int temp, i=0;

    for (i = 0; i < cantDatos/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[cantDatos-i-1];
        arr[cantDatos-i-1] = temp;
    }
}

void ordenamientoBurbuja(int *arr, int cantDatos)
{
    //vamos a comparar todos los datos en parejas cada pasada
    int i = 0, j = 0, temp;

    //como es en parejas, a cant de datos se le resta 1
    for (i = 0; i < cantDatos-1; i++)
    {
        //como ordenamos por pasadas, en cada pasada evaluamos menos que la anterior
        for (j = 0; j < cantDatos-i-1; j++)
        {
            //si un elemento es mayor al siguiente, reemplazamos sus posiciones
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void ordenamientoPorIndices(int *arr, int cantDatos, int *indOrdenados)
{
    //primero inicializamos el arreglo de indices ordenados con las
    //posiciones hasta el numero de datos
    int i=0, j=0, temp;

    for (i = 0; i < cantDatos; i++)
    {
        indOrdenados[i] = i;
    }

    for (i = 0; i < cantDatos-1; i++)
    {
        for (j = i+1; j < cantDatos; j++)
        {
            //como el arreglo de indices ordenados parte desde 0;
            //compararemos si no hay ningun valor siguiente mayor al valor de pos 0;
            //sumaremos al valor de la pos +1 y evaluaremos el siguiente numero
            //si hay un numero siguiente que sea mayor, entonces reemplazaremos sus pos
            if (arr[indOrdenados[i]] > arr[indOrdenados[j]])
            {
                temp = indOrdenados[i];
                indOrdenados[i] = indOrdenados[j];
                indOrdenados[j] = temp;
            }
        }
    }
}

void eliminarDuplicados(int *arr, int cantDatos, int &nuevoTam, int *arrSinDup)
{
    int i=0, j=0;
    bool esDuplicado = false;

    nuevoTam = 1;
    arrSinDup[0] = arr[0]; //el primer dato siempre se va a quedar

    //para cada valor en el arreglo principal hacemos pasadas chiquitas hasta
    //la posicion de ese valor
    for (i = 1; i < cantDatos; i++)
    {
        esDuplicado = false; //para cada pasada del arreglo principal asumimos que no esta repetido
        for (j = 0; j < nuevoTam; j++) //hacemos una pasada desde el inicio del arreglo sin duplicados
        {
            if (arr[i] == arrSinDup[j]) //si encuentra que el valor es igual pone que es duplicado
            {
                esDuplicado = true;
                break;
            }
        }
        if (not esDuplicado) // si no esta duplicado el valor lo agrega al nuevo arreglo y actualiza el tamaño
        {
            arrSinDup[nuevoTam] = arr[i];
            nuevoTam++;
        }
    }
}