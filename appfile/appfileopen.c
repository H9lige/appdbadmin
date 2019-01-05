#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

// const char *filename, const char *opentype
// "r" lectura fichero debe existir "w" escritura sobreescribe si no existe crea
// "a" escritura al final si no existe crea "r+" lectura escritura y debe existir
// "w+" lectura escritura sobreescribe si no existe crea
// "r+b" o "rb+" actualiza en binario archivo lectura escritura "rb" solo lectura binario

int fileopen(char filename, char opentype) {
	FILE * archivo;
	char caracter;
	// si open abre con exito referencia al archivo FILE* sino NULL
	archivo = fopen(filename,opentype);
	if (archivo==NULL)
	{
		printf("\nError de lectura de archivos");
	}
	else {
		printf("\nEl contenido de Memory es \n");
		while ((caracter = fgetc(archivo)) != EOF)
		{
			printf("%c",caracter);
		}
		//retorna 0 al cerrar correctamente sino EOF
		fclose(archivo);
	}
	
	return 0;
}