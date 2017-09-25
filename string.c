void primeraLetraMayuscula(char cadena[]) {
	int i; 

	for(i=0; cadena[i]; i++) {
		if(i==0) {
			cadena[i] = toupper(cadena[i]); // letra a mayuscula
		} else if(isspace(cadena[i])) {
			cadena[i+1] = toupper(cadena[i+1]);
		}
	}
}

// tener en cuenta para el parcial.
void borrarEspacios(char cadena[]) {
	int i=0, j=0;
	char cadenaNueva[80];

	while(i < strlen(cadena)) { // tamaño del a cadena.
		if(cadena[i]!=' ') { 
			cadenaNueva[j] = cadena[i];
			j++;
		}
		i++;
	}
	cadenaNueva[j] = '\0';

	strcpy(cadena,cadenaNueva); // copiar una cadena en la otra.

	puts(cadenaNueva);
}

void insertarSubcadenaStdio(char cadena[], char subCadena[], int posicion) {
	int i;

	for(i=0; cadena[i]; i++) {
		if(i==posicion) {
			sprintf(&cadena[posicion], "%s", subCadena); // parcial.
			// &cadena[posicion] apunta a la posicion que se ingreso
			// cadena[posicion] me estoy refiriendo al elemento que esta en esa posicion.
		}
	}

	puts(cadena);
}

ctype:
	isalpha(<caracter>)
	isdigit(<caracter>)
	isalnum(<caracter>)
	isupper(<caracter>)
	islower(<caracter>)
	isspace(<caracter>)
	toupper(<char>)
	tolower(<char>)

stdio:
	sprintf(&cadena[posicion], "%s", subCadena); // SE USA PARA CONCATENAR
	sscanf(cadena, "%f", &pi); // Paso el numero de tipo flotante

string:
	strlen(<cadena>)
	strcpy(<destino><origen>)
	strcat(<cad1><cad2>) // concatena las 2 cadenas, pone cad 2 al final de cad1
	strchr(<cadena><char>) // retorna un puntero al comiezo de la cadena donde encontro al caracter
	strstr(<cad1><cad2>) // busca una cadena dentro de otra y retorna un puntero a la direccion donde lo encontro
	strcmp(<cadena>)
