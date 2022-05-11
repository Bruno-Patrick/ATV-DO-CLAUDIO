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

Lista *lst_exclui(Lista *l,int valor){
    Lista *aux,*ant;
    ant = aux = l;
    while (aux!=NULL && aux->chave != valor){
        ant = aux;
        aux = aux->prox;
    }
    if (aux){ // if (aux != NULL)
        if (aux == l) // testa se é o primeiro nó
           l = aux->prox;
        else
            ant->prox = aux->prox;
        free(aux); // exclui aux  da memória
    }else{
        printf("\nChave %d não encontrada!!\n", valor);
    }
    return l;
}

Lista *lst_insere(Lista *l, int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL){
        printf("\nFALHA DE ALOCAÇÃO DE MEMÓRIA");
        exit(1); // término com falha
    }
    novo->chave = valor;
    if(l == NULL){
        l = novo;
        l->prox =  l;
    }
    //novo->prox = NULL;
    else{
        novo->prox = l->prox;
        l->prox = novo;
        l = novo;
    }
    return l;
     // lista atualizada
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

void consulta(Lista *l, int valor){
    Lista *aux = l;
    while (aux && aux->chave != valor)
        aux = aux->prox;
    if (aux!= NULL)
        printf("O Valor %d está na lista", valor);
    else
        printf("O valor %d nao está na lista", valor);
}

int menu(){
	int opcao;
	do{
		printf("\n1 - Inserir");
		printf("\n2 - Excuir");
		printf("\n3 - Consultar");
		printf("\n4 - Imprimir");
		printf("\n5 - Sair\nEscolha sua opcao:");
		scanf("%d", &opcao);
	} while( opcao <1 || opcao>5);
	return opcao;
}

int main(){
    Lista *inicio = lst_cria();
    int op = 0, valor;
    do{
        op=menu();
        switch(op){
    		case 1:
    		    printf("\nValor a ser inserido =");
    		    scanf("%d",&valor);
    			inicio = lst_insere(inicio,valor);
                break;
    		case 2:
                printf("\nValor a ser excluído =");
    		    scanf("%d",&valor);
    			inicio = lst_exclui(inicio,valor);
    			break;
    		case 3:
                printf("\nValor a ser procurado =");
    		    scanf("%d",&valor);
    		    consulta(inicio, valor);
    			break;
    		case 4: // imprimir
    			imprime(inicio);
    			break;
    		case 5:
    		    break;
    		default:
    			// do anything
    			break;
    	};
    }while ( op!= 5);
        free(inicio);
    return 0;
}
