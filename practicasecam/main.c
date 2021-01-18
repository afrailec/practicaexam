#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

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


int main(){

    srand(time(NULL));

    int matriz[N][N];
    int c, x;
    struct Lista list;

    list.cabecera=NULL;

    do{
        printf("ELIJA UNA OPCION:\n0-SALIR\n1-GENERAR E IMPRIMIR MATRIZ ALEATORIA\n2-INSERTAR ELEMENTO EN UNA LISTA\n3-IMPRIMIR UNA LISTA\n");
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
