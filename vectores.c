// Cargar un vector con números de tres dígitos generados al azar.
void cargar(int vector[MAX]) {
	int i=0;

	srand((int)time(NULL));

	while(i<MAX) {
		// rand()%(valorFinal - valorInicial+1) ??
		vector[i] = rand()%(999-100+1)+99;
		i++;
	}
}

// Modulo para ordenar el vector por metodo Burbuja.
void ordenar(int vector[MAX]) {
	int i, aux, j;

	for(i=0; i<MAX-1; i++) {
		for(j=i+1; j<MAX; j++) {
			if(vector[j] < vector[i]) {
				aux = vector[j];
				vector[j] = vector[i];
				vector[i] = aux;
			}
		}
	}
}

// Buscar un valor dentro de un vector ordenado y devolver la posición en que se halla dicho valor. (busqueda Binaria)
int busquedaBinaria(int vector[MAX]) {
	int i, j, posicion=-1, inicio=0, fin=MAX, medio, num;

	printf("Ingrese un numero de 3 cifras: ");
	scanf("%d",&num);

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
	return posicion;
}

// Determinar si el contenido de un vector es capicúa. No usar vectores auxiliares.
void capicua(int vector[MAX]) {
	int i, j, inicio = 0, fin = MAX, capicua = 1, medio;

	medio = (inicio + fin)/2;
	for(i=0; i<medio; i++){
		if(vector[i] != vector[fin-1]){
			capicua = 0;
		}
		fin--;
	}
	if(capicua == 1){
		printf("El vector es Capicua.\n");
	}else{
		printf("El vector NO es Capicua.\n");
	}
}

// b. Ordenar en forma ascendente cada una de las filas de una matriz - Metodo Burbuja. (IMPORTANTE - PARCIAL)
void ordenar(int matriz[][MAXC]) {
	int i, j, w, u, aux;
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

// Determinar si la matriz es simétrica con respecto a su diagonal secundaria.
void simetricaDiagonalSecundaria(int matriz[][MAXC]) {
	int f, c, simetrica = 1;

	for(f=MAXF-1; f>=0; f--) {
		for(c=MAXC-1; f+c>MAXF-1; c--) {
			if(matriz [f][c] != matriz[(MAXC-1)-c][(MAXF-1)-f]){
				simetrica = 0;
			}
			//printf("%d - %d\n",matriz [f][c],matriz[(MAXC-1)-c][(MAXF-1)-f]); Verificador
		}
	}

	if(simetrica == 0) {
		printf("La matriz NO es simetrica con respecto a su diagonal secundaria. \n\n");
	} else {
		printf("La matriz es simetrica con respecto a su diagonal secundaria. \n\n");
	}
}

// Diagonal Secundaria.
void dos(int matriz[][MAXC]) {
	int f, c, indice = MAXF-1, multiplo = 1;

	for(f=MAXF-1; f>=0; f--) {
		for(c=MAXC-1; c>=0; c--) {
			if(f+c == indice){
				matriz[f][c] = multiplo;
			} else {
				matriz[f][c] = 0;
			}
		}
		multiplo = multiplo * 3;
	}
	imprimir(matriz);
}

// Mostrar una matriz en forma de caracol.
void cinco(int matriz[][MAXC]) {
	int i, j;
    int count = 1;
    int aux = MAXF-1;
	int impar = 1;
    
    for(i = 1; i < MAXF; i++) {
        for(j = i-1; j < aux; j++) {
            matriz[MAXC-(aux+1)][j] = impar;
            impar = impar+2;
        }
        for( j = i-1; j < aux; j++) {
            matriz[j][aux] = impar;
            impar = impar+2;
        }
        for(j = aux; j >= (i-1); j--) {
            matriz[aux][j] = impar;
            impar = impar+2;
        }
        aux--;
        for(j = aux; j >= i; j--) {
            matriz[j][MAXC-(aux+2)] = impar;
            impar = impar+2;
        }
    }

	imprimir(matriz);
}

// Matriz Zig-Zag
void nueve(int matriz[][MAXC]) {
	int f, c, num=1, aux = MAXC-1;

	for(f=1; f<MAXF; f++) {
        for(c=f-1; c<aux; c++) {
            matriz[MAXF-(aux+1)][c] = num;
            num++;
        }
        for(c=f-1; c<aux; c++) {
            matriz[c][aux] = num;
            num++;
        }
        for(c=aux; c>=(f-1); c--) {
            matriz[aux][c] = num;
			num++;
        }
        aux--;
        for(c=aux; c>=f; c--) {
            matriz[c][MAXF-(aux+2)] = num;
            num++;
        }
    }
	imprimir(matriz);
}
