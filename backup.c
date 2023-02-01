/*******************************************************************************
 * Autores: Anthoni Bernardi Thomes Campos.
 * Disciplina: Programação I
 * Data de Entrega: 22/01/2023
 *
 * ------------------------------------------------------------------------------
 * Nome do Projeto : Super Jogo da Memória
 * Objetivo: Criar um jogo da memória que atualiza seu tabuleiro a cada acerto
 * e interaja com o jogador, conforme suas escolhas
 *********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define TAM 100

int tabuleiro[TAM][TAM]; //Tabuleiro padrão do jogo
int tabuleiro2[TAM][TAM] = {0}; //Tabuleiro máscara, utilizado para printar a casa descoberta, quando certa
int contador[TAM*TAM] = {0};
int quantidade_nomes[TAM];


typedef struct 
{
    int pontuacao[100];

} tPontuacao;

typedef struct 
{
    char* jogadores; //Ponteiro do tipo char, para registrar os jogadores

} tJogadores;



void intervalo(){for(int i=0; i<500000000; i++){}} //Função para dar intervalo no começo do jogo

void interface(int numero_casas) //Interface montada para dar ao código mais semelhança com um jogo
{
    int opcao;

    printf("\n\n\t\tSeja bem-vindo(a) ao SUPER JOGO DA MEMORIA!!!\n");
    intervalo();
    intervalo();
    intervalo();
    printf("\t  Esse jogo foi desenvolvido por: Anthoni Bernardi Thomes Campos\n\n");
    intervalo();
    intervalo();
    intervalo();
    printf("\n\t\tVOCE SE SENTE PRONTO(A) PARA JOGAR?\n\n");
    printf("(1) Claro que sim!!\n(2) Ainda nao, mas vou tentar\n(3) Definitivamente nao, eu desisto!\n");
    printf("\n\nInsira sua resposta aqui: ");
    scanf("%d", &opcao); //Lê a opção do usuário
        if (opcao==1)
        {
            op1: printf("PERFEITO!!Aperte qualquer tecla para jogar\n\n");
            getch();
        }
        else if (opcao==2)
        {
            op2: printf("CORAGEM JOGADOR!!Voce vai ver que nao e dificil. Aperte alguma tecla para comecar\n\n");
            getch();
        }
        else if (opcao==3)
        {
            op3: printf("Entendo...Espero que futuramente voce se sinta melhor. Aperte qualquer tecla para sair.\n\n");
            getch();
            exit(1);
        }
        else //Caso o usuário informe alguma opção não válida, o código entrará no loop, pedindo uma informação correta
        {
            while (opcao > 3 || opcao < 1)
            {
                printf("Jogador, essa opcao nao e valida, tente novamente\n\n");
                scanf("%d", &opcao);
                    if (opcao==1)
                    {
                        goto op1; //Quando o usuário informa uma opção correta, o código usa o "goto" para retornar às linhas de cima
                    }
                    else if (opcao==2)
                    {
                        goto op2;
                    }
                    else if (opcao==3)
                    {
                        goto op3;
                    }
            }
            
        }
    intervalo();
    printf("\n\n\t-----Para jogar, utilize coordenadas de 1 a %d, para linhas e colunas-----", numero_casas);
    intervalo();
    intervalo(); //As funçoes intervalo foram usadas como forma de dar um
    intervalo(); //tempo entre cada apresentação (usadas para evitar que
    intervalo(); //a biblioteca windows.h fosse uma opção)
    intervalo();
    system("cls");
}

void randomiza(int semente, int numero_casas) //Randomiza letras em posições do tabuleiro
{
    int k = 0;
    srand(semente);
    
    for (int i = 1; i <= numero_casas; i++)
    {
        for (int j = 1; j <= numero_casas; j++)
        {
            tabuleiro[i][j] = 65 + rand() % 26;
            contador[k] = tabuleiro[i][j]; //Aqui a variável contador recebe os valores da matriz
            k++;                           //para poder fazer a verificação dos pares, futuramente.
            printf("  %c  ", tabuleiro[i][j]);
        }
        printf("\n\n");
    }
}

void tabuleiroOculto(int numero_casas) //Printa o tabuleiro sem nenhum preenchimento de letras
{
  for (int i = 1; i <= numero_casas; i++)
  {
    for (int j = 1; j <= numero_casas; j++)
    {
        printf("  *  ");
    }
    printf("\n\n");
  }
  
}

void altera(int numero_casas)
{
    for (int i = 1; i <= numero_casas; i++)
    {
        for (int j = 1; j <= numero_casas; j++)
        {
            if (tabuleiro2[i][j] == 1)  //Quando o jogador acerta, a função muda o valor de "0" para "1"
            {
                printf("  %c  ", tabuleiro[i][j]); //Em seguida, printa a letra já descoberta
            }
            else
            {
                printf("  *  ");
            }
            
            
        }
    printf("\n\n");
    }
    
}

int pares(int par, int numero_casas)
{
    int conta = 0;
    par = 0;

    for (int i = 1; i <= numero_casas; i++)
    {
        for (int j = 1; j <= numero_casas; j++)
        {
            for (int k = 0; k < numero_casas*numero_casas; k++) //percorre os valores
            {
                if (contador[k]==tabuleiro[i][j])
                {
                    conta++; //variável para identificar o número de repetições
                }
            }
            
            if (conta >= 2)
            {
                par++;
            }
            conta = 0; //Aqui ele zera a variável
        }              //para poder começar uma nova posição
    }

    par = par/2; //Divide por dois, pois o par se repete ao percorrer a matriz
    return par;
}

void zera_struct(tPontuacao* a) //Ponteiro acessa o endereço da struct
{
    for (int i = 0; i < TAM; i++)
    {
        a->pontuacao[i] = 0; //Aqui as posições são zeradas 
    }
    
}



int main(int argc, char *argv[])
{
    int l1, c1, l2, c2, semente, numero_casas; //Usado nas coordenadas
    int aux, teste, n; //Usados nos pares
    int k = 3; //Usado para o argv com nomes
    char nome_result[TAM] = "Result_";
    FILE *arq; //Ponteiro para arquivo
    FILE *result;


    tPontuacao a; //Structs declaradas
    tJogadores nome[10];

    zera_struct(&a); //Chama a função de zerar structs
    

    if (argc < 3) //Testa a quantidade de argumentos
    {
        printf("\n\n\tFaltaram argumentos na chamada, tente novamente\n\n");
        exit(1);
    }
    
    for (int i = 3; i < 10; i++)
    {
        nome[i].jogadores = argv[i]; //Nomeia as posições da struct com os nomes passados no argumento
    }
    

    arq = fopen(argv[1], "w"); //Chamada para abrir e escrever no arquivo
        if (arq == NULL) //Se retornar nulo, deu erro
        {
            printf("Erro ao abrir!\n");
            exit(1);
        }
        else
        {
            fprintf(arq, "Pontuação:\n", stdout);
                for (int i = 3; i < argc; i++)
                {
                    fprintf(arq, "%s: %d\n", nome[i].jogadores, a.pontuacao[i]); //Printa os jogadores e seus pontos
                }
        }   
    
    fclose(arq); //Fecha o arquivo


    numero_casas = atoi(argv[2]); //Converte tamanho da matriz para int, para imprimir o tabuleiro

    system("color 3");  //Muda a cor da letra
    system("cls"); //Limpa o terminal
    interface(numero_casas);
    printf("Por favor, insira um valor de semente para começarmos: "); //Pede a semente para testes
    scanf("%d", &semente);
    printf("\n");
    randomiza(semente, numero_casas); //Chama a função, usando o valor escolhido pelo jogador
    intervalo();
    intervalo();    
    intervalo();
    system("cls");
    printf("\n");
    tabuleiroOculto(numero_casas); //Printa o tabuleiro com as " * "
    aux = pares(teste, numero_casas); //Testa quantos pares o tabuleiro possui

    zerando:
    while (1)
    {

        for (int i = 3; i < argc; i++) //"I" sempre tem que ser menor que o número de 
        {                                //nomes inseridos, para que os jogadores possam ser chamados        
        printf("%s, escolha duas coordenadas de linha e coluna (caso queira sair, insira as coordenadas 0, 0, 0, 0)\n", argv[i]);
        printf("FALTAM %d PARES\n", aux);
        scanf("%d %d %d %d", &l1, &c1, &l2, &c2);
            
            if ((l1 == 0 && c1 == 0) || (l2==0 && c2 == 0)) //Se colocar as coordenadas zero, o jogo acaba
            {
                system("color 6");
                printf("Ate mais, jogador(a)!!\n");
                exit(1);
            }
            
            else if (l1 > numero_casas || l1 < 1 || c1 > numero_casas || c1 < 1 || l2 > numero_casas || l2 < 1 || c2 > numero_casas || c2 < 1) //Coordenadas inválidas
            {
                printf("Coordenada invalida, tente novamente!!\n\n");
                i--;
            }
            
            else if (tabuleiro2[l1][c1] == 1 || tabuleiro2[l2][c2] == 1) //Quando a coordenada já foi descoberta, é impossível
            {                                                            //"reencontrar" ela       
                system("color 4");
                printf("\nCUIDADO JOGADOR, essa coordenada ja foi descoberta\n\n");
                intervalo();
                intervalo();
                intervalo();
                system("cls");
                altera(numero_casas);
                i--;
            }

            else if (l1 == l2 && c1 == c2)
            {
                printf("Insira coordenas diferentes, por favor!!\n\n");
                i--;
            }
            
            else if (tabuleiro[l1][c1] == tabuleiro[l2][c2]) //Se forem valores iguais, ele considera um acerto
            {
                system("color 2"); //Muda o terminal para verde, indicando acerto
                aux--;
                tabuleiro2[l1][c1] = 1; //Muda para um para imprimir a opção correta
                tabuleiro2[l2][c2] = 1;
                system("cls");
                printf("\nAcertou!!\n-------------------\n\n");
                altera(numero_casas);
                a.pontuacao[i]++; //Incrementa um ponto para o jogador que acertar
                
                arq = fopen(argv[1], "w"); //Mesma função que a abertura de cima, porém, começa a contabilizar pontos
                if (arq == NULL)
                {
                    printf("Erro ao abrir!\n");
                    exit(1);
                }
                else
                {
                    fprintf(arq, "Pontuação:\n", stdout);
                    fprintf(stdout, "Pontuação:\n", stdout); //Printa também o arquivo na tela
                        for (int i = 3; i < argc; i++)
                        {
                            fprintf(arq, "%s: %d\n", nome[i].jogadores, a.pontuacao[i]);
                            fprintf(stdout, "%s: %d\n\n", nome[i].jogadores, a.pontuacao[i]); //Printa pontos na tela
                        }
                }
                fclose(arq);
            }
            
            else if (tabuleiro[l1][c1] != tabuleiro[l2][c2]) //Se forem valores diferentes, ele considera um erro
            {
                system("color 4"); //Muda o terminal para vermelho - indicando erro
                tabuleiro2[l1][c1] = 1; //Muda para um para imprimir a opção
                tabuleiro2[l2][c2] = 1;
                system("cls");
                printf("\nErrou!!\n-------------------\n\n");
                altera(numero_casas);
                tabuleiro2[l1][c1] = 0; //Muda para zero para não imprimir o erro novamente
                tabuleiro2[l2][c2] = 0;
            }            
                if (aux==0) //Variável "aux" foi utilizada para 
                {           //retornar o valor de pares da função
                    system("color 2");
                    printf("Sem pares disponiveis, fim de jogo!!\n");
                    
                    strcat(nome_result, argv[1]); //Função da string.h para concatenar nome do arquivo
                    
                    result = fopen(nome_result, "w"); //Chamada para abrir e escrever no arquivo de resultado
                    if (arq == NULL) //Se retornar nulo, deu erro
                    {
                        printf("Erro ao abrir!\n");
                        exit(1);
                    }
                    else
                    {
                    fprintf(arq, "Pontuação:\n", stdout);
                        for (int i = 3; i < argc; i++)
                        {
                            fprintf(arq, "%s: %d\n", nome[i].jogadores, a.pontuacao[i]); //Printa os jogadores e seus pontos
                        }
                    }
                    fclose(result); //Fecha o arquivo
                    exit(1);
                
                }
                
            }
    }
    free(&numero_casas);
    return 0;
}