#include <stdio.h>
#include <time.h>

int n; //numero de produtos no carrinho
int i; //indice para mostrar os produtos sem alterar o numero do carrinho
int codigo[100]; //vetor dos codigos dos produtos
char nome[100][50]; //vetor dos nomes dos produtos
int regiao[100]; //vetor da regiao de entrega dos produtos
float peso[100]; //vetor do peso dos produtos
float preco[100]; //vetor do preco dos produtos
int pagamento; //confirmacao de ir para o pagamento
int finaliza; //confirmacao de finalizar a compra
float frete[100];
float totalProduto = 0;
float totalFrete = 0;
float totalCompras = 0;
time_t agora;
struct tm *dataHora; //variavel para data e hora separadas
/*
Faltando: previsao de entrega, modularizacao.

*/

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
				if (peso[i] > 2.00){
					frete[i] = 45.00;
				}
				else{
					frete[i] = 25.00;
				}
			}
			else if(regiao[i]==2){
				printf("\nRegiao: Sul");
				if (peso[i] > 2.00){
					frete [i] = 50.00;
				}
				else{
					frete[i] = 30.00;
				}
			}
			else if(regiao[i]==3){
				printf("\nRegiao: Nordeste");
				if (peso[i] > 2.00){
					frete [i] = 60.00;
				}
				else{ 
					frete[i] = 40.00;
				}
			}
			else if(regiao[i]==4){
				printf("\nRegiao: Norte");
				if (peso [i]> 2.00){
					frete [i] = 55.00;
				}
				else{
					frete[i] = 35.00;
				}
			}
			totalFrete = totalFrete + frete[i]; //calcula valor do frete 
			totalProduto = totalProduto + preco[i];// calcula valor total dos produtos
			printf("\n\n");
			
	}
	
	totalCompras = totalProduto + totalFrete;//Calcula valor total da compra
	
	//mostra o resumo da compra
	printf("\nTotal dos produtos: R$ %.2f", totalProduto);
	printf("\nTotal do frete: R$ %.2f", totalFrete);
	printf("\nTotal da compra: R$ %.2f \n", totalCompras);
	
	//confirma a compra, dando data dela e da entrega, ou retorna para o carrinho
	printf("Deseja finalizar a compra?\n");
	printf("1.Finalizar\n");
	printf("0.Continuar comprando\n");
	scanf("%d", &finaliza);
	time(&agora);
	dataHora=localtime(&agora);
	if (finaliza==1){
	printf("\nData da compra: %02d/%02d/%04d",
       dataHora->tm_mday,
       dataHora->tm_mon + 1,
       dataHora->tm_year + 1900);
	printf("\nPrevisao de entrega: ");
	}
	else{
		printf("\n");
		return main();
	}
	
	return 0;

}
