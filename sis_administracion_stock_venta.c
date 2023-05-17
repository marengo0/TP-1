
//ventas por dia, muestra informe
//venta por semana: muestra que quesos se vendieron, y la venta total
// en 3 al finalizar la semana generar menu para elegir que reporte mostrar: que queso se vendio mas, venta total, que dia se vendio mas



/*TRABAJO PRACTICO N-1
Alumnos: Lucas Galeano, Franco Puzzio,"ingresa el nombre del nazi que no me acuerdo"
-Lucas*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	int opc; int quesoStock = 20; int unidad; int ganancia = 0; int gananciaSemanal = 0; int n = 0;
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
			
			printf("Cuanto queso desea comprar?");
			scanf("%d",&unidad);
			//variable vender genera error, no continua y no cierra, el SCANF genera problemas (SOLUCION: &&&&&&&&&&&&&&&&&)
			quesoStock = quesoStock - unidad;
			break;
			
		case 2:
			system("cls");
			printf("LISTA DE PRODUCTOS\n");
			printf("==================");
			printf("\nid|nombre producto|stock|precio\n");
			printf("\n001|Queso cremoso  |%d|250$\n",quesoStock);
			printf("\n002|Queso muzarella|%d|250$\n",quesoStock);
			printf("\n001|Queso roquefort|%d|250$\n",quesoStock);
			printf("\n001|Queso cheddar  |%d|250$\n",quesoStock);
			printf("\n001|Queso sardo    |%d|250$\n",quesoStock);
			printf("\n001|Queso gruyere  |%d|250$\n",quesoStock);
			printf("\n001|Queso parmesano|%d|250$\n",quesoStock);
			printf("\n001|Queso azul     |%d|250$\n",quesoStock);
			printf("\n001|Queso    |%d|250$\n",quesoStock);
			system("pause");
			break;
		
		case 3:
			/*la variable "ganancia" no sumaba "unidad" sino que se le asignaba el resultado de unidad*precio del producto
			Se corrigio igualando a "ganancia" por su valor sumado por el producto de (unidad*x)

			NOTA: no podemos calcular la ganancia en "case 3" ya que siempre multiplicara a unidad por 250
			pienso que habra que o generarla dentro de una funcion o meterla en "case 2" -Lucas*/ 
		    
		system("cls");
			ganancia = ganancia+(unidad*250); //ESTA

			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("el ingreso total fue de: $ %d\n",ganancia);
			if (n>=7){
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("Las ganancias de la semana fueron de $ %d\n",gananciaSemanal);
			}
			system("pause");
            break;
        
		case 4:
		     //edite la linea 73 de "if(n<7) por if(n<=7) en caso de realizar una compra en el dia 7 y que genere errores, ya que si n = 7 --> n NO es menor a 7" -Lucas
            if(n<=7){
			n++;
			gananciaSemanal = gananciaSemanal + ganancia;
			ganancia = 0;
			//ganancia = 0 el nuevo dia se arranca con $ 0 ganancias
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
