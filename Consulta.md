# Consulta 

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