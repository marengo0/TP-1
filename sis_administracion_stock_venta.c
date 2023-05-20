
//ventas por dia, muestra informe
//venta por semana: muestra que quesos se vendieron, y la venta total
// en 3 al finalizar la semana generar menu para elegir que reporte mostrar: que queso se vendio mas, venta total, que dia se vendio mas



/*TRABAJO PRACTICO N-1
Alumnos: Lucas Galeano, Franco Puzzio, Leandro Chanarian
-Lucas*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int fun_ventas (int);
int main() {
	int opc; int quesoStock = 20; int unidad; int gananciaDia = 0; int gananciaSemanal = 0; int n = 1;
	printf("Sistema de control de stock/venta\n");
	printf("=================================\n");
    printf(" \n");
	printf("MENU PRINCIPAL DE CONTROL\n");
	printf("-------------------------\n");
	printf("1.Registrar venta/s\n");
	printf("2.Ver stock disponible\n");
	printf("3.Generar reporte de ingreso\n");
	printf("4.Cerrar el negocio por hoy\n");
	printf("0.salir\n");
	printf("Introduzca opcion:");
	scanf("%d",&opc);
	
	
	while(opc != 0){
	
	switch(opc){
		case 1:
			
			//La funcion fun_ventas se ingresa en case 1, elimina todo lo que hay en case 1
			gananciaDia = fun_ventas(gananciaDia);
			gananciaSemanal = gananciaSemanal + gananciaDia;
			
			break;
			
		case 2:
		/* actualizar el stock de cada producto, TAREA PENDIENTE */
			system("cls");
			printf("LISTA DE PRODUCTOS\n");
			printf("==================");
			printf("\nid|nombre producto|stock|precio\n");
			printf("\n001|Queso cremoso  |%d|250$\n",quesoStock);
			printf("\n002|Queso muzarella|%d|250$\n",quesoStock);
			printf("\n003|Queso roquefort|%d|250$\n",quesoStock);
			printf("\n004|Queso cheddar  |%d|250$\n",quesoStock);
			printf("\n005|Queso sardo    |%d|250$\n",quesoStock);
			printf("\n006|Queso gruyere  |%d|250$\n",quesoStock);
			printf("\n007|Queso parmesano|%d|250$\n",quesoStock);
			printf("\n008|Queso azul     |%d|250$\n",quesoStock);
			system("pause");
			break;
		
		case 3:
			/*la variable "ganancia" no sumaba "unidad" sino que se le asignaba el resultado de unidad*precio del producto
			Se corrigio igualando a "ganancia" por su valor sumado por el producto de (unidad*x)

			NOTA: no podemos calcular la ganancia en "case 3" ya que siempre multiplicara a unidad por 250
			pienso que habra que o generarla dentro de una funcion o meterla en "case 2" -Lucas*/ 
		    
		system("cls");
			

			
			if(n<7){
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("el ingreso total fue de: $ %d\n",gananciaDia);
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}else if (n=7){
				printf("el ingreso total fue de: $ %d\n",gananciaDia);
				printf("Las ganancias de la semana fueron de $ %d\n",gananciaSemanal);
			}
			system("pause");
            break;
        
		case 4:
		    n++;
		     //edite la linea 73 de "if(n<7) por if(n<=7) en caso de realizar una compra en el dia 7 y que genere errores, ya que si n = 7 --> n NO es menor a 7" -Lucas
            if(n<=7){
			/* gananciaSemanal = gananciaSemanal + gananciaDia; */
			gananciaDia = 0;
			//ganancia = 0 el nuevo dia se arranca con $ 0 ganancias
			}else if (n==8) { //este else discrimina el fin de la semana -Franco
				gananciaSemanal = 0;
				gananciaDia = 0;
				n = 1;
			}
		

	}

    system("cls");
	printf("Sistema de control de stock/venta\n");
	printf("=================================\n");
    printf(" \n");
	printf("MENU PRINCIPAL DE CONTROL\n");
	printf("-------------------------\n");
	printf("1.Registrar venta/s\n");
	printf("2.Ver stock disponible\n");
	printf("3.Generar reporte de ingreso\n");
	printf("4.Cerrar el negocio por hoy\n");
	printf("0.salir\n");
	printf("Introduzca opcion:");
	scanf("%d",&opc);	

}
return 0;

}

int fun_ventas (int ganaDia){

	int codigo; int carrito = 0; int n2 = 0; int unidades = 0;
	char salir[3]; char ver[3];
	printf("Ingrese el ID del producto a comprar, de otro modo presione 0 para salir al menu principal\n");
	scanf("%d",&codigo);
	while(codigo!=0){
		switch(codigo){
			case 001:
				printf("Cuantas unidades va a comprar?");
				scanf("%d",&unidades);
				ganaDia = ganaDia + (unidades*250);
				n2 = n2 + unidades;
				carrito = carrito + (unidades*250);
				break;
			case 002:
				printf("Cuantas unidades va a comprar?");
				scanf("%d",&unidades);
				ganaDia = ganaDia + (unidades*100);
				n2 = n2 + unidades;
				carrito = carrito + (unidades*100);
				break;
			}
	

			printf("Desea seguir comprando? SI/NO");
			scanf("%s",salir);
			//transforma las mayusculas en minusculas
			if (strcmp(salir, "SI") == 0){
				strcpy(salir, "si");
				}
			if (strcmp(salir, "NO") == 0){
				strcpy(salir, "no");
				}
			if(strcmp(salir, "no") == 0){
				codigo = 0;
				}
			
			
			printf("Quiere ver su carrito? SI/NO");
			scanf("%s", ver);
			if (strcmp(ver, "SI") == 0){
				strcpy(ver, "si");
				}
			if(strcmp(ver, "si") == 0){
				printf("Cantidad de productos a comprar: %d",n2);
				printf("Va a costar: $ %d", carrito);
				system("PAUSE");
				}
			//Si salir = "no" nunca entrará a este if y saldra al menu principal, de otro modo ingresará y preguntara nuevamente
			if(strcmp(salir, "si") == 0){
				printf("Ingrese el ID del producto a comprar, de otro modo presione 0 para salir al menu principal\n");
	         	scanf("%d",&codigo);
				}	
		}
	
	
	
	return ganaDia;
}