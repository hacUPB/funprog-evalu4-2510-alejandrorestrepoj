//Escribir los datos de IMC en otro archivo diferente.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int cant_registros;
    float *estatura;
    float *peso;
    float *imc;
    //1. Declarar el puntero
    FILE *p_datos;
    
    //2. Abrir el archivo
    p_datos = fopen("datos.txt", "r");
    
    //3. Verificar que se pudo abrir el archivo
    if(!p_datos)
    {
        printf("No se pudo abrir el archivo. \n");
        return 1;
    }

    //4. Operaciones de lectura
    fscanf(p_datos, "%d", &cant_registros);
    printf("Cantidad registros = %d\n", cant_registros);

    //Reservamos la memoria de forma dinámica
    peso = (float *)malloc(cant_registros * sizeof(float));
    estatura = (float *)malloc(cant_registros * sizeof(float));
    imc = (float *)malloc(cant_registros * sizeof(float));

    if (!peso || !estatura || !imc) //Cualquiera de los punteros es nulo, se cierra.
    {
        perror("No se pudo reservar la memoria. \n");
        fclose(p_datos);
        return 1;
    }
    

    for (int i = 0; i < cant_registros; i++)
    {
        fscanf(p_datos, "%f", &peso[i]);
        printf("Peso = %f\n", peso[i]);
        fscanf(p_datos, "%f", &estatura[i]);
        printf("Estatura = %f\n", estatura[i]);
        imc[i] = peso[i] / (estatura[i]*estatura[i]);
        printf("IMC = %f\n", imc[i]);
    } 

    //Liberar memoria
    free(peso);
    free(imc);
    free(estatura);
    return 0;
}