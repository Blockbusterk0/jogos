#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "tecla.h"
#include "tela.h"

#define TEXTO tema[0][0],tema[0][1],tema[0][2]
#define TITULO tema[1][0],tema[1][1],tema[1][2]
#define FUNDO tema[2][0],tema[2][1],tema[2][2]
#define UP input == 'w' || input == 'A'
#define DOWN input == 's' || input == 'B'
#define RIGHT input == 'd' || input == 'C'
#define LEFT input == 'a' || input == 'D'   
#define OK input == '\n' || input == ' '

//Use a proporcao do terminal 99x30!

int jogo_estado(char board[3][3], char j1, char j2)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == board[i][2])
        {
            if (board[i][0] == j1)
            {
                return j1;
            }
            if (board[i][0] == j2)
            {
                return j2;
            }
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == board[2][i])
        {
            if (board[0][i] == j1)
            {
                return j1;
            }
            if (board[0][i] == j2)
            {
                return j2;
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == board[2][2])
    {
        if (board[0][0] == j1)
        {
            return j1;
        }
        if (board[0][0] == j2)
        {
            return j2;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == board[2][0])
    {
        if (board[0][2] == j1)
        {
            return j1;
        }
        if (board[0][2] == j2)
        {
            return j2;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return ' ';
            }
        }
    }
    return 'd';
}

void hud(int tema[3][3])
{
    tela_limpa();
    tela_cor_fundo(FUNDO);
    tela_lincol(3,1);
    tela_cor_letra(TITULO);
    printf(" ░░░░░░██╗░█████╗░░██████╗░░█████╗░░░██████╗░░█████╗░░░██╗░░░██╗███████╗██╗░░░░░██╗░░██╗░█████╗░░░\n");
    printf(" ░░░░░░██║██╔══██╗██╔════╝░██╔══██╗░░██╔══██╗██╔══██╗░░██║░░░██║██╔════╝██║░░░░░██║░░██║██╔══██╗░░\n");
    printf(" ░░░░░░██║██║░░██║██║░░██╗░██║░░██║░░██║░░██║███████║░░╚██╗░██╔╝█████╗░░██║░░░░░███████║███████║░░\n");
    printf(" ░██╗░░██║██║░░██║██║░░╚██╗██║░░██║░░██║░░██║██╔══██║░░░╚████╔╝░██╔══╝░░██║░░░░░██╔══██║██╔══██║░░\n");
    printf(" ░╚█████╔╝╚█████╔╝╚██████╔╝╚█████╔╝░░██████╔╝██║░░██║░░░░╚██╔╝░░███████╗███████╗██║░░██║██║░░██║░░\n");
    printf(" ░░╚════╝░░╚════╝░░╚═════╝░░╚════╝░░░╚═════╝░╚═╝░░╚═╝░░░░░╚═╝░░░╚══════╝╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝░░\n");
    tela_lincol(11,2);
    printf("┏");
    tela_lincol(11,98);
    printf("┓");
    tela_lincol(30,2);
    printf("┗");
    tela_lincol(30,98);
    printf("┛");
    for (int i = 3; i < 98; i++)
    {
        tela_lincol(11,i);
        printf("━");
        tela_lincol(30,i);
        printf("━");
    }
    for (int i = 12; i < 30; i++)
    {
        tela_lincol(i,2);
        printf("┃");
        tela_lincol(i,98);
        printf("┃");
    }
}

int robo_joga(int dificuldade, char board[3][3], char iconj1, char iconj2)
{
    for(int i = 0; i < 250000000; i++){}
    if (dificuldade == 0)
    {
        int input_linha;
        int input_coluna;
        while(true)
        {
            input_linha = rand() % 3;
            input_coluna = rand() % 3;
            if (board[input_linha][input_coluna] != ' ') continue;
            else
            {
                if (input_linha == 0 && input_coluna == 0) return 1;
                if (input_linha == 0 && input_coluna == 1) return 2;
                if (input_linha == 0 && input_coluna == 2) return 3;
                if (input_linha == 1 && input_coluna == 0) return 4;
                if (input_linha == 1 && input_coluna == 1) return 5;
                if (input_linha == 1 && input_coluna == 2) return 6;
                if (input_linha == 2 && input_coluna == 0) return 7;
                if (input_linha == 2 && input_coluna == 1) return 8;
                if (input_linha == 2 && input_coluna == 2) return 9;
            }
        }
    }
    if (dificuldade == 1)
    {
        int input_linha;
        int input_coluna;
        int matriz_numerica[3][3];
        int somas_estrategia[8];
        int possibilidade_vitoria;
        int jogada_realizada = 0;
        int jogada_ensaiada = 0;
        int foco;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == iconj1) matriz_numerica[i][j] = -1;
                if (board[i][j] == iconj2) matriz_numerica[i][j] = 1;
                if (board[i][j] == ' ') matriz_numerica[i][j] = 0;
            }
        }
        somas_estrategia[0] = matriz_numerica[0][0] + matriz_numerica[0][1] + matriz_numerica[0][2];
        somas_estrategia[1] = matriz_numerica[1][0] + matriz_numerica[1][1] + matriz_numerica[1][2];
        somas_estrategia[2] = matriz_numerica[2][0] + matriz_numerica[2][1] + matriz_numerica[2][2];
        somas_estrategia[3] = matriz_numerica[0][0] + matriz_numerica[1][0] + matriz_numerica[2][0];
        somas_estrategia[4] = matriz_numerica[0][1] + matriz_numerica[1][1] + matriz_numerica[2][1];
        somas_estrategia[5] = matriz_numerica[0][2] + matriz_numerica[1][2] + matriz_numerica[2][2];
        somas_estrategia[6] = matriz_numerica[0][0] + matriz_numerica[1][1] + matriz_numerica[2][2];
        somas_estrategia[7] = matriz_numerica[0][2] + matriz_numerica[1][1] + matriz_numerica[2][0];
        for (int i = 0; i < 8; i++)
        {
            if (somas_estrategia[i] == 2 || somas_estrategia[i] == -2)
            {
                jogada_ensaiada = 1;
            }
        }
        if (jogada_ensaiada == 1)
        {
            for (foco = 2; foco >= -2; foco -=4)
            {
                for (possibilidade_vitoria = 0; possibilidade_vitoria < 8; possibilidade_vitoria++)
                {
                    if (somas_estrategia[possibilidade_vitoria] == foco && jogada_realizada == 0)
                    {
                        int i;
                        switch (possibilidade_vitoria)
                        {
                            case 0:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[0][i] == ' ')
                                    {
                                        input_linha = 0;
                                        input_coluna = i;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 1:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[1][i] == ' ')
                                    {
                                        input_linha = 1;
                                        input_coluna = i;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 2:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[2][i] == ' ')
                                    {
                                        input_linha = 2;
                                        input_coluna = i;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 3:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[i][0] == ' ')
                                    {
                                        input_linha = i;
                                        input_coluna = 0;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 4:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[i][1] == ' ')
                                    {
                                        input_linha = i;
                                        input_coluna = 1;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 5:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[i][2] == ' ')
                                    {
                                        input_linha = i;
                                        input_coluna = 2;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 6:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[i][i] == ' ')
                                    {
                                        input_linha = i;
                                        input_coluna = i;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 7:
                                if (board[0][2] == ' ')
                                {
                                    input_linha = 0;
                                    input_coluna = 2;
                                }
                                else if (board[1][1] == ' ')
                                {
                                    input_linha = 1;
                                    input_coluna = 1;
                                }
                                else if (board[2][0] == ' ')
                                {
                                    input_linha = 2;
                                    input_coluna = 0;
                                }
                                jogada_realizada = 1;
                                break;
                        }
                    }
                }
            }  
        if (input_linha == 0 && input_coluna == 0) return 1;
        if (input_linha == 0 && input_coluna == 1) return 2;
        if (input_linha == 0 && input_coluna == 2) return 3;
        if (input_linha == 1 && input_coluna == 0) return 4;
        if (input_linha == 1 && input_coluna == 1) return 5;
        if (input_linha == 1 && input_coluna == 2) return 6;
        if (input_linha == 2 && input_coluna == 0) return 7;
        if (input_linha == 2 && input_coluna == 1) return 8;
        if (input_linha == 2 && input_coluna == 2) return 9;
        }
        else
        {
            while(true)
            {
                input_linha = rand() % 3;
                input_coluna = rand() % 3;
                if (board[input_linha][input_coluna] != ' ') continue;
                else
                {
                    if (input_linha == 0 && input_coluna == 0) return 1;
                    if (input_linha == 0 && input_coluna == 1) return 2;
                    if (input_linha == 0 && input_coluna == 2) return 3;
                    if (input_linha == 1 && input_coluna == 0) return 4;
                    if (input_linha == 1 && input_coluna == 1) return 5;
                    if (input_linha == 1 && input_coluna == 2) return 6;
                    if (input_linha == 2 && input_coluna == 0) return 7;
                    if (input_linha == 2 && input_coluna == 1) return 8;
                    if (input_linha == 2 && input_coluna == 2) return 9;
                }
            }
        }
    }
}

int imprime_jogo(int jogador, int jogadores, char board[3][3], int tema[3][3], int estilo, char iconj1, char iconj2, int cursor)
{
    hud(tema);
    tela_cor_letra(TEXTO);
    int cursor_linha;
    int cursor_coluna;
    if (cursor == 1) {cursor_linha = 18; cursor_coluna = 46;}
    if (cursor == 2) {cursor_linha = 18; cursor_coluna = 50;}
    if (cursor == 3) {cursor_linha = 18; cursor_coluna = 54;}
    if (cursor == 4) {cursor_linha = 20; cursor_coluna = 46;}
    if (cursor == 5) {cursor_linha = 20; cursor_coluna = 50;}
    if (cursor == 6) {cursor_linha = 20; cursor_coluna = 54;}
    if (cursor == 7) {cursor_linha = 22; cursor_coluna = 46;}
    if (cursor == 8) {cursor_linha = 22; cursor_coluna = 50;}
    if (cursor == 9) {cursor_linha = 22; cursor_coluna = 54;}
    int frame = 0;
    while (true)
    {
        tela_lincol(13,8);
        if (jogadores == 1)
        {
            if (jogador == 1) printf("Sua vez - marcador: %c ", iconj1);
            else printf("Vez do Robo - marcador: %c ", iconj2);
        }
        if (jogadores == 2)
        {
            printf("Vez do jogador %d ", jogador);
            if (jogador == 1) printf("- marcador: %c ", iconj1);
            else printf("- marcador: %c ", iconj2);
        }
        if (estilo == 1)
        {
            tela_lincol(18,45);
            printf(" %c │ %c │ %c", board[0][0], board[0][1], board[0][2]);
            tela_lincol(19,45);
            printf("───┼───┼───");
            tela_lincol(20,45);
            printf(" %c │ %c │ %c", board[1][0], board[1][1], board[1][2]);
            tela_lincol(21,45);
            printf("───┼───┼───");
            tela_lincol(22,45);
            printf(" %c │ %c │ %c", board[2][0], board[2][1], board[2][2]);
        }
        if (estilo == 2)
        {
            tela_lincol(17,44);
            printf("┏━━━┳━━━┳━━━┓");
            tela_lincol(18,44);
            printf("┃ %c ┃ %c ┃ %c ┃", board[0][0], board[0][1], board[0][2]);
            tela_lincol(19,44);
            printf("┣━━━╋━━━╋━━━┫");
            tela_lincol(20,44);
            printf("┃ %c ┃ %c ┃ %c ┃", board[1][0], board[1][1], board[1][2]);
            tela_lincol(21,44);
            printf("┣━━━╋━━━╋━━━┫");
            tela_lincol(22,44);
            printf("┃ %c ┃ %c ┃ %c ┃", board[2][0], board[2][1], board[2][2]);
            tela_lincol(23,44);
            printf("┗━━━┻━━━┻━━━┛");
        }
        if (!(jogadores == 1 && jogador == 2))
        {
            if (frame % 8 == 0 ||  frame % 8 == 1 || frame % 8 == 2 ||  frame % 8 == 3)
            {
                tela_lincol(cursor_linha, cursor_coluna);
                tela_cor_fundo(TITULO);
                if (cursor_linha == 18 && cursor_coluna == 46 ) printf("%c", board[0][0]);
                if (cursor_linha == 18 && cursor_coluna == 50 ) printf("%c", board[0][1]);
                if (cursor_linha == 18 && cursor_coluna == 54 ) printf("%c", board[0][2]);
                if (cursor_linha == 20 && cursor_coluna == 46 ) printf("%c", board[1][0]);
                if (cursor_linha == 20 && cursor_coluna == 50 ) printf("%c", board[1][1]);
                if (cursor_linha == 20 && cursor_coluna == 54 ) printf("%c", board[1][2]);
                if (cursor_linha == 22 && cursor_coluna == 46 ) printf("%c", board[2][0]);
                if (cursor_linha == 22 && cursor_coluna == 50 ) printf("%c", board[2][1]);
                if (cursor_linha == 22 && cursor_coluna == 54 ) printf("%c", board[2][2]);
            }
            frame++;
            tela_cor_fundo(FUNDO);
            tela_atualiza();
            char input = tecla_le_char(); // 18,46 ; 18,50 ; 18,54 ; 20,46 ; 20,50; 20,54 ; 22,46 ; 22,50 ; 22,54
            if (UP)
            {
                if (cursor_linha != 18) cursor_linha -= 2;
                frame = 0;
            }    
            if (DOWN)
            {
                if (cursor_linha != 22) cursor_linha += 2;
                frame = 0;
            }
            if (LEFT)
            {
                if (cursor_coluna != 46) cursor_coluna -= 4;
                frame = 0;
            }    
            if (RIGHT)
            {
                if (cursor_coluna != 54) cursor_coluna += 4;
                frame = 0;
            }            
            if (OK)
            {
                if (cursor_linha == 18 && cursor_coluna == 46 && board[0][0] == ' ') return 1;
                if (cursor_linha == 18 && cursor_coluna == 50 && board[0][1] == ' ') return 2;
                if (cursor_linha == 18 && cursor_coluna == 54 && board[0][2] == ' ') return 3;
                if (cursor_linha == 20 && cursor_coluna == 46 && board[1][0] == ' ') return 4;
                if (cursor_linha == 20 && cursor_coluna == 50 && board[1][1] == ' ') return 5;
                if (cursor_linha == 20 && cursor_coluna == 54 && board[1][2] == ' ') return 6;
                if (cursor_linha == 22 && cursor_coluna == 46 && board[2][0] == ' ') return 7;
                if (cursor_linha == 22 && cursor_coluna == 50 && board[2][1] == ' ') return 8;
                if (cursor_linha == 22 && cursor_coluna == 54 && board[2][2] == ' ') return 9;
            }
        }
        else
        {
            tela_atualiza();
            return 0;
        }
    }
}

bool imprime_resultado(int resultado, int jogadores, char board[3][3], int tema[3][3], int estilo, char sj1, char sj2, int vj, int vr, int v1, int v2, int e1, int e2)
{
    hud(tema);
    if (estilo == 1)
    {
        tela_lincol(18,45);
        printf(" %c │ %c │ %c", board[0][0], board[0][1], board[0][2]);
        tela_lincol(19,45);
        printf("───┼───┼───");
        tela_lincol(20,45);
        printf(" %c │ %c │ %c", board[1][0], board[1][1], board[1][2]);
        tela_lincol(21,45);
        printf("───┼───┼───");
        tela_lincol(22,45);
        printf(" %c │ %c │ %c", board[2][0], board[2][1], board[2][2]);
    }
    if (estilo == 2)
    {
        tela_lincol(17,44);
        printf("┏━━━┳━━━┳━━━┓");
        tela_lincol(18,44);
        printf("┃ %c ┃ %c ┃ %c ┃", board[0][0], board[0][1], board[0][2]);
        tela_lincol(19,44);
        printf("┣━━━╋━━━╋━━━┫");
        tela_lincol(20,44);
        printf("┃ %c ┃ %c ┃ %c ┃", board[1][0], board[1][1], board[1][2]);
        tela_lincol(21,44);
        printf("┣━━━╋━━━╋━━━┫");
        tela_lincol(22,44);
        printf("┃ %c ┃ %c ┃ %c ┃", board[2][0], board[2][1], board[2][2]);
        tela_lincol(23,44);
        printf("┗━━━┻━━━┻━━━┛");
    }
    tela_lincol(13,8);
    tela_cor_letra(TEXTO);
    printf("Fim de jogo!");
    tela_lincol(15,8);
    if (jogadores == 1)
    {
        tela_cor_letra(TITULO);
        if (resultado == 1)
        {
            printf("Voce venceu!"); 
        }
        if (resultado == 2)
        {
            printf("O Robo venceu!");
        }
        if (resultado == 0)
        {
            printf("O jogo empatou!");
        }
        tela_cor_letra(TEXTO); 
        tela_lincol(17,8);
        printf("Vitorias do jogador: %d", vj);
        tela_lincol(19,8);
        printf("Vitorias do Robo: %d", vr);
        tela_lincol(21,8);
        printf("Empates: %d", e1);
    }
    if (jogadores == 2)
    {
        tela_cor_letra(TITULO);
        if (resultado == 1)
        {
            printf("O jogador 1 venceu! - %c", sj1); 
        }
        if (resultado == 2)
        {
            printf("O jogador 2 venceu! - %c", sj2); 
        }
        if (resultado == 0)
        {
            printf("O jogo empatou!");
        }
        tela_cor_letra(TEXTO); 
        tela_lincol(17,8);
        printf("Vitorias do jogador 1: %d", v1);
        tela_lincol(19,8);
        printf("Vitorias do jogador 2: %d", v2);
        tela_lincol(21,8);
        printf("Empates: %d", e2);
    }
    tela_lincol(26,8);
    printf("Aperte ENTER ou ESPACO para jogar novamente.");
    tela_lincol(28,8);
    printf("Aperte H para sair.");
    tela_atualiza();
    while (true)
    {
        char input = tecla_le_char();
        if (OK)
        {
        return true;
        }    
        if (input == 'h')
        {
            return false;
        }
    }
}

int personalizacao(int tema[3][3], int ponteiro)
{
    int pos_ponteiro = ponteiro;
    while (true)
    {  
        hud(tema);
        tela_cor_letra(TEXTO);
        tela_lincol(13,8);
        printf("Trocar tema");
        tela_lincol(15, 8);
        printf("Trocar grade");
        tela_lincol(17, 8);
        printf("Trocar icone jogador 1");
        tela_lincol(19,8);
        printf("Trocar icone jogador 2");
        tela_lincol(21,8);
        printf("Trocar dificuldade");
        tela_lincol(28,8);
        printf("Voltar");
        tela_lincol(pos_ponteiro, 5);
        printf("►");
        tela_atualiza();
        char input = tecla_le_char();
        if (UP)
        {
            if (pos_ponteiro == 28) pos_ponteiro = 21;
            else if (pos_ponteiro != 13) pos_ponteiro-=2;
            
        }    
        if (DOWN)
        {
            if (pos_ponteiro == 21) pos_ponteiro = 28;
            else if (pos_ponteiro != 28) pos_ponteiro+=2;
        }    
        if (OK)
        {
            if (pos_ponteiro == 28)
            {
                return -1;
            }
            else if  (pos_ponteiro == 13)
            {
                return 1;
            }
            else if (pos_ponteiro == 15)
            {
                return 2;
            }
            else if (pos_ponteiro == 17)
            {
                return 3;
            }
            else if (pos_ponteiro == 19)
            {
                return 4;
            }         
            else if (pos_ponteiro == 21)
            {
                return 5;
            }         
        }            
    }  
}

int pers_tema(int tema[3][3], int ponteiro, int tema1[3][3], int tema2[3][3], int tema3[3][3], int tema4[3][3], int tema5[3][3])
{
    int pos_ponteiro = ponteiro;
    while (true)
    {
        hud(tema);
        tela_cor_letra(TEXTO);
        tela_lincol(13,8);
        printf("Tema 1: ");
        tela_cor_letra(tema1[0][0],tema1[0][1],tema1[0][2]);
        tela_cor_fundo(tema1[2][0],tema1[2][1],tema1[2][2]);
        printf("Texto");
        tela_cor_letra(tema1[1][0],tema1[1][1],tema1[1][2]);
        printf("Titulo");
        tela_lincol(15, 8);
        tela_cor_letra(TEXTO);
        tela_cor_fundo(FUNDO);
        printf("Tema 2: ");
        tela_cor_letra(tema2[0][0],tema2[0][1],tema2[0][2]);
        tela_cor_fundo(tema2[2][0],tema2[2][1],tema2[2][2]);
        printf("Texto");
        tela_cor_letra(tema2[1][0],tema2[1][1],tema2[1][2]);
        printf("Titulo");
        tela_lincol(17,8);
        tela_cor_letra(TEXTO);
        tela_cor_fundo(FUNDO);
        printf("Tema 3: ");
        tela_cor_letra(tema3[0][0],tema3[0][1],tema3[0][2]);
        tela_cor_fundo(tema3[2][0],tema3[2][1],tema3[2][2]);
        printf("Texto");
        tela_cor_letra(tema3[1][0],tema3[1][1],tema3[1][2]);
        printf("Titulo");
        tela_lincol(19,8);
        tela_cor_letra(TEXTO);
        tela_cor_fundo(FUNDO);
        printf("Tema 4: ");
        tela_cor_letra(tema4[0][0],tema4[0][1],tema4[0][2]);
        tela_cor_fundo(tema4[2][0],tema4[2][1],tema4[2][2]);
        printf("Texto");
        tela_cor_letra(tema4[1][0],tema4[1][1],tema4[1][2]);
        printf("Titulo");
        tela_lincol(21,8);
        tela_cor_letra(TEXTO);
        tela_cor_fundo(FUNDO);
        printf("Tema 5: ");
        tela_cor_letra(tema5[0][0],tema5[0][1],tema5[0][2]);
        tela_cor_fundo(tema5[2][0],tema5[2][1],tema5[2][2]);
        printf("Texto");
        tela_cor_letra(tema5[1][0],tema5[1][1],tema5[1][2]);
        printf("Titulo");
        tela_cor_letra(TEXTO);
        tela_cor_fundo(FUNDO);
        tela_lincol(28,8);
        printf("Voltar");
        tela_lincol(pos_ponteiro, 5);
        printf("►");
        tela_atualiza();
        char input = tecla_le_char();
        if (UP)
        {
            if (pos_ponteiro == 28) pos_ponteiro = 21;
            else if (pos_ponteiro != 13) pos_ponteiro-=2;
        }    
        if (DOWN)
        {
            if (pos_ponteiro == 21) pos_ponteiro = 28;
            else if (pos_ponteiro != 28) pos_ponteiro+=2;
        }    
        if (OK)
        {
            if (pos_ponteiro == 28)
            {
                return -1;
            }
            else if  (pos_ponteiro == 13)
            {
                return 1;
            }
            else if (pos_ponteiro == 15)
            {
                return 2;
            }
            else if (pos_ponteiro == 17)
            {
                return 3;
            }
            else if (pos_ponteiro == 19)
            {
                return 4;
            }
            else if (pos_ponteiro == 21)
            {
                return 5;
            }
        }
    }
}

int pers_grade(int tema[3][3], int ponteiro)
{
    int pos_ponteiro_lin = 15;
    int pos_ponteiro_col = ponteiro;
    
    while(true)
    {
        hud(tema);
        tela_cor_letra(TEXTO);
        tela_lincol(15,8);
        printf("Grade 1: ");
        tela_lincol(17,8);
        printf(" X │ O │ X");
        tela_lincol(18,8);
        printf("───┼───┼───");
        tela_lincol(19,8);
        printf(" O │ X │ O");
        tela_lincol(20,8);
        printf("───┼───┼───");
        tela_lincol(21,8);
        printf(" X │ O │ X");
            
        tela_lincol(15,58);
        printf("Grade 2: ");
        tela_lincol(17,58);
        printf("┏━━━┳━━━┳━━━┓");
        tela_lincol(18,58);
        printf("┃ X ┃ O ┃ X ┃");    
        tela_lincol(19,58);
        printf("┣━━━╋━━━╋━━━┫");    
        tela_lincol(20,58);
        printf("┃ O ┃ X ┃ O ┃");    
        tela_lincol(21,58);
        printf("┣━━━╋━━━╋━━━┫");    
        tela_lincol(22,58);
        printf("┃ X ┃ O ┃ X ┃");    
        tela_lincol(23,58);
        printf("┗━━━┻━━━┻━━━┛");
        tela_lincol(28,8);
        printf("Voltar");
        tela_lincol(pos_ponteiro_lin, pos_ponteiro_col);
        printf("►");
        tela_atualiza();
        char input = tecla_le_char();
        if (UP)
        {
            if (pos_ponteiro_lin == 28) pos_ponteiro_lin = 15;
        }    
        if (DOWN)
        {
            if (pos_ponteiro_lin == 15 && pos_ponteiro_col == 5) pos_ponteiro_lin = 28;
        }
        if (pos_ponteiro_lin == 15)
        {
            if (LEFT)
            {
                if (pos_ponteiro_col == 55) pos_ponteiro_col = 5;
            }    
            if (RIGHT)
            {
                if (pos_ponteiro_col == 5) pos_ponteiro_col = 55;
            }            
        }
        if (OK)
        {
            if (pos_ponteiro_lin == 28 && pos_ponteiro_col == 5)
            {
                return -1;
            }
            else if  (pos_ponteiro_lin == 15 && pos_ponteiro_col == 5)
            {
                return 1;
            }
            else if (pos_ponteiro_lin == 15 && pos_ponteiro_col == 55)
            {
                return 2;
            }
        }
    }   
}

char pers_simbolo(int jogador, int tema[3][3], char simbolo1, char simbolo2)
{
    int marcador;
    if (jogador == 1) marcador = simbolo1;
    if (jogador == 2) marcador = simbolo2;
    while (true)
    {
        hud(tema);
        tela_cor_letra(TEXTO);
        tela_lincol(13,8);
        if (jogador == 1) printf("Digite o simbolo para atribuir ao jogador 1: ");
        if (jogador == 2) printf("Digite o simbolo para atribuir ao jogador 2 e ao Robo: ");
        tela_lincol(15,8);
        printf("Use o shift normalmente.");
        tela_lincol(21,8);
        printf("Simbolo selecionado: ");
        tela_lincol(21,29);
        printf("%c", marcador);
        tela_lincol(28,8);
        printf("Aperte ENTER ou ESPACO para voltar.");
        tela_atualiza();
        char input = tecla_le_char();
        if (!(OK) && input != '\0' && input != '\t' && input != '\e' && input != '\b' && input != '\v')
        {
            marcador = input;    
        }
        else if ((OK) && marcador != ' ')
        {
            return marcador;
        }
    }
}

int pers_dificuldade(int tema[3][3], int ponteiro)
{
    int pos_ponteiro = ponteiro;
    while(true)
    {
        hud(tema);
        tela_cor_letra(TEXTO);
        tela_lincol(13,8);
        printf("Escolha a inteligencia do Robo:");
        tela_lincol(15,8);
        printf("Pouca");
        tela_lincol(17,8);
        printf("Media");
        tela_lincol(28,8);
        printf("Voltar");   
        tela_lincol(pos_ponteiro, 5);
        printf("►");
        tela_atualiza();
        char input = tecla_le_char();
        if (UP)
        {
            if (pos_ponteiro == 28) pos_ponteiro = 17;
            else if (pos_ponteiro != 15) pos_ponteiro-=2;
        }    
        if (DOWN)
        {
            if (pos_ponteiro == 17) pos_ponteiro = 28;
            else if (pos_ponteiro != 28) pos_ponteiro+=2;
        }    
        if (OK)
        {
            if (pos_ponteiro == 28)
            {
                return -1;
            }
            else if  (pos_ponteiro == 15)
            {
                return 0;
            }
            else if  (pos_ponteiro == 17)
            {
                return 1;
            }
        }  
    }
}

int main()
{
    char jogo[3][3];
    char simbolo_j1 = 'X';
    char simbolo_j2 = 'O';
    int dificuldade = 1;
    int jogadores;
    int tema[3][3] = {{200,200,200},{99,89,133},{24,18,43}};
    int grade = 1;
    char input;
    bool jogo_ligado = true;
    int frame = 0; // random improvisado kk
    int vitorias_1 = 0;
    int vitorias_robo = 0;
    int empates_1 = 0;
    int vitorias_j1 = 0;
    int vitorias_j2 = 0;
    int empates_2 = 0;
    int pos_ponteiro_menu = 13;
    int pos_ponteiro_pers = 13;
    int pos_ponteiro_tema = 13;
    int pos_ponteiro_grade = 5;
    int pos_ponteiro_icone1 = 15;
    int pos_ponteiro_icone2 = 17;
    int pos_ponteiro_dific = 17;
    int cursor;
    tela_ini();
    tecla_ini();
    while(jogo_ligado == true)
    {
        while (true)
        {
            tela_mostra_cursor(false);
            hud(tema);
            tela_lincol(13,8);
            tela_cor_letra(TEXTO);
            printf("1 Jogador");
            tela_lincol(15,8);
            printf("2 Jogadores");
            tela_lincol(17,8);
            printf("Personalizar");
            tela_lincol(28,8);
            printf("Sair");
            tela_lincol(pos_ponteiro_menu, 5);
            printf("►");
            tela_atualiza();
            frame++;
            input = tecla_le_char();
            if (UP)
            {
                if (pos_ponteiro_menu == 28) pos_ponteiro_menu=17; 
                else if (pos_ponteiro_menu != 13) pos_ponteiro_menu-=2;
            }    
            if (DOWN)
            {
                if (pos_ponteiro_menu == 17) pos_ponteiro_menu=28;
                else if (pos_ponteiro_menu != 28) pos_ponteiro_menu+=2;
            }    
            if (OK)
            {
                if  (pos_ponteiro_menu == 28)
                {
                    jogo_ligado = false;
                    break;
                }
                else if  (pos_ponteiro_menu == 13)
                {
                    jogadores = 1;
                    break;
                }
                else if  (pos_ponteiro_menu == 15)
                {
                    jogadores = 2;
                    break;
                }
                else if (pos_ponteiro_menu == 17)
                {
                    pos_ponteiro_menu = 13;
                    while (true)
                    {
                        int pers = personalizacao(tema, pos_ponteiro_pers);
                        if (pers == -1) break;
                        else if (pers == 1)
                        {
                            pos_ponteiro_pers = 13;
                            
                            while (true)
                            {
                                int tema1[3][3] = {{200,200,200},{99,89,133},{24,18,43}};
                                int tema2[3][3] = {{248, 249, 250},{247, 37, 133},{58, 12, 163}};
                                int tema3[3][3] = {{202, 210, 197},{82, 121, 111},{47, 62, 70}};
                                int tema4[3][3] = {{255, 248, 240},{132, 0, 50},{0, 18, 51}};
                                int tema5[3][3] = {{94, 48, 35},{192, 133, 82},{243, 233, 220}};
                                int perstema = pers_tema(tema, pos_ponteiro_tema, tema1, tema2, tema3, tema4, tema5);
                                if (perstema == -1)
                                {
                                    break;
                                }
                                else
                                {
                                    for (int i = 0; i < 3; i++)
                                    {
                                        for (int j = 0; j < 3; j++)
                                        {
                                            if (perstema == 1)
                                            {
                                                tema[i][j] = tema1[i][j];
                                                pos_ponteiro_tema = 13;
                                            }
                                            if (perstema == 2)
                                            {
                                                tema[i][j] = tema2[i][j];
                                                pos_ponteiro_tema = 15;
                                            }
                                            if (perstema == 3)
                                            {
                                                tema[i][j] = tema3[i][j];
                                                pos_ponteiro_tema = 17;
                                            }
                                            if (perstema == 4)
                                            {
                                                tema[i][j] = tema4[i][j];
                                                pos_ponteiro_tema = 19;
                                            }
                                            if (perstema == 5)
                                            {
                                                tema[i][j] = tema5[i][j];
                                                pos_ponteiro_tema = 21;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else if (pers == 2)
                        {
                            pos_ponteiro_pers = 15;
                            char persgrade = pers_grade(tema, pos_ponteiro_grade);
                            if (persgrade != -1)
                            {
                                grade = persgrade;
                            }
                            if (persgrade == 1) pos_ponteiro_grade = 5;
                            if (persgrade == 2) pos_ponteiro_grade = 55;

                        }
                        else if (pers == 3)
                        {
                            pos_ponteiro_pers = 17;
                            char perssimbolo = pers_simbolo(1, tema, simbolo_j1, simbolo_j2);
                            simbolo_j1 = perssimbolo;
                        }
                        else if (pers == 4)
                        {
                            pos_ponteiro_pers = 19;
                            char perssimbolo = pers_simbolo(2, tema, simbolo_j1, simbolo_j2);
                            simbolo_j2 = perssimbolo;
                        }
                        else if (pers == 5)
                        {
                            pos_ponteiro_pers = 21;
                            int persdifculdade = pers_dificuldade(tema, pos_ponteiro_dific);
                            if (persdifculdade != -1)
                            {
                                dificuldade = persdifculdade;
                            }
                            if (persdifculdade == 0) pos_ponteiro_dific = 15;
                            if (persdifculdade == 1) pos_ponteiro_dific = 17;
                        }
                    }
                }
            }
        }
        if (jogo_ligado == true)
        {
            cursor = 5;
            bool jogador_1_comeca;
            if (frame % 2 == 0) jogador_1_comeca = true;
            else jogador_1_comeca = false;
            
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    jogo[i][j] = ' ';
                }
            }
            
            int lugar;
            int jogador_da_rodada;
            int jogo_status = ' ';
            bool restart;
            if (jogadores == 1)
            {
                if (jogador_1_comeca == true)
                {
                    while (jogo_status == ' ')
                    {
                        jogador_da_rodada = 1;
                        lugar = imprime_jogo(jogador_da_rodada, jogadores, jogo, tema, grade, simbolo_j1, simbolo_j2, cursor);
                        cursor = lugar;
                        if (lugar == 1) jogo[0][0] = simbolo_j1;
                        if (lugar == 2) jogo[0][1] = simbolo_j1;
                        if (lugar == 3) jogo[0][2] = simbolo_j1;
                        if (lugar == 4) jogo[1][0] = simbolo_j1;
                        if (lugar == 5) jogo[1][1] = simbolo_j1;
                        if (lugar == 6) jogo[1][2] = simbolo_j1;
                        if (lugar == 7) jogo[2][0] = simbolo_j1;
                        if (lugar == 8) jogo[2][1] = simbolo_j1;
                        if (lugar == 9) jogo[2][2] = simbolo_j1;
                        jogo_status = jogo_estado(jogo, simbolo_j1, simbolo_j2);
                        if (jogo_status != ' ') continue;
                        jogador_da_rodada = 2;
                        imprime_jogo(jogador_da_rodada, jogadores, jogo, tema, grade, simbolo_j1, simbolo_j2, cursor);
                        lugar = robo_joga(dificuldade, jogo, simbolo_j1, simbolo_j2);
                        if (lugar == 1) jogo[0][0] = simbolo_j2;
                        if (lugar == 2) jogo[0][1] = simbolo_j2;
                        if (lugar == 3) jogo[0][2] = simbolo_j2;
                        if (lugar == 4) jogo[1][0] = simbolo_j2;
                        if (lugar == 5) jogo[1][1] = simbolo_j2;
                        if (lugar == 6) jogo[1][2] = simbolo_j2;
                        if (lugar == 7) jogo[2][0] = simbolo_j2;
                        if (lugar == 8) jogo[2][1] = simbolo_j2;
                        if (lugar == 9) jogo[2][2] = simbolo_j2;
                        jogo_status = jogo_estado(jogo, simbolo_j1, simbolo_j2);
                        if (jogo_status != ' ') continue;    
                    }
                }
                if (jogador_1_comeca == false)
                {
                    while (jogo_status == ' ')
                    {
                        jogador_da_rodada = 2;
                        imprime_jogo(jogador_da_rodada, jogadores, jogo, tema, grade, simbolo_j1, simbolo_j2, cursor);
                        lugar = robo_joga(dificuldade, jogo, simbolo_j1, simbolo_j2);
                        if (lugar == 1) jogo[0][0] = simbolo_j2;
                        if (lugar == 2) jogo[0][1] = simbolo_j2;
                        if (lugar == 3) jogo[0][2] = simbolo_j2;
                        if (lugar == 4) jogo[1][0] = simbolo_j2;
                        if (lugar == 5) jogo[1][1] = simbolo_j2;
                        if (lugar == 6) jogo[1][2] = simbolo_j2;
                        if (lugar == 7) jogo[2][0] = simbolo_j2;
                        if (lugar == 8) jogo[2][1] = simbolo_j2;
                        if (lugar == 9) jogo[2][2] = simbolo_j2;
                        jogo_status = jogo_estado(jogo, simbolo_j1, simbolo_j2);
                        if (jogo_status != ' ') continue;
                        jogador_da_rodada = 1;
                        lugar = imprime_jogo(jogador_da_rodada, jogadores, jogo, tema, grade, simbolo_j1, simbolo_j2, cursor);
                        cursor = lugar;
                        if (lugar == 1) jogo[0][0] = simbolo_j1;
                        if (lugar == 2) jogo[0][1] = simbolo_j1;
                        if (lugar == 3) jogo[0][2] = simbolo_j1;
                        if (lugar == 4) jogo[1][0] = simbolo_j1;
                        if (lugar == 5) jogo[1][1] = simbolo_j1;
                        if (lugar == 6) jogo[1][2] = simbolo_j1;
                        if (lugar == 7) jogo[2][0] = simbolo_j1;
                        if (lugar == 8) jogo[2][1] = simbolo_j1;
                        if (lugar == 9) jogo[2][2] = simbolo_j1;                        jogo_status = jogo_estado(jogo, simbolo_j1, simbolo_j2);
                        if (jogo_status != ' ') continue;
                    }
                }
                if (jogo_status == simbolo_j1)
                {
                    vitorias_1++;
                    restart = imprime_resultado(1,jogadores,jogo,tema,grade,simbolo_j1,simbolo_j2,vitorias_1,vitorias_robo,vitorias_j1,vitorias_j2,empates_1,empates_2);
                }
                if (jogo_status == simbolo_j2)
                {
                    vitorias_robo++;
                    restart = imprime_resultado(2,jogadores,jogo,tema,grade,simbolo_j1,simbolo_j2,vitorias_1,vitorias_robo,vitorias_j1,vitorias_j2,empates_1,empates_2);
                }
                if (jogo_status == 'd')
                {
                    empates_1++;
                    restart = imprime_resultado(0,jogadores,jogo,tema,grade,simbolo_j1,simbolo_j2,vitorias_1,vitorias_robo,vitorias_j1,vitorias_j2,empates_1,empates_2);
                }
            }
            if (jogadores == 2)
            {
                if (jogador_1_comeca == true)
                {
                    while (jogo_status == ' ')
                    {
                        jogador_da_rodada = 1;
                        lugar = imprime_jogo(jogador_da_rodada, jogadores, jogo, tema, grade, simbolo_j1, simbolo_j2, cursor);
                        cursor = lugar;
                        if (lugar == 1) jogo[0][0] = simbolo_j1;
                        if (lugar == 2) jogo[0][1] = simbolo_j1;
                        if (lugar == 3) jogo[0][2] = simbolo_j1;
                        if (lugar == 4) jogo[1][0] = simbolo_j1;
                        if (lugar == 5) jogo[1][1] = simbolo_j1;
                        if (lugar == 6) jogo[1][2] = simbolo_j1;
                        if (lugar == 7) jogo[2][0] = simbolo_j1;
                        if (lugar == 8) jogo[2][1] = simbolo_j1;
                        if (lugar == 9) jogo[2][2] = simbolo_j1;
                        jogo_status = jogo_estado(jogo, simbolo_j1, simbolo_j2);
                        if (jogo_status != ' ') continue;
                        jogador_da_rodada = 2;
                        lugar = imprime_jogo(jogador_da_rodada, jogadores, jogo, tema, grade, simbolo_j1, simbolo_j2, cursor);
                        cursor = lugar;
                        if (lugar == 1) jogo[0][0] = simbolo_j2;
                        if (lugar == 2) jogo[0][1] = simbolo_j2;
                        if (lugar == 3) jogo[0][2] = simbolo_j2;
                        if (lugar == 4) jogo[1][0] = simbolo_j2;
                        if (lugar == 5) jogo[1][1] = simbolo_j2;
                        if (lugar == 6) jogo[1][2] = simbolo_j2;
                        if (lugar == 7) jogo[2][0] = simbolo_j2;
                        if (lugar == 8) jogo[2][1] = simbolo_j2;
                        if (lugar == 9) jogo[2][2] = simbolo_j2;
                        jogo_status = jogo_estado(jogo, simbolo_j1, simbolo_j2);
                        if (jogo_status != ' ') continue;    
                    } 
                }
                if (jogador_1_comeca == false)
                {
                    while (jogo_status == ' ')
                    {
                        jogador_da_rodada = 2;
                        lugar = imprime_jogo(jogador_da_rodada, jogadores, jogo, tema, grade, simbolo_j1, simbolo_j2, cursor);
                        cursor = lugar;
                        if (lugar == 1) jogo[0][0] = simbolo_j2;
                        if (lugar == 2) jogo[0][1] = simbolo_j2;
                        if (lugar == 3) jogo[0][2] = simbolo_j2;
                        if (lugar == 4) jogo[1][0] = simbolo_j2;
                        if (lugar == 5) jogo[1][1] = simbolo_j2;
                        if (lugar == 6) jogo[1][2] = simbolo_j2;
                        if (lugar == 7) jogo[2][0] = simbolo_j2;
                        if (lugar == 8) jogo[2][1] = simbolo_j2;
                        if (lugar == 9) jogo[2][2] = simbolo_j2;
                        jogo_status = jogo_estado(jogo, simbolo_j1, simbolo_j2);
                        if (jogo_status != ' ') continue;    
                        jogador_da_rodada = 1;
                        lugar = imprime_jogo(jogador_da_rodada, jogadores, jogo, tema, grade, simbolo_j1, simbolo_j2, cursor);
                        cursor = lugar;
                        if (lugar == 1) jogo[0][0] = simbolo_j1;
                        if (lugar == 2) jogo[0][1] = simbolo_j1;
                        if (lugar == 3) jogo[0][2] = simbolo_j1;
                        if (lugar == 4) jogo[1][0] = simbolo_j1;
                        if (lugar == 5) jogo[1][1] = simbolo_j1;
                        if (lugar == 6) jogo[1][2] = simbolo_j1;
                        if (lugar == 7) jogo[2][0] = simbolo_j1;
                        if (lugar == 8) jogo[2][1] = simbolo_j1;
                        if (lugar == 9) jogo[2][2] = simbolo_j1;
                        jogo_status = jogo_estado(jogo, simbolo_j1, simbolo_j2);
                        if (jogo_status != ' ') continue;
                    }
                }
                if (jogo_status == simbolo_j1)
                {
                    vitorias_j1++;
                    restart = imprime_resultado(1,jogadores,jogo,tema,grade,simbolo_j1,simbolo_j2,vitorias_1,vitorias_robo,vitorias_j1,vitorias_j2,empates_1,empates_2);
                }
                if (jogo_status == simbolo_j2)
                {
                    vitorias_j2++;
                    restart = imprime_resultado(2,jogadores,jogo,tema,grade,simbolo_j1,simbolo_j2,vitorias_1,vitorias_robo,vitorias_j1,vitorias_j2,empates_1,empates_2);
                }
                if (jogo_status == 'd')
                {
                    empates_2++;
                    restart = imprime_resultado(0,jogadores,jogo,tema,grade,simbolo_j1,simbolo_j2,vitorias_1,vitorias_robo,vitorias_j1,vitorias_j2,empates_1,empates_2);
                }
            }
            if (restart == false) jogo_ligado = false;
            continue;
        }
    }
    tecla_fim();
    tela_fim();
}
