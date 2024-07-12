# Get Next Line

## Descripción

Este proyecto es parte del 42 cursus y se llama **get next line**. El objetivo es trabajar la gestión de la lectura de ficheros mediante un buffer. La función realiza la escritura en pantalla de un fichero linea por linea. La función está preparada para trabajar con solo un fichero. La parte del bonus, por el contrario, es una ampliación de la misma función para que la función pueda gestionar varios _file descriptor_ simultaneamente. Para mas detalle, se recomienda leer el enunciado del proyecto en el _subject.pdf_

## Prototipo de la función y la compilación
El prototipo de la función es la siguiente. Recibe como argumento el _file descriptor_ de un fichero que de antemano ha sido abierto de manera correcta con `open()` y devuelve la siguiente linea del fichero. Se considera una linea la cadena de caracteres que acaba en un salto de linea.

```sh
char	*get_next_line(int fd)
```
Para compilar un programa que use dicha función se tiene que añadir los dos ficheros de la siguiente manera:

```sh
cc programa.c get_next_line.c get_next_line_utils.c -o nombre_del_programa.c
```
Para compilar un programa que use dicha función con la opción bonus se tiene que añadir los dos ficheros del bonus de la siguiente manera:

```sh
cc programa.c get_next_line_bonus.c get_next_line_utils_bonus.c -o nombre_del_programa.c
```
## Ejemplo de uso

```sh
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int  main(void)
{
    int        fd;
    char       *line;
    const char *fichero = "fichero.txt";

    fd = open(fichero, O_RDONLY);
    if (fd == -1)
        return(perror("Error al abrir el archivo"), 1);
    while ((line = get_next_line(fd)) != NULL)
        printf("%s", line);
    close(fd);
    return (0);
}
```

