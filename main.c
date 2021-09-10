#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int dado;
    struct no* prox;
    struct no* anterior;
}No;

typedef struct lista{
    int tam;
    No* comeco;
    No* fim;
}Lista;


Lista* iniciarList();
void add(Lista* list, int dado);
void printLista(Lista* list);
void deletprim(Lista* list);
No* indice(Lista* list,int ind);
int posicao(Lista* lista, int m);

Lista* iniciarList(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista -> tam = 0;
    lista -> comeco = NULL;
    lista -> fim = NULL;
    return lista;
}

void add(Lista* list, int dado){
    No* no = (No*)malloc(sizeof(No));
    no -> dado = dado;
    if(list->tam == 0){
        list->comeco = no;
        list->fim = no;
        list->tam++;
        no->anterior = NULL;
        no->prox = NULL;
    }else if(list->tam == 1){
		list->comeco->prox = no;
		list->comeco->anterior = no;
		list->fim = no;
		no->anterior = list->comeco;
		no->prox = list->comeco;
		list->tam++;
	}else{
		list->comeco->anterior= no;
		no->prox = list->comeco;
		no->anterior = list->fim;
		list->fim->prox = no;
		list->fim = no;
		list->tam++;
	}
}

void printLista(Lista* list){
    No* ponteiro = list -> comeco;
    printf("valor: %d\n", ponteiro -> dado);
    ponteiro = ponteiro->prox;
    while (ponteiro != list->comeco){
        printf("valor: %d\n", ponteiro -> dado);
        ponteiro = ponteiro -> prox;
    }   
}

int posicao(Lista* lista,int m){
    if(lista->tam == 1){
        return lista->comeco->dado;
    }else if(lista->tam == 0){
        return -1;
    }else if(lista->tam > 1){
        No* ponteiro = lista->comeco;
        No* aux = NULL;
        int tamanho = lista->tam;
        for(int ii=1;ii < tamanho;ii++){
            for(int i = 1; i < m;i++){
                ponteiro = ponteiro->prox;
            }
            ponteiro->anterior->prox = ponteiro->prox;
            ponteiro->prox->anterior = ponteiro->anterior;
            ponteiro = ponteiro->prox;
            lista->tam--;
        }
        return ponteiro->dado;
    }
}

int main(){
    Lista* lista = iniciarList();
    int quan,n,m,dado,i,numero;
    scanf("%d",&quan);
    for(i = 0; i<quan;i++){
        scanf("%d %d",&n,&m);
        for(int x=1;x<=n;x++){
            add(lista,x);
        }
        numero = posicao(lista,m);
        printf("Resultado: %d\n",numero);
        free(lista);
        Lista* lista = iniciarList();
    }
    return 0;
}