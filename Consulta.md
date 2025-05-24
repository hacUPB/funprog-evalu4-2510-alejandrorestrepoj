# Consulta 

## Funciones de `<string.h>`

| Función     | Prototipo                                                 | Parámetros                                                                                                | Descripción breve                                                                                                 |
| ----------- | --------------------------------------------------------- | --------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------- |
| **strlen**  | `size_t strlen(const char *s);`                           | `s` – cadena de caracteres terminada en `\0`.                                                             | Devuelve la longitud (nº de caracteres) de la cadena *sin* contar el terminador `\0`.                             |
| **strcpy**  | `char *strcpy(char *dest, const char *src);`              | `dest` – buffer destino;<br>`src` – cadena origen (terminada en `\0`).                                    | Copia todo `src` (incluido `\0`) a `dest`.                                                                        |
| **strncpy** | `char *strncpy(char *dest, const char *src, size_t n);`   | `dest` – buffer destino;<br>`src` – cadena origen;<br>`n` – nº máximo de caracteres a copiar.             | Copia hasta `n` caracteres: si `src` < `n` copia también ceros hasta `n`, si `src` ≥ `n` NO añade `\0`.           |
| **strcat**  | `char *strcat(char *dest, const char *src);`              | `dest` – cadena destino (debe tener espacio);<br>`src` – cadena a anexar.                                 | Añade `src` al final de `dest` (sobrescribe su `\0` y pone el nuevo).                                             |
| **strncat** | `char *strncat(char *dest, const char *src, size_t n);`   | `dest` – cadena destino;<br>`src` – cadena a anexar;<br>`n` – nº máximo de caracteres de `src` a agregar. | Añade a `dest` los primeros `n` caracteres de `src`, y luego `\0`.                                                |
| **strcmp**  | `int strcmp(const char *s1, const char *s2);`             | `s1`, `s2` – cadenas a comparar.                                                                          | Compara lexicográficamente: devuelve <0 si `s1<s2`, 0 si iguales, >0 si `s1>s2`.                                  |
| **strncmp** | `int strncmp(const char *s1, const char *s2, size_t n);`  | `s1`, `s2` – cadenas;<br>`n` – nº máximo de caracteres a comparar.                                        | Igual que `strcmp`, pero solo hasta `n` caracteres.                                                               |
| **strchr**  | `char *strchr(const char *s, int c);`                     | `s` – cadena;<br>`c` – carácter buscado (se convierte a `char`).                                          | Devuelve puntero a la primera ocurrencia de `c` en `s`, o `NULL` si no está.                                      |
| **strstr**  | `char *strstr(const char *haystack, const char *needle);` | `haystack` – cadena a buscar en;<br>`needle` – subcadena buscada.                                         | Devuelve puntero a la primera aparición de `needle` en `haystack`, o `NULL`.                                      |
| **strtok**  | `char *strtok(char *s, const char *delim);`               | `s` – cadena a fragmentar (solo en la primera llamada);<br>`delim` – conjunto de separadores.             | Retorna token tras token: llama con `s`, luego con `NULL`. Modifica la cadena, reemplazando separadores por `\0`. |

### Ejemplo de uso

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char texto[100] = "Hola mundo, ¡bienvenidos!";
    char copia[100];

    printf("Longitud: %zu\n", strlen(texto));

    strcpy(copia, texto);
    printf("Copia: \"%s\"\n", copia);

    char *p = strstr(texto, "bienvenidos");
    if (p) printf("Encontrado en: \"%s\"\n", p);

    char s[] = "uno,dos;tres cuatro";
    char *tok = strtok(s, ",; ");
    while (tok) {
        printf("Token: %s\n", tok);
        tok = strtok(NULL, ",; ");
    }
    return 0;
}
```

---

## Funciones de `<ctype.h>`

| Función     | Prototipo             | Parámetros                                            | Descripción breve                                                            |
| ----------- | --------------------- | ----------------------------------------------------- | ---------------------------------------------------------------------------- |
| **isalpha** | `int isalpha(int c);` | `c` – carácter (pasado como `unsigned char` o `EOF`). | Devuelve no cero si `c` es letra (A–Z o a–z).                                |
| **isdigit** | `int isdigit(int c);` | `c` – carácter.                                       | No cero si `c` es dígito decimal (0–9).                                      |
| **isalnum** | `int isalnum(int c);` | `c` – carácter.                                       | No cero si es letra o dígito (es combinación de `isalpha` o `isdigit`).      |
| **islower** | `int islower(int c);` | `c` – carácter.                                       | No cero si `c` es letra minúscula (a–z).                                     |
| **isupper** | `int isupper(int c);` | `c` – carácter.                                       | No cero si `c` es letra mayúscula (A–Z).                                     |
| **tolower** | `int tolower(int c);` | `c` – carácter.                                       | Si es letra mayúscula, devuelve su minúscula; sino devuelve `c` sin cambios. |
| **toupper** | `int toupper(int c);` | `c` – carácter.                                       | Si es letra minúscula, devuelve su mayúscula; sino devuelve `c` sin cambios. |

### Ejemplo de uso

```c
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char *s = "AbC123!";
    for (size_t i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (isalpha(c)) {
            printf("%c es letra, mayúscula? %d, minúscula? %d\n", c, isupper(c), islower(c));
        } else if (isdigit(c)) {
            printf("%c es dígito\n", c);
        } else {
            printf("%c es otro carácter\n", c);
        }
        printf("  tolower → %c, toupper → %c\n", tolower(c), toupper(c));
    }
    return 0;
}
```


## Calloc

Descripcion: La función calloc() reserva espacio de almacenamiento para una matriz de elementos num , cada uno de ellos de longitud tamaño bytes. A continuación, la función calloc() proporciona a todos los bits de cada elemento un valor inicial de 0.

Prototipo: 
```
void *calloc(size_t num, size_t size).
```

Parametros: 
* nitems − Representa el número de elementos a asignar.
* tamaño − Representa el tamaño de cada elemento.

Valor de retorno: La función calloc() devuelve un puntero al espacio reservado. El espacio de almacenamiento al que apunta el valor de retorno está adecuadamente alineado para el almacenamiento de cualquier tipo de objeto. Para obtener un puntero a un tipo, utilice una conversión de tipo en el valor de retorno. El valor de retorno es NULL si no hay suficiente almacenamiento, o si núm o tamaño es 0.

Ejemplo: 

```
#include <stdio.h>
#include <stdlib.h>
int main() {
   int n = 5;
   int *array;
   
   // use calloc function to allocate the memory
   array = (int*)calloc(n, sizeof(int));
   
   if (array == NULL) {
      fprintf(stderr, "Memory allocation failed!\n");
      return 1;
   }
   
   //Display the array value
   printf("Array elements after calloc: ");
   for (int i = 0; i < n; i++) {
      printf("%d ", array[i]);
   }
   printf("\n");
   
   //free the allocated memory
   free(array);
   return 0;
}
```

# Realloc

Descripcion: La función realloc() cambia el tamaño de un bloque de almacenamiento reservado anteriormente. El argumento ptr apunta al principio del bloque. El argumento tamaño proporciona el nuevo tamaño del bloque, en bytes. El contenido del bloque no se modifica hasta el más corto de los tamaños nuevos y antiguos.

Si ptr es NULL, realloc() reserva un bloque de almacenamiento de tamaño bytes. No da necesariamente a todos los bits de cada elemento un valor inicial de 0.

Si tamaño es 0 y ptr no es NULL, realloc() libera el almacenamiento asignado a ptr y devuelve NULL

Prototipo:
```
void *realloc(void *ptr, size_t size)
```

Parametros: La función realloc() en C toma dos parámetros: ptr y size. ptr es un puntero a la memoria que se va a redimensionar, y size es el nuevo tamaño en bytes. 

Detalles de los parámetros:

#### *ptr (void ):

Este puntero debe apuntar a una ubicación de memoria que haya sido asignada previamente mediante malloc(), calloc(), o realloc(). Si ptr es NULL, realloc() funcionará como malloc() y asignará un nuevo bloque de memoria. 

#### size (size_t):

Este parámetro especifica el nuevo tamaño del bloque de memoria en bytes. Si el tamaño es 0, la memoria apuntada por ptr se desasigna, y realloc() devuelve NULL. 

Valor de retorno: La función realloc() devuelve un puntero al bloque de almacenamiento reasignado. La función realloc() puede mover la ubicación de almacenamiento del bloque. Por lo tanto, el argumento ptr en la función realloc() no es necesariamente el mismo que el valor de retorno.

Si tamaño es 0, la función realloc() devuelve NULL. Si no hay suficiente almacenamiento para expandir el bloque al tamaño especificado, el bloque original no se modifica y la función realloc() devuelve NULL.

El almacenamiento al que el valor de retorno apunta está alineado para el almacenamiento de cualquier tipo de objeto.



Ejemplo: 

```
#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
  long * array;    /* start of the array */
  long * ptr;      /* pointer to array   */
  int    i;        /* index variable     */
  int  num1, num2; /* number of entries of the array */
  void print_array( long *ptr_array, int size);
  printf( "Enter the size of the array\n" );
  scanf( "%i", &num1);
  /* allocate num1 entries using malloc() */
  if ( (array = (long *) malloc( num1 * sizeof( long ))) != NULL )
  {
     for ( ptr = array, i = 0; i < num1 ; ++i ) /* assign values */
        *ptr++ = i;
     print_array( array, num1 );
     printf("\n");
  }
  else { /*  malloc error  */
    perror( "Out of storage" );
    abort();
  }
  /* Change the size of the array ... */
  printf( "Enter the size of the new array\n" );
  scanf( "%i", &num2);
  if ( (array = (long *) realloc( array, num2* sizeof( long ))) != NULL )
  {
     for ( ptr = array + num1, i = num1; i <= num2; ++i )
        *ptr++ = i + 2000;  /* assign values to new elements */
     print_array( array, num2 );
  }
  else { /* realloc error */
    perror( "Out of storage" );
    abort();
  }
}
 
void print_array( long  * ptr_array, int size )
{
  int i;
  long * index = ptr_array;
  printf("The array of size %d is:\n", size);
  for ( i = 0; i < size; ++i )           /* print the array out    */
    printf( "  array[ %i ] = %li\n", i, ptr_array[i] );
}
 
/**** If the initial value entered is 2 and the second value entered 
      is 4, then the expected output is:
Enter the size of the array
The array of size 2 is:
  array[ 0 ] = 0
  array[ 1 ] = 1
Enter the size of the new array
The array of size 4 is:
  array[ 0 ] = 0
  array[ 1 ] = 1
  array[ 2 ] = 2002
  array[ 3 ] = 2003                                                */
  ```