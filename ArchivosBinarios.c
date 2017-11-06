#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grabar();
void mostrar();
void agregarAcumulado();
void ordenar();
void buscar();
void eliminarL();
void eliminarF();

void grabar() {
	FILE *archivo;
	int registro;
	archivo = fopen("numReales.dat","wb");
	
	if(archivo==NULL) {
		puts("No se pudo crear el archivo.");
	}
	puts("Ingrese un numero al azar, -1 para finalizar.");
	scanf("%d",&registro);
	while(registro!=-1){
		fwrite(&registro, sizeof(registro), 1, archivo);
		puts("Ingrese un numero al azar, -1 para finalizar.");
		scanf("%d",&registro);
	}
	fclose(archivo);
}

void mostrar() {
	int registro;
	FILE* archivo;
	archivo = fopen("numReales.dat","rb");

	if(archivo==NULL) {
		puts("No se pudo crar el archivo.");
		return;
	}
	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		printf("%4d", registro);
		fread(&registro, sizeof(registro), 1, archivo);
	}
	printf("\n");
	fclose(archivo);
}

void agregarAcumulado() {
	int registro, suma=0;
	FILE *archivo;
	archivo = fopen("numReales.dat","rb");

	if(archivo==NULL) {
		puts("No se pudo crear el archivo.");
		return;
	}
	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		suma = suma+registro;
		fread(&registro, sizeof(registro), 1, archivo);
	}
	fclose(archivo);

	archivo = fopen("numReales.dat","ab");
	//fseek(archivo, sizeof(int), SEEK_END);
	fwrite(&suma, sizeof(suma), 1, archivo);

	fclose(archivo);
}

void ordenar() { //Parcial
	int i,j,cantreg,terminar=0;
	int reg1,reg2;
	FILE *archivo;
	archivo = fopen("numReales.dat","rb+");

	if(archivo==NULL) {
		puts("No se puede abrir el archivo.");
		return;
	}

	// Calculamos la cantidad de registros
	fseek(archivo,0,SEEK_END);
	cantreg=ftell(archivo)/sizeof(float);
	i=1;
	while (terminar==0){
		terminar=1;
		for (j=0;j<cantreg-i;j++){
			fseek(archivo,j*sizeof(int),SEEK_SET);
			fread(&reg1,sizeof(reg1),1,archivo);
			fread(&reg2,sizeof(reg2),1,archivo);
			if (reg1>reg2){
				fseek(archivo,-2*(int)sizeof(reg1),SEEK_CUR);
				fwrite(&reg2,sizeof(reg2),1,archivo);
				fwrite(&reg1,sizeof(reg1),1,archivo);
				terminar=0;
			}
		}
		i++;
	}
	fclose(archivo);
}

void buscar() {
	FILE *archivo;
	int izq=0, der, centro, cantregistro, numBuscado;
	int reg;
	archivo = fopen("numReales.dat","rb+");
	if (archivo == NULL){
		puts("No se puede abrir el archivo.");
		return;
	}
	puts("Que numero desea buscar?");
	scanf("%d",&numBuscado);

	// Calculamos la cantidad de registros
	fseek(archivo,0,SEEK_END);
	cantregistro = ftell(archivo)/sizeof(float);
	der = cantregistro-1;
	centro = (izq+der)/2;

	fseek(archivo,centro*sizeof(centro),SEEK_SET);
	fread(&reg,sizeof(reg),1,archivo);

	while (reg!=numBuscado && izq<=der){
		if (reg>numBuscado)
			der=centro-1;
		else
			izq=centro+1;
		centro=(izq+der)/2;
		fseek(archivo,centro*sizeof(float),SEEK_SET);
		fread(&reg,sizeof(reg),1,archivo);
	}
	fclose(archivo);
	if (izq<=der)
		printf("El valor se encontro en el registro: %d\n", centro);
	else
		printf("El valor no se encontro en el archivo. \n");
}

void eliminarL() {
	int registro, regEliminar;
	FILE *archivo;
	archivo = fopen("numReales.dat","rb+");

	puts("Ingrese el registro a eliminar: ");
	scanf("%d",&regEliminar);

	if(archivo==NULL) {
		puts("No se pudo abrir el archivo.");
		return;
	}
	fread(&registro,sizeof(registro),1,archivo);
	while(!feof(archivo)) {
		if(registro==regEliminar) {
			// Cambio el valor del registro por su negativo para luego poder recuperarlo;
			registro=-1*registro;
			// Me paro en la posicion donde esta el registro que quiero borrar.
			fseek(archivo, -1*(int)sizeof(registro), SEEK_CUR);
			// Escribo en nuevo valor(-1) en el registro.
			fwrite(&registro, sizeof(registro), 1, archivo);
			// Me vuelvo a parar en la posicion en la que estaba para seguir la busqueda.
			fseek(archivo, 0, SEEK_CUR);
		}
		fread(&registro, sizeof(registro), 1, archivo);
	}
	fclose(archivo);
}

void eliminarF() { // Parcial.
	FILE *archEntrada,*archSalida;
	int registro, regEliminar;
	char comando[80];
	archEntrada = fopen("numReales.dat","rb");
	if (archEntrada==NULL){
		puts("No se pudo abrir el archivo de entrada");
		return;
	}
	archSalida=fopen("temporal.dat","wb");
	if (archSalida==NULL){
		puts("No se pudo crear el archivo de salida");
		return;
	}

	puts("Ingrese el registro a eliminar: ");
	scanf("%d",&regEliminar);

	fread(&registro,sizeof(registro),1,archEntrada);
	while (!feof(archEntrada)){
		if (registro!=regEliminar)
			fwrite(&registro,sizeof(registro),1,archSalida);
		else
			puts("El registro se elimino exitosamente.");
		fread(&registro,sizeof(registro),1,archEntrada);		
	}
	fclose(archEntrada);
	fclose(archSalida);
	if(remove("numReales.dat")) {
		puts("No se pudo borrar el archivo.");
	}
	if(rename("temporal.dat","numReales.dat")) {
		puts("No se pudo renombrar el archivo nuevo");
	}
}

int main() {
	int opcion=-1;

	while(opcion != 0) {
		puts("x----------------------------------------x");
		puts("Ingrese una opcion: ");
		puts("1 - Grabar");
		puts("2 - Mostrar");
		puts("3 - Agregar Acumulado");
		puts("4 - Ordenar");
		puts("5 - Buscar");
		puts("6 - EliminarL");
		puts("7 - EliminarF");
		puts("0 - Salir");
		scanf("%d",&opcion);
		switch(opcion) {
		case 0:
			opcion = 0;
			break;
		case 1: 
			grabar();
			break;
		case 2:
			mostrar();
			break;
		case 3:
			agregarAcumulado();
			break;
		case 4:
			ordenar();
			break;
		case 5:
			buscar();
			break;
		case 6:
			eliminarL();
			break;
		case 7:
			eliminarF();
			break;
		default:
			break;
		}
	}

	system("PAUSE");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sAlumno{
	int legajo;
	char nombre[80];
	int materias;
};

int main() {

	FILE* archivo;
	struct sAlumno alum;
	archivo = fopen("Alumnos.dat","wb");

	if(archivo==NULL) {
		puts("No se pudo crear el archivo.");
		return 0;
	}

	// Metodo para escritura.
	puts("Ingrese legajo de un alumno. Finalice con -1");
	scanf("%d", &alum.legajo);

	while(alum.legajo!=-1) {
		fflush(stdin);
		puts("Ingrese nombre: ");
		gets(alum.nombre);
		puts("Ingrese materias: ");
		scanf("%d",&alum.materias);
		fwrite(&alum, sizeof(alum),1,archivo);

		puts("Ingrese legajo.");
		scanf("%d", &alum.legajo);
	}
	fclose(archivo);

	//Metodo para lectura.
	archivo = fopen("Alumnos.dat","rb");
	if(archivo==NULL) {
		puts("No se pudo crear el archivo.");
		return 0;
	}

	fread(&alum, sizeof(alum),1,archivo);
	while(!feof(archivo)) {
		printf("Legajo %d\n", alum.legajo);
		printf("Nombre %s\n", alum.nombre);
		printf("Cantidad de materias %d\n", alum.materias);
		fread(&alum, sizeof(alum),1,archivo);
	}
	fclose(archivo);

	system("PAUSE");
	return 0;
}

seek_set (desde el principio del archivo)
seek_cur (desde el registro actual)
seek_end (desde el final del archivo)

fseek(nombreDelArchivo, sizeof(int), seek_set);
Desplaza la posición actual de lectura/escritura del fichero a otro punto. 
El desplazamiento puede ser positivo (avanzar), cero o negativo (retroceder). 
La posición de origen se puede indicar con la ayuda de tres constantes: SEEK_SET (0, comienzo), 
SEEK_CUR (1, actual), SEEK_END (2, final)
