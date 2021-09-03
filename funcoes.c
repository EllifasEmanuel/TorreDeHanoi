#include "estruturas.h"

//Funções da pilha para as torres
TipoPilha* CreatePilha(){	//CRIAR PILHA
	
	TipoPilha* aux = (TipoPilha*) malloc (sizeof(TipoPilha));
	aux->base = NULL;
	aux->topo = NULL;
}

void PushPilha(TipoPilha *Pilha, ItemPilha Discos){ //INSERIR OS ELEMENTOS NA PILHA
	ElementosPilha *aux, *aux2;
	
	if((aux = malloc(sizeof(ElementosPilha)))==NULL) {
       printf("ERRO.\n");
   }
	
	if(Pilha->Tamanho == 0) {
		Pilha->base = aux;
		Pilha->topo = Pilha->base;
		Pilha->topo->anterior= NULL;
	}

	else{
	
		Pilha->topo->proximo = aux;
		aux2 = Pilha->topo;
		Pilha->topo= aux;
		Pilha->topo->proximo = NULL;
		Pilha->topo->anterior = aux2;
		
	}

	Pilha->topo->DadosTorre = Discos;
	Pilha->topo->proximo = NULL;
	
}

void PopPilha(TipoPilha *Pilha) {
	ElementosPilha *aux,*aux2;
	if(Pilha->Tamanho == 0) {
		printf("\nNao e possivel retirar");
		printf("\nPilha vazia\n\n");
		system("pause");
	}
	if(Pilha->Tamanho == 1) {		
		Pilha->topo= NULL;	
		Pilha->Tamanho--;
		free(aux2);	
	}
	else{
		aux	= Pilha->topo;
		Pilha->topo->anterior->proximo = NULL;
		Pilha->topo = Pilha->topo->anterior;
		Pilha->Tamanho--;
		free(aux);
	}
}

void DisplayPilha(TipoPilha Pilha1, TipoPilha Pilha2, TipoPilha Pilha3) {
	ElementosPilha *aux1,*aux2,*aux3;
	int i=0;
	if(Pilha1.Tamanho == 0 && Pilha2.Tamanho == 0 && Pilha3.Tamanho == 0) {
		printf("\nNao e possivel imprimir");
		printf("\nPilha vazia\n\n");
		system("pause");
		exit(1);
	}
	else{
		aux1 = Pilha1.topo;
		aux2 = Pilha2.topo;
		aux3 = Pilha3.topo;
		
		printf("Torre 1\t\tTorre 2\t\tTorre 3");
		
		while(aux1 != NULL) {
			printf("\n\n->%d<-\t", aux1->DadosTorre.Discos);
			aux1 = aux1->anterior;
		}
	
		while(aux2 != NULL) {
			printf("\n\t\t->%d<-\t\t", aux2->DadosTorre.Discos);
			aux2 = aux2->anterior;
		}
		
		while(aux3 != NULL) {
			printf("\n\t\t\t\t->%d<-\t", aux3->DadosTorre.Discos);
			aux3 = aux3->anterior;
		}
		printf("\n\n");
	}
}

//Funções da fila para os monges
TipoFila* CreateMonge(){
	
	TipoFila* Fila = (TipoFila*) malloc (sizeof(TipoFila));
	
	if(Fila != NULL){
		Fila->ultimo = NULL;
		Fila->primeiro = NULL;
		Fila->Tamanho = 0;
	}
	else{
		printf("Erro!");
	}
	return Fila;
}

void EnqueueMonge(TipoFila* Fila, int Quantidade){
	
	if(Fila == NULL){
		printf("Erro!");
	}
	
	ElementosFila* aux = (ElementosFila*) malloc (sizeof(ElementosFila));
	
	if(aux == NULL){
		printf("Erro!\n");
	}
	
	Quantidade = Fila->Tamanho;
	printf("Quantidade de monges = #%d\n",Quantidade);
	printf("\nDigite o nome do monge: ");
	fflush(stdin);
	gets(aux->DadosMonge.Nome);
	
	aux->proximo = NULL;
	
	if(Fila->ultimo == NULL){
		Fila->Tamanho = 1;
		Fila->primeiro = aux;
	}
	else{
		Fila->ultimo->proximo = aux;
		Fila->Tamanho++;
	}
	
	Fila->ultimo = aux;
}

void DisplayMonge(TipoFila* Fila){
	ElementosFila *aux = Fila->primeiro;
	
	if(aux == NULL){
		printf("Fila vazia!\n");
	}
	else{
		printf("-------------------------------------------\n");
	}
	
	while(aux != NULL){
		printf("Nome do monge: %s\n",aux->DadosMonge.Nome);
		printf("-------------------------------------------\n");
		aux = aux->proximo;
	}
	system("pause");
}

void DequeueMonge(TipoFila* Fila){ 
	
	if(Fila == NULL){
		printf("Erro!\n");
	}
	
	if(Fila->primeiro == NULL){
		printf("\nFila vazia!\n");	
	}
	
	ElementosFila *aux = Fila->primeiro;
	Fila->primeiro = Fila->primeiro->proximo;
	
	printf("\nMonge que sera removido:\n");
	printf("Nome = %s\n",aux->DadosMonge.Nome);
	printf("Quantidade de jogadas = %d\n",aux->DadosMonge.Jogadas);
	
	if(Fila->primeiro == NULL){
		printf("\nSem monges na fila!\n\n");
		Fila->ultimo = NULL;
	}
	free(aux);
}
