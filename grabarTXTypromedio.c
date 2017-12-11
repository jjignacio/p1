/*6.	Hacer un programa que invoque y pruebe las siguientes funciones:
grabarPrecios() permite grabar en un archivo de texto el rango de precio sugerido de un producto. 
Cada dato se debe grabar en línea distinta.
descripción
precioDesde
precioHasta 
grabarPromedios() permite leer el archivo generado en la función anterior y generar otro archivo de texto con los promedios de los precios de los productos. 
Tanto la descripción como el promedio se graban en diferentes líneas.
descripción
promedio
mostrarMejores() permite mostrar los productos cuyo precio promedio es superior al precio promedio de todos los productos. 

*/



#include <stdio.h>
#define MAX 30

typedef struct {
	char descripcion[MAX];
	int preciodesde;
	int preciohasta;
}sproducto;

void grabarprecios(FILE *arch);
void grabarpromedios(FILE *arch);
void mostrarmejores(FILE *arch);

int main(){


FILE *arch;

			arch=fopen("productos.txt","wt+");
			grabarprecios(arch);
			fclose(arch);

			arch=fopen("productos.txt","rt+");
			grabarpromedios(arch);  //lo graba en archivo "promedios.txt"
			fclose(arch);

			arch=fopen("promedios.txt","rt+");
			mostrarmejores(arch);   //lo muestra en pantalla
			fclose(arch);



system("PAUSE");
return 0;
}

void grabarprecios(FILE *arch){

	sproducto producto;
	int i=0;

	while(i!=-1){
	
	printf("Producto: \n");
	scanf("%s",&producto.descripcion);
	fflush(stdin);
	fputs(&producto.descripcion,arch);
	fputc(10,arch);


	printf("Precio desde: \n");
	scanf("%d",&producto.preciodesde);
	fflush(stdin);
	fprintf(arch,"%d",producto.preciodesde);
	fputc(10,arch);

	printf("Precio Hasta: \n");
	scanf("%d",&producto.preciodesde);
	fflush(stdin);
	fprintf(arch,"%d",producto.preciodesde);
	fputc(10,arch);

	printf("Para terminar -1 sino cualquier valor \n");
	scanf("%d",&i);
	fflush(stdin);

	}

}
void grabarpromedios(FILE *arch){

	FILE *destino;
	sproducto producto;

	float promedio;

	destino=fopen("promedios.txt","wt+");

	
		fscanf(arch,"%s",producto.descripcion);  //es dir de memoria ya
		fscanf(arch,"%d",&producto.preciodesde);
		fscanf(arch,"%d",&producto.preciohasta);

	while(!feof(arch)){
	
		//fgets(&producto.descripcion,MAX,arch);
		

				promedio=(float)((producto.preciodesde+producto.preciohasta)/2);
	
				fputs(producto.descripcion,destino);
				fputc(10,destino);
				fprintf(destino,"%f",promedio);
				fputc(10,destino);


				fscanf(arch,"%s",producto.descripcion);
				fscanf(arch,"%d",&producto.preciodesde);
				fscanf(arch,"%d",&producto.preciohasta);
	
		}

fclose(destino);
}


void mostrarmejores(FILE *arch){

	sproducto producto;

	float promedio,suma=0;
	int cantidad=0;

		fgets(producto.descripcion,MAX,arch);
		
	while(!feof(arch)){
			
			fscanf(arch,"%f\n",&promedio);
			suma=suma+promedio;
			cantidad++;
			fgets(producto.descripcion,MAX,arch);
			
			
		}
			
			
			suma=(float)(suma/cantidad);

			printf("promedio total: %f \n",suma);
			
			rewind(arch);

			fgets(producto.descripcion,MAX,arch);
			

while(!feof(arch)){
			
	fscanf(arch,"%f\n",&promedio);

	if(promedio>suma){
			printf("Producto: %s\n",producto.descripcion);
			printf("Precio Promedio: %f \n",promedio);
					
	}
			fgets(producto.descripcion,MAX,arch);
}
}

