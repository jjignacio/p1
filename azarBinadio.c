/*Crear un archivo
binario con números al azar entre 1 y 5000, cuya cantidad de registros 
también se encuentra con los números al azar entre 1 y RAND_MAX. Luego crear 2 archivos, y 
con el archivo creado anteriormente, separar aquellos valores q poseen un 5 (en cualquier ubicación) a un archivo, 
y aquellos q no tengan 5 pasarlos al otro archivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RAND_MAX 5  //para q sea leible

void crear_archivo(FILE* arch);
void imprimir_archivo(FILE* arch);
void separar_archivos(FILE* arch, FILE* con5, FILE* sin5);

int main(){
	
	FILE* arch;
		FILE* con5;
		FILE* sin5;
	
	arch=fopen("archivo.dat","wb+");
	crear_archivo(arch);
	fclose(arch);

	
	arch=fopen("archivo.dat","rb");
	printf("ARCHIVO ORIGINAL: \n");
	imprimir_archivo(arch);
	fclose(arch);
	printf("\n");

	arch=fopen("archivo.dat","rb");
	con5=fopen("con5.dat","wb+");
	sin5=fopen("sin5.dat","wb+");

	separar_archivos(arch,con5,sin5);

	fclose(arch);
	fclose(con5);
	fclose(sin5);

	con5=fopen("con5.dat","rb+");
	printf("ARCHIVO con5: \n");
	imprimir_archivo(con5);
	fclose(con5);
	printf("\n");

	sin5=fopen("sin5.dat","rb+");
	printf("ARCHIVO sin5: \n");
	imprimir_archivo(sin5);
	fclose(sin5);
	printf("\n");

	system("PAUSE");

	return 0;




}

void crear_archivo(FILE* arch){

	int i,datos;

	srand(time(NULL));

	for(i=0;i<RAND_MAX;i++){
			
		datos=rand() % (5000-1+1)+1;
		fwrite(&datos,sizeof(int),1,arch);
	
	}

}


void imprimir_archivo(FILE* arch){

	int i,datos;
	rewind(arch);
	
	fread(&datos,sizeof(int),1,arch);
	
	while(!feof(arch)){
			
		printf("%5d",datos);
		fread(&datos,sizeof(int),1,arch);
		
	}

	printf("\n");

}

void separar_archivos(FILE* arch, FILE* con5,FILE* sin5){

		int datos;
		char numero[5];

		
		
		fread(&datos,sizeof(int),1,arch);
			sprintf(numero,"%d",datos);

		while(!feof(arch))
		{
			
			
		if((strchr(numero,'5')!=NULL)){
				fwrite(&datos,sizeof(int),1,con5);
			}else{
					fwrite(&datos,sizeof(int),1,sin5);
				}
	
		fread(&datos,sizeof(int),1,arch);
		sprintf(numero,"%d",datos);
		}


}
