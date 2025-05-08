#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int can_res;
    float *resistencias;
    printf("Ingrese la cantidad de resistencias: \n");
    scanf("%d", &can_res);
    resistencias = (float*)calloc(sizeof(float), can_res);
    for (int i = 0; i < can_res; i++) {
        printf("Ingrese el valor de la resistencia %d: \n", i + 1);
        scanf("%f", &resistencias[i]);        
    }
    float resistencia_total = 0;
    for (int i = 0; i < can_res; i++) {
        resistencia_total += 1/resistencias[i];
    }
    printf("La resistencia total es: %.2f\n", resistencia_total);
    free(resistencias);
    resistencias = NULL;
    return 0;
}

