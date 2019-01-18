#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
#include "pch.h"

#define MAXCOL 100
#define MAXQUERY 1000

typedef struct {
	char db;
	char sqlType;
	char table;
	char callback;
	char query[MAXQUERY];
	char columnName[MAXCOL];
	char columnType[MAXCOL];
	char columnData[MAXCOL];
}sql;

int insertData(sql *consulta);
int createTable(sql *consulta);
int selectData(sql *consulta);
int dropTable(sql *consulta);
int callback(void* data, int ncols, char** values, char** headers);

int main(int argc, char* argv[]) {
	system("cls");
	sql *consulta;
	sqlite3 *db; //tipo de sqlite3.o
	char *zErr = 0;
	int rc;
	//arg main -file -tabla -consulta(cr,in,se,dr) -funcionDeVuelta
	consulta->db = argv[1];
	consulta->table = argv[2];
	consulta->sqlType = argv[3];
	consulta->callback = argv[4];
	rc = sqlite3_open(consulta->db, &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	else {
		fprintf(stderr, "<<<Base de datos abierta correctamente>>>\n");
		switch (consulta->sqlType)
		{
		case 'cr':
			createTable(&consulta);
			break;
		case 'in':
			insertData(&consulta);
			break;
		case 'se':
			selectData(&consulta);
			break;
		case 'dr':
			dropTable(&consulta);
			break;
		default:
			listarTabla(&consulta);
			break;
		}	
			char *argF1 = "Consulta SQL realizada!";
			sqlite3_exec(db,consulta->query,consulta->callback,NULL,argF1);
		if (rc != SQLITE_OK)
		{
			if (zErr != NULL)
			{
				fprintf(stderr, "SQL Error: %s\n", zErr);
				sqlite3_free(zErr);
			}
		}
		sqlite3_close(db);
		return 0;
	}
}
int insertData(sql *consulta) {
	strcpy(consulta->query, "insert into ");
	strcat(consulta->query, consulta->table);
	strcat(consulta->query, "(");
	int i = 0;
	while (i < MAXCOL)
	{
		printf("\nNombre de columna a insertar<%d>: ", i);
		scanf("%s", &consulta->columnName[i]);
		strcat(consulta->query, consulta->columnName[i]);
	CONTINUAR:
		printf("\n¿Quieres introducir mas?Si/No");
		char *z;
		scanf("%s", z);
		strlwr(z);
		if ((z[0] == 's') || (z[0] == 's' && z[1] == 'i'))
		{
			strcat(consulta->query, ", ");
			i++;
		}
		else {
			if ((z[0] == 'n') || (z[0] == 'n' && z[1] == 'o'))
			{
				strcat(consulta->query, ") values (");
				break;
			}
			else {
				goto CONTINUAR;
			}
		}
	}
	i = 0;
	while (consulta->columnName[i]!='\0')
	{
		printf("\nValor para columna %s: ", consulta->columnName[i]);
		scanf("%s", &consulta->columnData[i]);
		strcat(consulta->query, consulta->columnData[i]);
		strcat(consulta->query, ", ");
		i++;
	}
	strcat(consulta->query, ");");
	printf("la consulta es: %s", consulta->query);
}
int createTable(sql *consulta) {
	strcpy(consulta->query, "create table ");
	strcat(consulta->query, consulta->table);
	strcat(consulta->query, "(");
	printf("\nIntroduzca columnas de la tabla %s", consulta->table);
	int i = 0;
	while (i < MAXCOL)
	{
		printf("\nNombre de columna <%d>: ", i+1);
		scanf("%s", &consulta->columnName[i]);
		printf(" Tipo dato para columna %s:\n", consulta->columnName);
		scanf("%s", &consulta->columnType[i]);
		strcat(consulta->query, consulta->columnName[i]);
		strcat(consulta->query, " ");
		strcat(consulta->query, consulta->columnType[i]);
	CONTINUAR:
		printf("\n¿Quieres introducir mas?Si/No");
		char *z;
		scanf("%s", z);
		strlwr(z);
		printf(z);
		if ((z[0] == 's') || (z[0] == 's' && z[1]=='i'))
		{
			strcat(consulta->query, ", ");
			i++;
		}
		else {
			if ((z[0]=='n') || (z[0] == 'n' && z[1] == 'o'))
			{
				strcat(consulta->query, ");");
				printf("la consulta es: %s", consulta->query);
				break;
			}else{
				goto CONTINUAR;
			}
		}
	}
}
int selectData(sql *consulta) {
	strcpy(consulta->query, "select ");
	int i = 0;
	while (i < MAXCOL)
	{
		printf("\nIntroduzca nombre de columna a seleccionar ");
		scanf("%s", &consulta->columnName[i]);
		strcat(consulta->query, consulta->columnName[i]);
	CONTINUAR:
		printf("\n¿Quieres introducir mas?Si/No");
		char *z;
		scanf("%s", z);
		strlwr(z);
		printf(z);
		if ((z[0] == 's') || (z[0] == 's' && z[1] == 'i'))
		{
			strcat(consulta->query, ", ");
			i++;
		}
		else {
			if ((z[0] == 'n') || (z[0] == 'n' && z[1] == 'o'))
			{
				strcat(consulta->query, ") from");
				break;
			}
			else {
				goto CONTINUAR;
			}
		}
	}
	strcpy(consulta->query, consulta->table);
	while (1==1)
	{
	ANADIR:
		printf("\n¿Quieres añadir coincidencias en la buscaqueda?Si/No");
		char *y;
		scanf("%s", y);
		strlwr(y);
		printf(y);
		if ((y[0] == 's') || (y[0] == 's' && y[1] == 'i'))
		{
			strcat(consulta->query, " where ");
			
			scanf("%s", y);
		}
		else {
			if ((y[0] == 'n') || (y[0] == 'n' && y[1] == 'o'))
			{
				strcat(consulta->query, ";");
				break;
			}
			else {
				goto ANADIR;
			}
		}
	}
	printf("la consulta es: %s", consulta->query);
}
int dropTable(sql *consulta) {
	strcpy(consulta->query, "drop table ");
	strcat(consulta->query, consulta->table);
	strcpy(consulta->query, ";");
}
int callback(void* data, int ncols, char** values, char** headers) {
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for (int i = 0; i < ncols; i++)
	{
		fprintf(stderr, "%s=%s ", headers[i], values[i]);
	}
	fprintf(stderr, "\n");
	return 0;
}