//
// Created by carlo on 2/10/2025.
//
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesAdicionales.h"

void cargarDatos(int *arr,int &cantDatos)
{
    int i=0, suma=0, promedio;

    ifstream arch("ArchivosDeDatos/notas.txt", ios::in);
    if (not arch.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }

    arch >> cantDatos;
    for (i=0;i<cantDatos;i++)
    {
        arch >> arr[i];
        suma += arr[i];
    }
    promedio = suma/cantDatos;
    cout << "El promedio es: "<<promedio<<endl;
}

void encontrarMaxyMin(int *arr,int cantDatos, int &max, int &min)
{
    int i=0;
    max = 0;
    min = INT_MAX;

    for (i=0;i<cantDatos;i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
        if (arr[i]<min)
        {
            min = arr[i];
        }
    }
}

void imprimir(int *arr, int cantDatos)
{
    int i=0;
    for (i=0;i<cantDatos;i++)
    {
        cout << "Elemento: " << i + 1 << " "<< arr[i] << endl;
    }
}

void invertir(int *arr, int cantDatos)
{
    int temp, i=0;

    for (i=0;i<cantDatos/2;i++)
    {
        temp = arr[i];
        arr[i] = arr[cantDatos-1-i];
        arr[cantDatos-1-i] = temp;
        cout << arr[i] << endl;
    }
}

int eliminarDuplicados(int *arr, int cantDatos)
{
    int nuevoTamano, i=0, j;
    bool esDuplicado;

    if (cantDatos == 0) return 0;
    nuevoTamano = 1;

    for (i=1;i<cantDatos;i++)
    {
        esDuplicado = false;
        for (j=1; j<nuevoTamano; j++)
        {
            if (arr[i] == arr[j])
            {
                esDuplicado = true;
                break;
            }
        }
        if (not esDuplicado)
        {
            arr[nuevoTamano] = arr[i];
            nuevoTamano++;
        }
    }
}

void ordenamientoBurbuja(int *arr, int cantDatos)
{
    int i, j, temp;
    for (i=0; i<cantDatos; i++)
    {
        for (j=0; j<cantDatos-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void ordenamientoPorIndices(int *arr, int cantDatos, int *indicesOrd)
{
    int i, j, temp;
    //inicializar el arreeglo de indices para tenerlo en
    // 0, 1, 2 ,3 ,4 .... , cantDatos-1
    for (i=0; i<cantDatos; i++)
    {
        indicesOrd[i] = i;
    }

    //ejecutar ordenamiento
    for (i=0; i<cantDatos-1; i++)
    {
        for (j=i+1; j<cantDatos; j++)
        {
            if (arr[indicesOrd[i]] > arr[indicesOrd[j]])
            {
                temp = indicesOrd[i];
                indicesOrd[i] = indicesOrd[j];
                indicesOrd[j] = temp;
            }
        }
    }
}