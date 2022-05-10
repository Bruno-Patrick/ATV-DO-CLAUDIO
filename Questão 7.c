#include <stdio.h>
#include<stdlib.h> // malloc, free

typedef struct lista{
    int chave;
    // pr�ximo elemento da lista
    struct lista *prox;
} Lista;

Lista *lst_cria(){
    return (Lista*)NULL;
}


Lista *lst_insere(Lista *l, int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL){
        printf("\nFALHA DE ALOCA��O DE MEM�RIA");
        exit(1); // t�rmino com falha
    }
    novo->chave = valor;
    novo->prox = l;
    l = novo;
    return l; // lista atualizada
}

Lista *lst_insere_ordenado(Lista *l, int valor){
    Lista *aux = l,*ant, *novo = (Lista*)malloc(sizeof(Lista));
    aux = l;
    ant = NULL;
    if (novo == NULL){
        printf("\nFALHA DE ALOCA��O DE MEM�RIA");
        exit(1); // t�rmino com falha
    }
    novo->chave = valor;
    if (aux == NULL){
        novo->prox = NULL;
        l = novo;
    }else{
        while(aux != NULL && aux->chave < valor){
            ant = aux;
            aux = aux->prox;
        }
        novo->prox = aux;
        if(ant == NULL){
            l = novo;
        }else{
            ant->prox = novo;
        }
    }
    return l;
}

void lst_concatenar(Lista* l1, Lista* l2){
    Lista *novo = (Lista*) malloc(sizeof(Lista));

    if (novo == NULL){
        printf("\nFALHA DE ALOCA��O DE MEM�RIA");
        exit(1); // t�rmino com falha
    }

    Lista *aux, *aux1;
    aux = l1;
    aux1 = l2;
    novo->prox = NULL;
    while(aux && aux->prox){
        novo->chave = aux->chave;
        aux = aux->prox;
        novo = novo->prox;
    }
    return novo;
}

void imprime(Lista *l){
    Lista* aux = l;
    printf("\n");
    if (!aux)
        printf("Lista vazia\n");
    while (aux!=NULL){
        printf(" %d -> ", aux->chave);
        aux = aux->prox;
    }
}

int menu(){
	int opcao;
	do{
		printf("\n\n1 - Inserir na lista 1");
		printf("\n2 - Inserir na lista 2");
		printf("\n3 - Concatenar");
		printf("\n4 - Imprimir");
		printf("\n5 - Sair\nEscolha sua opcao:");
		scanf("%d", &opcao);
	} while( opcao <1 || opcao>5);
	return opcao;
}

int main(){
    Lista *inicio = lst_cria();
    Lista *inicio2 = lst_cria();
    int op = 0, valor, valor2;
    do{
        op=menu();
        switch(op){
    		case 1:
    		    printf("\nValor a ser inserido = ");
    		    scanf("%d",&valor);
    			inicio = lst_insere(inicio,valor);
                break;
    		case 2:
                printf("\nValor a ser inserido = ");
    		    scanf("%d",&valor2);
    			inicio2 = lst_insere(inicio2,valor2);
    			break;
    		case 3:
                lst_concatenar(inicio, inicio2);
    		    imprime(inicio);
    			break;
    		case 4: // imprimir
    			imprime(inicio);
    			imprime(inicio2);
    			break;
    		case 5:
    		    break;
    		default:
    			// do anything
    			break;
    	};
    }while ( op <= 4);
        free(inicio);
    return 0;
}
