#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//Pilha
typedef struct Itens{
	int Discos;
}ItemPilha;

typedef struct Elementos{
	ItemPilha DadosTorre;
	struct Elementos *proximo;
	struct Elementos *anterior;
}ElementosPilha;

typedef struct pilha{
	ElementosPilha *topo;
	ElementosPilha *base;
	int Tamanho;
}TipoPilha;

//Fila
typedef struct monge{
	char Nome[50];
	int Jogadas;
}ItensMonge;

typedef struct elementosfila{
	ItensMonge DadosMonge;
	struct elementosfila *proximo;
}ElementosFila;

typedef struct fila{
	ElementosFila *primeiro;
	ElementosFila *ultimo;
	int Tamanho;
}TipoFila;


//Cabeçalho da fila para os monges
TipoFila* CreateMonge();//Criar a fila

void EnqueueMonge(TipoFila* Fila, int Quantidade);//Enfileirar a fila

void DisplayMonge(TipoFila* Fila);// Exibir a fila

void DequeueMonge(TipoFila* Fila);// Desenfirelar a fila

//Cabeçalho da pilha para a torre
TipoPilha* CreatePilha();//Criar a pilha

void PushPilha(TipoPilha *Pilha, ItemPilha X);//Inserir no topo da pilha

void PopPilha(TipoPilha *Pilha);//Remover do topo da pilha

void DisplayPilha(TipoPilha Pilha1, TipoPilha Pilha2, TipoPilha Pilha3);//Exibir pilha
