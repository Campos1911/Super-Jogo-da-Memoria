/*******************************************************************************
 * Autores: Anthoni Bernardi Thomes Campos.
 * Disciplina: Programação I
 * Data de Entrega: 22/01/2023
 *
 * ----------------------
 * Nome do Projeto : Super Jogo da Memória
 * Objetivo: Criar um jogo da memória que atualiza seu tabuleiro a cada acerto
 * e interaja com o jogador, conforme suas escolhas
 *********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int tabuleiro[4][4]; //Tabuleiro padrão do jogo
int tabuleiro2[4][4] = {0}; //Tabuleiro máscara, utilizado para printar a casa descoberta, quando certa
int contador[16] = {0};

void interface() //Interface montada para dar ao código mais semelhança com um jogo
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
    printf("\n\n\t-----Para jogar, utilize coordenadas de 0 a 3, para linhas e colunas-----");
    intervalo();
    intervalo();
    intervalo();
    intervalo();
    intervalo();
    system("cls");
}

void randomiza(int semente) //Randomiza letras em posições do tabuleiro
{
    int k = 0;
    srand(semente);
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tabuleiro[i][j] = 65 + rand() % 26;
            contador[k] = tabuleiro[i][j];
            k++;
            printf("  %c  ", tabuleiro[i][j]);
        }
        printf("\n\n");
    }
}

void tabuleiroOculto() //Printa o tabuleiro sem nenhum preenchimento de letras
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
        printf("  *  ");
    }
    printf("\n\n");
  }
  
}

void altera()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
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

int pares(int par)
{
    int conta = 0;
    par = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 16; k++)
            {
                if (contador[k]==tabuleiro[i][j])
                {
                    conta++;
                }
            }
            
            if (conta==2 || conta ==3)
            {
                par++;
            }

            else if (conta==4)
            {
                par++;
            }
            conta = 0;
        }
    }

    par = par/2;
    return par;
}

void intervalo(){for(int i=0; i<500000000; i++){}} //Função para dar intervalo no começo do jogo


int main() 
{
    int l1, c1, l2, c2, semente;
    int aux, teste = 0;

    system("color 3");  //Muda a cor da letra
    system("cls"); //Limpa o terminal
    interface();
    printf("Por favor, insira um valor de semente para começarmos: "); //Pede a semente para testes
    scanf("%d", &semente);
    printf("\n");
    randomiza(semente); //Chama a função, usando o valor escolhido pelo jogador
    intervalo();
    intervalo();    
    intervalo();
    system("cls");
    printf("\n");
    tabuleiroOculto(); //Printa o tabuleiro com as " * "
    aux = pares(teste); //Testa quantos pares o tabuleiro possui

    while (1)
    {
        printf("Escolha duas coordenadas de linha e coluna (caso queira sair, insira as coordenadas 0, 0, 0, 0)\n");
        printf("FALTAM %d PARES\n", aux);
        scanf("%d %d %d %d", &l1, &c1, &l2, &c2);
            
            if (l1 == 0 && c1 == 0 && l2==0 && c2 == 0) //Se colocar as coordenadas zero, o jogo acaba
            {
                system("color 6");
                printf("Ate mais, jogador(a)!!\n");
                break;
            }
            
            else if (l1 >= 4 || l1 < 0 || c1 >= 4 || c1 < 0 || l2 >= 4 || l2 < 0 || c2 >= 4 || c2 < 0)
            {
                printf("Coordenada invalida, tente novamente!!\n\n");
            }
            
            else if (tabuleiro2[l1][c1] == 1 || tabuleiro2[l2][c2] == 1)
            {
                system("color 4");
                printf("\nCUIDADO JOGADOR, essa coordenada ja foi descoberta\n\n");
                intervalo();
                intervalo();
                intervalo();
                system("cls");
                altera();
            }
            
            else if (tabuleiro[l1][c1] == tabuleiro[l2][c2]) //Se forem valores iguais, ele considera um acerto
            {
                system("color 2"); //Muda o terminal para verde, indicando acerto
                aux--;
                tabuleiro2[l1][c1] = 1; //Muda para um para imprimir a opção correta
                tabuleiro2[l2][c2] = 1;
                system("cls");
                printf("\nAcertou!!\n-------------------\n\n");
                altera();
            }
            
            else if (tabuleiro[l1][c1] != tabuleiro[l2][c2]) //Se forem valores diferentes, ele considera um erro
            {
                system("color 4"); //Muda o terminal para vermelho - indicando erro
                tabuleiro2[l1][c1] = 1; //Muda para um para imprimir a opção
                tabuleiro2[l2][c2] = 1;
                system("cls");
                printf("\nErrou!!\n-------------------\n\n");
                altera();
                tabuleiro2[l1][c1] = 0; //Muda para zero para não imprimir o erro novamente
                tabuleiro2[l2][c2] = 0;
            }            
                if (aux==0)
                {
                    system("color 2");
                    printf("Sem pares disponiveis, fim de jogo!!\n");
                    break;
                }
            
    }
    return 0;
}
