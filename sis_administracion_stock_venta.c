
/*TRABAJO PRACTICO N-1
Alumnos: Lucas Galeano, Franco Puzzio, Leandro Chanarian
-LucasS*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

void func_mostrar_dia(int);
//int fun_ventas (int);
//int func_actualiza_stock(int);

int main() {
	int opc;
	int quesoStock = 20; 
	int cremosoStock = 20;
	int muzaStock = 20;
	int roqueStock = 20;
	int cheddarStock = 20;
	int gananciaDia = 0; 
	int gananciaSemanal = 0; 
	int n = 1;
	//VAR compras
	int codigo;
	int carrito = 0; 
	int n2 = 0; 
	int unidades = 0;
	char salir[3];
	char ver[3];
	
	//MENU
	printf("Sistema de control de stock/venta\n");
	printf("=================================\n");
    printf(" \n");
    func_mostrar_dia(n);
	printf("MENU PRINCIPAL DE CONTROL\n");
	printf("-------------------------\n");
	printf("1.Registrar venta/s\n");
	printf("2.Ver stock disponible\n");
	printf("3.Generar reporte de ingreso\n");
	printf("4.Cerrar el negocio por hoy\n");
	printf("0.salir\n");
	printf("Introduzca opcion:");
	scanf("%d",&opc);
	
	//SECCION DE PROCEDIMIENTOS 
	while(opc != 0){
		system("cls");
		switch(opc){
			case 1:				
				printf("Ingrese el ID del producto a comprar, de otro modo presione 0 para salir al menu principal\n");
				scanf("%d",&codigo);
				while(codigo!=0){
					switch(codigo){
						case 001:
								printf("Cuantas unidades va a comprar?\n");
								scanf("%d",&unidades);
								if(cremosoStock < unidades){
									system("cls");
									printf("Lo sentimos, no tenemos stock :c\n");
									printf("Nos quedan: %d unidades de este queso\n", cremosoStock);									
								}else{
									gananciaDia = gananciaDia + (unidades*250);
									n2 = n2 + unidades;
									cremosoStock = cremosoStock - unidades;					
									carrito = carrito + (unidades*250);										
								}					
							break;
						case 002:
							printf("Cuantas unidades va a comprar?\n");
							scanf("%d",&unidades);
								if(muzaStock < unidades){
									system("cls");
									printf("Lo sentimos, no tenemos stock :c\n");
									printf("Nos quedan: %d unidades de este queso\n", muzaStock);	
								}else{
									gananciaDia = gananciaDia + (unidades*100);
									n2 = n2 + unidades;
									muzaStock = muzaStock - unidades;
									carrito = carrito + (unidades*100);									
								}
							break;
						
						case 003:
							printf("Cuantas unidades va a comprar?\n");
							scanf("%d",&unidades);
								if(roqueStock < unidades){
									system("cls");
									printf("Lo sentimos, no tenemos stock :c\n");
									printf("Nos quedan: %d unidades de este queso\n", roqueStock);	
								}else{
									gananciaDia = gananciaDia + (unidades*300);
									n2 = n2 + unidades;
									roqueStock = roqueStock - unidades;
									carrito = carrito + (unidades*300);									
								}							
	
							break;
						
						case 004:
							printf("Cuantas unidades va a comprar?\n");
							scanf("%d",&unidades);
								if(cheddarStock < unidades){
									system("cls");
									printf("Lo sentimos, no tenemos stock :c\n");
									printf("Nos quedan: %d unidades de este queso\n", cheddarStock);	
								}else{
									gananciaDia = gananciaDia + (unidades*350);
									n2 = n2 + unidades;
									cheddarStock = cheddarStock - unidades;
									carrito = carrito + (unidades*350);									
								}							
		
							break;
					}							
						printf("Desea seguir comprando? SI/NO\n");
						scanf("%s",salir);
						//transforma las mayusculas en minusculas
						if (strcmp(salir, "SI") == 0){
							strcpy(salir, "si");
							}
						if (strcmp(salir, "sI") == 0){
							strcpy(salir, "si");
							}
						if (strcmp(salir, "Si") == 0){
							strcpy(salir, "si");
							}

						if (strcmp(salir, "NO") == 0){
							strcpy(salir, "no");
							}
						if (strcmp(salir, "nO") == 0){
							strcpy(salir, "no");
							}
						if (strcmp(salir, "No") == 0){
							strcpy(salir, "no");
							}	
						

						if(strcmp(salir, "no") == 0){
							codigo = 0;
							}
						
												
						printf("Quiere ver su carrito? SI/NO\n");
						scanf("%s",ver);

						if (strcmp(ver, "SI") == 0){
							strcpy(ver, "si");
							}
						if (strcmp(ver, "sI") == 0){
							strcpy(ver, "si");
							}
						if (strcmp(ver, "Si") == 0){
							strcpy(ver, "si");
							}

						if(strcmp(ver, "si") == 0){
							system("cls");
							printf("Cantidad de productos a comprar: %d\n",n2);
							printf("Va a costar: $ %d\n", carrito);
							system("pause");
							}
						//Si salir = "no" nunca entrará a este if y saldra al menu principal, de otro modo ingresará y preguntara nuevamente
						if(strcmp(salir, "si") == 0){
							system("cls");
							printf("Ingrese el ID del producto a comprar, de otro modo presione 0 para salir al menu principal\n");
				         	scanf("%d",&codigo);
							}	
					}
				//En el segundo trabajo eliminar carrito y n2 = 0 ya que en la funcion se resetearán por su cuenta.
				carrito = 0;
				n2 = 0;
				gananciaSemanal = gananciaSemanal + gananciaDia;

				break;
			case 2: 
				//Error rarisimo, si stock es 0 en vez de oprimir el case 2 me envia al case 3.
				// el codigo de "recargar" stock en case 4 si funciona, y al pasar de dia y oprimir 2 muestra el stock correspondiente/Franco
				// SOLUCIONADO el break estaba dentro del if y no dentro del case, por lo tanto salteaba al paso 3 /Franco y Lucas
				if(cremosoStock <= 0 && muzaStock <= 0 && roqueStock <= 0 && cheddarStock <= 0){ // a futuro, comparar cada stock e informar SOLO si no hay stock de dicho producto, mostrar si los demas
				system("cls");                                                                  // poseen stock /Franco																									
					printf("Lo sentimos, no tenemos mas stock por hoy :c\n");
					system("pause");
				}else{
					system("cls");
					printf("LISTA DE PRODUCTOS\n");
					printf("==================");
					printf("\nid|nombre producto|stock|precio\n");
					printf("\n001|Queso cremoso  |%d|250$\n",cremosoStock);
					printf("\n002|Queso muzarella|%d|100$\n",muzaStock);
					printf("\n003|Queso roquefort|%d|300$\n",roqueStock);
					printf("\n004|Queso cheddar  |%d|350$\n",cheddarStock);
					system("pause");					
				}
				break;
		
			case 3:

				/*la variable "ganancia" no sumaba "unidad" sino que se le asignaba el resultado de unidad*precio del producto
				Se corrigio igualando a "ganancia" por su valor sumado por el producto de (unidad*x)*/

				system("cls");
				func_mostrar_dia(n);
				if(n<7){
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					printf("El ingreso total fue de:"COLOR_GREEN" $ %d\n"COLOR_RESET,gananciaDia);
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				}else if (n=7){
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					printf("El ingreso total fue de:"COLOR_GREEN" $ %d\n"COLOR_RESET,gananciaDia);
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					printf("Las ganancias de la semana fueron de:"COLOR_GREEN" $ %d\n"COLOR_RESET,gananciaSemanal);
				}
				system("pause");
        	    break;
        
			case 4:
				gananciaDia = 0;
			     //edite "if(n<7) por if(n<=7) en caso de realizar una compra en el dia 7 y que genere errores, ya que si n = 7 --> n NO es menor a 7" -Lucas
   		        n++;
				if(n<=7){
				gananciaDia = 0;
				                   //gananciaDia = 0 el nuevo dia se arranca con $ 0 ganancias
				}else if (n==8) { //este else identifica el fin de la semana -Franco
					gananciaSemanal = 0;
					gananciaDia = 0;
					n = 1;
				}
				break;

			default:
				printf(COLOR_RED "ERROR, ingrese una opcion correcta\n"COLOR_RESET);
				system("pause");
				exit;
                //HACERRRRRRRRRRRRRRRRR
				/*/if(quesoStock < 20){//codigo que actualiza el stock si baja de 20 unidades
					quesoStock = 20;
				}*/
		}

        system("cls");
		printf("Sistema de control de stock/venta\n");
		printf("=================================\n");
        printf(" \n");
 	    func_mostrar_dia(n);
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

void func_mostrar_dia(int d){
	switch(d){
		case 1:
			printf(COLOR_CYAN "Dia Lunes" COLOR_RESET "\n");
			break;
		case 2:
			printf(COLOR_CYAN"Dia Martes\n"COLOR_RESET);
			break;
		case 3:
			printf(COLOR_CYAN"Dia Miercoles\n"COLOR_RESET);	
			break;				
		case 4:
			printf(COLOR_CYAN"Dia Jueves\n"COLOR_RESET);	
			break;				
		case 5:
			printf(COLOR_CYAN"Dia Viernes\n"COLOR_RESET);
			break;						
		case 6:
			printf(COLOR_CYAN"Dia Sabado\n"COLOR_RESET);	
			break;					
		case 7:
			printf(COLOR_CYAN"Dia Domingo\n"COLOR_RESET);
			break;						
	}
}

/*int fun_ventas (int ganaDia){
	
	int codigo;
	int carrito = 0; 
	int n2 = 0; 
	int unidades = 0;
	
	char salir[3];
	char ver[3];
	
	printf("Ingrese el ID del producto a comprar, de otro modo presione 0 para salir al menu principal\n");
	scanf("%d",&codigo);
	while(codigo!=0){
		switch(codigo){
			case 001:
				printf("Cuantas unidades va a comprar?");
				scanf("%d",&unidades);
				ganaDia = ganaDia + (unidades*250);
				n2 = n2 + unidades;
				func_actualiza_stock(unidades);

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
			//Si salir = "no" nunca entrar� a este if y saldra al menu principal, de otro modo ingresar� y preguntara nuevamente
			if(strcmp(salir, "si") == 0){
				printf("Ingrese el ID del producto a comprar, de otro modo presione 0 para salir al menu principal\n");
	         	scanf("%d",&codigo);
				}	
		}
	
	
	
	return ganaDia;
}*/




/*int func_actualiza_stock(int uni){
	int stk;
	stk = stk - uni;
	return stk;
}*/


