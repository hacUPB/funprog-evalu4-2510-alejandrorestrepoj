// Reservar memoria para ingresar el nombre de un curso de la carrera 
// Solicitar y guardar el nombre del curso en la memoria reservada
// Solicitar el codigo NRC del curso
// Redimensionar memoria para que el nombre quepa exacto 
// Solicitar el codigo NRC del curso
// Redimensionar la memoria para guardar el nuevo dato

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *nombre_curso;
    int nrc;
    printf("Ingrese el nombre del curso: \n");
    nombre_curso = (char*)calloc(50, sizeof(char)); // Reservar memoria para el nombre del curso
    scanf("%s", nombre_curso); // Guardar el nombre del curso en la memoria reservada
    printf("Ingrese el codigo NRC del curso: \n");
    scanf("%d", &nrc); // Solicitar el codigo NRC del curso
    nombre_curso = (char*)realloc(nombre_curso, strlen(nombre_curso) + 1); // Redimensionar memoria para que el nombre quepa exacto
    printf("El nombre del curso es: %s\n", nombre_curso); // Imprimir el nombre del curso
    printf("El codigo NRC del curso es: %d\n", nrc); // Imprimir el codigo NRC del curso
    free(nombre_curso); // Liberar la memoria reservada
    return 0;
}
// El programa solicita al usuario el nombre de un curso y su código NRC