#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Archivos binarios(entrada y salida) de acceso secuencial.
typedef struct {
	int lu;
	char nombre[80];
	char domicilio[80];
}talumno;

talumno leerRegistro(FILE*archivo, int numReg);
void grabarRegistro(FILE*archivo,int numReg, talumno dato);

int main() {
	FILE*archivo;
	talumno alumno1,alumno2;
	int i,j,cantReg;
	archivo=fopen("Alumnos.dat","wb");
	if(archivo==NULL){
		puts("No se puede crear el archivo.");
		return 1;
	}
	fseek(archivo,0,SEEK_END);
		//Metodo de seleccion
	cantReg=sizeof(talumno);
	for(i=0;i<cantReg-1;i++) {
		for(j=i+1;j<cantReg-1;j++) {
			alumno1 = leerRegistro(archivo,i);
			alumno2 = leerRegistro(archivo,j);
			if(strcmp(alumno1.nombre,alumno2.nombre)>0) {
				grabarRegistro(archivo,i,alumno2);
				grabarRegistro(archivo,j,alumno1);
			}
		}
	}

	printf("Ingrese LU:(-1 para terminar)");
	scanf("%d",&alumno1.lu);
	while(alumno1.lu!=-1){
		getchar();
		printf("Nombre? ");
		gets(alumno1.nombre);
		printf("Domicilio? ");
		gets(alumno1.domicilio);
		fwrite(&alumno1,sizeof(alumno1),1,archivo);//size es la cantidad de elementos a escribir.
		printf("Ingrese LU:(-1 para terminar)");
		scanf("%d",&alumno1.lu);
	}
	fclose(archivo);

	archivo=fopen("Alumnos.dat","rb");
	if(archivo==NULL){
		puts("No se puede abrir el archivo.");
		return 1;
	}
	fread(&alumno1,sizeof(alumno1),1,archivo);
	//usar este while para hacer el borrado fisico. borrado logico cambiando el estado.
	while(!feof(archivo)){ //mientas que no sea el final del archivo.
		if(alumno1.lu>0 && alumno1.lu<10000000) {
			printf("%d - %s\n",alumno1.lu,alumno1.nombre);
		}
		fread(&alumno1,sizeof(alumno1),1,archivo);
	}
	fclose(archivo);

	system("Pause");
	return 0;
}

talumno leerRegistro(FILE*archivo, int numReg) {
	talumno dato;
	fseek(archivo,numReg*sizeof(dato),SEEK_SET);
	fread(&dato,sizeof(dato),1,archivo);
	return dato;
}


void grabarRegistro(FILE*archivo,int numReg, talumno dato) {
	fseek(archivo,numReg*sizeof(dato),SEEK_SET);
	fwrite(&dato,sizeof(dato),1,archivo);
}

