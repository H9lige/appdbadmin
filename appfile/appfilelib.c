#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#define BUFFERMAX 1000000
// const char *filename, const char *opentype
// "r" lectura fichero debe existir "w" escritura sobreescribe si no existe crea
// "a" escritura al final si no existe crea "r+" lectura escritura y debe existir
// "w+" lectura escritura sobreescribe si no existe crea
// "r+b" o "rb+" actualiza en binario archivo lectura escritura "rb" solo lectura binario
char fileread(FILE *archivo, char *texto) {
	int i = 0;
	char caracter;
	printf("\nLeyendo fichero ... \n");
	while ((caracter = fgetc(archivo)) != EOF)
	{
		texto[i] = caracter;
		i++;
	}
	return;
}
int filewrite(FILE *archivo, char *texto) {
	printf("\nLeyendo fichero ... \n");
	fputs(texto, archivo);
}
int fileopen(const char filename,const char opentype) {
	FILE * archivo;
	errno_t err;
	// si open abre con exito referencia al archivo FILE* sino NULL
	err = fopen_s(&archivo,filename,opentype);
	if (err==NULL)
	{
		printf("\nError de lectura de archivos (%c)",err);
		exit(1);
	}
	else {
		//funcion trabaja sobre fichero
		char texto[BUFFERMAX];
		switch ((char)opentype)
		{
		case 'r':
			fileread(archivo, texto);
			break;
		case 'w':
			//filewrite(archivo,texto);
		default:
			break;
		}
		//retorna 0 al cerrar correctamente sino EOF
		if (!fclose(archivo))
		{
			printf("Fichero cerrado");
			return;//texto
		}
		else {
			return 1;
		}
	}
	return 0;
}