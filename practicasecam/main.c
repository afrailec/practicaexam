#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void inicializar_matriz(int matriz[N][N]);
void rellenar_matriz(int matriz[N][N]);
int random_number();
void imprimir_matriz();

int main()
{
    srand(time(NULL));

    int matriz[N][N];
    int c;

    do{
        printf("ELIJA UNA OPCION:\n0-SALIR\n1-GENERAR E IMPRIMIR MATRIZ ALEATORIA\n");
        scanf("%d", &c);
        if(c==1){
            inicializar_matriz(matriz);
            rellenar_matriz(matriz);
            imprimir_matriz(matriz);
        }
    }while(c!=0);

    return 0;
}

void inicializar_matriz(int matriz[N][N]){
    int i,j;

    for(i=0; i<=N; i++){
        for(j=0; j<=N; j++){
            matriz[i][j]=0;
        }
    }
}

void rellenar_matriz(int matriz[N][N]){
    int i,j;

    for(i=0; i<=N; i++){
        for(j=0; j<=N; j++){
            matriz[i][j]=random_number();
        }
    }
}

int random_number(){
    return rand()%10;
}

void imprimir_matriz(int matriz[N][N]){
    int i,j;

    for(i=0; i<=N; i++){
        for(j=0; j<=N; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}
