#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char mapa[16][16];
int pos_atual_player[2] = {0,0};
int pos_inimigos[5][2] = {{0,0},{0,0},{0,0},{0,0},{0,0}};
int pos_pontos[10][2] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
int quantidade_barreiras;
int quantidade_inimigos;
char jogador = 79;
char inimigo = 158;
char barreira = 219;
char ponto = 15;
int pontuacao;

int timer(float a)
{
    int i;
    for (i = 1; i < a*500000000; i++){}
}

int sorteio(int quantidade) 
{
    int dado = rand() % quantidade;
    return dado;
}

void jogo_limpar_mapa()
{
    int i, j;
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 16; j++)
        {
            mapa[i][j] = ' ';
        }
    }
    for (i = 0; i < 16; i++)
    {
        mapa[0][i] = barreira;
        mapa[15][i] = barreira;
        mapa[i][0] = barreira;
        mapa[i][15] = barreira;
    }
    for (i = 0; i < 20; i++)
    {
        int l, c;
        l = sorteio(16);
        c = sorteio(16);
        mapa[l][c] = barreira;
    }
}

void jogo_imprime_mapa()
{
    int i, j;
    printf("\n\n\n\n");
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 16; j++)
        {
            printf("%c", mapa[i][j]);
        }
        if (i == 0)
        {
            printf("   pontuacao: %d", pontuacao);
        }
        if (i == 2)
        {
            printf("   player: %d, %d    ",pos_atual_player[0], pos_atual_player[1]);
        }
        if (i == 4)
        {
            printf("   inimigo 0: %d, %d     ",pos_inimigos[0][0], pos_inimigos[0][1]);
        }
        if (i == 5)
        {
            printf("   inimigo 1: %d, %d     ",pos_inimigos[1][0], pos_inimigos[1][1]);
        }
        if (i == 6)
        {
            printf("   inimigo 2: %d, %d     ",pos_inimigos[2][0], pos_inimigos[2][1]);
        }
        if (i == 7)
        {
            printf("   inimigo 3: %d, %d     ",pos_inimigos[3][0], pos_inimigos[3][1]);
        }
        if (i == 8)
        {
            printf("   inimigo 4: %d, %d     ",pos_inimigos[4][0], pos_inimigos[4][1]);
        }
        
        printf("\n");
    }
}

void jogo_spawna_pontos()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        int alocado = 0;
        while (alocado == 0)
        {
            int x, y;
            x = sorteio(16);
            y = sorteio(16);
            if (mapa[x][y] == ' ')
            {
                mapa[x][y] = ponto; 
                pos_pontos[i][0] = x;
                pos_pontos[i][1] = y;
                alocado = 1;
            }
        }
    }
}

int jogo_teste_pontos()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (pos_atual_player[0] == pos_pontos[i][0] && pos_atual_player[1] == pos_pontos[i][1])
        {
            pos_pontos[i][0] = -1;
            pos_pontos[i][1] = -1;
            pontuacao += 1;
        }
    }

}

void jogo_spawna_inimigos()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        int alocado = 0;
        while (alocado == 0)
        {
            int x, y;
            x = sorteio(16);
            y = sorteio(16);
            if (mapa[x][y] == ' ')
            {
                mapa[x][y] = inimigo; 
                pos_inimigos[i][0] = x;
                pos_inimigos[i][1] = y;
                alocado = 1;
            }
        }
    }
}

void jogo_move_inimigos()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        int moveu = 0;
        while (moveu == 0)
        {
            mapa[pos_inimigos[i][0]][pos_inimigos[i][1]] = ' ';
            int direcao = sorteio(4);
            if (direcao == 0)
            {
                if (mapa[pos_inimigos[i][0]][pos_inimigos[i][1]+1] == ' ' || mapa[pos_inimigos[i][0]][pos_inimigos[i][1]+1] == jogador)
                {
                    pos_inimigos[i][1] += 1;
                    moveu = 1;
                }
            }
            if (direcao == 1)
            {
                if (mapa[pos_inimigos[i][0]-1][pos_inimigos[i][1]] == ' ' || mapa[pos_inimigos[i][0]-1][pos_inimigos[i][1]] == jogador)
                {
                    pos_inimigos[i][0] -= 1;
                    moveu = 1;
                }
            }
            if (direcao == 2)
            {
                if (mapa[pos_inimigos[i][0]][pos_inimigos[i][1]-1] == ' ' || mapa[pos_inimigos[i][0]][pos_inimigos[i][1]-1] == jogador)
                {
                    pos_inimigos[i][1] -= 1;
                    moveu = 1;
                }
            }
            if (direcao == 3)
            {
                if (mapa[pos_inimigos[i][0]+1][pos_inimigos[i][1]] == ' ' || mapa[pos_inimigos[i][0]+1][pos_inimigos[i][1]] == jogador)
                {
                    pos_inimigos[i][0] += 1;
                    moveu = 1;
                }
            }
        }
        mapa[pos_inimigos[i][0]][pos_inimigos[i][1]] = inimigo;
    }
    timer(0.1);
    jogo_imprime_mapa();
}

int jogo_teste_morte()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (pos_inimigos[i][0] == pos_atual_player[0] && pos_inimigos[i][1] == pos_atual_player[1])
        {
            return 1;
        }
    }
    return 0;
}

void jogo_move_player(int i, int j)
{
    mapa[i][j] = jogador;
    pos_atual_player[0] = i;
    pos_atual_player[1] = j;
}

void jogo_controle_player()
{
    int moveu = 0;
    char direcao;
    while (moveu == 0)
    {
        direcao = getch();
        if (direcao == 'w')
        {
            if (mapa[pos_atual_player[0]-1][pos_atual_player[1]] != barreira)
            {
                mapa[pos_atual_player[0]][pos_atual_player[1]] = ' ';
                jogo_move_player(pos_atual_player[0]-1, pos_atual_player[1]);
                moveu = 1;
            }
        }
        else if (direcao == 'a')
        {
            if (mapa[pos_atual_player[0]][pos_atual_player[1]-1] != barreira)
            {
                mapa[pos_atual_player[0]][pos_atual_player[1]] = ' ';
                jogo_move_player(pos_atual_player[0], pos_atual_player[1]-1);
                moveu = 1;
            }
        }
        else if (direcao == 's')
        {
            if (mapa[pos_atual_player[0]+1][pos_atual_player[1]] != barreira)
            {
                mapa[pos_atual_player[0]][pos_atual_player[1]] = ' ';
                jogo_move_player(pos_atual_player[0]+1, pos_atual_player[1]);
                moveu = 1;
            }
        }
        else if (direcao == 'd')
        {
            if (mapa[pos_atual_player[0]][pos_atual_player[1]+1] != barreira)
            {
                mapa[pos_atual_player[0]][pos_atual_player[1]] = ' ';
                jogo_move_player(pos_atual_player[0], pos_atual_player[1]+1);
                moveu = 1;
            }
        }    
    }
    jogo_imprime_mapa();    
}

void main()
{
    int morreu;
    pontuacao = 0;
    srand(time(0));
    jogo_limpar_mapa();
    jogo_move_player(8,8);
    jogo_spawna_inimigos();
    jogo_spawna_pontos();
    jogo_imprime_mapa();
    while(pontuacao < 10)
    {
        jogo_controle_player();
        morreu = jogo_teste_morte();
        if (morreu == 1) break;
        jogo_teste_pontos();
        jogo_move_inimigos();
        morreu = jogo_teste_morte();
        if (morreu == 1) break;
    }
    if (morreu == 1)
    {
        printf("Voce perdeu. Pontuacao: %d", pontuacao);
    }
    else
    {
        printf("Voce ganhou.");
    }
}