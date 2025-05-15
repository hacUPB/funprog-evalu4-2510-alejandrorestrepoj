#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Prototipos de funciones
int menu(void);
int nombre_arch(void);
int estad_txt(void);
int frecu_vocal(void);
int reemplazar(void);
int save(void);

int main(void)
{
    int opc;
    do {
        opc = menu();
        switch (opc) {
            case 1:
                nombre_arch();
                break;
            case 2:
                estad_txt();
                break;
            case 3:
                frecu_vocal();
                break;
            case 4:
                reemplazar();
                break;
            case 5:
                save();
                break;
            default:
                if (opc >= 1 && opc <= 5)
                    ; // no debería llegar aquí
                else
                    printf("Saliendo del programa...\n");
        }
    } while (opc >= 1 && opc <= 5);

    return 0;
}

int menu(void)
{
    int opc;
    printf("\n¿Que desea hacer?\n");
    printf(" 1. Ingresar el nombre del archivo a leer\n");
    printf(" 2. Calcular estadísticas de un texto\n");
    printf(" 3. Calcular frecuencia de vocales (a, e, i, o, u)\n");
    printf(" 4. Cambiar una palabra por otra (find & replace)\n");
    printf(" 5. Guardar resultado en archivo\n");
    printf(" 6. Salir\n");
    printf("Opción: ");
    if (scanf("%d", &opc) != 1) {
        opc = 6;
        while (getchar() != '\n');
    }
    return opc;
}

int nombre_arch(void)
{
    char filename[256];
    FILE *file;
    char *content = NULL;
    char buffer[BUFFER_SIZE];
    size_t totalSize = 0;

    printf("Ingrese el nombre del archivo .txt: ");
    scanf("%255s", filename);

    file = fopen(filename, "r");
    if (!file) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        size_t len = strlen(buffer);
        char *temp = realloc(content, totalSize + len + 1);
        if (!temp) {
            perror("Error al asignar memoria.");
            free(content);
            fclose(file);
            return 1;
        }
        content = temp;
        memcpy(content + totalSize, buffer, len);
        totalSize += len;
        content[totalSize] = '\0';
    }
    fclose(file);

    printf("\nContenido del archivo:\n%s\n", content);
    free(content);
    return 0;
}

