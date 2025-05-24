#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

char *content = NULL;
size_t totalSize = 0;
int num_chars = 0, num_words = 0, num_spaces = 0, num_lines = 0;
int freq[5] = {0}; // a, e, i, o, u

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
            case 1: nombre_arch();    break;
            case 2: estad_txt();      break;
            case 3: frecu_vocal();    break;
            case 4: reemplazar();     break;
            case 5: save();           break;
            default: printf("Saliendo del programa...\n");
        }
    } while (opc >= 1 && opc <= 5);

    free(content); 
    return 0;
}

int menu(void)
{
    int opc;
    printf("Menu:\n");
    printf(" 1. Ingresar el nombre del archivo a leer\n");
    printf(" 2. Calcular estadisticas de un texto\n");
    printf(" 3. Calcular frecuencia de vocales (a, e, i, o, u)\n");
    printf(" 4. Cambiar una palabra por otra (find & replace)\n");
    printf(" 5. Guardar resultado en archivo\n");
    printf(" 6. Salir\n");
    printf("Opcion: ");
    if (scanf("%d", &opc) != 1) {
        opc = 6;
        while (getchar() != '\n');
    }
    getchar();
    return opc;
}

int nombre_arch(void)
{
    char filename[256];
    FILE *file;
    char buffer[BUFFER_SIZE];

    free(content);
    content = NULL;
    totalSize = 0;

    printf("Ingrese el nombre del archivo y al final .txt: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");
    if (!file) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        size_t len = strlen(buffer);
        char *temp = (char *) realloc(content, totalSize + len + 1);
        if (!temp) {
            perror("Error al asignar memoria.");
            free(content);
            fclose(file);
            return 1;
        }
        content = temp;
        strcpy(content + totalSize, buffer, len);
        totalSize += len;
        content[totalSize] = '\0';
    }
    fclose(file);

    printf("\nContenido del archivo:\n%s\n", content);
    return 0;
}

int estad_txt(void)
{
    if (content == NULL) {
        printf("No se ha cargado ningun archivo.\n");
        return 1;
    }

    num_chars = num_words = num_spaces = num_lines = 0;
    int in_word = 0;

    for (size_t i = 0; i < totalSize; i++) {
        if (content[i] != '\n')          num_chars++;
        if (content[i] == ' ')           num_spaces++;
        if (isspace((unsigned char)content[i])) {
            if (in_word) {
                num_words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
        if (content[i] == '\n')          num_lines++;
    }
    if (in_word) num_words++;

    printf("\nEstadisticas del archivo:\n");
    printf("Total de caracteres (sin contar saltos de linea): %d\n", num_chars);
    printf("Total de palabras: %d\n", num_words);
    printf("Total de espacios en blanco: %d\n", num_spaces);
    printf("Total de lineas: %d\n", num_lines);

    return 0;
}

int frecu_vocal(void)
{
    if (content == NULL) {
        printf("No se ha cargado ningun archivo.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) freq[i] = 0;

    for (size_t i = 0; i < totalSize; i++) {
        char c = tolower((unsigned char)content[i]);
        switch (c)
        {
            case 'a': freq[0]++; break;
            case 'e': freq[1]++; break;
            case 'i': freq[2]++; break;
            case 'o': freq[3]++; break;
            case 'u': freq[4]++; break;
        }
    }

    printf("\nFrecuencia de vocales:\n");
    printf("a: %d\n", freq[0]);
    printf("e: %d\n", freq[1]);
    printf("i: %d\n", freq[2]);
    printf("o: %d\n", freq[3]);
    printf("u: %d\n", freq[4]);

    return 0;
}

int reemplazar(void)
{
    if (content == NULL) {
        printf("No se ha cargado ningun archivo.\n");
        return 1;
    }

    char palabra[100], reemplazo[100];
    printf("Palabra a buscar: ");
    fgets(palabra, sizeof(palabra), stdin);
    palabra[strcspn(palabra, "\n")] = '\0';

    printf("Palabra de reemplazo: ");
    fgets(reemplazo, sizeof(reemplazo), stdin);
    reemplazo[strcspn(reemplazo, "\n")] = '\0';

    size_t len_pal = strlen(palabra);
    size_t len_rep = strlen(reemplazo);
    size_t cap_nuevo = totalSize;
    char *nuevo = malloc(cap_nuevo + 1);
    if (!nuevo) {
        perror("Error de memoria");
        return 1;
    }

    size_t i = 0, j = 0;
    while (i < totalSize) {
        if (len_pal > 0 && i + len_pal <= totalSize
            && strncmp(&content[i], palabra, len_pal) == 0)
        {
            while (j + len_rep >= cap_nuevo) {
                cap_nuevo *= 2;
                char *t = realloc(nuevo, cap_nuevo + 1);
                if (!t) {
                    perror("Error al expandir memoria");
                    free(nuevo);
                    return 1;
                }
                nuevo = t;
            }
            memcpy(&nuevo[j], reemplazo, len_rep);
            j += len_rep;
            i += len_pal;
        } else {
            nuevo[j++] = content[i++];
        }
    }
    nuevo[j] = '\0';

    free(content);
    content = nuevo;
    totalSize = j;

    printf("Reemplazo completado.\n");
    return 0;
}

int save(void)
{
    if (content == NULL) {
        printf("No hay contenido para guardar.\n");
        return 1;
    }

    char filename[256];
    printf("Ingrese el nombre del archivo de salida: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("No se pudo crear el archivo");
        return 1;
    }

    fprintf(file, "Estadisticas del archivo:\n");
    fprintf(file, "Total de caracteres (sin contar saltos de linea): %d\n", num_chars);
    fprintf(file, "Total de palabras: %d\n", num_words);
    fprintf(file, "Total de espacios en blanco: %d\n", num_spaces);
    fprintf(file, "Total de lineas: %d\n\n", num_lines);

    fprintf(file, "Frecuencia de vocales:\n");
    fprintf(file, "a: %d\n", freq[0]);
    fprintf(file, "e: %d\n", freq[1]);
    fprintf(file, "i: %d\n", freq[2]);
    fprintf(file, "o: %d\n", freq[3]);
    fprintf(file, "u: %d\n\n", freq[4]);

    fprintf(file, "Texto modificado:\n%s\n", content);
    fclose(file);

    printf("Archivo guardado exitosamente como '%s'\n", filename);
    return 0;
}
