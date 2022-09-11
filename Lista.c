#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>

#define MAX 50

//typedef int TIPOCHAVE;

typedef struct{
	int chave;
	float salario;
}REGISTRO;

typedef struct{
	REGISTRO A[MAX];
	int nroElem;
}LISTA;

void inicializarLista(LISTA* l);
int tamanho(LISTA* l);
void exibirLista(LISTA* l);
int buscaSequencial(LISTA* l, int);
bool inserirElemLista(LISTA* l, REGISTRO reg, int);
bool excluirElemLista(int, LISTA* l);
void reinicializarLista(LISTA* l);
bool inserirElemInicio(LISTA* l, REGISTRO reg);
bool inserirElemFim(LISTA* l, REGISTRO);

void main(){
	setlocale(LC_ALL, "Portuguese");
	LISTA l;
	REGISTRO reg;
	int op;
	printf("\t\t\tBem-vindo!\n");
	printf("-----------------------------------------------------------");
	
	do{
	
		printf("\n\n\nEscolha uma das opções abaixo:\n");
		printf("\n1- Inicializar lista");
		printf("\n2- Tamanho da lista");
		printf("\n3- Exibir lista");
		printf("\n4- Busca sequencial");
		printf("\n5- Inserir elemento da lista");
		printf("\n6- Excluir elemento da lista");
		printf("\n7- Reinicializar lista");
		printf("\n8- Inserir elemento no início da lista");
		printf("\n9- Inserir elemento no fim da lista");
		printf("\n0- Sair da aplicação\n");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				system("cls");
				printf("\n\nLista inicializada!");
				inicializarLista(&l);
			break;
			case 2:
				system("cls");
				printf("\n\nTamanho da lista: %i", tamanho(&l));
			break;
			case 3:
				system("cls");
				printf("\n\nExibindo a lista...\n\n");
				exibirLista(&l);
			break;
			case 4:
				
				system("cls");
				printf("\n\nBusca sequencial...\n\n");
				
				printf("Informe o valor da chave: ");
				scanf("%i", &reg.chave);
				
				int posicao = buscaSequencial(&l, reg.chave);
				printf("Chave encontrada na posição %i", posicao);
				
			break;
			case 5:
				
				system("cls");
				printf("\n\nInserir elemento na lista...\n\n");
				int i;
				
				printf("Informe a posição: ");
				scanf("%i", &i);
				
				printf("Informe a chave: ");
				scanf("%i", &reg.chave);
				
				printf("Informe o salário: ");
				scanf("%f", &reg.salario);
				
				inserirElemLista(&l,reg,i);
			break;
			case 6:
				
				system("cls");
				printf("\n\nExcluir elemento da lista...\n\n");
				
				printf("Informe a chave: ");
				scanf("%i", &reg.chave);
				
				excluirElemLista(reg.chave,&l);
			break;
			case 7:
				system("cls");
				printf("\n\nReinicializar lista...\n\n");
				reinicializarLista(&l);
			break;
			case 8:
				system("cls");
				printf("\n\nInserir elemento no início da lista...\n\n");
				
				printf("Informe a chave: ");
				scanf("%i", &reg.chave);
		
				printf("Informe o salário: ");
				scanf("%f", &reg.salario);
				
				inserirElemInicio(&l, reg);
			break;
			case 9:
				system("cls");
				printf("\n\nInserir elemento no fim da lista...\n\n");
				
				printf("Informe a chave: ");
				scanf("%i", &reg.chave);
			
				printf("Informe o salário: ");
				scanf("%f", &reg.salario);
			
				inserirElemFim(&l, reg);
			break;
			case 0:
				printf("\n\nAplicação finalizada");
			break;
			default:
				printf("\n\nOpção inválida!");
		}
	}while(op!=0);
}

void inicializarLista(LISTA* l){
	l->nroElem = 0;
}
int tamanho(LISTA* l){
	return l->nroElem;
}
void exibirLista(LISTA* l){
	int i;
	printf("Lista:\n");
	printf("%i elemento(s)\n\n", l->nroElem);
	for (i=0; i < l->nroElem; i++)
		printf("Chave: %i\n", l->A[i].chave);
	printf("\n");
}
int buscaSequencial(LISTA* l, int ch){
	int i = 0;
	while (i < l->nroElem){
		if(ch == l->A[i].chave) return i;
		else i++;
	}
	return -1;
}
bool inserirElemLista(LISTA* l, REGISTRO reg, int i){
	int j;
	if ((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
		return false;
	for (j = l->nroElem; j > i; j--) l->A[j] = l->A[j-1];
	l->A[i] = reg;
	l->nroElem++;
	return true;

}
bool excluirElemLista(int ch, LISTA* l){
	int pos, j;
	pos = buscaSequencial(l,ch);
	if(pos == -1) return false;
	for(j = pos; j < l->nroElem-1; j++)
		l->A[j] = l->A[j+1];
	l->nroElem--;
	return true;
}
void reinicializarLista(LISTA* l){
	l->nroElem = 0;
}
bool inserirElemInicio(LISTA* l, REGISTRO reg){
	return inserirElemLista(l, reg, 0);
}
bool inserirElemFim(LISTA* l, REGISTRO reg){
	return inserirElemLista(l, reg, l->nroElem);
}
