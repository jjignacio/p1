#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct sfecha {
	int dia, mes, anio;
};

struct salumno {
	char lu[10];
	char nombre[80];
	char domicilio[80];
	int materias;
	struct sfecha fechaNacimiento;
};

void materiasCursando(int cantidad);
void domicilioAlumno(struct salumno alumno);
int main() {
	struct sfecha hoy;
	struct salumno alumno;
	struct salumno curso[50];
	hoy.dia = 7;
	hoy.mes = 6;
	hoy.anio = 2017;
	printf("La fecha de hoy es: %d/%d/%d\n",hoy.dia,hoy.mes,hoy.anio);

	strcpy(alumno.lu,"154878");
	strcpy(alumno.nombre,"Alejo");
	strcpy(alumno.domicilio,"jujuy 779");

	alumno.materias = 5;
	alumno.fechaNacimiento.dia = 02;
	alumno.fechaNacimiento.mes = 12;
	alumno.fechaNacimiento.anio = 1992;

	strcpy(curso[1].lu,"1548777");
	curso[1].fechaNacimiento.anio=2000;

	curso[0] = alumno;
	printf("Nombre del alumno 0: %s\n",curso[0].nombre);
	
	materiasCursando(alumno.materias);
	domicilioAlumno(alumno);

	system("Pause");
}

//pasaje de estructuras por parametro(campos por valor).
void materiasCursando(int cantidad) {
	printf("Materias cursando: %d\n",cantidad);
}

//pasaje de estructuras por parametro(estructura por valor).
void domicilioAlumno(struct salumno alumno) {
	printf("Direccion: %s \n",alumno.domicilio);
}



