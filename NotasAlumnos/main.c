#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
void ingresarAlumno(char nombre[][20], char apellido[][20], int nLeg[], int n1[], int n2[], int tam, int *i);
float calcularPromedio(int a, int b);
void mostrarAlumnos(int numeroLegajo[], char apellido[][20], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam);
void ordenarAlumnos(int numeroLegajo[], char apellido[][20], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam);

int main()
{
    char nombre[TAM][20];
    char apellido[TAM][20];
    int numeroLegajo[TAM];
    int nota1[TAM];
    int nota2[TAM];
    int i = 0;
    float promedio[TAM];

   // ingresarAlumno(nombre, apellido, numeroLegajo, nota1, nota2, TAM, &cantAlumnos);
    char respuesta;
    do
    {

        printf("Ingrese el numero de legajo: ");
        scanf("%d", &numeroLegajo[i]);
        printf("\n");

        printf("Ingrese el nombre del estudiante %d: ", numeroLegajo[i]);
        fflush(stdin);
        gets(nombre[i]);
        printf("\n");

        printf("Ingrese el apellido: ");
        fflush(stdin);
        gets(apellido[i]);
        printf("\n");

        printf("Ingrese la nota del primer parcial: ");
        scanf("%d", &nota1[i]);
        printf("\n");

        printf("Ingrese la nota del segundo parcial: ");
        scanf("%d", &nota2[i]);
        printf("\n");

        printf("Desea ingresar otro alumno? \n");
        fflush(stdin);
        scanf ("%c", &respuesta);

        i++;
        if(i==TAM)
        {
            printf("Ya no puede ingresar mas alumnos.\n");
            respuesta = 'n';
        }

    }while(respuesta == 's');




    for(int j = 0; j <i; j++)
    {

        promedio[j] = calcularPromedio(nota1[j], nota2[j]);
    }


    mostrarAlumnos(numeroLegajo, apellido, nombre, nota1, nota2, promedio, i);

    ordenarAlumnos(numeroLegajo, apellido, nombre, nota1, nota2, promedio, i);

    mostrarAlumnos(numeroLegajo, apellido, nombre, nota1, nota2, promedio, i);


    return 0;
}

void mostrarAlumnos(int numeroLegajo[], char apellido[][20], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    printf("\t        ***Listado Alumnos***\n");
    printf("__________________________________________________________________\n\n");
    printf("N Legajo\t Apellido\t  Nombre    nota 1     nota 2     promedio\n");
    for(int j = 0; j < tam; j++)
    {
        printf("%5.d  %15s %15s      %5.d        %5.d       %.2f  \n", numeroLegajo[j], apellido[j], nombre[j], nota1[j], nota2[j], promedio[j]);
        printf("\n");
    }

}

void ordenarAlumnos(int numeroLegajo[], char apellido[][20], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int auxInt;
    float auxFloat;
    char auxArray[20];
    for(int i = 0; i < tam; i++)
    {
        for(int j = i+1 ; j<tam; j++)
        {
            if(numeroLegajo[i]>numeroLegajo[j])
            {
                auxInt = numeroLegajo[i];
                numeroLegajo[i] = numeroLegajo[j];
                numeroLegajo[j] = auxInt;

                strcpy(auxArray, apellido[i]);
                strcpy(apellido[i], apellido[j]);
                strcpy(apellido[j], auxArray);

                strcpy(auxArray, nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxArray);

                auxInt = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxInt;

                auxInt = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxInt;

                auxFloat = promedio[i];
                promedio[i] = promedio[j];
                promedio[j] = auxFloat;
            }
        }
    }
}



//void ingresarAlumno(char nombre[][20], char apellido[][20], int nLeg[], int n1[], int n2[], int tam, int *i)
//{
//    char respuesta;
//    do
//    {
//
//        printf("Ingrese el numero de legajo: ");
//        scanf("%d", &nLeg[i]);
//        printf("\n");
//
//        printf("Ingrese el nombre del estudiante %d: ", nLeg[i]);
//        fflush(stdin);
//        gets(nombre[i]);
//        printf("\n");
//
//        printf("Ingrese el apellido: ");
//        fflush(stdin);
//        gets(apellido[i]);
//        printf("\n");
//
//        printf("Ingrese la nota del primer parcial: ");
//        scanf("%d", &n1[i]);
//        printf("\n");
//
//        printf("Ingrese la nota del segundo parcial: ");
//        scanf("%d", &n2[i]);
//        printf("\n");
//
//        printf("Desea ingresar otro alumno? \n");
//        fflush(stdin);
//        scanf ("%c", &respuesta);
//
//        &i++;
//        if(i==tam)
//        {
//            printf("Ya no puede ingresar mas alumnos.\n");
//            respuesta = 'n';
//        }
//
//    }while(respuesta != 's');
//
//
//
//}

float calcularPromedio(int a, int b)
{
    return (float) (a+b)/2;
}
