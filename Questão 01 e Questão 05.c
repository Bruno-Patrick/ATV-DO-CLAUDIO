#include <stdio.h>
#include<stdlib.h> // malloc, free

typedef struct lista{
    int chave;
    // próximo elemento da lista
    struct lista *prox;
    struct lista *ant;
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

void imprime(Lista *l){
    Lista* aux = l;
    printf("\n");
    if (!aux)
        printf("Lista vazia\n");
    while (aux!=NULL){
        printf(" %d -> ", aux->chave);
        aux = aux->prox;
    }
    printf("NULL");
}

Lista *lst_inverte(Lista *l){
    Lista *aux, *ant;
    if (l){ //if (l != null)
        ant = l;
        aux = l->prox;
        ant->prox = NULL;
    }
    while (aux){
        l = aux;
        aux = aux->prox;
        l->prox = ant;
        ant = l;
    }
    return l;
}

int menu(){
	int opcao;
	do{
		printf("\n1 – Inserir");
		printf("\n2 – Excuir");
		printf("\n3 – Consultar");
		printf("\n4 – Imprimir");
		printf("\n5 – Sair\nEscolha sua opcao:");
		scanf("%d", &opcao);
	} while( opcao <1 || opcao>5);
	return opcao;
}
void consulta(Lista *l, int valor){
    Lista *aux;
    for (aux=l;aux!=NULL;aux = aux->prox){
        if (aux->chave == valor){
            return aux;
        }
        else{
            printf("O elemento informado não está na lista!");
        }
    }
}

int main()
{
    Lista *inicio = lst_cria();
        int escolha = menu();
        int valor;
        int key = 1;
        while (key != 0){
            switch(escolha){
            case 1:
            //inserir
                printf("Qual valor você quer inserir na lista? ");
                scanf("%d", &valor);
                inicio = lst_insere(inicio, valor);
                imprime(inicio);
                break;
            case 2:
                //excluir
                printf("Qual valor você quer excluir na lista? ");
                scanf("%d", valor);
                inicio = lst_exclui(inicio, valor);
                imprime(inicio);
                break;
            case 3:
                //consultar
                printf("Qual valor você quer consultar na lista? ");
                scanf("%d", valor);
                consulta(inicio, valor);
                imprime(inicio);
                break;
            case 4:
                imprime(inicio);
                // imprimir
                break;
            case 5:
                // sair
                key = 0;
                break;
            default:
			// do anything
                break;
	};
            if (key != 0){
                escolha = menu();
            };
        };

    imprime(inicio);
    return 0;
}
