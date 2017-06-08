#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Archivos binarios(E/S) de acceso directo.
typedef struct {
	int lu;
	char nombre[80];
	char domicilio[80];
}talumno;

talumno leerRegistro(FILE*archivo, int numReg);
void grabarRegistro(FILE*archivo, int numReg,talumno dato);

int main() {
	FILE*archivo;
	talumno alumno;
	archivo=fopen("Alumnos.txt","rb+");
	if(archivo==NULL){
		puts("No se puede crear el archivo.");
		return 1;
	}

	fread(&alumno,sizeof(alumno),1,archivo);

	while(!feof(archivo)){ //mientas que no sea el final del archivo.
		if(alumno.lu>0 && alumno.lu<10000000) {
			alumno.lu = -1*alumno.lu;
			fseek(archivo,-1*(int)sizeof(alumno),SEEK_CUR);
			fwrite(&alumno,sizeof(alumno),1,archivo);
			fseek(archivo,0,SEEK_CUR);
		}
		fread(&alumno,sizeof(alumno),1,archivo);
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

void grabarRegistro(FILE*archivo, int numReg,talumno dato) {
	fseek(archivo,numReg*sizeof(dato),SEEK_SET);
	fwrite(&dato,sizeof(dato,1,archivo));
}