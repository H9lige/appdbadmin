// appdb.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <stdio.h>

int main(char mode)
{
    printf("Hello World!\n");
	switch ((char)mode)
	{//j = json | c = csv | e = excel
	case 'j':
		//se usa json_object('ex','[52,50]')->'{"ex":"[52,50]"}'
		//se usa json_object('ex',json('[52,50]'))->'{"ex":[52,50]}'
		//se usa json_object('ex',json_array(52,50))->'{"ex":[52,50]}'
		break;
	case 'c':
		break;
	case 'e':
		break;
	default:
		break;
	}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 
//	1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
