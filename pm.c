#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*                   PROGRAMA PARA O CALCULO DO PRECO MEDIO 
 *  -----------------------------------------------------------------------------------
 *  Este código em C e um sistema simples para calcular o preço médio de ações, 
 *  tanto para novas aquisições quanto para ações já presentes na carteira do usuário. 
 *  -----------------------------------------------------------------------------------
 *  author: Felipe Alexandre
 *  versao 0.1
 *  
 */



#define SIZE 50

/*PROTOTIPOS*/

/*WINDOWS*/
void cleanBuffer(void);

/*CALCULA O PRECO MEDIO DE NOVAS ACOES */
float preco_medio(int quantidade , float compra[]);

/*CALCULA O PRECO MEDIO DE ACOES EM CARTEIRA E NOVAS AQUISICOES*/
float preco_medio_em_carteira(int quantidade , float compra[], int quantidadeAtual , float custoTotalAtual);


/*OBTEM INFORMACOES DE NOVAS ACOES PARA O CALCULO DO PRECO MEDIO*/
void novas_acoes();

/*OBTEM INFORMACOES DE ACOES EM CARTEIRA PARA O CALCULO DO PRECO MEDIO*/
void acoes_em_carteira();

/*EXIBE O MENU*/
void menu();



/*MAIN*/
int main(void){



  menu();




  return 0;

}


void cleanBuffer(void){
     char clean;
     while((clean  = getchar()) != '\n' && clean != EOF);
}


float preco_medio(int quantidade , float compra[]){


    float calcTotal = 0.0;

    for(int i = 0 ; i < quantidade; i++){

      calcTotal += compra[i];

    }

     printf("CUSTO TOTAL ->> %1.2f\n" , calcTotal);

     return calcTotal/quantidade;
}

float preco_medio_em_carteira(int quantidade , float compra[], int quantidadeAtual , float custoTotalAtual){


    float calcTotal = 0.0;
    float valorAtualizado= 0.0;

    for(int i = 0 ; i < quantidade; i++){

      calcTotal += compra[i];
      float custoTotal =  calcTotal + custoTotalAtual;
      valorAtualizado =  custoTotal;

    }

     printf("CUSTO TOTAL ATUALIZADO %1.2f\n" , valorAtualizado);

     return valorAtualizado/(quantidade+quantidadeAtual);
}



void novas_acoes(){

     //nome da acao
     char ticker[SIZE];

     //quantidade de acoes
     int  quantidade =0;

     //recebe valores de cada uma das acaoes
     float recValor[5];

     //valor das acoes
     float valor = 0.0;


     printf("TICKER OU NOME DA EMPRESA: ");
     fgets(ticker , SIZE , stdin);
     setbuf(stdin, NULL);// no windows substitua pelo cleanBuffer()

     printf("QUANTIDADE: ");scanf(" %d" ,&quantidade);

     for(int i = 0 ; i < quantidade ; i++){

        printf("DIGITE O VALOR DA %d COMPRA: " , (1+i));scanf(" %f",&valor);


        recValor[i] = valor;
     }


     printf("->> %1.2f\n" , preco_medio(quantidade, recValor));

}

void acoes_em_carteira(){

     //nome da acao
     char ticker[SIZE];

    //quantidade de acoes
     int  quantidadeEmCarteira =0;

      int quantidadeComprada= 0;

     //recebe valores de cada uma das acaoes
     float recValor[5];

     //valor das acoes
     float valor = 0.0;

     float custoTotalATual = 0.0;


     printf("TICKER OU NOME DA EMPRESA: ");
     fgets(ticker , SIZE , stdin);
     setbuf(stdin, NULL);

     printf("QUANTIDADE EM CARTEIRA: ");scanf(" %d" ,&quantidadeEmCarteira);
     int guardaQuantidadeEmCarteira = quantidadeEmCarteira;
     setbuf(stdin,NULL);

     printf("CUSTO TOTAL ATUAL: ");scanf("%f", &custoTotalATual);
     float guardaCustoTotalAtual =  custoTotalATual;

     printf("DIGITE QUANTAS NOVOS ATIVOS COMPRADOS: ");scanf("%d" ,&quantidadeComprada);
     int guardaQuantidadeAtivoComprado = quantidadeComprada;



     int somaTotalQuantidade = guardaQuantidadeEmCarteira + guardaQuantidadeAtivoComprado;



     for(int i =  0 ; i < quantidadeComprada ;i++){


        printf("DIGITE O VALOR DA %d COMPRA: " , (1+i));scanf(" %f",&valor);

        recValor[i] = valor;

     }
     
     printf("QUANTIDADE ATUALIZADA: %d\n" , somaTotalQuantidade );
     
     
     float pm = preco_medio_em_carteira(quantidadeComprada , recValor ,quantidadeEmCarteira,guardaCustoTotalAtual); 
     printf("SEU PRECO MEDIO:  %1.2f\n" , pm);




}


void menu(){

   int menu_de_opcao=0;


 do{

        printf("*============================= MENU ================================*\n");
        printf("||1- CALCULAR PRECO MEDIO DE NOVAS ACOES                            ||\n");
        printf("||2- CALCULAR PRECO MEDIO DE ACOES EM CARTEIRA COM NOVAS AQUISICOES ||\n");
        printf("||0- ENCERRAR PROGRAMA                                              ||\n");
        printf("*===================================================================*\n");
        printf("DIGITE AQUI: ");scanf("%d" , &menu_de_opcao);
        setbuf(stdin, NULL);


        switch(menu_de_opcao){

        case 1:

           printf("--> CALCULANDO NOVAS ACOES <--\n");
           novas_acoes();
           break;

        case 2:

           printf("--> CALCULANDO ACOES EM CARTEIRA E NOVAS COMPRAS <--\n");
           acoes_em_carteira();
           break;


        case 0:

            printf("PROGRAMA ENCERRADO!");
            exit(0);
            break;

        default:
            printf("VOCE DIGITOU UMA OPCAO INVALIDA");
        }


     }while(menu_de_opcao != 0);


}



