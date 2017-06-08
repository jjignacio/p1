#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

//Modulo para cargar un vector de forma aleatoria.
void cargarVector(int vector[MAX]) {
	int i=0;

	srand((int)time(NULL));

	while(i<MAX){
		vector[i] = rand()%(999-100+1)+99;
		i++;
	}

}

//(Opcion 3)Cargar una matriz con números enteros de tres dígitos, generados al azar.
void cargarMatrizAzar(int matriz[][MAXC]) {
	int f, c, num;

	srand((int)time(NULL));

	for(f=0; f<MAXF; f++) {
		for(c=0; c<MAXC ;c++) {
			matriz[f][c] = rand()%(999-100+1)+99;
		}
	}
	printf("Matriz cargada con Exito.\n\n");
}

//Modulo para ordenar el vector por metodo Burbuja.
void ordenarVector(int vector[MAX]) {
	int i, aux, j;

	for(i=0; i<MAX-1; i++){
		for(j=i+1; j<MAX; j++){
			if(vector[j] < vector[i]){
				aux = vector[j];
				vector[j] = vector[i];
				vector[i] = aux;
			}
		}
	}
}

//(Opcion 4)Ordenar en forma ascendente cada una de las filas de una matriz.
void ordenarMatriz(int matriz[][MAXC]) {
	int i, aux, j, w, u;
	for(i=0; i<MAXF; i++) {
		for(j=0; j<MAXC; j++) {
			for(w=0; w<MAXF; w++) {
				for(u=0; u<MAXC; u++) {
					if(matriz[i][j]<matriz[w][u]) {
						aux = matriz[i][j];
						matriz[i][j] = matriz[w][u];
						matriz[w][u] = aux;
					}
				}
			}
		}
	}
	printf("Matriz ordenada.\n\n");
}

//Modulo para mostar el vector.
void mostarVector (int vector[MAX]) {
	int i;

	printf("Vector: \n");
	for(i=0; i<MAX ; i++) {
		printf("Posicion %d valor %d\n",i,vector[i]);
		printf("\n");
	}
}

//Modulo para burcar un numero dentro del vector, por busqueda Binaria.
void busquedaBinaria(int vector[MAX], int num) {
	int i, j, posicion=-1, inicio=0, fin=MAX, medio;

	while (inicio <= fin && posicion == -1){
		medio = (inicio + fin)/2;
		if(vector[medio] == num){
			posicion = medio;
		}else{
			if(vector[medio] > num){
				fin = medio-1;
			}else{
				inicio = medio+1;
			}
		}
	}
	if(posicion == -1){
		printf("%4d\n",posicion);
	}else{
		printf("La posicion en la que se encuentra el numero es: %2d y\n", posicion);
	}
}