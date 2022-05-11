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
    novo->prox = l;
    l = novo;
    return l; // lista atualizada
}

Lista *inserePos(Lista *l, int valor, int p){
    Lista *aux1,* aux2,*tam,*novo = (Lista*)malloc(sizeof(Lista));
    int cont =0,conta2 =0;
    aux1 =l;
    tam =l;
    p = p-1;
    if (novo == NULL){
        printf("\nFALHA DE ALOCAÇÃO DE MEMÓRIA");
        exit(1); // término com falha
    }
    novo->chave = valor;
    while(tam != NULL){
        tam = tam->prox;
        conta2++;
    }
    if(p >conta2 || p<0){
        aux2 = l;
        while(aux2->prox)
            aux2 = aux2->prox;
        aux2->prox = novo;
        l = novo;
        return l;
    }
    while(cont <p-1){
        aux1 = aux1->prox;
        cont++;
    }
    aux2 = aux1->prox;
    aux1->prox = novo;
    novo->prox=aux2;
    l = novo;
    return l;
}

void consulta(Lista *l, int valor){
    Lista *aux = l;
    while (aux && aux->chave != valor)
        aux = aux->prox;
    if (aux!= NULL)
        printf("O Valor %d está na lisa", valor);
    else
        printf("O valor %d nao está na lista", valor);
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
		printf("\n1 - Inserir");
		printf("\n2 - Excuir");
		printf("\n3 - Consulta");
		printf("\n4 - Imprimir");
        printf("\n5 - Inserir posicao");
		printf("\n6 - Sair\nEscolha sua opcao:");
		scanf("%d", &opcao);
	} while( opcao <1 || opcao>6);
	return opcao;
}

int main(){
    Lista *inicio = lst_cria();
    int op = 0, valor, p;
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
               printf("\nValor a ser inserido =");
               scanf("%d",&valor);
               printf("\nPosição a ser inserido =");
               scanf("%d",&p);
               inserePos(inicio,valor,p);
                break;
    		case 6:
    		    break;
    		default:
    			// do anything
    			break;
    	};
    }while ( op!= 6);
        free(inicio);
    return 0;
}
