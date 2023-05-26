#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int fun_scoreL(int, int);
int fun_scoreV(int);
int main(int argc, char *argv[]) {
	char local[10]; char visitante[10]; char continuar = 's';char Tlocal;char Tvis; char campeon[10] = "";
	int gLocal = 0; int gVisitante = 0; int pL = 0;int pV = 0; int band = 1; int maxPts = 0;
	int t1 = 0; int t2 = 0; int t3 = 0; int t4 = 0;

    while(continuar=='s'){
        printf("Torneito\n");
        printf("========\n");
        printf("");
        printf("Ingrese el equipo de local:");
        fflush(stdin);
        scanf("%s",local);
        fflush(stdin);
        printf("\nIngrese el equipo de visitante");
        scanf("%s",visitante);
        printf("Ingrese los goles de %s",local);
        scanf("%d",&gLocal);
        printf("\nIngrese los goles de %s",visitante);
        scanf("%d",&gVisitante);
	
	
		if(strcmp(local,"Merlo")==0){
			Tlocal = 'm';
            printf("%c",Tlocal);
            system("pause");
			
		}
		if(strcmp(local,"Moron")==0){
			Tlocal = 'o';
			
		}	
		if(strcmp(local,"Ituzaingo")==0){
			Tlocal = 'i';
			
		}
		if(strcmp(local,"Atlas")==0){
			Tlocal = 'a';
			
		}

        if(strcmp(visitante,"Merlo")==0){
			Tvis = 'm';
            printf("%c",Tvis);
            system("pause");
			
		}
		if(strcmp(visitante,"Moron")==0){
			Tvis = 'o';
			
		}	
		if(strcmp(visitante,"Ituzaingo")==0){
			Tvis = 'i';
			
		}
		if(strcmp(visitante,"Atlas")==0){
			Tvis = 'a';
			
		}

		pL = fun_scoreL(gLocal,gVisitante);
		pV = fun_scoreV(pL);
		printf("el local tiene %d puntos y el visitante %d puntos",pL,pV);
		//system("pause");
	
	
		switch(Tlocal){
            case 'm':
                t1 = t1+pL;
                if (band==1){
                band = 0;
                maxPts = t1; 
            }else {if(t1>maxPts){
                maxPts = t1;
            }
            }
            break;
            case 'o':
                t2 = t2+pL;
                if (band==1){
                band = 0;
                maxPts = t2; 
            }else{if(t2>maxPts){
            maxPts = t2;
            }
            }
            break;
            case 'i':
                t3 = t3+pL;
                if (band==1){
                band = 0;
                maxPts = t3; 
            }else{if(t3>maxPts){
                maxPts = t3;
            }
            }
            break;
            case 'a':
                t4 = t4+pL;
                if (band==1){
                band = 0;
                maxPts = t4; 
            }else{if(t4>maxPts){
            maxPts = t4;
            }
            }
            break;	
		}
		
	    switch(Tvis){
            case 'm':
                t1 = t1+pV;
                if (band==1){
                band = 0;
                maxPts = t1; 
            }else{if(t1>maxPts){
                maxPts = t1;
                strcpy(campeon,"Merlo");
            }
            }
            break;
            case 'o':
                t2 = t2+pV;
                if (band==1){
                band = 0;
                maxPts = t2; 
            }else{if(t2>maxPts){
                maxPts = t2;
                strcpy(campeon,"Moron");
            }
            }
            break;
            case 'i':
                t3 = t3+pV;
                if (band==1){
                band = 0;
                maxPts = t3; 
            }else {if(t3>maxPts){
                maxPts = t3;
                strcpy(campeon,"Ituzaingo");
            }
            }
            break;
            case 'a':
                t4 = t4+pV;
                if (band==1){
                band = 0;
                maxPts = t4; 
            }else {if(t4>maxPts){
                maxPts = t4;
                strcpy(campeon,"Atlas");
            }
            }
            break;			
	    }
        printf("desea continuar?\n");
        printf("Ingrese s, o, n ");
        fflush(stdin);
        scanf("%c",&continuar);
	} 
    fflush(stdin);
    printf("el equipo ganador es %s ",campeon);	
    system("pause");
	return 0;
}

int fun_scoreL(int p_gLocal,int p_gVisitante){
	int ptsLocal = 0;
	if(p_gLocal>p_gVisitante){
		ptsLocal = 3;
	}
	if(p_gLocal<p_gVisitante){
		p_gLocal = 0;
	}
	if(p_gLocal==p_gVisitante){
		ptsLocal = 1;
	}
	return ptsLocal;
}
int fun_scoreV(int p_ptsLocal){
	int ptsVis = 0;
	if(p_ptsLocal==3){
		ptsVis = 0;
	}
	if(p_ptsLocal==1){
		ptsVis = 1;
	}
	if(p_ptsLocal==0){
		ptsVis = 3;
	}
	return ptsVis;
}

