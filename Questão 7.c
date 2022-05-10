#include <stdio.h>
#include<stdlib.h> // malloc, free

typedef struct lista{
    int chave;
    // próximo elemento da lista
    struct lista *prox;
} Lista;

Lista *lst_cria(){
    return (Lista*)NULL;
}


Lista *lst_insere(Lista *l, int valor){
    //AQUI ESTÁ INSERINDO NO INÍCIO
    Lista *aux, *novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL){
        printf("\nFALHA DE ALOCAÇÃO DE MEMÓRIA");
        exit(1); // término com falha
    }
    novo->chave = valor;
    novo->prox = NULL;
    if (l == NULL)
        l = novo;
    else{
        aux = l;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return l; // lista atualizada
}

Lista *lst_insere_ordenado(Lista *l, int valor){
    Lista *aux = l,*ant, *novo = (Lista*)malloc(sizeof(Lista));
    aux = l;
    ant = NULL;
    if (novo == NULL){
        printf("\nFALHA DE ALOCAÇÃO DE MEMÓRIA");
        exit(1); // término com falha
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

lst_concatenar(Lista* l1, Lista* l2){
    Lista *aux1, *aux2, *novo = (Lista*) malloc(sizeof(Lista));
free(aux1);
    if (aux1 || aux2 || novo){
        printf("\nFALHA DE ALOCAÇÃO DE MEMÓRIA");
        exit(1); // término com falha
    }

    aux1 = l1;
    aux2 = l2;

    while(aux1->prox && aux2->prox){
        novo = aux1->chave;
        novo->prox = aux2->chave;
        aux1 = aux1->prox;
        aux2 = aux2->prox;
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
    Lista *inicio3 = lst_cria();
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
    		    inicio3 = lst_concatenar(inicio, inicio2);
    		    imprime(inicio3);
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
