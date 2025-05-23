
# Documentación del Programa en C

## 1. Explicación del análisis del problema

Este programa tiene como objetivo manipular y analizar archivos de texto plano `.txt`. Se solicitó una aplicación que leyera un archivo, calculara estadísticas como número de caracteres, palabras, líneas y espacios, analizara la frecuencia de las vocales, permitiera reemplazar palabras específicas por otras, y finalmente, guardara el resultado en un nuevo archivo.

Para resolver el problema, decidimos trabajar con memoria dinámica (`malloc`, `realloc`) para almacenar el contenido del archivo, lo cual nos da flexibilidad sin depender de un tamaño fijo. Se estructuró el código por funciones, cada una encargada de una tarea específica del flujo general del programa.

---

## 2. Estrategia de solución

### Estructura general

El programa está compuesto por un menú que permite al usuario ejecutar las siguientes operaciones:

- Leer el contenido de un archivo `.txt` (función `nombre_arch`)
- Calcular estadísticas del texto (`estad_txt`)
- Calcular frecuencia de vocales (`frecu_vocal`)
- Reemplazar una palabra por otra (`reemplazar`)
- Guardar el contenido resultante en un archivo (`save`)

El contenido del archivo se guarda en un puntero global `content`, y se usan otras variables globales para almacenar los resultados del análisis, de manera que estén disponibles al momento de guardar.

---

## 3. Tabla de variables

### Función: `nombre_arch`

| Función     | Variable  | Tipo      | Rol      |
|-------------|-----------|-----------|----------|
| nombre_arch | filename  | char[]    | Entrada  |
| nombre_arch | buffer    | char[]    | Temporal |
| nombre_arch | file      | FILE*     | Temporal |
| nombre_arch | content   | char*     | Salida   |
| nombre_arch | totalSize | size_t    | Salida   |

### Función: `estad_txt`

| Función    | Variable    | Tipo     | Rol     |
|------------|-------------|----------|---------|
| estad_txt  | content     | char*    | Entrada |
| estad_txt  | num_chars   | int      | Salida  |
| estad_txt  | num_words   | int      | Salida  |
| estad_txt  | num_spaces  | int      | Salida  |
| estad_txt  | num_lines   | int      | Salida  |

### Función: `frecu_vocal`

| Función      | Variable | Tipo     | Rol     |
|--------------|----------|----------|---------|
| frecu_vocal  | content  | char*    | Entrada |
| frecu_vocal  | freq     | int[5]   | Salida  |

### Función: `reemplazar`

| Función     | Variable   | Tipo     | Rol                |
|-------------|------------|----------|--------------------|
| reemplazar  | palabra    | char[]   | Entrada            |
| reemplazar  | reemplazo  | char[]   | Entrada            |
| reemplazar  | nuevo      | char*    | Salida             |
| reemplazar  | content    | char*    | Entrada/Modificada |

### Función: `save`

| Función | Variable   | Tipo     | Rol      |
|---------|------------|----------|----------|
| save    | filename   | char[]   | Entrada  |
| save    | file       | FILE*    | Temporal |
| save    | content    | char*    | Entrada  |
| save    | num_chars  | int      | Entrada  |
| save    | freq       | int[5]   | Entrada  |

---

## 4. 🧮Diagramas, esquemas o pseudocódigo

### Pseudocódigo de `main`

```
Inicio
Solicitar palabra a buscar y palabra de reemplazo
Recorrer el texto original:
    Si se encuentra la palabra objetivo:
        Copiar la palabra de reemplazo al nuevo buffer
    Si no:
        Copiar carácter original al nuevo buffer
Actualizar puntero `content` con el nuevo contenido
```

---
