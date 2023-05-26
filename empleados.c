

/*Ejercicio Evaluación de Desempeño
Se desea hacer una aplicación para registrar las evaluaciones de desempeño de los empleados de
una empresa, cuyos datos son los siguientes:
Código de empleado (entero)
Días trabajados (entero)
Profesional (“SI”/”NO”)
Factores a evaluar:
Calidad y Cantidad de Trabajo (entero, valores de 1 a 5)
Cooperación (entero, valores de 1 a 5)
Capacidad de Análisis y Creatividad (entero, valores de 1 a 5). Ingresar sólo si el empleado es
profesional.
La calificación de los factores es de 1 a 5, siendo 5 la calificación más alta. La Capacidad de Análisis y
Creatividad se evalúa sólo a los empleados profesionales
Los datos de los empleados terminan cuando el operador indica que no desea registrar más
empleados.
Se pide informar: Por cada empleado profesional, si tiene o no potencial de desarrollo. Hacer una
función, que tenga como parámetros los tres factores a evaluar, y devuelva el valor 1 si el empleado
profesional tiene potencial de desarrollo y el valor 0 si no lo tiene. Mostrar por pantalla el código de
empleado profesional y un cartel indicando “TIENE CAPACIDAD DE DESARROLLO”, o “NO TIENE
CAPACIDAD DE DESARROLLO”, haciendo otra función que tenga como parámetros el Código de
empleado y el resultado obtenido en la primera función.
El empleado profesional tiene potencial de desarrollo si sus calificaciones son:
Calidad y Cantidad de Trabajo>=4 y
Cooperación>=4 y
Capacidad de Análisis y Creatividad>=4
Al finalizar el registro de las evaluaciones, se debe informar:
a) La cantidad de empleados profesionales “Fuera de Nivel”. Son aquellos empleados
profesionales cuya calificación promedio es menor a 3.
b) El código de empleado con mayor cantidad de días trabajados (se supone único).
No se pueden utilizar variables globales. Se pide: CODIFICACION EN LENGUAJE C DEL ALGORITMO.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fun_discriminante(int,int,int);
int fun_reporte(int,int);
int main(int argc, char *argv[]) {
	int id = 0; int diasTrabajo = 0; int  calidad = 0; int coop = 0; int creatividad = 0; int result = 0; int n = 0; float promedio = 0; int max = 0; int band = 0; int idAux = 0;
	char pro[3]; char registrar[3];
    
    printf("%cDesea registrar un empleado?",168);
    fflush(stdin);
    scanf("%s",registrar);
    if (strcmp(registrar,"SI")==0) {
		strcpy(registrar,"si");
	}
	else if (strcmp(registrar,"NO")==0){
		strcpy(registrar,"no");
	}
    // strcmp tambien hay que usarlo cuando se compara un string en un while 
    while (strcmp(registrar, "no")!=0){
        system("cls");
        printf("Administrador de empleados\n");
        printf("\nIngrese codigo de empleado:");
        scanf("%d",&id);
        printf("\nIngrese dias trabajados:");
        scanf("%d",&diasTrabajo);
        printf("\n%cEs profesional?",168);
        fflush(stdin);
        scanf("%s",pro);

        
        if (strcmp(pro,"SI")==0) {
            strcpy(pro,"si");
        }
        else if (strcmp(pro,"NO")==0){
            strcpy(pro,"no");
        }
    
        printf("\nIngrese calidad y cantidad de trabajo(rango de 1 a 5)");
        scanf("%d",&calidad);
        printf("\nIngrese cooperacion");
        scanf("%d",&coop);

        printf("\nIngrese capacidad de analisis y creatividad");
        scanf("%d",&creatividad);

        if(strcmp(pro,"si")==0){
            result=fun_discriminante(calidad,coop,creatividad);
            //printf("%d",result);
            fun_reporte(id,result);
            promedio = (calidad+coop+creatividad)/3;
            if(promedio<3){
                n++;
                printf("%f",promedio);
            }
        }  

        if(diasTrabajo>max){
            band = 1;
        }

        if(band==1){
            max = diasTrabajo;
            idAux = id;
        }

    
        
        printf("%cDesea seguir registrando empleados?",168);
        fflush(stdin);
        scanf ("%s",registrar);
        
        if (strcmp(registrar,"SI")==0) {
            strcpy(registrar,"si");
        }
        else if (strcmp(registrar,"NO")==0){
            strcpy(registrar,"no");
        }

    }
	system("cls");
    printf("la cantidad de empleados fuera de nivel son %d\n",n);
    printf("el empleado %d es el que mas dias trabajo\n",id);
    system("pause");
	return 0;
}


int fun_discriminante(int p_calidad,int p_coop,int p_creatividad){
	
	if(p_calidad>=4 && p_coop>=4 && p_creatividad>=4){
		return 1;
	}
    else return 0;   	
}
int fun_reporte(int p_id, int p_result){

    if(p_result==1){
        printf("El empleado %d tiene capacidad de desarrollo",p_id);
    } 
    else{
        printf("El empleado %d no tiene capacidad de desarrollo",p_id);
        system("pause");
        system("cls");}
}
