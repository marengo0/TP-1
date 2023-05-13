
//ventas por dia, muestra informe
//venta por semana: muestra que quesos se vendieron, y la venta total
// en 3 al finalizar la semana generar menu para elegir que reporte mostrar: que queso se vendio mas, venta total, que dia se vendio mas







#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main() {
	int opc; int quesoStock = 20; int unidad; int ganancia = 0;
	printf("Sistema de control de stock/venta\n");
	printf("=================================\n");
  printf(" \n");
	printf("MENU PRINCIPAL DE CONTROL\n");
	printf("-------------------------\n");
	printf("1.Registrar venta/s\n");
	printf("2.Ver stock disponible\n");
	printf("3.Generar reporte de ingreso\n");
	printf("4.salir\n");
	printf("Introduzca opcion:");
	scanf("%d",&opc);
	
	
	while(opc != 4){ //dia
	
	switch(opc){
		case 1:
			
			printf("Cuanto queso desea comprar?");
			scanf("%d",&unidad);//variable vender genera error, no continua y no cierra, el SCANF genera problemas (SOLUCION: &&&&&&&&&&&&&&&&&)
			// para los enteros el scanf lleva %d,&nombreVariable
			quesoStock = quesoStock - unidad;
			break;
			
		case 2:
			system("cls");
			printf("LISTA DE PRODUCTOS\n");
			printf("==================");
			printf("\nid|nombre producto|stock|precio\n");
			printf("\n001|Queso    |%d|250$\n",quesoStock);
			system("pause");
			break;
		
		case 3:
			ganancia = unidad*250;
			printf("el ingreso total fue de: $ %d\n",ganancia);
      system("pause");
      break;
			
			
	//	default:
			
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
	printf("4.salir\n");
	printf("Introduzca opcion:");
	scanf("%d",&opc);

}
return 0;

}
