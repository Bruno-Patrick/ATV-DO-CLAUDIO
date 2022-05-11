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

Lista *lst_concatena(Lista* l1, Lista* l2){
    Lista *novo, *aux1, *aux2, *aux3, *l3 = (Lista*)malloc(sizeof(Lista));

    if (novo == NULL){
        printf("\nFALHA DE ALOCAÇÃO DE MEMÓRIA");
        exit(1); // término com falha
    }
    aux1 = l1;
    aux2 = l2;
    aux3 = NULL;
    if (!aux3){
        if (aux1->chave <= aux2->chave)
        {
            aux3 = aux1;
            aux1 = aux1->prox;
        }
        else{
            aux3 = aux2;
            aux2 = aux2->prox;
        }
        l3 = aux3;
    }
    while (aux1 != NULL && aux2 != NULL){
        if (aux1 -> chave <= aux2 -> chave){
            aux3->prox = aux1;
            aux1 = aux1->prox;
            aux3 = aux3->prox;

        }
        else{
            aux3->prox = aux2;
            aux2 = aux2->prox;
            aux3 = aux3->prox;
        }
    }
    if (aux1 == NULL){
        while (aux2 != NULL){
            aux3->prox = aux2;
            aux2 = aux2->prox;
            aux3 = aux3->prox;
        }
    }
    else{
        while (aux1 != NULL){
            aux3->prox = aux1;
            aux1 = aux1->prox;
            aux3 = aux3->prox;
        }
    }
    return l3;
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
		printf("\n5 - Concatena");
		printf("\n6 - Sair\nEscolha sua opcao:");
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
    			imprime(inicio3);
    			break;
    		case 5:
    		    inicio3 = lst_concatena(inicio, inicio2);
    		    imprime(inicio3);
    		    break;
            case 6:
                exit(1);
                break;
    		default:
    			// do anything
    			break;
    	};
    }while ( op!= 6);
        free(inicio);
    return 0;
}
