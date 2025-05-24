
# Documentación del Programa en C

## 1. Explicación del análisis del problema

Este programa tiene como objetivo manipular y analizar archivos de texto plano `.txt`. Se solicitó una aplicación que leyera un archivo, calculara estadísticas como número de caracteres, palabras, líneas y espacios, analizara la frecuencia de las vocales, permitiera reemplazar palabras específicas por otras, y finalmente, guardara el resultado en un nuevo archivo.

Para resolver el problema, decidimos trabajar con memoria dinámica (`malloc`, `realloc`) para almacenar el contenido del archivo, lo cual nos da flexibilidad sin depender de un tamaño fijo. Se estructuró el código por funciones, cada una encargada de una tarea específica del flujo general del programa.

La primera funcion es nombre_arch(void), la cual tiene el fin de ingresar el nombre del archivo de texto (.txt), cargando su contenido en la memoria siguiendo estos pasos:

1. Pide al usuario que inserte el nombre junto al formato del archivo (.txt).
2. Intenta abrir el archivo en forma de lectura. 
2.1. En caso de que no se abra, mostrara un error y cerrara el archivo que se intento abrir.
3. Si el archivo se abre correctamente, leera cada linea del contenido y guardara todo en una sola variable (content).
4. Mostrara el contenido en la pantalla.

La segunda funcion es estad_txt, la cual cargara las "estadisticas" del texto (Es decir, la cantidad de caracteres, palabras, espacios en blancos y lineas.) siguiendo estos pasos.

1. Verifica si hay algun archivo correctamente.
1.1. En caso de que no, te devolvera al menu.
2. Recorre cada caracter del texto, aumentando el contador segun sea el que identifique.
3. Mostrara el contenido en la pantalla.

La tercera funcion es frecu_vocal, la cual contara cuantas veces aparece cada vocal (a,e,i,o,u) en el contenido del archivo usando cinco contadores, siguiendo estos pasos:

1. Verifica si hay algun archivo correctamente.
1.1. En caso de que no, te devolvera al menu.
2. Inicia los contadores de la funcion.
3. Recorre cada caracter del texto -Si encuentra una mayuscula, la transforma a minuscula con tolower- e incrementa el contador correspondiente.
4. Mostrara el contenido en la pantalla.

La cuarta funcion es reemplazar, la cual permite al usuario buscar una palabra y reemplazarla por otra en todo el contenido del texto, siguiendo estos pasos:

1. Verifica si hay algun archivo correctamente.
1.1. En caso de que no, te devolvera al menu.
2. Le pedira al usuario la palabra que desea buscar y la que desea guardar, guardandolo en variables.
3. Se creara un nuevo contenido con las palabras reemplazadas.
4. Libera la memoria del contenido anterior, reemplazandolo por el nuevo.
5. Le dira al usuario que el contenido fue reemplazado con exito.

La quinta funcion es save, la cual permite guardar todo lo hecho anteriormente en un nuevo archivo, siguiendo estos pasos:
1. Verifica si hay algun archivo correctamente.
1.1. En caso de que no, te devolvera al menu.
2. Pide al usuario el nombre del archivo donde desea guardar los resultados.
3. Crear un nuevo archivo en modo de escritura. 
4. En el archivo se escribiran las estadisticas del texto, la frecuencia de las vocales; o mejor dicho, el contenido actual modificado.
5. Cerrara el archivo e informara que se guardo correctamente.

---

## 2. Estrategia de solución

Al igual que con retos anteriores, se decidio dividir en distintas funciones donde abarque cada una de las acciones que se desea hacer en el nuevo archivo de texto.

La parte mas dificil fue hacer que se abriera un archivo con un nombre indeterminado que el usuario llenara, pero una vez concluida esta parte las otras cuatro funciones no fueron tan complicadas como las otras. 

A diferencia de otros retos, aca las acciones no eran independientes una de las otras, asi que por obligacion se debia hacer que la primera opcion del menu fuera obligatoria. En caso de no hacerla correctamente, se señalaria y se devolveria al menu, para asi cargar el archivo desde la primera opcion. Ya, al abrir el archivo se podia hacer cualquiera de las acciones, pero todas en un mismo archivo. 

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

### Pseudocódigo de `main`

```
Inicio
        Escribir "Menu:"
        Escribir " 1. Ingresar el nombre del archivo a leer"
        Escribir " 2. Calcular estadísticas de un texto"
        Escribir " 3. Calcular frecuencia de vocales (a, e, i, o, u)"
        Escribir " 4. Cambiar una palabra por otra"
        Escribir " 5. Guardar resultado en archivo"
        Escribir " 6. Salir"
        Escribir "Opción: "
        Leer opcion
        Segun la opcion leida:
            Hacer el caso 1:
                Escribir "Ingrese el nombre del archivo con extensión .txt"
                Leer nombre_archivo.
                Abrir archivo en modo lectura.
                Si no se puede abrir.
                    Escribir "No se pudo abrir el archivo"
                    Cerrar el archivo.
                    Fin si.
                Fin Si.
                Leer el contenido del archivo.
                Guardar en variable 'contenido'.
                Escribir "Contenido del archivo:"
                Escribir contenido.
            Fin si.

            Hacer el caso 2:
                Si no hay contenido cargado.
                    Escribir "No se ha cargado ningún archivo."
                    Salir del caso 2.
                Fin Si.
                Inicializar contadores: caracteres, palabras, espacios, líneas.
                Para cada carácter dentro de la variable 'contenido'.
                    Si el carácter no es salto de línea, incrementar caracteres.
                    Si el carácter es espacio, incrementar espacios.
                    Si el carácter es espacio o salto, y estamos dentro de palabra, incrementar palabras.
                    Si el carácter es salto de línea, incrementar líneas.
                Fin para.
                Escribir "Total de caracteres: ", caracteres.
                Escribir "Total de palabras: ", palabras.
                Escribir "Total de espacios: ", espacios.
                Escribir "Total de líneas: ", líneas.
            Fin del caso 2.

            Caso 3:
                Si no hay contenido cargado.
                    Escribir "No se ha cargado ningún archivo."
                    Salir del caso 3.
                Fin Si.
                Inicializar contadores de vocales: a, e, i, o, u.
                Para cada carácter en el texto abierto.
                    Convertir a minúscula.
                    Si es vocal, incrementar contador correspondiente.
                Fin para.
                Escribir frecuencia de cada vocal.
            Fin del caso 3.

            Caso 4:
                Si no hay contenido cargado.
                    Escribir "No se ha cargado ningún archivo."
                    Salir del caso 4.
                Fin si.
                Escribir "Palabra a buscar:"
                Leer palabra_buscar.
                Escribir "Palabra de reemplazo:"
                Leer palabra_reemplazo.
                Crear nuevo contenido reemplazando todas las apariciones de palabra_buscar.
                Actualizar contenido con el nuevo texto.
                Escribir "Reemplazo completado."
            Fin del caso 4.

            Caso 5:
                Si no hay contenido cargado.
                    Escribir "No se ha cargado ningún archivo."
                    Salir del caso 5.
                Fin si.
                Escribir "Ingrese el nombre del archivo de salida:"
                Leer nombre_salida.
                Abrir el archivo de salida en modo escritura.
                Escribir las estadísticas al archivo.
                Escribir la frecuencia de vocales al archivo.
                Escribir el contenido modificado al archivo.
                Cerrar archivo.
                Escribir "Archivo guardado exitosamente."
            Fin del caso 5.

            Caso 6:
                Escribir "Saliendo del programa..."
            Fin del caso 6.
        Fin hasta que la opcion sea mayor que 5
Fin.
---
