#include <stdio.h>

int main(int argc, char const *angv[])
{
    FILE *p_archivo;
    p_archivo = fopen("Texto1.txt", "w");
    if(p_archivo != NULL)
    {
        prinf("Se crea el archivo. \n");
    }
    fclose(p_archivo);
    return 0;
}