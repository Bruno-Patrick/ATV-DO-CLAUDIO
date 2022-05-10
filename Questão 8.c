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

void lst_concatena2(Lista* l1, Lista* l2){
    Lista* aux, *aux1;
    aux = l1;
    while(aux && aux->prox){
        aux = aux->prox;
    }
    aux1 = l2;
    while(aux1 != NULL){
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        novo ->chave = aux1->chave;
        novo->prox = NULL;
        aux1 = aux1->prox;
        aux->prox = novo;
        aux = aux->prox;
    }
}

Lista *lst_insere(Lista *l, int valor){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    if (novo == NULL){
        printf("\nFALHA DE ALOCAÇÃO DE MEMÓRIA");
        exit(1); // término com falha
    }
    novo->chave = valor;
    novo->prox = l;
    l = novo;
    return l; // lista atualizada
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

void lst_consulta(Lista *l, int valor){
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
		printf("\n5 - Concatena2");
		printf("\n6 - Sair\nEscolha sua opcao:");
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
    		    printf("\nValor a ser inserido =");
    		    scanf("%d",&valor);
    			inicio = lst_insere(inicio,valor);
    			printf("\nValor a ser inserido =");
    		    scanf("%d",&valor2);
    			inicio2 = lst_insere(inicio2,valor2);
                break;
    		case 2:
                printf("\nValor a ser excluído =");
    		    scanf("%d",&valor);
    			inicio = lst_exclui(inicio,valor);
    			scanf("%d",&valor2);
    			inicio2 = lst_exclui(inicio2,valor2);
    			break;
    		case 3:
                printf("\nValor a ser procurado =");
                scanf("%d",&valor);
                lst_consulta(inicio, valor);
                scanf("%d",&valor2);
                lst_consulta(inicio2, valor2);
    			break;
    		case 4: // imprimir
    			imprime(inicio);
    			imprime(inicio2);
    			break;
    		case 5:
    		    lst_concatena2(inicio, inicio2);
    		    imprime(inicio);
    		    break;
            case 6:
                break;
    		default:
    			// do anything
    			break;
    	};
    }while ( op!= 5);
        free(inicio);
    return 0;
}
