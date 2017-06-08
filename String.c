#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void eliminarSubcadena(char cadena[], int pos, int cant);
void cantPalabras(char cadena[]);
void invertir(char cadena[]);
void concatenar(char cadena[]);
void concatenar(char cadena[], char cadena2[]);
void copiarCadena(char cadena1[],char cadena2[]);
void concatenarCadena(char destino[]);
void buscarElemento(char destino[]);
int main() {
	char cadena[40];
	char cadena2[10];
	char cadena3[10];
	char destino[20];
	char origen[10];
	int pos, cantidad;
	int num;

	/*printf("ingrese num: \n");
	scanf("%d",&num);
	sscanf(cadena3,"%d",&num);
	printf("%d",num);*/

	puts("Ingrese cadena origen.\n");
	//gets(origen);
	gets(destino);
	//copiarCadena(destino,origen);
	//concatenarCadena(destino);
	buscarElemento(destino);

	/*puts("Ingrese un texto.\n");
	gets(cadena);
	printf("Usted ingreso: %s\n",cadena);

	puts("Ingrese texto2.\n");
	gets(cadena2);
	printf("Usted ingreso: %s\n",cadena2);

	printf("Longitud: %d\n",longitud(cadena));

	printf("Ingrese posicion de inicio: \n");
	scanf("%d", &pos);

	printf("Ingrese cantidad de caracteres: \n");
	scanf("%d", &cantidad);
	*/

	//Libreria <stdio.h>
	printf("Ingrese un Numero.\n");
	scanf("%d",&num);
	sprintf(cadena3,"%d",num);
	puts(cadena3);
	
	/*eliminarSubcadena(cadena,pos,cantidad);
	cantPalabras(cadena);
	invertir(cadena);
	concatenar(cadena);
	concatenar(cadena, cadena2);
	copiarCadena(cadena1,cadena2);
	*/
	

	system("Pause");
	return 0;
}

int longitud(char cadena[]) {
	int i=0;	
	while(cadena[i]!='\0') {
		i++;
	}
	return i;
}

void concatenar(char cadena[], char cadena2[]) {
	int i,j;
	for(i=0;cadena[i];i++) {
	}
	for(j=0;cadena2[j];j++) {
		cadena[i+j] = cadena2[j];
	}
	cadena[i+j] = '\0';
	printf(cadena);
}

void eliminarSubcadena(char cadena[], int pos, int cant) {
	int i=0, j=0;
	i=pos+cant;
	j=(int)strlen(cadena);
	while(cadena[i]) {
		cadena[pos]=cadena[i];
		pos++;
		i++;
	}
	cadena[j-cant]='\0';
	puts(cadena);
	return;
}

void cantPalabras(char cadena[]) {
	int aux=0, i=0;
	while(cadena[i]) {
		if(cadena[i]=='-') {
			aux++;
		}
		i++;
	}
	printf("Cantidad de palabras: %d\n",aux+1);
	return;
}

void invertir(char cadena[]) {
	int i=0, j=0;
	char aux[50];
	strcpy(aux,cadena);
	j=strlen(cadena)-1;
	while(j>=0) {
		cadena[i]=aux[j];
		i++;
		j--;
	}
	cadena[i]='\0';
	puts("Cadena invertida: ");
	puts(cadena);
	return;
}

//Copiar cadena con libreria string.h
void copiarCadena(char destino[],char origen[]) {
	strlen(origen);
	strcpy(destino,origen);
	printf("Cadena origen: %s\n",origen);
	printf("Cadena destino: %s\n",destino);
}

//Concatenar elementos a la cadena con libreria string.h
void concatenarCadena(char destino[]) {
	strcat(destino,"como ");
	strcat(destino,"estas? ");
	printf("Cadena destino: %s\n",destino);
}

//Buscar caracter dentro de una cadena con libreria string.h
void buscarElemento(char destino[]) {
	char * ptr;
	ptr=strchr(destino,'h');
	if(ptr!=NULL){
		printf("La letra H se encontro en la posicion: %d\n",ptr-destino);
	}
}