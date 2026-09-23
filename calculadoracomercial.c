/*
O que está faltando?

1. Preco do frete, preco total, data e hora da compra;
2. previsão de entrega, modularizacao;
3. preco de frete e compra eh so botar uma adicao no laco "do" e mostrar no fim; e
4. nao sei como se adiciona dias a uma data, a modularizacao acho que eh so botar cada um desses blocos numa funcao.

*/

#include <stdio.h>

int n; //numero de produtos no carrinho
int i; //indice para mostrar os produtos sem alterar o numero do carrinho
int codigo[100]; //vetor dos codigos dos produtos
char nome[100][50]; //vetor dos nomes dos produtos
int regiao[100]; //vetor da regiao de entrega dos produtos
float peso[100]; //vetor do peso dos produtos
float preco[100]; //vetor do preco dos produtos
int pagamento; //confirmacao de ir para o pagamento
int finaliza; //confirmacao de finalizar a compra

int main(){
	
	//laco "do" que permite ate 100 produtos em uma compra
	do{
		printf("Qual o codigo do produto desejado? ");
		scanf("%d", &codigo[n]);
		printf("Qual o nome do produto? ");
		scanf("%s", &nome[n]);
		printf("Qual o preco do produto? ");
		scanf("%f", &preco[n]);
		printf("Qual o peso do produto? ");
		scanf("%f", &peso[n]);
		printf("Qual a regiao do frete?\n");
		printf("1.Sudeste\n");
		printf("2.Sul\n");
		printf("3.Nordeste\n");
		printf("4.Norte\n");
		scanf("%d", &regiao[n]);
		printf("\n1.Ir para pagamento\n");
		printf("0.Continuar comprando\n");
		n++;
		scanf("%d",&pagamento);
		printf("\n");
	} while (pagamento != 1);
	
	//imprime o resumo da compra
	for(i = 0; i < n; ++i){
			printf("Codigo: %d", codigo[i]);
			printf("\nProduto: %s", nome[i]);
			printf("\nPeso: %.2f", peso[i]);
			printf("\nPreco: %.2f", preco[i]);
			if(regiao[i]==1){
				printf("\nRegiao: Sudeste");
			}
			else if(regiao[i]==2){
				printf("\nRegiao: Sul");
			}
			else if(regiao[i]==3){
				printf("\nRegiao: Nordeste");
			}
			else if(regiao[i]==4){
				printf("\nRegiao: Norte");
			}
			printf("\n\n");
			
	}
	
	//confirma a compra, dando data dela e da entrega, ou retorna para o carrinho
	printf("Deseja finalizar a compra?\n");
	printf("1.Finalizar\n");
	printf("0.Continuar comprando\n");
	scanf("%d", &finaliza);
	if (finaliza==1){
		printf("\nData da compra: ");
		printf("\nPrevisao de entrega: ");
	}
	else{
		printf("\n");
		return main();
	}
	
	return 0;

}
