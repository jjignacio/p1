#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int grabarPrecios ();
int grabarPromedios();
int mostrarMejores();
int pasarBinario();
int mostrarBinario();
#define N 256

typedef struct producto{	
	char descripcion[50];
	float preciomini,preciomax;
}tprod;
typedef struct sproducutobin
{
	char descripcion[50];
	float promedio;
}tprodbinario;
int main ()
{
	int option;
	
	//grabarPrecios();
	//grabarPromedios();
	puts ("Desea mostrar los mejores promedios? \n\t[1] - SI.\n\t[0] - NO.");
	scanf ("%d", &option);
	if (option==1)
	{
		mostrarMejores();
	}
	pasarBinario();
	puts ("Se paso a binario correctamente");
	system("pause");
	system("cls");
	mostrarBinario();
	return 0;
}

int grabarPrecios ()
{
	FILE *archivo;
	int option=1;
	tprod producto1;
	archivo= fopen("productos.txt","wt");
	if (archivo==NULL)
	{
		puts ("No se pudo abrir correctamente para grabar el archivo 'productos.txt'");
		return 1;
	}
	while (option!=0)
	{
		puts("Ingrese la descripcion del producto");
		gets(producto1.descripcion);
		fflush(stdin);
		fputs(producto1.descripcion, archivo);
		fputc('\n',archivo);

		puts ("Ingrese desde donde es el precio del prod.");
		scanf("%f",&producto1.preciomini);
		fflush(stdin);
		fprintf (archivo,"%.2f",producto1.preciomini);
		fputc('\n',archivo);

		puts("Ingrese hasta donde es el precio del prod.");
		scanf("%f",&producto1.preciomax);
		fflush(stdin);
		fprintf (archivo,"%.2f",producto1.preciomax);
		fputc('\n',archivo);

		puts("Desea ingresar otro producto?  \n\t[1] - SI.\n\t[0] - NO.");
		scanf("%d", &option);
		fflush(stdin);
	}
	fclose(archivo);
	return 0;
}
int grabarPromedios()
{
	FILE *archivo,*archprod;
	char aux[N];
	float min,max,prom=0;
	archivo = fopen ("productos.txt","rt");
	if (archivo==NULL)
	{
		puts("No se pudo abrir para la lectura el archivo 'productos.txt'");
		return 1;
	}
	archprod=fopen("promedios de productos.txt", "wt");
	if (archprod==NULL)
	{
		puts("No se pudo abrir para la escritura el archivo 'promedios de productos.txt'?");
		return 1;
	}
	do
	{
		fgets(aux,N,archivo);
		fputs(aux,archprod);

		fscanf(archivo,"%f\n",&min);
		fscanf(archivo,"%f\n",&max);
		prom=((min+max)/2);
		fprintf(archprod,"%.2f",prom);
		fputc('\n',archprod);


	} while (!feof(archivo));
	puts("Se han grabado los promedios de los precios de los productos ingresados");

	fclose(archivo);
	fclose(archprod);
	return 0;
}
int mostrarMejores()
{
	FILE *archprod;
	char descrip[N],aux[N];
	int cont=0;
	float precio,prom=0;
	archprod = fopen ("promedios de productos.txt","rt");
	if (archprod==NULL)
	{
		puts("No se pudo abrir para la lectura el archivo 'promedios de productos.txt'");
		return 1;
	}
	do
	{
		fgets(descrip,N,archprod);
		fgets(aux,N,archprod);
		sscanf(aux,"%f",&precio);
		prom=prom+precio;
		cont++;
	} while (!feof(archprod));
	if (cont !=0)
	{
		prom=prom/cont;
	}
	rewind(archprod);
	fgets(descrip,N,archprod);
	fgets(aux,N,archprod);
	sscanf(aux,"%f",&precio);
	 while (!feof(archprod))
	 {
		if (precio>prom)
		{	
			puts("Producto que supera al promedio:\n");
			puts (descrip);
			printf("%.2f\n",precio);
		}
		else
		{
			printf("\nLa gaseosa %s NO es mayor al promedio\n\n",descrip);

		}
	fgets(descrip,N,archprod);
		fgets(aux,N,archprod);
		sscanf(aux,"%f",&precio);
	}
	fclose(archprod);
	return 0;

}
int pasarBinario()
{
	FILE *archprod,*archivobin;
	tprodbinario producto;
	archprod=fopen("promedios de productos.txt", "rt");
	if (archprod==NULL)
	{
		puts("No se pudo abrir para la escritura el archivo 'promedios de productos.txt'?");
		return 1;
	}
	archivobin=fopen("promediosprod.dat","wb");
	if (archivobin==NULL)
	{
		puts("No se pudo abrir el archivo 'promediosprod.dat'?");
		return 1;
	}
	fgets(producto.descripcion,40,archprod);
	fscanf (archprod,"%f\n",&producto.promedio);
	while (!feof(archprod))
	{
		fwrite (&producto,sizeof(producto),1,archivobin);
		fgets(producto.descripcion,50,archprod);
		fscanf (archprod,"%f\n",&producto.promedio);
	}
	fwrite (&producto,sizeof(producto),1,archivobin);
	fclose(archivobin);
	fclose(archprod);
	return 0;
}
int mostrarBinario()
{
	FILE *archivo;
	tprodbinario producto1;
	archivo=fopen("promediosprod.dat","rb");
	if (archivo==NULL)
	{
		puts("No se pudo abrir el archivo 'promediosprod.dat'?");
		return 1;
	}
	fread(&producto1,sizeof(producto1),1,archivo);
	while (!feof(archivo))
	{
		printf ("\n\n\tProducto: %s\n", producto1.descripcion);
		printf("\tPrecio: %.2f \n\n", producto1.promedio);
		fread(&producto1,sizeof(producto1),1,archivo);
	}
	fclose(archivo);
	return 0;
}

