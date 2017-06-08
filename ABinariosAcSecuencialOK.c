+#include <stdio.h>
 +#include <string.h>
 +#include <stdlib.h>
 +#include <ctype.h>
 +
 +//Archivos binarios(entrada y salida) de acceso secuencial.
 +typedef struct {
 +	int lu;
 +	char nombre[80];
 +	char domicilio[80];
 +}talumno;
 +
 +int main() {
 +	FILE*archivo;
 +	talumno alumno;
 +	archivo=fopen("Alumnos.txt","wb");
 +	if(archivo==NULL){
 +		puts("No se puede crear el archivo.");
 +		return 1;
 +	}
 +	printf("Ingrese LU:(-1 para terminar)");
 +	scanf("%d",&alumno.lu);
 +	while(alumno.lu!=-1){
 +		getchar();
 +		printf("Nombre? ");
 +		gets(alumno.nombre);
 +		printf("Domicilio? ");
 +		gets(alumno.domicilio);
 +		fwrite(&alumno,sizeof(alumno),1,archivo);//size es la cantidad de elementos a escribir.
 +		printf("Ingrese LU:(-1 para terminar)");
 +		scanf("%d",&alumno.lu);
 +	}
 +	fclose(archivo);
 +
 +	archivo=fopen("Alumnos.txt","rb");
 +	if(archivo==NULL){
 +		puts("No se puede abrir el archivo.");
 +		return 1;
 +	}
 +	fread(&alumno,sizeof(alumno),1,archivo);
 +	while(!feof(archivo)){ //mientas que no sea el final del archivo.
 +		if(alumno.lu>0 && alumno.lu<10000000) {
 +			printf("%d - %s\n",alumno.lu,alumno.nombre);
 +		}
 +		fread(&alumno,sizeof(alumno),1,archivo);
 +	}
 +	fclose(archivo);
 +
 +	system("Pause");
 +	return 0;
 +} 