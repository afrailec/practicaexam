#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3


struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

struct Lista{
    struct Nodo *cabecera;
};

void inicializar_matriz(int matriz[N][N]);
void rellenar_matriz(int matriz[N][N]);
int random_number();
void imprimir_matriz();

void introducir_lista(int valor, struct Lista *);
void imprimir_lista(struct Lista);

void intToString(int n, char *s);

void matrizAVector(int A[][N], int v[]);
void imprimir_array(int vector[20]);


int main(){

    srand(time(NULL));

    int matriz[N][N];
    int c, x, num;
    struct Lista list;
    char string[15];
    int vector[20];

    list.cabecera=NULL;

    do{
        printf("ELIJA UNA OPCION:\n0-SALIR\n1-GENERAR E IMPRIMIR MATRIZ ALEATORIA\n2-INSERTAR ELEMENTO EN UNA LISTA\n3-IMPRIMIR UNA LISTA\n4-LIMPIAR PANTALLA\n5-INTRODUCIR NUMERO EN STRING\n6-MATRIZ A VECTOR(REQUIERE 1)\n");
        scanf("%d", &c);

        if(c==1){
            inicializar_matriz(matriz);
            rellenar_matriz(matriz);
            imprimir_matriz(matriz);
        }

        if(c==2){
            printf("Introduzca el dato a introducir en la lista:");
            scanf("%d", &x);
            introducir_lista(x, &list);
        }

        if(c==3){
            imprimir_lista(list);
        }
        if(c==4){
            system("cls");
        }
        if(c==5){
            printf("Introduzca el numero:");
            scanf("%d", &num);
            intToString(num, string);
            puts(string);
        }
        if(c==6){
            matrizAVector(matriz, vector);
            imprimir_array(vector);
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

void introducir_lista(int valor, struct Lista *lista){
    struct Nodo *nuevo;
    nuevo= malloc (sizeof(struct Nodo));
    nuevo->dato= valor;
    nuevo->siguiente= lista->cabecera;
    lista->cabecera = nuevo;

};

void imprimir_lista(struct Lista lista){
    struct Nodo *aux;
    aux=lista.cabecera;
    printf ("contenido de la lista: ");
    while (aux != NULL) {
        printf("%d -> ", aux->dato);
        aux=aux->siguiente;
    }
    printf ("NULL\n");
};

void intToString(int n, char *s){
    int i=0, power=1, copy;

    if(n<0){
        n=-n;
        s[i++]='-';
    }

    copy=n;

    while(copy>10){
        power *= 10;
        copy/=10;
    }
    for(;n>0;i++){
        s[i]='0'+n/power;
        n=n%power;
        power/=10;
    }

    s[i]='\0';

}

void matrizAVector(int A[][N], int v[]){
    int cont=0;
    int i,j;

    for(i=0;i<=N;i++){
        for(j=N;j>i;j--){
            v[cont++]=A[j][i];
        }
        for(;j<=N;j++){
            v[cont++]=A[i][j];
        }
    }
}

void imprimir_array(int vector[20]){
    int i;

    for(i=0; i<16; i++){
        printf("%d  ", vector[i]);
    }
}
