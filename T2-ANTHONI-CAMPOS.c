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
#include <time.h>
#include <string.h>
#include <unistd.h>

#define TAM 100

typedef struct 
{
    int pontuacao[100];

} tPontuacao;

typedef struct 
{
    char* jogadores; //Ponteiro do tipo char, para registrar os jogadores

} tJogadores;


void interface(int tamanho_matriz) //Interface montada para dar ao código mais semelhança com um jogo
{
    int opcao;
    char confirmacao;

    printf("\n\n\t\tSeja bem-vindo(a) ao SUPER JOGO DA MEMORIA!!!\n");
    sleep(1);
    sleep(1);
    sleep(1);
    printf("\t  Esse jogo foi desenvolvido por: Anthoni Bernardi Thomes Campos\n\n");
    sleep(1);
    sleep(1);
    sleep(1);
    printf("\n\t\tVOCE SE SENTE PRONTO(A) PARA JOGAR?\n\n");
    printf("(1) Claro que sim!!\n(2) Ainda nao, mas vou tentar\n(3) Definitivamente nao, eu desisto!\n");
    printf("\n\nInsira sua resposta aqui: ");
    scanf("%d", &opcao); //Lê a opção do usuário
        while (opcao > 3 || opcao < 1)
        {
            printf("Jogador, essa opcao nao e valida, tente novamente\n\n");
            scanf("%d", &opcao);
        }
            
        while (1)
        { 
            if (opcao==1)
            {
                printf("PERFEITO!!Insira qualquer tecla para jogar\n\n");
                scanf(" %c", &confirmacao);
                break;
                
            }
            else if (opcao==2)
            {
                printf("CORAGEM JOGADOR!!Voce vai ver que nao e dificil. Insira alguma tecla para comecar\n\n");
                scanf(" %c", &confirmacao);
                break;
            }
            else if (opcao==3)
            {
                printf("Entendo...Espero que futuramente voce se sinta melhor. Insira qualquer tecla para sair.\n\n");
                scanf(" %c", &confirmacao);
                exit(1);
            }
        }
    
    sleep(1);
    printf("\n\n\t-----Para jogar, utilize coordenadas de 1 a %d, para linhas e colunas-----", tamanho_matriz);
    printf("\n"); //Utilizado por conta de um bug na função 'sleep', que não printa o texto de cima
    sleep(1);
    sleep(1); //As funçoes intervalo foram usadas como forma de dar um
    sleep(1); //tempo entre cada apresentação (usadas para evitar que
    sleep(1); //a biblioteca windows.h fosse uma opção)
    sleep(1);
    printf("\e[H\e[2J");
}

void randomiza(int semente, int contador[TAM], int tabuleiro[TAM][TAM], int tamanho_matriz) //Randomiza letras em posições do tabuleiro
{
    int k = 0;
    srand(semente);
    
    for (int i = 1; i <= tamanho_matriz; i++)
    {
        for (int j = 1; j <= tamanho_matriz; j++)
        {
            tabuleiro[i][j] = 65 + rand() % 26;
            contador[k] = tabuleiro[i][j]; //Aqui a variável contador recebe os valores da matriz
            k++;                           //para poder fazer a verificação dos pares, futuramente.
            printf("  %c  ", tabuleiro[i][j]);
        }
        printf("\n\n");
    }
}

void tabuleiroOculto(int tamanho_matriz) //Printa o tabuleiro sem nenhum preenchimento de letras
{
  for (int i = 1; i <= tamanho_matriz; i++)
  {
    for (int j = 1; j <= tamanho_matriz; j++)
    {
        printf("  *  ");
    }
    printf("\n\n");
  }
  
}

void altera(int tabuleiro2[TAM][TAM], int tabuleiro[TAM][TAM], int tamanho_matriz)
{
    for (int i = 1; i <= tamanho_matriz; i++)
    {
        for (int j = 1; j <= tamanho_matriz; j++)
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

int pares(int par, int tamanho_matriz, int tabuleiro[TAM][TAM], int contador[TAM])
{
    int conta = 0;
    par = 0;

    for (int i = 1; i <= tamanho_matriz; i++)
    {
        for (int j = 1; j <= tamanho_matriz; j++)
        {
            for (int k = 0; k < tamanho_matriz*tamanho_matriz; k++) //percorre os valores
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
    int l1, c1, l2, c2, semente, tamanho_matriz; //Usado nas coordenadas
    int tabuleiro[TAM][TAM], tabuleiro2[TAM][TAM], contador[TAM];
    int aux, teste; //Usados nos pares
    int *slots;
    char nome_result[TAM] = "Result_";
    FILE *arq; //Ponteiro para arquivo
    FILE *result;


    tPontuacao a; //Structs declaradas
    tJogadores nome[TAM];    

    zera_struct(&a); //Chama a função de zerar structs
    tamanho_matriz = (atoi(argv[2])); //Converte tamanho da matriz para int ao quadrado
    

    if (argc < 3) //Testa a quantidade de argumentos
    {
        printf("\n\n\tFaltaram argumentos na chamada, tente novamente\n\n");
        exit(1);
    }
    
    for (int i = 3; i < TAM; i++)
    {
        nome[i].jogadores = argv[i]; //Nomeia as posições da struct com os nomes passados no argumento
    }
    


    slots = malloc(tamanho_matriz*sizeof(int));
    printf("\033[34m");  //Muda a cor da letra
    printf("\e[H\e[2J"); //Limpa o terminal
    interface(tamanho_matriz);
    printf("Por favor, insira um valor de semente para começarmos: "); //Pede a semente para testes
    scanf("%d", &semente);
    printf("\n");
    randomiza(semente, contador, tabuleiro, tamanho_matriz); //Chama a função, usando o valor escolhido pelo jogador
    sleep(1);
    sleep(1);    
    sleep(1);
    printf("\e[H\e[2J");
    printf("\n");
    tabuleiroOculto(tamanho_matriz); //Printa o tabuleiro com as " * "
    aux = pares(teste, tamanho_matriz, tabuleiro,contador); //Testa quantos pares o tabuleiro possui
    
    arq = fopen(argv[1], "w"); //Chamada para abrir e escrever no arquivo
        if (arq == NULL) //Se retornar nulo, deu erro
        {
            printf("Erro ao abrir!\n");
            exit(1);
        }
        else
        {
            fprintf(arq, "Tabuleiro:\n");
            for (int i = 1; i <= tamanho_matriz; i++)
            {
                for (int j = 1; j <= tamanho_matriz; j++)
                {
                    fprintf(arq, "  %c  ", tabuleiro[i][j]);
                }
                fprintf(arq, "\n\n");
            }
            
        }
    
    fclose(arq); //Fecha o arquivo

    while (1)
    {

        for (int i = 3; i < argc; i++) //"I" sempre tem que ser menor que o número de 
        {                                //nomes inseridos, para que os jogadores possam ser chamados        
        printf("%s, escolha duas coordenadas de linha e coluna (caso queira sair, insira as coordenadas 0, 0)\n", argv[i]);
        printf("FALTAM %d PARES\n", aux);
        scanf("%d %d %d %d", &l1, &c1, &l2, &c2);
            
            if ((l1 == 0 && c1 == 0) || (l2==0 && c2 == 0)) //Se colocar as coordenadas zero, o jogo acaba
            {
                printf("\033[33m");
                printf("Ate mais, jogador(a)!!\n");
                exit(1);
            }
            
            else if (l1 > tamanho_matriz || l1 < 1 || c1 > tamanho_matriz || c1 < 1 || l2 > tamanho_matriz || l2 < 1 || c2 > tamanho_matriz || c2 < 1) //Coordenadas inválidas
            {
                printf("Coordenada invalida, tente novamente!!\n\n");
                i--;
            }
            
            else if (tabuleiro2[l1][c1] == 1 || tabuleiro2[l2][c2] == 1) //Quando a coordenada já foi descoberta, é impossível
            {                                                            //"reencontrar" ela       
                printf("\033[31m"); //Vermelho
                printf("\nCUIDADO JOGADOR, essa coordenada ja foi descoberta\n\n");
                sleep(1);
                sleep(1);
                sleep(1);
                printf("\e[H\e[2J");
                altera(tabuleiro2, tabuleiro, tamanho_matriz);
                i--;
            }

            else if (l1 == l2 && c1 == c2)
            {
                printf("Insira coordenas diferentes, por favor!!\n\n");
                i--;
            }
            
            else if (tabuleiro[l1][c1] == tabuleiro[l2][c2]) //Se forem valores iguais, ele considera um acerto
            {
                printf("\033[32m"); //Muda o terminal para verde, indicando acerto
                aux--;
                tabuleiro2[l1][c1] = 1; //Muda para um para imprimir a opção correta
                tabuleiro2[l2][c2] = 1;
                printf("\e[H\e[2J");
                printf("\nAcertou!!\n-------------------\n\n");
                altera(tabuleiro2, tabuleiro, tamanho_matriz);
                a.pontuacao[i]++; //Incrementa um ponto para o jogador que acertar
                    fprintf(stdout, "Pontuação:\n"); //Printa também o arquivo na tela
                        for (int i = 3; i < argc; i++)
                        {
                            fprintf(stdout, "%s: %d\n\n", nome[i].jogadores, a.pontuacao[i]); //Printa pontos na tela
                        }
            }
            
            else if (tabuleiro[l1][c1] != tabuleiro[l2][c2]) //Se forem valores diferentes, ele considera um erro
            {
                printf("\033[31m"); //Muda o terminal para vermelho - indicando erro
                tabuleiro2[l1][c1] = 1; //Muda para um para imprimir a opção
                tabuleiro2[l2][c2] = 1;
                printf("\e[H\e[2J");
                printf("\nErrou!!\n-------------------\n\n");
                altera(tabuleiro2, tabuleiro, tamanho_matriz);
                tabuleiro2[l1][c1] = 0; //Muda para zero para não imprimir o erro novamente
                tabuleiro2[l2][c2] = 0;
                    fprintf(stdout, "Pontuação:\n"); //Printa também o arquivo na tela
                        for (int i = 3; i < argc; i++)
                        {
                            fprintf(stdout, "%s: %d\n\n", nome[i].jogadores, a.pontuacao[i]); //Printa pontos na tela
                        }
            }            
                if (aux==0) //Variável "aux" foi utilizada para 
                {           //retornar o valor de pares da função
                    printf("\033[32m");
                    printf("Sem pares disponiveis, fim de jogo!!\n");
                    result = fopen(strcat(nome_result, argv[1]), "w"); //Chamada para concatenar os nomes e escrever resultados
                    if (arq == NULL) //Se retornar nulo, deu erro
                    {
                        printf("Erro ao abrir!\n");
                        exit(1);
                    }
                    else
                    {
                    fprintf(arq, "Resultado do Tabuleiro:\n");
                        for (int i = 1; i <= tamanho_matriz; i++)
                        {
                            for (int j = 1; j <= tamanho_matriz; j++)
                            {
                                if (tabuleiro2[i][j] == 1)
                                {
                                   fprintf(arq, "  %c  ", tabuleiro[i][j]); //Printa o par
                                }
                                else
                                {
                                    fprintf(arq, "  *  "); //Printa vazio se não houver um par
                                }
                                
                                
                            }
                            fprintf(arq, "\n\n");
                        }
                    }
                    fclose(result); //Fecha o arquivo
                    exit(1);
                
                }
                
            }
            free(slots);
    }
    return 0;
}