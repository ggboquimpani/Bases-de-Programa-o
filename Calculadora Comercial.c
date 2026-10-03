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

int inputCompra(){ //recebe dados da compra
	do{
		printf("Qual o codigo do produto desejado? ");
		scanf("%d", &codigo[n]);
		printf("Qual o nome do produto? ");
		scanf(" %[^\n]", &nome[n]);
		printf("Qual o preco do produto? R$ ");
		scanf("%f", &preco[n]);
		printf("Qual o peso do produto? ");
		scanf("%f", &peso[n]);
		printf("Qual a regiao do frete?\n");
		printf("1.Sudeste\n");
		printf("2.Sul\n");
		printf("3.Nordeste\n");
		printf("4.Norte\n");
		scanf("%d", &regiao[n]);
		calculaPreco();
		calculaFrete();
		irParaPagamento();
	} while (pagamento != 1);
}

int irParaPagamento(){ //procede para pagamento ou continua a compra
	printf("\n1.Ir para pagamento\n");
		printf("0.Continuar comprando\n");
		n++;
		scanf("%d",&pagamento);
		printf("\n");
}
int calculaPreco(){ //calcula total do preco dos produtos
	totalProduto = totalProduto + preco[n];
}
int calculaFrete(){ //calcula total do frete
	if(regiao[n]==1){
				if (peso[n] > 2.00){
					frete[n] = 45.00;
				}
				else{
					frete[n] = 25.00;
				}
			}
			else if(regiao[n]==2){
				if (peso[n] > 2.00){
					frete [n] = 50.00;
				}
				else{
					frete[n] = 30.00;
				}
			}
			else if(regiao[n]==3){
				if (peso[n] > 2.00){
					frete [n] = 60.00;
				}
				else{ 
					frete[n] = 40.00;
				}
			}
			else if(regiao[n]==4){
				if (peso [n]> 2.00){
					frete [n] = 55.00;
				}
				else{
					frete[n] = 35.00;
				}
			}
	totalFrete = totalFrete + frete[n];
}

int calculaTotal(){ // calcula total do preco + frete
	totalCompras = totalProduto + totalFrete;
}

int resumoCompra(){ // imprime resumo da compra
	for(i = 0; i < n; ++i){
			printf("Codigo: %d", codigo[i]);
			printf("\nProduto: %s", nome[i]);
			printf("\nPreco: R$ %.2f", preco[i]);
			printf("\nPeso: %.2f kg", peso[i]);
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
			printf("\nFrete: R$ %.2f", frete [i]);
			printf("\n\n");
			
	}

	printf("\nTotal dos produtos: R$ %.2f", totalProduto);
	printf("\nTotal do frete: R$ %.2f", totalFrete);
	printf("\nTotal da compra: R$ %.2f \n", totalCompras);
}

int finalizaCompra(){ //confirma a compra ou volta para o carrinho
	printf("\nDeseja finalizar a compra?\n");
	printf("1.Finalizar\n");
	printf("0.Continuar comprando\n");
	scanf("%d", &finaliza);
	if (finaliza==1){
	dataCompraEntrega();
	}
	else{
		printf("\n");
		return main();
	}
}

int dataCompraEntrega(){ // imprime a data da compra e a previsao de entrega
	time(&agora);
	dataHora=localtime(&agora);
	printf("\nHora e data da compra: %02d:%02d, %02d/%02d/%04d",
		dataHora->tm_hour,
		dataHora->tm_min,
    	dataHora->tm_mday,
    	dataHora->tm_mon + 1,
    	dataHora->tm_year + 1900);
    
	dataHora->tm_mday += 7;
	mktime(dataHora);
	
	printf("\nPrevisao de entrega: %02d/%02d/%04d",
		dataHora->tm_mday,
    	dataHora->tm_mon + 1,
    	dataHora->tm_year + 1900);
}

int main(){
	
	inputCompra();
	calculaTotal();
	resumoCompra();
	finalizaCompra();
	
	return 0;

}
