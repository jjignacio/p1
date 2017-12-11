#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct snodo
{
	char codBarras[22];
	char nombreProd[64];
	float precioUnit;
	int stock;
	struct snodo *sig;
}tnodo;
typedef tnodo *tpuntero;

void cargarProductos(tpuntero *cabeza);
void bajaProducto (tpuntero *cabeza);
void imprmirProductos (tpuntero cabeza);
int main ()
{
	tpuntero cabeza;
	int option;
	cabeza=NULL;
	do
	{
		system("cls");
		printf("\tMENU:");
		printf("\n\t\t[1] DAR DE ALTA UN PRODUCTO.");
		printf("\n\t\t[2] DAR DE BAJA UN PRODUCTO.");
		printf("\n\t\t[3] MOSTRAR TODOS LOS PRODUCTOS.");
		printf("\n\t\t[0] SALIR DEL PROGRAMA.\n");
		scanf("%d",&option);
		switch (option)		
		{
			case 1:
				cargarProductos(&cabeza);
				break;
			case 2:
				bajaProducto(&cabeza);
				break;
			case 3:	
				imprmirProductos(cabeza);
				break;
			case 0:
				option=-1;
				break;
		}
		
	} while (option!=-1);

	return 0;
}
void cargarProductos(tpuntero *cabeza)
{
	tpuntero nuevo,actual,anterior;
	nuevo=(tpuntero)malloc(sizeof(tnodo));
	actual=*cabeza;
	anterior=NULL;

	fflush(stdin);
	puts ("Ingrese el codigo de barras del producto:");
	gets(nuevo->codBarras);
	fflush(stdin);

	puts("Ingrese el nombre del producto:");
	gets(nuevo->nombreProd);
	fflush(stdin);

	puts("Ingrese el precio unitario del producto:");
	scanf("%f",&nuevo->precioUnit);
	fflush(stdin);

	puts("Ingrese el stock del producto");
	scanf("%d",&nuevo->stock);
	fflush(stdin);


	while (actual!=NULL)
	{
		anterior=actual;
		actual=actual->sig;
	}
	if (anterior==NULL)
	{
		nuevo->sig=*cabeza;
		*cabeza=nuevo;
	}
	else
	{
		anterior->sig=nuevo;
		nuevo->sig=actual;
	}
}
void bajaProducto (tpuntero *cabeza)
{
	tpuntero siguiente, actual, anterior;
	char nombre[50];
	actual=*cabeza;
	anterior=NULL;
	siguiente=actual->sig;
	puts("Ingrese el nombre del producto que desea dar de baja..");
	fflush(stdin);
	gets(nombre);
	fflush(stdin);
	while ((strcmp(actual->nombreProd,nombre)!=0) && (siguiente!=NULL)) 
	{
			anterior=actual;
			actual=siguiente;
			siguiente=siguiente->sig;
	}
	if (anterior!=NULL)
	{
		if (strcmp(actual->nombreProd,nombre)==0)
		{
			anterior->sig=siguiente;
			free(actual);
		}
		else
		{
			puts("No se encontro el elemento que desea borrar");
			system("pause");
		}
	}
	else
	{
		*cabeza=siguiente;
		free(actual);
	}
}

void imprmirProductos (tpuntero cabeza)
{
	int i=1;
	tpuntero actual;
	actual=cabeza;
	while (actual!=NULL)
	{
		printf("\nProducto %d :\n",i);
		printf("\n\tCodigo de barras: %s", actual->codBarras);
		printf("\n\tNombre del producto: %s",actual->nombreProd);
		printf("\n\tPrecio unitario: %f",actual->precioUnit);
		printf("\n\tStock del Producto: %d\n\n", actual->stock);
		i++;
		actual=actual->sig;
	}
	system("pause");
}
