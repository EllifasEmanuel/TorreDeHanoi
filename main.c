#include "estruturas.h"

int main(){
	int Op, Menu, QuantidadeDiscos, i=0;
	int Tamanho=0;
	
	TipoPilha Pilha1, Pilha2, Pilha3;
	
	ItemPilha disco, aux, aux2;
	
	TipoFila *Fila = CreateMonge();

	CreatePilha(&Pilha1);
	CreatePilha(&Pilha2);
	CreatePilha(&Pilha3);
	
	Pilha1.Tamanho = 0;
	Pilha2.Tamanho = 0;
	Pilha3.Tamanho = 0;
	
	disco.Discos = 0;
	
	PushPilha(&Pilha1, disco);	
	PushPilha(&Pilha2, disco);
	PushPilha(&Pilha3, disco);	
	
	Pilha1.Tamanho ++;
	Pilha2.Tamanho ++;
	Pilha3.Tamanho ++;
	
	QuantidadeDiscos = 7;
	
	i = QuantidadeDiscos;
	 
	while(i > 0){	
		
		disco.Discos=i;
		PushPilha(&Pilha1, disco);
		Pilha1.Tamanho++;
		i--;
	}
	
	do{
		system("color 00");
		printf("---------- MENU MONGE ----------\n");
		printf("1) Inserir monge.\n");
		printf("2) Exibir monges.\n");
		printf("0) Sair.\n");
		fflush(stdin);
		scanf("%d",& Menu);
		system("cls");
		
		switch(Menu){
			case 1:
				system("cls");
				EnqueueMonge(Fila,Tamanho);
				Tamanho++;
				system("cls");
				break;
			
			case 2:
				DisplayMonge(Fila);
				system("cls");
				break;
		}
	}while(Menu != 0);
	
	if(Tamanho > 0){
		do{
			DisplayPilha(Pilha1, Pilha2, Pilha3);		
			
			printf("\nMONGE : %s\n",Fila->primeiro->DadosMonge.Nome);
			printf("Quantidade de jogadas: %d\n",Fila->primeiro->DadosMonge.Jogadas);
			printf("---------- MENU JOGO ----------");
			printf("\n\nPilha de Origem > Pilha de Destino\n\n");
			printf("1) 1 > 2\n");
			printf("2) 1 > 3\n");
			printf("3) 2 > 1\n");
			printf("4) 2 > 3\n");
			printf("5) 3 > 1\n");
			printf("6) 3 > 2\n");
			
			fflush(stdin);
			scanf("%d",& Op);
			system("cls");
			switch(Op){
				
				case 1:		
					aux = Pilha1.topo->DadosTorre;  
					aux2 = Pilha2.topo->DadosTorre;
									
									
									
					if(Pilha1.Tamanho == 1){
						printf("Esta pilha esta vazia\n");
						break;
					}
					if(aux.Discos > aux2.Discos && Pilha2.Tamanho > 1){
						printf("\nJogada invalida pois o disco abaixo e menor ou a pilha esta vazia\n");
						system("pause");
						break;
					}
					
					PopPilha(&Pilha1);				
					PushPilha(&Pilha2, aux);
					Pilha2.Tamanho++;	
					Fila->primeiro->DadosMonge.Jogadas++;
					
					if(Pilha2.Tamanho == QuantidadeDiscos + 1){
						system("cls");					
						DisplayPilha(Pilha1, Pilha2, Pilha3);	
						system("color 04");
						printf("\nPO monge %s conseguiu terminar a torre.",Fila->primeiro->DadosMonge.Nome);
						printf("\nNumero de Jogadas: %d\n",Fila->primeiro->DadosMonge.Jogadas);
						Tamanho--;
						DequeueMonge(Fila);
						system("pause");
						
						//Resetando e criando uma nova pilha
						system("color 00");
						CreatePilha(&Pilha1);
						CreatePilha(&Pilha2);
						CreatePilha(&Pilha3);
						
						Pilha1.Tamanho = 0;
						Pilha2.Tamanho = 0;
						Pilha3.Tamanho = 0;
						
						disco.Discos = 0;
						
						PushPilha(&Pilha1, disco);	
						PushPilha(&Pilha2, disco);
						PushPilha(&Pilha3, disco);	
						
						Pilha1.Tamanho ++;
						Pilha2.Tamanho ++;
						Pilha3.Tamanho ++;
						
						QuantidadeDiscos = 7;
						
						i = QuantidadeDiscos;
						 
						while(i > 0){	
							
							disco.Discos=i;
							PushPilha(&Pilha1, disco);
							Pilha1.Tamanho++;
							i--;
						}
					}
					system("cls");			
					break;	
								
				case 2:
					aux = Pilha1.topo->DadosTorre;
					aux2 = Pilha3.topo->DadosTorre;
					
					
					if(Pilha1.Tamanho == 1){
						printf("Esta pilha esta vazia\n");
						break;
					}				
					
					
					if(aux.Discos > aux2.Discos && Pilha3.Tamanho > 1 ){   
						printf("\njogada invalida pois o disco abaixo e menor\n");
						system("pause");
						break;
					}
					
					PopPilha(&Pilha1);	
					PushPilha(&Pilha3, aux);
					Pilha3.Tamanho++;
					Fila->primeiro->DadosMonge.Jogadas++;	
					if(Pilha3.Tamanho == QuantidadeDiscos + 1){
						system("cls");					
						DisplayPilha(Pilha1, Pilha2, Pilha3);
						system("color 04");	
						printf("\nO monge %s conseguiu terminar a torre.",Fila->primeiro->DadosMonge.Nome);
						printf("\nNumero de Jogadas: %d\n",Fila->primeiro->DadosMonge.Jogadas);
						Tamanho--;
						DequeueMonge(Fila);
						system("pause");
						
						//Resetando e criando uma nova pilha
						system("color 00");
						CreatePilha(&Pilha1);
						CreatePilha(&Pilha2);
						CreatePilha(&Pilha3);
						
						Pilha1.Tamanho = 0;
						Pilha2.Tamanho = 0;
						Pilha3.Tamanho = 0;
						
						disco.Discos = 0;
						
						PushPilha(&Pilha1, disco);	
						PushPilha(&Pilha2, disco);
						PushPilha(&Pilha3, disco);
											
						Pilha1.Tamanho ++;
						Pilha2.Tamanho ++;
						Pilha3.Tamanho ++;
						
						QuantidadeDiscos = 7;
						
						i = QuantidadeDiscos;
						 
						while(i > 0){	
							
							disco.Discos=i;
							PushPilha(&Pilha1, disco);
							Pilha1.Tamanho++;
							i--;
						}
						break;
					}
					
					system("cls");
					break;
					
					
				case 3:		
					aux = Pilha2.topo->DadosTorre;
					aux2 = Pilha1.topo->DadosTorre;	
					
					
					if(Pilha2.Tamanho == 1){
						printf("Esta pilha esta vazia\n");
						system("pause");
						break;
					}
								
								
					if(aux.Discos > aux2.Discos && Pilha1.Tamanho > 1){ 
						printf("\njogada invalida pois o disco abaixo e menor\n");
						system("pause");
						break;
					}
					
					PopPilha(&Pilha2);
					PushPilha(&Pilha1, aux);
					Pilha1.Tamanho++;	
					Fila->primeiro->DadosMonge.Jogadas++;
					system("cls");			
					break;		
						
				case 4:
					aux = Pilha2.topo->DadosTorre;
					aux2 = Pilha3.topo->DadosTorre;	
					
					
					if(Pilha2.Tamanho == 1){
						printf("Esta pilha esta vazia\n");
						system("pause");
						break;
					}			
					
					if(aux.Discos > aux2.Discos && Pilha3.Tamanho > 1 ){ 
						printf("\nJogada invalida pois o disco abaixo e menor\n");
						system("pause");
						break;
					}
					
					PopPilha(&Pilha2);
					PushPilha(&Pilha3, aux);
					Pilha3.Tamanho++;	
					Fila->primeiro->DadosMonge.Jogadas++;
					
					if(Pilha3.Tamanho == QuantidadeDiscos + 1){
						system("cls");
						system("color 04");					
						DisplayPilha(Pilha1, Pilha2, Pilha3);	
						printf("\nO monge %s conseguiu terminar a torre.",Fila->primeiro->DadosMonge.Nome);
						printf("\nNumero de Jogadas: %d\n",Fila->primeiro->DadosMonge.Jogadas);
						Tamanho--;
						DequeueMonge(Fila);
						system("pause");
						
						//Resetando e criando uma nova pilha
						system("color 00");
						CreatePilha(&Pilha1);
						CreatePilha(&Pilha2);
						CreatePilha(&Pilha3);
						
						Pilha1.Tamanho = 0;
						Pilha2.Tamanho = 0;
						Pilha3.Tamanho = 0;
						
						disco.Discos = 0;
						
						PushPilha(&Pilha1, disco);	
						PushPilha(&Pilha2, disco);
						PushPilha(&Pilha3, disco);	
						
						Pilha1.Tamanho ++;
						Pilha2.Tamanho ++;
						Pilha3.Tamanho ++;
						
						QuantidadeDiscos = 7;
						
						i = QuantidadeDiscos;
						 
						while(i > 0){	
							
							disco.Discos=i;
							PushPilha(&Pilha1, disco);
							Pilha1.Tamanho++;
							i--;
						}
						break;
					}
					
					system("cls");			
					break;	
					
				case 5:
					aux = Pilha3.topo->DadosTorre;
					aux2 = Pilha1.topo->DadosTorre;
					
					
					if(Pilha3.Tamanho == 1){
						printf("Esta pilha esta vazia\n");
						system("pause");
						break;
					}				
					
					if(aux.Discos > aux2.Discos && Pilha1.Tamanho > 1){
						printf("\nJogada invalida pois o disco abaixo e menor\n");
						system("pause");
						break;
					}
					
					PopPilha(&Pilha3);
					PushPilha(&Pilha1, aux);
					Pilha1.Tamanho++;	
					Fila->primeiro->DadosMonge.Jogadas++;
					system("cls");			
					break;	
					
					
					
				case 6:
					aux = Pilha3.topo->DadosTorre;
					aux2 = Pilha2.topo->DadosTorre;
					
					if(Pilha3.Tamanho == 1){
						printf("Esta pilha esta vazia\n");
						system("pause");
						break;
					}	
								
					if(aux.Discos > aux2.Discos && Pilha2.Tamanho > 1){ 
						printf("\nJogada invalida pois o disco abaixo e menor\n");
						system("pause");
						break;
					}
					
					PopPilha(&Pilha3);
					PushPilha(&Pilha2, aux);
					Pilha2.Tamanho++;
					Fila->primeiro->DadosMonge.Jogadas++;	
					
					if(Pilha2.Tamanho == QuantidadeDiscos + 1){
						system("cls");				
						system("color 04");	
						DisplayPilha(Pilha1, Pilha2, Pilha3);	
						printf("\nO monge %s conseguiu terminar a torre.",Fila->primeiro->DadosMonge.Nome);
						printf("\nNumero de Jogadas: %d\n",Fila->primeiro->DadosMonge.Jogadas);
						Tamanho--;
						DequeueMonge(Fila);
						system("pause");
						
						//Resetando e criando uma nova pilha
						system("color 00");
						CreatePilha(&Pilha1);
						CreatePilha(&Pilha2);
						CreatePilha(&Pilha3);
						
						Pilha1.Tamanho = 0;
						Pilha2.Tamanho = 0;
						Pilha3.Tamanho = 0;
						
						disco.Discos = 0;
						
						PushPilha(&Pilha1, disco);	
						PushPilha(&Pilha2, disco);
						PushPilha(&Pilha3, disco);	
						
						Pilha1.Tamanho ++;
						Pilha2.Tamanho ++;
						Pilha3.Tamanho ++;
						
						QuantidadeDiscos = 7;
						
						i = QuantidadeDiscos;
						 
						while(i > 0){	
							
							disco.Discos=i;
							PushPilha(&Pilha1, disco);
							Pilha1.Tamanho++;
							i--;
						}
						system("cls");
						break;
					}
					break;
			}
		}while(Tamanho != 0);
	}
	
	else{
		printf("\nJogo finalizado T_T!");
	}
	printf("\nJogo finalizado T_T!");
	
}
