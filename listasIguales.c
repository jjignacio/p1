#include <stdio.h>
#include <stdlib.h>

typedef struct snodo{
	int valor;
	struct snodo *sig;
}tnodo;

typedef tnodo* tpuntero;			//puntero q nos da acceso a la lista

void insertaralprincipio(tpuntero* cabeza, int e);  //INSERTAR AL PRINCIPIO
int  imprimirlista (tpuntero cabeza,tpuntero cabeza2);    //IMPRIMIR LISTA
void borrarlista (tpuntero* cabeza);  //BORRAR LISTA
void borrarprimernodo(tpuntero* cabeza);		//BORRAR PRIMER NODO
void insertaralfinal(tpuntero* cabeza, int e);   // ISERTAR AL FINAL
void borrarultimonodo(tpuntero* cabeza);			//BORRAR ULTIMO NODO
void insertarenorden(tpuntero* cabeza, int e);   //INSERTAR EN ORDEN

int main(){
	int e;
	tpuntero cabeza,cabeza2;
	cabeza=NULL;
	cabeza2=NULL;    //NO OLVIDAR, sino no anda!
	
	printf("Ingrese elementos para LISTA 1, -1 para terminar: \n");
	scanf("%d",&e);

while(e!=-1){
	insertaralfinal(&cabeza, e);
	scanf("%d",&e);
}

printf("Ingrese elementos para LISTA 2, -1 para terminar: \n");
	scanf("%d",&e);

while(e!=-1){
	insertaralfinal(&cabeza2, e);
	scanf("%d",&e);
}


printf("Las listas son 0=distintas / 1=iguales :  %d \n", imprimirlista(cabeza,cabeza2));


getch();
return 0;
}

void insertaralprincipio(tpuntero *cabeza, int e){
	tpuntero nuevo;
	nuevo=(tpuntero)malloc(sizeof(tnodo));		//No usar tpuntero (es puntero)
	nuevo->valor=e;
	nuevo->sig=*cabeza;		// es el NULL q cargamos antes
	*cabeza=nuevo;			//cabeza ahora apunta a nuevo
}

int imprimirlista(tpuntero cabeza,tpuntero cabeza2){
	int iguales=1;

	while(cabeza!=NULL && cabeza2!=NULL && iguales==1){
		if(cabeza->valor==cabeza2->valor){
			iguales=1;
			cabeza=cabeza->sig;
			cabeza2=cabeza2->sig;
		}	else {
					iguales=0;
				}
	
	}
	return iguales;
}

void borrarlista(tpuntero *cabeza){	
/*es como el imprimir pero ahora pasado por referencia*/
	tpuntero actual;
	while(*cabeza!=NULL){
		actual=*cabeza;
		*cabeza=(*cabeza)->sig;
		free(actual);
	}
}

void borrarprimernodo(tpuntero *cabeza){
	tpuntero actual;
	if(*cabeza!=NULL){
		actual=*cabeza;
		*cabeza=(*cabeza)->sig;
		free(actual);
	}
}		//es igual a la de borrar lista solo que en vez de un while tiene un if


void insertaralfinal(tpuntero *cabeza, int e){
	tpuntero actual, anterior, nuevo;
	anterior=NULL;
	actual=*cabeza;
	while(actual!=NULL){
		anterior=actual;
		actual=actual->sig;
	}
	nuevo=(tpuntero) malloc (sizeof(tnodo));
	nuevo->valor=e;
	nuevo->sig=NULL;
if(anterior!=NULL){
		anterior->sig=nuevo;
	}else{
		*cabeza=nuevo;
	}
}

void borrarultimonodo(tpuntero *cabeza){
	tpuntero anteanterior, anterior, actual;
	actual=*cabeza;
	anterior=NULL;
	anteanterior=NULL;
	while(actual!=NULL){
		anteanterior=anterior;
		anterior=actual;
		actual=actual->sig;
	}
	if(anteanterior!=NULL){		//entonces la lista tiene 2 o + nodos
		free(anterior);
		anteanterior->sig=NULL;
	}else if (anterior!=NULL){		//un solo nodo
		free(anterior);
		*cabeza=NULL;
	}
}

void insertarenorden(tpuntero *cabeza, int e){
	tpuntero actual, anterior, nuevo;
	actual=*cabeza;
	anterior=NULL;


	while(actual!=NULL&&actual->valor<e){   //me posiciono donde voy a insertar
		anterior=actual;
		actual=actual->sig;
	}
	nuevo=(tpuntero)malloc(sizeof(tnodo));
	nuevo->valor=e;
	nuevo->sig=actual;
	if (anterior!=NULL){
		anterior->sig=nuevo;
	}else{
		*cabeza=nuevo;
	}
}
