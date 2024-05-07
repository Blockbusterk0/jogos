#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
char simbolo_jogador_1 = 'X';
char simbolo_jogador_2 = 'O';
int boardskin = 1;
int dificuldade = 1;
int sorteio(int limite)
{
    int dado = rand() % limite ;
    return dado;
}

void jogo_limpar_grade()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

int jogo_numero_jogadores()
{
    int jogadores;
    int config;
    while (jogadores != 1 && jogadores != 2)
    {
        config = 0;
        jogadores = 0;
        printf("\nJogo da Velha");
        printf("\n[1] 1 Jogador     [2] 2 Jogadores     [3] Configuracoes\n");
        scanf("%d", &jogadores);
        while (jogadores != 1 && jogadores != 2 && jogadores != 3 && jogadores != 4 && jogadores != 5)
        {
            scanf("%d", &jogadores);
        }
        if (jogadores == 3)
        {
            while (config != 5)
            {
                printf("\nConfiguracoes:");
                printf("\n[1] Trocar simbolo jogador 1     [2] Trocar simbolo jogador 2 / Robo     [3] Escolher estilo     [4] Dificuldade     [5] Voltar\n");
                scanf("%d", &config);
                while (config != 1 && config != 2 && config != 3 && config != 4 && config != 5)
                {
                    scanf("%d", &config);
                }
                if (config == 1)
                {
                    printf("\nEscolha o simbolo do jogador 1: ");
                    scanf(" %c", &simbolo_jogador_1);
                }
                if (config == 2)
                {
                    printf("\nEscolha o simbolo do jogador 2 e do Robo: ");
                    scanf(" %c", &simbolo_jogador_2);
                }
                if (config == 3)
                {
                    printf("\nEscolha o estilo do jogo: ");
                    printf("\n[1]             [2]             [3]             [4]");
                    printf("\n X | O | O       X | O | O       X # O # O       X | O | O ");
                    printf("\n---|---|---     -------|---     ###########     jogodavelha");
                    printf("\n O | X | X       O | X | X       O # X # X       O | X | X ");
                    printf("\n---|---|---     ---|-------     ###########     jogodavelha");
                    printf("\n O | X | O       O | X | O       O # X # O       O | X | O\n");
                    scanf("%d", &boardskin);
                    while (boardskin < 0 || boardskin > 4)
                    {
                        scanf("%d", &boardskin);
                    }
                }
                if (config == 4)
                {
                    printf("\nEscolha a inteligencia do Robo:     [0] Baixa     [1] Alta\n");
                    scanf("%d", &dificuldade);
                    while (dificuldade != 0 && dificuldade != 1)
                    {
                        scanf("%d", &dificuldade);
                    }
                }
            }

        }  
    }
    
    return jogadores;
}

int jogo_teste_empate()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

int jogo_teste_vitoria()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == board[i][2])
        {
            if (board[i][0] == simbolo_jogador_1)
            {
                return 1;
            }
            else if (board[i][0] == simbolo_jogador_2)
            {
                return 2;
            }
        }
    }
    for (j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] == board[2][j])
        {
            if (board[0][j] == simbolo_jogador_1)
            {
                return 1;
            }
            else if (board[0][j] == simbolo_jogador_2)
            {
                return 2;
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == board[2][2])
    {
        if (board[0][0] == simbolo_jogador_1)
        {
            return 1;
        }
        else if (board[0][0] == simbolo_jogador_2)
        {
            return 2;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == board[2][0])
    {
        if (board[0][2] == simbolo_jogador_1)
        {
            return 1;
        }
        else if (board[0][2] == simbolo_jogador_2)
        {
            return 2;
        }
    }
    return 0;
}

void jogo_jogar_jogador(int jogador)
{
    int input_linha, input_coluna;
    char marcador;
    switch(jogador)
    {
        case 1:
            marcador = simbolo_jogador_1;
            break;
        case 2:
            marcador = simbolo_jogador_2;
            break;
    }
    printf("Vez do jogador %d.", jogador);
    while (1 == 1)
    {
        printf("\nDigite a linha que voce quer jogar: ");
        scanf("%d", &input_linha);
        while (input_linha < 1 || input_linha > 3)
        {
            printf("Digite uma linha valida que voce quer jogar: ");
            scanf("%d", &input_linha);
        }
        printf("Digite a coluna que voce quer jogar: ");
        scanf("%d", &input_coluna);
        while (input_coluna < 1 || input_coluna > 3)
        {
            printf("Digite uma coluna valida que voce quer jogar: ");
            scanf("%d", &input_coluna);
        }
        if (board[input_linha-1][input_coluna-1] != ' ')
        {
            printf("Lugar ja escolhido.");
            continue;
        }
        else if (board[input_linha-1][input_coluna-1] == ' ')
        {
            board[input_linha-1][input_coluna-1] = marcador;
            break;
        }
    }
    jogo_imprimir_grade();
}

void jogo_jogar_robo(int jogador)
{
    int input_linha, input_coluna;
    char marcador;
    switch(jogador)
    {
        case 1:
            marcador = simbolo_jogador_1;
            break;
        case 2:
            marcador = simbolo_jogador_2;
            break;
    }
    printf("Vez do Robo.");
    if (dificuldade == 0)
    {
        while (1 == 1)
        {
            input_linha = sorteio(3);
            input_coluna = sorteio(3);
            if (board[input_linha][input_coluna] != ' ')
            {
                continue;
            }
            else if (board[input_linha][input_coluna] == ' ')
            {
                board[input_linha][input_coluna] = marcador;
                break;
            }
        }
    }
    if (dificuldade == 1)
    {
        int i, j;
        int matriz_numerica[3][3];
        int somas_estrategia[8];
        int possibilidade_vitoria;
        int jogada_realizada = 0;
        int jogada_ensaiada = 0;
        int foco;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] == simbolo_jogador_1)
                {
                    matriz_numerica[i][j] = -1;
                }
                else if (board[i][j] == simbolo_jogador_2)
                {
                    matriz_numerica[i][j] = 1;
                }
                else if (board[i][j] == ' ')
                {
                    matriz_numerica[i][j] = 0;
                }
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
        for (i = 0; i < 8; i++)
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
                        switch (possibilidade_vitoria)
                        {
                            case 0:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[0][i] == ' ')
                                    {
                                        board[0][i] = marcador;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 1:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[1][i] == ' ')
                                    {
                                        board[1][i] = marcador;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 2:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[2][i] == ' ')
                                    {
                                        board[2][i] = marcador;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 3:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[i][0] == ' ')
                                    {
                                        board[i][0] = marcador;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 4:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[i][1] == ' ')
                                    {
                                        board[i][1] = marcador;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 5:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[i][2] == ' ')
                                    {
                                        board[i][2] = marcador;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 6:
                                for (i = 0; i < 3; i++)
                                {
                                    if (board[i][i] == ' ')
                                    {
                                        board[i][i] = marcador;
                                        jogada_realizada = 1;
                                    }
                                }
                                break;
                            case 7:
                                if (board[0][2] == ' ')
                                {
                                    board[0][2] = marcador;
                                }
                                else if (board[1][1] == ' ')
                                {
                                    board[1][1] = marcador;
                                }
                                else if (board[2][0] == ' ')
                                {
                                    board[2][0] = marcador;
                                }
                                jogada_realizada = 1;
                                break;
                        }
                    }
                }
            }  
        }
        while (jogada_realizada == 0)
        {
            input_linha = sorteio(3);
            input_coluna = sorteio(3);
            if (board[input_linha][input_coluna] != ' ')
            {
                continue;
            }
            else if (board[input_linha][input_coluna] == ' ')
            {
                board[input_linha][input_coluna] = marcador;
                jogada_realizada = 1;
            }
            
        }
    }
    jogo_imprimir_grade();
}

void jogo_imprimir_grade()
{
    if (boardskin == 1)
    {  
        printf("\n\n\n  1   2   3 ");
        printf("\n1 %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
        printf("\n ---|---|---");
        printf("\n2 %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
        printf("\n ---|---|---");
        printf("\n3 %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    }
    if (boardskin == 2)
    {  
        printf("\n\n\n  1   2   3 ");
        printf("\n1 %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
        printf("\n -------|---");
        printf("\n2 %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
        printf("\n ---|-------");
        printf("\n3 %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    }
    if (boardskin == 3)
    {  
        printf("\n\n\n  1   2   3 ");
        printf("\n1 %c # %c # %c ", board[0][0], board[0][1], board[0][2]);
        printf("\n ###########");
        printf("\n2 %c # %c # %c ", board[1][0], board[1][1], board[1][2]);
        printf("\n ###########");
        printf("\n3 %c # %c # %c \n", board[2][0], board[2][1], board[2][2]);
    }
    if (boardskin == 4)
    {  
        printf("\n\n\n  1   2   3 ");
        printf("\n1 %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
        printf("\n jogodavelha");
        printf("\n2 %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
        printf("\n jogodavelha");
        printf("\n3 %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    }
    if (boardskin == 0)
    {  
        printf("\n\n\n#\n");
    }
}

int main()
{
    srand(time(0));
    int jogadores;
    int vitoria;
    int empate;
    int n_vitorias_jogador = 0;
    int n_vitorias_robo = 0;
    int n_vitorias_jogador_1 = 0;
    int n_vitorias_jogador_2 = 0;
    int n_empates = 0;
    int n_empates_2 = 0;
    int jogador_1_comeca;
    char jogar_novamente;
    while (1 == 1)
    {
        vitoria = 0;
        empate = 0;
        printf("\n\n\n\n\n\n\n\n\n");
        jogo_limpar_grade();
        jogadores = jogo_numero_jogadores();
        jogo_imprimir_grade();
        jogador_1_comeca = sorteio(2);
        if (jogadores == 1)
        {
            if (jogador_1_comeca == 0)
            {
                while (vitoria == 0 && empate == 0)
                {
                    jogo_jogar_robo(2);
                    vitoria = jogo_teste_vitoria();
                    empate = jogo_teste_empate();
                    if (vitoria != 0 || empate != 0)
                    continue;
                    jogo_jogar_jogador(1);
                    vitoria = jogo_teste_vitoria();
                    empate = jogo_teste_empate();
                    if (vitoria != 0 || empate != 0)
                    continue;
                }
            }
            else if (jogador_1_comeca == 1)
            {
                while (vitoria == 0 && empate == 0)
                {
                    jogo_jogar_jogador(1);
                    vitoria = jogo_teste_vitoria();
                    empate = jogo_teste_empate();
                    if (vitoria != 0 || empate != 0)
                    continue;
                    jogo_jogar_robo(2);
                    vitoria = jogo_teste_vitoria();
                    empate = jogo_teste_empate();
                    if (vitoria != 0 || empate != 0)
                    continue;
                }
            }
            if (vitoria == 1)
            {
                printf("Voce venceu!");
                n_vitorias_jogador++;
            }
            else if (vitoria == 2)
            {
                printf("O Robo venceu!");
                n_vitorias_robo++;
            }
            else if (empate == 1)
            {
                printf("O jogo empatou!");
                n_empates++;
            }
            printf("\nVitorias Jogador: %d\tVitorias Robo: %d\tEmpates: %d", n_vitorias_jogador, n_vitorias_robo, n_empates);
        }
        else if (jogadores == 2)
        {
            if (jogador_1_comeca == 0)
            {
                while (vitoria == 0 && empate == 0)
                {
                    jogo_jogar_jogador(2);
                    vitoria = jogo_teste_vitoria();
                    empate = jogo_teste_empate();
                    if (vitoria != 0 || empate != 0)
                    continue;
                    jogo_jogar_jogador(1);
                    vitoria = jogo_teste_vitoria();
                    empate = jogo_teste_empate();
                    if (vitoria != 0 || empate != 0)
                    continue;
                }
            }
            else if (jogador_1_comeca == 1)
            {
                while (vitoria == 0 && empate == 0)
                {
                    jogo_jogar_jogador(1);
                    vitoria = jogo_teste_vitoria();
                    empate = jogo_teste_empate();
                    if (vitoria != 0 || empate != 0)
                    continue;
                    jogo_jogar_jogador(2);
                    vitoria = jogo_teste_vitoria();
                    empate = jogo_teste_empate();
                    if (vitoria != 0 || empate != 0)
                    continue;
                }      
            }
            if (vitoria == 1)
            {
                printf("O jogador 1 venceu!");
                n_vitorias_jogador_1++;
            }
            else if (vitoria == 2)
            {
                printf("O jogador 2 venceu!");
                n_vitorias_jogador_2++;
            }
            else if (empate == 1)
            {
                printf("O jogo empatou!");
                n_empates_2++;
            }
            printf("\nVitorias Jogador 1: %d\tVitorias Jogador 2: %d\tEmpates: %d", n_vitorias_jogador_1, n_vitorias_jogador_2, n_empates_2);
        }
        printf("\nDeseja jogar novamente?     [s]     [n]\n");
        scanf("%c", &jogar_novamente);
        while (jogar_novamente != 's' && jogar_novamente != 'n')
        {
            scanf("%c", &jogar_novamente);
        }
        if (jogar_novamente == 's')
        {
            continue;
        }
        else if (jogar_novamente == 'n')
        {
            break;
        }            
    }
}
