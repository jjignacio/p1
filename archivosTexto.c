#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void escrituraConFormato();
void leerConFormato();

void escrituraConFormato() {
	FILE *archivo;
	archivo = fopen("archivo.txt","wt");
	if(archivo==NULL) {
		puts("No se pudo abrir el archivo.");
		return;
	}
	fprintf(archivo,"%f %s",3.1416,"PI");
	fclose(archivo);
}

void leerConFormato() {
	float pi;
	float cad[10];
	
	FILE *archivo;
	archivo = fopen("archivo.txt","rt");
	if(archivo==NULL) {
		puts("No se pudo abrir el archivo.");
		return;
	}
	fscanf(archivo,"%f",&pi);
	fscanf(archivo,"%s",cad);
	printf("%f %s", pi, cad);
	printf("\n");
	fclose(archivo);
}

int main() {
	char c;
	FILE *archEntrada, *archSalida;
	archEntrada = fopen("archivo.txt","rt");

	if(archEntrada==NULL) {
		puts("No se pudo abrir el archivo.");
		return 0;
	}

	archSalida = fopen("archivo2.txt","wt");
	if(archSalida==NULL) {
		puts("No se pudo crear el archivo.");
		return 0;
	}

	c = fgetc(archEntrada);
	while(!feof(archEntrada)) {
		c = toupper(c);
		fputc(c, archSalida);
		c = fgetc(archEntrada);
	}
	fclose(archEntrada);
	fclose(archSalida);

	escrituraConFormato();
	leerConFormato();

	system("PAUSE");
	return 0;
}

1 - Caracter a caracter:
	fgetc(<archivo>) -> char
	fputc(<char>,<archivos>)
2 - Linea a linea:
	fgets(<cadena>,<tamaño>,<archivo>);
	fputs(<cadena>,<archivo>);
3 - Con formato:
	fprintf(<archivo>,<cadenaConversion>,<variable>);
	fscanf(<archivo>,<cadenaConversion>,<variable>);

#pragma warning (disable:4996)
#include <stdio.h>
#include <ctype.h>
#define N 256

int eliminarDirectivas ();
int main ()
{
	eliminarDirectivas ();
	return 0;
}

int eliminarDirectivas ()
{
	FILE *origen, *destino;
	char cad[N];
	int i;
	origen =fopen ("programa.txt","rt");
	if (origen == NULL)
	{
		puts ("No se pudo abrir para la lectura el archivo programa.txt");
		return 1;
	}
	destino = fopen ("destino.txt", "wt");
	if (destino == NULL)
	{
		puts ("No se pudo abrir para la escritura el archivo destino.txt");
		return 1;
	}
	fgets (cad, N, origen);
	while (!feof (origen))
	{
		for (i = 0; i < N; i++)
		{
			if (cad[i]== '#')
			{
				cad[i]= '\n';
				cad[i+1]= '\0';
				
			}
		}
		fputs(cad, destino);
		fgets (cad,N,origen);
	}
	return 0;
}

