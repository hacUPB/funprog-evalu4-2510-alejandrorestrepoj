# DEFINICION

Archivo: Grupo de datos estructurados que son almacenados en algun medio que pueden ser usados por las aplicaciones. Tiene dos tipos de archivos:

### Archivos de texto
Secuencia de caracteres organizadas en lineas terminadas por un caracter de nueva linea (\n)

Canciones, fuentes de programas, base de datos simples, etc.

Son planos: Todas las letras tienen el mismo formato y no hay palabras subrayadas

### Archivos Binarios

Secuencia de bytes que contiene informacion de cualquier tipo codificada en binario para el proposito de almacenamiento y procesamiento en ordenadores

Ejecutables, compilados, etc.

EJ: 4000 bytes / 1024 = 3,9 kylobytes

Para leer un archivo binario, hay que comprender lo que hay en su interior, y poder aplicarlo necesitamos:

* Archivo de cabecera <stdio.h>

# ¿Como hacerlo?

#### Puntero a un archivo
Es el hilo comun que unifica el sistema de E/S con un buffer, ademas se dice que apunta a una informacion que define varias cosas sobre el archivo, incluyendo el nombre, el estado y la posicion actual del archivo


```
File *archivo;
```

### Abriendo un archivo

La funcion fopen() abre una secuencia para que pueda ser utilizada y la asocia a un archivo

Su prototipo es:
```
File *fopen(const char *nombreAr, const char *modo);
```

* nombreAr: Puntero a una cadena de caracteres nombre valido del archivo y puede incluir una especificacion del directorio
* La cadena a la que apunta modo determina como se abre el archivo. La siguiente tabla muestra los valores permitidos para modo

r = Archivo solo lectura
w = Abre solo para escritura. Si el archivo ya existe, el apuntador se coloca al inicio y sobreescribe, destruyendo al archivo anterior
a = Se abre un archivo para agregar nuevos datos al final. Si el archivo no existe, crea uno nuevo
r+ = Se abre un archivo para realizar modificaciones. Permite leer y escribir. El archivo tiene que existir
w+ = Se abre un archivo para leer y escribir. Si el archivo existe, el apuntador se coloca al inicio, sobreescribe y destruye el archivo anterior
a+ = Se abre un nuevo archivo para lectura y para incorporar nuevos datos al final. Si el archivo no existe, se crea uno nuevo.

### Funcion fprintf()

Funciona igual que printf en cuanto a parametros, pero la salida se dirige a un archivo en lugar de a la pantalla

El prototipo correspondiente de fprintf es:

```
int fprintf(File *archivo, const char *formato, argumento, ...);
```

### Funcion fscanf()

Funciona igual que scanf en cuanto a parametros, pero la entrada se toma de un fichero en lugar del teclado.

El prototipo correspondiente de fscanf es:

```
int fscanf(FILE *fichero, const char *formato, argumento, ...)
```