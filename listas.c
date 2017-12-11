#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct sNodo {
	int valor;
	struct sNodo *siguiente;
};
typedef struct sNodo* tpuntero;

void insertarAlPrincipio(tpuntero *cabeza, int n);
void insertarAlFinal(tpuntero *cabeza, int n);
void insertarenorden(tpuntero *cabeza, int n);
void insertarenorden_sinrepetidos(tpuntero *cabeza, int n);
void imprimirLista(tpuntero cabeza);
void borrarLista(tpuntero *cabeza);
void borrarPrimerNodo(tpuntero *cabeza);
void borrarUltimoNodo(tpuntero *cabeza);
void borraElemento(tpuntero *cabeza, int valor);
int borrarNodo(tpuntero *cabeza,int posicion);
void invertirLista(tpuntero *cabeza);

int main() {
	int n;
	tpuntero cabeza = NULL;

	puts("Ingrese valor, -1 para finalizar.");
	scanf("%d", &n);

	while(n != -1) {
		insertarAlPrincipio(&cabeza, n);
		puts("Ingrese valor, -1 para finalizar.");
		scanf("%d", &n);
	}

	imprimirLista(cabeza);

	invertirLista(&cabeza);

	puts("Ingrese el elemento que desea eliminar: ");
	scanf("%d",&n);

	borraElemento(&cabeza, n);

	imprimirLista(cabeza);

	borrarLista(&cabeza);
	if(cabeza==NULL) {
		puts("Lista Vacia.");
	}

	system("PAUSE");
	return 0;
}

/* 
malloc =  Sirve para solicitar un bloque de memoria del tamaño suministrado 
como parámetro. Devuelve un puntero a la zona de memoria concedida.
Si malloc es incapaz de conceder el bloque (p.ej. no hay memoria suficiente), devuelve un puntero nulo.
*/
void insertarAlPrincipio(tpuntero *cabeza, int n) {
	tpuntero nuevo;
	nuevo = (tpuntero)malloc(sizeof(struct sNodo)); // Bloque de memoria del tamaño del nodo que necesito.
	nuevo->valor = n;
	nuevo->siguiente = *cabeza; // es el NULL q cargamos antes.
	*cabeza = nuevo; //cabeza ahora apunta a nuevo.
}

void imprimirLista(tpuntero cabeza) {  //crea una copia del valor de cabeza en ese momento, despues lo destruye.
	while(cabeza != NULL) {
		printf("%d",cabeza->valor);
		cabeza = cabeza->siguiente; //si no pasabamos la cabeza por valor hubiera quedado NULL y la perdiamos.
	}
}

/*
Que pasa si la lista esta vacia?
Que pasa si la lista tiene un solo elemento?
Que pasa si la lista tiene mas de un elemento?
*/

void borrarLista(tpuntero *cabeza) { //es como el imprimir pero ahora pasado por referencia.
	tpuntero actual;
	while(*cabeza != NULL) {
		actual = *cabeza;
		*cabeza = (*cabeza)->siguiente;
		free(actual);
	}
}

void borrarPrimerNodo(tpuntero *cabeza) { //es igual a la de borrar lista solo que en vez de un while tiene un if
	tpuntero actual;
	if(*cabeza != NULL) {
		actual = *cabeza;
		*cabeza = (*cabeza)->siguiente;
		free(actual);
	}
}

void borrarUltimoNodo(tpuntero *cabeza) {
	tpuntero anteanterior, anterior, actual;
	actual=*cabeza;
	anterior=NULL;
	anteanterior=NULL;
	while(actual!=NULL){
		anteanterior=anterior;
		anterior=actual;
		actual=actual->siguiente;
	}
	if(anteanterior!=NULL){		//entonces la lista tiene 2 o + nodos
		free(anterior);
		anteanterior->siguiente=NULL;
	}else if (anterior!=NULL){		//un solo nodo
		free(anterior);
		*cabeza=NULL;
	}
}

void borraElemento(tpuntero *cabeza, int valor) {
	tpuntero anterior,actual,siguiente;
	anterior = NULL;
	actual = *cabeza;
	siguiente = actual->siguiente;
	while((actual->valor != valor) && (siguiente != NULL)) {
		anterior=actual;
		actual=siguiente;
		siguiente=siguiente->siguiente;
	}
	if(actual->valor == valor) {
		if(anterior == NULL) {
			*cabeza=siguiente;
			free(actual);
		} else {
			anterior->siguiente = siguiente;
			free(actual);
		}
	} else {
		puts("No se pudo eliminar el elemento.");
	}
	puts("Elemento eliminado con exito.");
}

int borrarNodo(tpuntero *cabeza,int posicion) {
	int cantNodos = 0;
	tpuntero anterior,actual,siguiente;
	actual = *cabeza;
	while(actual!=NULL) {
		cantNodos++;
		actual=actual->siguiente;
	}
	actual = *cabeza;
	anterior = NULL;
	siguiente = actual->siguiente;
	if (cantNodos<posicion) {
		printf("No existe el nodo numero %d\n\n",posicion);
		return 1;
	}
	while((posicion>1)&&(siguiente!=NULL)) {
		anterior = actual;
		actual = siguiente;
		siguiente = siguiente->siguiente;
		posicion--;
	}
	if(anterior==NULL) {
		*cabeza = siguiente;
		free(actual);
	} else {
		anterior->siguiente = siguiente;
		free(actual);
	}
	return 0;
}

void insertarAlFinal(tpuntero *cabeza, int n) {
	tpuntero anterior, actual, nuevo;
	actual = *cabeza;
	anterior = NULL;

	while(actual != NULL) {
		anterior = actual;
		actual = actual->siguiente;
	}

	nuevo=(tpuntero) malloc (sizeof(struct sNodo));
	nuevo->valor = n;
	nuevo->siguiente = NULL;

	if(anterior!=NULL) {
		anterior->siguiente = nuevo;
	} else {
		*cabeza = nuevo;
	}
}

void insertarenorden(tpuntero *cabeza, int n) { // insertar un elemento en formado ordenada.
	tpuntero actual, anterior, nuevo;
	actual = *cabeza;
	anterior = NULL;
	while(actual != NULL && actual->valor < n){
		anterior = actual;
		actual = actual->siguiente;
	}
	nuevo=(tpuntero)malloc(sizeof(struct sNodo));
	nuevo->valor=n;
	nuevo->siguiente = actual;
	if(anterior != NULL) {
		anterior->siguiente = nuevo;
	}else{
		*cabeza = nuevo;
	}
}

void insertarenorden_sinrepetidos(tpuntero *cabeza, int n){
	tpuntero actual, anterior, nuevo;
	actual=*cabeza;
	anterior=NULL;

	while(actual != NULL && actual->valor < n) {
		anterior=actual;
		actual=actual->siguiente;
	}
	if(actual==NULL) {
		nuevo=(tpuntero)malloc(sizeof(struct sNodo));
		nuevo->valor = n;
		nuevo->siguiente=actual;
		if(anterior!=NULL) {
			anterior->siguiente = nuevo;
		} else {
			*cabeza=nuevo;
		}
	} else {
		if(actual->valor != n) {
			nuevo=(tpuntero)malloc(sizeof(struct sNodo));
			nuevo->valor = n;
			nuevo->siguiente = actual;
			if(anterior != NULL) {
				anterior->siguiente = nuevo;
			} else {
				*cabeza=nuevo;
			}
		}
	}
}

void invertirLista(tpuntero *cabeza) {
	tpuntero actual,anterior, siguiente;
	actual = *cabeza;
	anterior = NULL;
	siguiente = actual->siguiente;
	while (siguiente!=NULL) {
		actual->siguiente = anterior; //hago que actual apunte a NULL (la primera vez)
		anterior = actual; 
		actual = siguiente; //actual tiene el valor del anteultimo nodo, y apunta al anterior(en caso de 1,2,3)
		siguiente = siguiente->siguiente; //sig apunta a NULL (la primera vez)
	}
	actual->siguiente = anterior;
	*cabeza = actual;
}
