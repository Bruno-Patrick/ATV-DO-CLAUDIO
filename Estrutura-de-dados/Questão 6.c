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

Lista *lst_nos(Lista *l){

    int tamanho = 0;
    Lista *aux = (Lista*) malloc(sizeof(Lista));
    aux = l;

    if(aux){
        while(aux){
            tamanho++;
            aux = aux->prox;
        }
    }
    else
        printf("Erro ao alocar memória");
    return tamanho;
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

int menu(){
	int opcao;
	do{
		printf("\n1 – Inserir");
		printf("\n2 – Imprimir");
		printf("\n3 – Quantidade de nós");
        printf("\n4 – Sair\nEscolha sua opcao:");
		scanf("%d", &opcao);
	} while( opcao <1 || opcao>6);
	return opcao;
}

int main()
{

 Lista *inicio = lst_cria();
        int escolha = menu();
        int tam = 0;
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
                imprime(inicio);
                // imprimir
                break;
            case 3:
                tam = lst_nos(inicio);
                printf("\n A quantidade de nos eh: %d \n", tam);
                break;
            case 4:
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

}
