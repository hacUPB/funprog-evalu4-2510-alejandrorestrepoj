#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

//1. **Ingresar el nombre del archivo a leer.**
    //- El usuario debe poder digitar el nombre de un archivo `.txt` para ser leído desde disco.
    //- Usar memoria dinámica para cargar el contenido completo del archivo en un arreglo de caracteres.
//2. **Calcular estadísticas del texto:**
    //- Total de caracteres (excluyendo `\n` si se desea).
    //- Total de palabras (definidas como secuencias separadas por espacios).
    //- Total de espacios en blanco.
    //- Total de líneas.
//3. **Calcular la frecuencia de aparición de las vocales (a, e, i, o, u)**
    //- Mostrar cuántas veces aparece cada vocal (mayúsculas y minúsculas combinadas).
//4. **Cambiar una palabra del texto por otra (find & replace):**
    //- Pedir al usuario una palabra a buscar y otra para reemplazarla.
    //- Hacer el reemplazo en todo el texto utilizando memoria dinámica si es necesario.
//5. **Guardar los resultados en un nuevo archivo:**
    //- Preguntar al usuario el nombre del archivo de salida.
    //- Guardar en este archivo:
        //- Las estadísticas calculadas.
        //- La frecuencia de vocales.
        //- El texto modificado (si hubo reemplazo de palabra).

int menu()
{
    int opc;
    printf("¿Que desea hacer? \n");
    printf(" 1. Ingresar el nombre del archivo a leer. \n 2. Calcular estadisticas de un texto. \n 3. Calcular la frecuencia de aparición de las vocales (a, e, i, o, u) \n 4. Cambiar una palabra por otra (find and replace) \n 5. Guardar archivo. \n");
    scanf("%d", &opc);
    return opc;
}

int nombre_arch();
int estad_txt();
int frecu_vocal();
int reemplazar();
int save();

int main(void)
{
    int opc = menu();
    do
    {
        opc = menu();
        switch (opc)
        {
        case 1:
            printf("Nombre del archivo.");
            nombre_arch();
            break;
    
        case 2:
            printf("Estadisticas del texto.");
            estad_txt();
            break;

        case 3: 
            printf("Frecuencia de vocales.");
            frecu_vocal();
            break;

        case 4:
            printf("Cambiar palabras.");
            save();
            break;

        case 5:
            printf("Guardar.");
            break;
    
        default:
            break;
        }
    } while (opc <= 5);
    return 0;
}

int nombre_arch()
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
            perror("Error al asignar memoria");
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