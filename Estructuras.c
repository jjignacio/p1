#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void simplificarFraccion(struct sfraccion fraccion1);
int verificadorFecha(struct sfecha fecha1);
void sumarDias(struct sfecha fecha1);
void horaValida(struct shorario horario1);
void compararHoras(struct shorario horario1, struct shorario horario2);

struct sfraccion {
	int numerador;
	int denominador;
};

struct sfecha {
	int dia;
	int mes;
	int anio;
};

struct shorario {
	int horas;
	int minutos;
};

struct spelicula {
	char nombre[15];
	struct shorario duracion;
	struct sfecha fechaEstreno;
	struct sfraccion costoFilmacion;
};

void simplificarFraccion(struct sfraccion fraccion1) {
	while(fraccion1.numerador%2 == 0 && fraccion1.denominador%2 == 0) {
		fraccion1.numerador = fraccion1.numerador/2;
		fraccion1.denominador = fraccion1.denominador/2;
	}
	while(fraccion1.numerador%3 == 0 && fraccion1.denominador%3 == 0) {
		fraccion1.numerador = fraccion1.numerador/3;
		fraccion1.denominador = fraccion1.denominador/3;
	}
	while(fraccion1.numerador%4 == 0 && fraccion1.denominador%4 == 0) {
		fraccion1.numerador = fraccion1.numerador/4;
		fraccion1.denominador = fraccion1.denominador/4;
	}
	while(fraccion1.numerador%5 == 0 && fraccion1.denominador%5 == 0) {
		fraccion1.numerador = fraccion1.numerador/5;
		fraccion1.denominador = fraccion1.denominador/5;
	}
	printf("Fraccion simplificada: %d/%d \n",fraccion1.numerador, fraccion1.denominador);
}

int verificadorFecha(struct sfecha fecha1) {
	int enero = 1, febrero = 2, marzo = 3, abril = 4, mayo = 5, junio = 6; 
	int julio = 7, agosto = 8, septiembre = 9, octubre = 10, noviembre = 11, diciembre = 12;
	char validador = 0;
	
	if(fecha1.anio >= 1500 && fecha1.anio <= 2020){
		if(fecha1.mes == enero || fecha1.mes == marzo || fecha1.mes == mayo  || fecha1.mes == julio || fecha1.mes == agosto || fecha1.mes == octubre || fecha1.mes == diciembre) {
			if(fecha1.dia <= 31){
				// Fecha Valida
				validador = 1;
			}
		} else if (fecha1.mes == abril || fecha1.mes == junio || fecha1.mes == septiembre || fecha1.mes == noviembre) {
			if(fecha1.dia <= 30) {
				// Fecha Valida
				validador = 1;
			}
		} else if (fecha1.mes == febrero ) {
			if(fecha1.dia <= 28){
				// Fecha Valida
				validador = 1;
			}
		}
	}
	return validador;
}

void sumarDias(struct sfecha fecha1) {
	int dias;
	int enero = 1, febrero = 2, marzo = 3, abril = 4, mayo = 5, junio = 6; 
	int julio = 7, agosto = 8, septiembre = 9, octubre = 10, noviembre = 11, diciembre = 12;

	if(verificadorFecha(fecha1) == 1) {
		printf("Cuantos dias desea agregar?: \n");
		scanf("%d",&dias);
		while(dias != 0) {
			if(fecha1.mes == enero || fecha1.mes == marzo || fecha1.mes == mayo  || fecha1.mes == julio || fecha1.mes == agosto || fecha1.mes == octubre || fecha1.mes == diciembre) {
				if(fecha1.dia == 31) {
					if(fecha1.mes == diciembre) {
						fecha1.mes = 1;
						fecha1.anio = fecha1.anio+1;
					} else {
						fecha1.mes = fecha1.mes+1;
					}
					fecha1.dia = 1;
					dias--;
				} else {
					fecha1.dia++;
					dias--;
				}
			} else if (fecha1.mes == abril || fecha1.mes == junio || fecha1.mes == septiembre || fecha1.mes == noviembre) {
				if(fecha1.dia == 30) {
					fecha1.dia = 1;
					fecha1.mes = fecha1.mes+1;
					dias--;
				} else {
					fecha1.dia++;
					dias--;
				}
			} else if (fecha1.mes == febrero ) {
				if(fecha1.dia == 28){
					fecha1.dia = 1;
					fecha1.mes = fecha1.mes+1;
					dias--;
				} else {
					fecha1.dia++;
					dias--;
				}
			}
		}
		printf("Nueva fecha %2d/%2d/%d.\n",fecha1.dia, fecha1.mes, fecha1.anio);
	} else {
		printf("La fecha %2d/%2d/%d NO es una fecha valida.\n",fecha1.dia, fecha1.mes, fecha1.anio);
	}
}

void horaValida(struct shorario horario1) {
	if(horario1.horas>=0 && horario1.horas<=23) {
		if(horario1.minutos>=0 && horario1.minutos<=59) {
			printf("El horario ingresado es valido.\n");
		} else {
			printf("Los minutos ingresados no son validos.\n");
		}
	} else {
		printf("Las horas ingresadas no son validas.\n");
	}
}

void compararHoras(struct shorario horario1, struct shorario horario2) {
	if(horario1.horas == horario2.horas) {
		if(horario1.minutos == horario2.minutos) {
			printf("Los horarios ingresados son iguales.\n");
		} else {
			printf("Los minutos ingresados son distintos.\n");
		}
	} else {
		printf("Las horas ingresadas son distintas.\n");
	}
}

int main() {
	int denominador, numerador, dia, mes, anio, horas1, minutos1, horas2, minutos2;
	
	struct sfraccion fraccion1;
	struct sfecha fecha1;
	struct shorario horario1, horario2;
	
	printf("Ingrese denominador: ");
	scanf("%d", &denominador);
	fraccion1.denominador = denominador;

	printf("Ingrese numerador: ");
	scanf("%d", &numerador);
	fraccion1.numerador = numerador;

	printf("Numerador ingresado: %d. \n", fraccion1.numerador);
	printf("Denominador ingresado: %d. \n", fraccion1.denominador);

	simplificarFraccion(fraccion1);

	printf("Ingrese un dia: ");
	scanf("%d", &dia);
	fecha1.dia = dia;
	
	printf("Ingrese un mes: ");
	scanf("%d", &mes);
	fecha1.mes = mes;

	printf("Ingrese un anio: ");
	scanf("%d", &anio);
	fecha1.anio = anio;

	if(verificadorFecha(fecha1) == 1) {
		printf("La fecha %2d/%2d/%d es una fecha valida.\n",fecha1.dia, fecha1.mes, fecha1.anio);
	} else {
		printf("La fecha %2d/%2d/%d NO es una fecha valida.\n",fecha1.dia, fecha1.mes, fecha1.anio);
	}

	sumarDias(fecha1);

	printf("Ingrese una hora: ");
	scanf("%d", &horas1);
	horario1.horas = horas1;

	printf("Ingrese minutos: ");
	scanf("%d", &minutos1);
	horario1.minutos = minutos1;

	horaValida(horario1);

	printf("Ingrese una hora: ");
	scanf("%d", &horas2);
	horario2.horas = horas2;

	printf("Ingrese minutos: ");
	scanf("%d", &minutos2);
	horario2.minutos = minutos2;

	compararHoras(horario1, horario2);

	system("Pause");
	return 0;
}


_________________________________________________________________________________________________________________________

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2

void alta(struct sdatosPelicula biblioteca[MAX]);
void baja(struct sdatosPelicula biblioteca[MAX]);
void mostrar(struct sdatosPelicula biblioteca[MAX]);

struct sfraccion {
	int numerador;
	int denominador;
};

struct sfecha {
	int dia;
	int mes;
	int anio;
};

struct shorario {
	int hora;
	int minuto;
};

struct sdatosPelicula {
	char nombre[20];
	struct shorario duracion;
	struct sfecha fechaEstreno;
	int costoFilmacion;
};

void alta(struct sdatosPelicula biblioteca[MAX]) {
	char aux[20];
	int i=0, terminar=0;

	//for(i=0; i<MAX; i++) {
	while(i<MAX && terminar==0) {

		fflush(stdin);

		//Nombre.
		puts("Ingrese Nombre: ");
		gets(biblioteca[i].nombre);
		//strcpy(biblioteca[i].nombre, aux); //PARCIAL.

		if(strcmp ("", biblioteca[i].nombre) == 0) {
			terminar = 1;
		} else {
			//Duracion.
			puts("Ingrese duracion de la pelicula.");
			puts("Hora: ");
			scanf("%d",&biblioteca[i].duracion.hora);
			puts("Minutos: ");
			scanf("%d",&biblioteca[i].duracion.minuto);

			//Fecha estreno.
			puts("Ingrese fecha de estreno de la pelicula.");
			puts("Dia: ");
			scanf("%d",&biblioteca[i].fechaEstreno.dia);
			puts("Mes: ");
			scanf("%d",&biblioteca[i].fechaEstreno.mes);
			puts("Anio: ");
			scanf("%d",&biblioteca[i].fechaEstreno.anio);

			//Costo Filmacion.
			puts("Ingrese costo de filmacion: ");
			scanf("%d",&biblioteca[i].costoFilmacion);
		}

		i++;

		printf("------------------------------------------\n");

		//getchar();
	}
}

void baja(struct sdatosPelicula biblioteca[MAX]) {
	char nombre[20];
	int i;

	puts("Ingrese nombre de la pelicula que desea eliminar: ");
	scanf("%s", nombre);

	for(i=0; i<MAX; i++) {
		if(strcmp(nombre, biblioteca[i].nombre) == 0) {
			//Nombre.
			*biblioteca[i].nombre = NULL; //Puntero al primer elemento. PARCIAL.

			//Duracion.
			biblioteca[i].duracion.hora = NULL;
			biblioteca[i].duracion.minuto = NULL;
			
			//Fecha estreno.
			biblioteca[i].fechaEstreno.dia = NULL;
			biblioteca[i].fechaEstreno.mes = NULL;
			biblioteca[i].fechaEstreno.anio = NULL;
			
			//Costo Filmacion.
			biblioteca[i].costoFilmacion = NULL;
		}
	}
}

void mostrar(struct sdatosPelicula biblioteca[MAX]) {
	int i;

	for(i=0; i<MAX; i++) {
		//Nombre.
		printf("Pelicula %d: ",i+1);
		puts(biblioteca[i].nombre);

		//Duracion.
		printf("Duracion de la pelicula: %d:%d \n",biblioteca[i].duracion.hora, biblioteca[i].duracion.minuto);
		
		//Fecha estreno.
		printf("Fecha de estreno de la pelicula: %2d/%2d/%2d \n",biblioteca[i].fechaEstreno.dia, biblioteca[i].fechaEstreno.mes, biblioteca[i].fechaEstreno.anio);

		//Costo Filmacion.
		printf("Costo de filmacion: %d \n", biblioteca[i].costoFilmacion);

		printf("-------------------------------------------\n");
	}
}

int main() {

	struct sdatosPelicula biblioteca[MAX];

	alta(biblioteca);
	mostrar(biblioteca);
	baja(biblioteca);
	mostrar(biblioteca);

	system("PAUSE");
	return 0;
}
