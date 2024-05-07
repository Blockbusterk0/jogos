/*
 ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄     ▄▄▄▄▄▄▄▄▄▄▄      
▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌   ▐░░░░░░░░░░░▌        /$$                      /$$      
 ▀▀▀▀▀█░█▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀▀▀▀▀▀█░▌   ▐░█▀▀▀▀▀▀▀▀▀        |  $$                    /$$/      
      ▐░▌    ▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌          ▐░▌   ▐░▌                  \  $$      /$$$$$$     /$$/         
      ▐░▌    ▐░▌       ▐░▌▐░▌ ▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌          ▐░▌   ▐░▌                   \  $$    /$$__  $$   /$$/        
      ▐░▌    ▐░▌       ▐░▌▐░▌▐░░░░░░░░▌▐░▌       ▐░▌ ▄▄▄▄▄▄▄▄▄█░▌   ▐░▌                    \  $$  | $$  \ $$  /$$/         
      ▐░▌    ▐░▌       ▐░▌▐░▌ ▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌   ▐░▌                     \  $$ | $$  | $$ /$$/          
      ▐░▌    ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀▀▀    ▐░▌                      \  $$|  $$$$$$//$$/           
 ▄▄▄▄▄█░▌    ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄  ▄ ▐░█▄▄▄▄▄▄▄▄▄              \__/ \______/|__/            
▐░░░░░░░▌    ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌▐░░░░░░░░░░░▌     
 ▀▀▀▀▀▀▀      ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀  ▀▀▀▀▀▀▀▀▀▀▀      





  ______     _ _                         _ _                   _   _  /\/|             _                                                 _             
 |  ____|   (_) |                       (_) |                 | \ | ||/\/             | |                                               (_)            
 | |____   ___| |_ ___   ___ _ __   ___  _| | ___ _ __ ___    |  \| | __ _  ___     __| | ___  ___  ___ __ _    __ _   _ __   __ _  __ _ _ _ __   __ _ 
 |  __\ \ / / | __/ _ \ / __| '_ \ / _ \| | |/ _ \ '__/ __|   | . ` |/ _` |/ _ \   / _` |/ _ \/ __|/ __/ _` |  / _` | | '_ \ / _` |/ _` | | '_ \ / _` |
 | |___\ V /| | ||  __/ \__ \ |_) | (_) | | |  __/ |  \__ \_  | |\  | (_| | (_) | | (_| |  __/\__ \ (_| (_| | | (_| | | |_) | (_| | (_| | | | | | (_| |
 |______\_/ |_|\__\___| |___/ .__/ \___/|_|_|\___|_|  |___(_) |_| \_|\__,_|\___/   \__,_|\___||___/\___\__,_|  \__,_| | .__/ \__,_|\__, |_|_| |_|\__,_|
                            | |                                                                     )_)               | |           __/ |              
                            |_|                                                                                       |_|          |___/               

















*/





#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int pos_atual_player = 1;
int pos_atual_alvo0 = 10;
int pos_atual_alvo1 = 20;
int pos_atual_alvo2 = 30;
int pos_atual_alvo3 = 40;
int pos_atual_alvo4 = 50;
char continuar;
int vidas = 5;
int erro;
char terreno[100];
char pavimento = '_';
char p1[5][2][32];

void timer(float a)
{
    int i;
    for (i = 1; i < a*500000000; i++)
    {

    }
}

int sorteio(int limite)
{
    srand(time(0));
    int dado = rand() % limite ;
    return dado;
}

void spawn_alvo(int onde, char alvo)
{
    terreno[onde] = alvo;
}

void tela_jogo(float a)
{
    printf("\n\n\n\n\n\n%s", terreno);
    timer(a);
}

void mover_player(int casa)
{
    terreno[pos_atual_player-1] = pavimento;
    terreno[pos_atual_player] = pavimento;
    terreno[pos_atual_player+1] = pavimento;
    terreno[casa-1] = '\\';
    terreno[casa] = 'o';
    terreno[casa+1] = '/';
    pos_atual_player = casa;
    tela_jogo(0.25);
}

void mover_player_auto(int ate_onde)
{
    while (pos_atual_player < ate_onde)
    {
        mover_player(pos_atual_player+1);
        timer(0.25);
    }
}

void dialogo(char nome[32], char texto[128])
{
    printf("\n%s: %s\t\t\tAperte <enter> para continuar.", nome, texto);
    scanf("%c", &continuar);
}

void animacao_ataque()
{
    int repeticoes = 1;
    char inimigo = terreno[pos_atual_player + 3];
    tela_jogo(1);
    while (repeticoes <= 2)
    {
        terreno[pos_atual_player-1] = pavimento;
        terreno[pos_atual_player] = pavimento;
        terreno[pos_atual_player+1] = pavimento;
        terreno[pos_atual_player + 2] = '\\';
        terreno[pos_atual_player + 3] = 'o';
        terreno[pos_atual_player + 4] = '/';
        tela_jogo(1);;
        terreno[pos_atual_player-1] = '\\';
        terreno[pos_atual_player] = 'o';
        terreno[pos_atual_player+1] = '/';
        terreno[pos_atual_player + 2] = pavimento;
        terreno[pos_atual_player + 3] = inimigo;
        terreno[pos_atual_player + 4] = pavimento;
        tela_jogo(1);
        repeticoes++;
    }
    terreno[pos_atual_player-1] = pavimento;
    terreno[pos_atual_player] = pavimento;
    terreno[pos_atual_player+1] = pavimento;
    terreno[pos_atual_player + 2] = '\\';
    terreno[pos_atual_player + 3] = 'o';
    terreno[pos_atual_player + 4] = '/';
    tela_jogo(1);
    pos_atual_player += 3;
    
    
}

void animacao_ataque_boss()
{
    tela_jogo(1);
    terreno[pos_atual_player+1] = '-';
    terreno[pos_atual_player + 2] = '-';
    terreno[pos_atual_player + 4] = '>';
    terreno[pos_atual_player + 6] = '<';
    tela_jogo(1);
    terreno[pos_atual_player+1] = '/';
    terreno[pos_atual_player + 2] = pavimento;
    terreno[pos_atual_player + 4] = 'o';
    terreno[pos_atual_player + 6] = 'o';
    tela_jogo(1);
}

int ataque(char pergunta[128], char resposta_correta[16])
{
    char resposta[16];
    printf("\nPara atacar responda corretamente: %s\n", pergunta);
    fgets(resposta, 16, stdin);
    while (strnicmp(resposta_correta, resposta, strlen(resposta_correta)) != 0)
    {
        printf("Errou! ");
        timer(1);
        srand(time(NULL));
        erro = rand()%6;
        switch(erro)
        {
            
            case 0:
                printf("Sua espada escorrega da sua mao e voce toma um socao na cara. ");
                break;
            case 1:
                printf("Voce tropeca e bate a cara no chao. O inimigo ri de voce. ");
                break;
            case 2:
                printf("Voce se assusta e nao desvia o ataque do inimigo. ");
                break;
            case 3:
                printf("Voce se distrai com um passaro voando e leva um chute. ");
                break;
            case 4:
                printf("Por mais incrivel que seja voce conseguiu se acertar com a espada.");
                break;
            case 5:
                printf("Voce esqueceu de sacar sua espada a tempo e apanhou a sangue frio. ");
                break;
        }
        vidas--;
        timer(1);
        printf("Voce perdeu 1 vida.\tVidas: %d/5", vidas);
        if(vidas > 0)
        {
            timer(1);
            printf("\nTente novamente: %s\n", pergunta);
            fgets(resposta, 16, stdin);
        }
        else
        {
            timer(1);
            printf("\nVoce morreu. Deseja jogar de novo? (s/n)\n");
            char escolha;
            scanf("%c", &escolha);
            while ( escolha != 's' && escolha != 'n')
            scanf("%c", &escolha);
            if (escolha == 's')
                return 1;
            else if (escolha == 'n')
                return -1;
            
        }
    }
    printf("Voce acertou! ");
    timer(1);
    return 0;

}

int ataque_int(char pergunta[128], int resposta_correta)
{
    int resposta;
    printf("\nPara atacar responda corretamente: %s\n", pergunta);
    scanf("%d", &resposta);
    while (resposta_correta != resposta)
    {
        printf("Errou! ");
        timer(1);
        srand(time(NULL));
        erro = rand()%6;
        switch(erro)
        {
            
            case 0:
                printf("Sua espada escorrega da sua mao e voce toma um socao na cara. ");
                break;
            case 1:
                printf("Voce tropeca e bate a cara no chao. O inimigo ri de voce. ");
                break;
            case 2:
                printf("Voce se assusta e nao desvia o ataque do inimigo. ");
                break;
            case 3:
                printf("Voce se distrai com um passaro voando e leva um chute. ");
                break;
            case 4:
                printf("Por mais incrivel que seja voce conseguiu se acertar com a espada.");
                break;
            case 5:
                printf("Voce esqueceu de sacar sua espada a tempo e apanhou a sangue frio. ");
                break;
        }
        vidas--;
        timer(1);
        printf("Voce perdeu 1 vida.\tVidas: %d/5", vidas);
        if(vidas > 0)
        {
            resposta_correta = resposta_correta;
            timer(1);
            printf("\nTente novamente: %s\n", pergunta);
            scanf("%d", &resposta);
        }
        else
        {
            timer(1);
            printf("\nVoce morreu. Deseja jogar de novo? (s/n)\n");
            char escolha;
            scanf("%c", &escolha);
            while ( escolha != 's' && escolha != 'n')
            scanf("%c", &escolha);
            if (escolha == 's')
                return 1;
            else if (escolha == 'n')
                return -1;
            
        }
    }
    printf("Voce acertou! ");
    timer(1);
    return 0;

}

void main()
{
    int repetir = 1;
    char pergunta_atual[128];
    char resposta_correta_atual[16];
    while (repetir == 1)
    {
        repetir = 0;
        vidas = 5;
        pos_atual_player = 1;
        for (int i = 0; i<70; i++)
        terreno[i] = pavimento;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nBem vindo ao jogo2.c\nAperte <enter> para jogar.");
        scanf("%c", &continuar);
        mover_player(1);
        spawn_alvo(pos_atual_alvo0, 'M');
        spawn_alvo(pos_atual_alvo1, 'A');
        spawn_alvo(pos_atual_alvo2, 'o');
        spawn_alvo(pos_atual_alvo3, 'X');
        spawn_alvo(pos_atual_alvo4, 'T');
        mover_player_auto(pos_atual_alvo0-3);
        dialogo("Voce", "Aaaah! uma aranha!!!!");
        dialogo("Aranha", "Oh, valente aventureiro, cuja curiosidade o conduz aos reconditos da natureza...");
        dialogo("Aranha", "permita-me, como aranha, apresentar-lhe meu humilde dominio.");
        dialogo("Aranha", "Bem-vindo a minha abobada sedosa, tecida com os fios de minh-");
        dialogo("Voce", "CHEGA!");
        switch(sorteio(5))
        {
            case 0:
            strcpy(pergunta_atual, "3x+5=11");
            strcpy(resposta_correta_atual, "2");
            break;
            case 1:
            strcpy(pergunta_atual, "2x-3=7");
            strcpy(resposta_correta_atual, "5");
            break;
            case 2:
            strcpy(pergunta_atual, "5x+8=18");
            strcpy(resposta_correta_atual, "2");
            break;
            case 3:
            strcpy(pergunta_atual, "3x-6=15");
            strcpy(resposta_correta_atual, "7");
            break;
            case 4:
            strcpy(pergunta_atual, "x+4=10");
            strcpy(resposta_correta_atual, "6");
            break;
        }
        repetir = ataque(pergunta_atual, resposta_correta_atual);
        if (repetir == -1)
        break;
        else if (repetir == 1)
        continue;
        animacao_ataque();
        mover_player_auto(pos_atual_alvo1-3);
        dialogo("Voce", "Identifique-se, criatura!");
        dialogo("???", "Sou uma placa de piso molhado amarela cuidado piso molhado");
        dialogo("Voce", "Mas o programador nao colocou agua no jogo entao como estaria o piso molhado?");
        dialogo("Placa de piso molhado", "Nao tenho capacidade de pensar nessa hipotese.");
        dialogo("Placa de piso molhado", "Eh bom voce ter afiado sua espada hoje, senao nao iras passar por mim!");
        switch(sorteio(5))
        {
            case 0:
            strcpy(pergunta_atual, "escreva atacar");
            strcpy(resposta_correta_atual, "atacar");
            break;
            case 1:
            strcpy(pergunta_atual, "escreva ataque");
            strcpy(resposta_correta_atual, "ataque");
            break;
            case 2:
            strcpy(pergunta_atual, "escreva espada");
            strcpy(resposta_correta_atual, "espada");
            break;
            case 3:
            strcpy(pergunta_atual, "escreva atacante");
            strcpy(resposta_correta_atual, "atacante");
            break;
            case 4:
            strcpy(pergunta_atual, "escreva atacador");
            strcpy(resposta_correta_atual, "atacador");
            break;
        }
        repetir = ataque(pergunta_atual, resposta_correta_atual);
        if (repetir == -1)
        break;
        else if (repetir == 1)
        continue;
        animacao_ataque();
        mover_player_auto(pos_atual_alvo2-3);
        dialogo("Voce", "O que seria uma figura no formato de \"o\" no meio de meu caminho?");
        dialogo("Pedra", "...");
        dialogo("Voce", "*cutuca a pedra*");
        dialogo("Pedra", "*bocejo* ah, oi aventureiro, precisa de algo?");
        dialogo("Voce", "Sim, seguir meu caminho, mas voce esta inconvenientemente parada no meio dele.");
        dialogo("Pedra", "Tenha mais respeito senhor desconhecido, sabes quantos anos ja estou nesse planeta?");
        dialogo("Voce", "... nao.");
        dialogo("Pedra", "Nao se preocupe, se voce descobrir, *entrega a voce um papel*");
        dialogo("Pedra", "Posso rolar alguns centimentros para o lado e voce passara.");
        dialogo("Pedra", "E para manter o codigo mais simples, eu te deixo usar a espada naquele tronco ali.");
        dialogo("Pedra", "So tenha cuidado que ele bate de volta, mas quando voce acertar a charada ele para.");
        switch(sorteio(5))
        {
            case 0:
            strcpy(pergunta_atual, "quanto eh 13^2 + 26?");
            strcpy(resposta_correta_atual, "195");
            break;
            case 1:
            strcpy(pergunta_atual, "quanto eh 10^2 + 95 + 1?");
            strcpy(resposta_correta_atual, "196");
            break;
            case 2:
            strcpy(pergunta_atual, "quanto eh 14^2 + 1?");
            strcpy(resposta_correta_atual, "197");
            break;
            case 3:
            strcpy(pergunta_atual, "quanto eh 11^2 + 77?");
            strcpy(resposta_correta_atual, "198");
            break;
            case 4:
            strcpy(pergunta_atual, "quanto eh 12^2 + 55?");
            strcpy(resposta_correta_atual, "199");
            break;
        }
        repetir = ataque(pergunta_atual, resposta_correta_atual);
        if (repetir == -1)
        break;
        else if (repetir == 1)
        continue;
        dialogo("Pedra", "Bom trabalho! Cumprirei minha promessa.");
        terreno[pos_atual_alvo2] = '_';
        timer(1);
        mover_player_auto(pos_atual_alvo3-3);
        dialogo("Voce", "Quem eh voce X gigante?");
        dialogo("???", "De fato eu me pareco com um X gigante, mas na verdade eu sou um robo com bracos e pernas enormes.");
        dialogo("robo", "BEEP BOP.");
        dialogo("robo", "So a sorte vai poder ajudar voce agora, pois minha bateria esta muito bem escondida.");
        dialogo("Voce", "Ta.");
        printf("Digite a letra 'b' para braco ou 'p' para perna, em seguida 'e' para esquerdo ou 'd' para direito, e aperte <enter> (\"ex: be\")\n");
        switch(sorteio(4))
        {
            case 0:
            strcpy(pergunta_atual, "onde voce vai acertar?");
            strcpy(resposta_correta_atual, "be");
            break;
            case 1:
            strcpy(pergunta_atual, "onde voce vai acertar?");
            strcpy(resposta_correta_atual, "bd");
            break;
            case 2:
            strcpy(pergunta_atual, "onde voce vai acertar?");
            strcpy(resposta_correta_atual, "pe");
            break;
            case 3:
            strcpy(pergunta_atual, "onde voce vai acertar?");
            strcpy(resposta_correta_atual, "pd");
            break;
        }
        repetir = ataque(pergunta_atual, resposta_correta_atual);
        if (repetir == -1)
        break;
        else if (repetir == 1)
        continue;
        animacao_ataque();
        mover_player_auto(pos_atual_alvo4-3);
        dialogo("Voce", "O robo ali atras era grande, mas essa coisa tem uns 40 metros!");
        dialogo("???", "38 para ser exato. Sou o Cristo Redentor, literalmente!");
        dialogo("Voce", "Que doidera.");
        dialogo("Voce", "Quem te colocou aqui?");
        dialogo("Cristo Redentor", "Os humanos.");
        dialogo("Voce", "Que?");
        dialogo("Voce", "Bem, eu tenho que seguir meu caminho.");
        dialogo("Cristo Redentor", "Tu nao pode.");
        dialogo("Voce", "Como assim?");
        dialogo("Cristo Redentor", "Eu nao deixo.");
        dialogo("Voce", "Tu eh literalmente uma estatua.");
        dialogo("Voce", "E se eu simplesmente passar pelo teu lado?");
        dialogo("Cristo Redentor", "...");
        dialogo("Cristo Redentor", "Nao, nananinanao. Nao pode.");
        dialogo("Voce", "Vai ficar inventando regra agora entao? Nao me resta escolha.");
        switch(sorteio(5))
        {
            case 0:
            strcpy(pergunta_atual, "Qual o primeiro nome do descobridor do Brasil escrito ao contrario?");
            strcpy(resposta_correta_atual, "ordep");
            break;
            case 1:
            strcpy(pergunta_atual, "Quais as iniciais dos paises que eliminaram o Brasil nas copas de 14, 18 e 22? (escreva tudo junto)");
            strcpy(resposta_correta_atual, "abc");
            break;
            case 2:
            strcpy(pergunta_atual, "Qual estado mais ao norte do Brasil?");
            strcpy(resposta_correta_atual, "Roraima");
            break;
            case 3:
            strcpy(pergunta_atual, "Em que ano o Brasil se tornou republica?");
            strcpy(resposta_correta_atual, "1889");
            break;
            case 4:
            strcpy(pergunta_atual, "Qual o ano da constituicao atual do Brasil?");
            strcpy(resposta_correta_atual, "1988");
            break;
        }
        repetir = ataque(pergunta_atual, resposta_correta_atual);
        if (repetir == -1)
        break;
        else if (repetir == 1)
        continue;
        animacao_ataque();
        mover_player_auto(61);
        dialogo("Voce", "Eh isso? Cheguei ao fim?");
        dialogo("...", "...");
        dialogo("...", "...");
        dialogo("???", "NAO POR MUITO TEMPO!!");
        dialogo("???", "ACHASTE QUE O JOGO NAO TERIA UMA BATALHA FINAL?");
        dialogo("???", "MUUUAAAAAAAAAAHAHAHAHAHAHAAAAA");
        dialogo("???", "PREPARE-SE, MORTAL!");
        dialogo("???", "AI");
        dialogo("???", "VOU");
        dialogo("???", "EU!");
        tela_jogo(1);
        terreno[64] = '[';
        terreno[65] = 'o';
        terreno[66] = '_';
        terreno[67] = 'o';
        terreno[68] = ']';
        tela_jogo(1);
        repetir = ataque("Por quantos personagens voce passou antes de chegar aqui (por extenso)?", "cinco");
        if (repetir == -1)
        break;
        else if (repetir == 1)
        continue;
        animacao_ataque_boss();
        repetir = ataque("Digite as letras que representavam eles da direita para a esquerda", "TXoAM");
        if (repetir == -1)
        break;
        else if (repetir == 1)
        continue;
        animacao_ataque_boss();
        repetir = ataque_int("Com quantas vidas voce chegou a esta batalha? (use apenas algarismos)", vidas);
        if (repetir == -1)
        break;
        else if (repetir == 1)
        continue;
        animacao_ataque_boss();
        dialogo("Voce", "Hora do ataque especial!");
        repetir = ataque("escreva teleporte para teleportar magicamente na posicao estrategica:", "teleporte");
        if (repetir == -1)
        break;
        else if (repetir == 1)
        continue;
        terreno[65] = '@';
        terreno[66] = '_';
        terreno[67] = '@';
        mover_player(50);
        dialogo("Voce", "AGORA!");
        repetir = ataque("qual o limite, quando x se aproxima de 0, de (sen(x)/x)?", "1");
        if (repetir == -1)
        break;
        else if (repetir == 1)
        continue;
        tela_jogo(1);
        terreno[pos_atual_player+1] = '}';
        tela_jogo(1);
        terreno[pos_atual_player+2] = '-';
        tela_jogo(0.25);
        for (int i = pos_atual_player+3; i < 64; i++)
        {
            terreno[i-1] = pavimento;
            terreno[i] = '-';
            tela_jogo(0.25);
        }
        terreno[63] = pavimento;
        terreno[65] = '>';
        terreno[66] = '_';
        terreno[67] = '<';
        tela_jogo(1);
        terreno[65] = '@';
        terreno[66] = '_';
        terreno[67] = '@';
        tela_jogo(1);
        terreno[pos_atual_player+1] = '/';
        tela_jogo(1);
        dialogo("Voce", "FINISH HIM!");
        repetir = ataque("Qual cor visivel tem maior comprimento de onda?", "vermelho");
        if (repetir == -1)
        break;
        else if (repetir == 1)
        continue;
        tela_jogo(1);
        terreno[pos_atual_player+1] = ')';
        tela_jogo(0.5);
        terreno[pos_atual_player+1] = '/';
        terreno[pos_atual_player+2] = ')';
        tela_jogo(0.5);
        for (int i = pos_atual_player+3; i < 64; i++)
        {
            terreno[i-1] = pavimento;
            terreno[i] = ')';
            tela_jogo(0.25);
        }
        for (int i = 64; i < 80; i++)
        {
            if (i<=70)
            terreno[i-1] = pavimento;
            else
            terreno[i-1] = ' ';
            terreno[i] = ')';
            terreno[i+1] = '[';
            terreno[i+2] = 'x';
            terreno[i+3] = '_';
            terreno[i+4] = 'x';
            terreno[i+5] = ']';
            tela_jogo(0.25);
        }
        terreno[82] = '#';
        tela_jogo(0.25);
        terreno[81] = '#';
        terreno[83] = '#';
        terreno[82] = ' ';
        tela_jogo(0.25);
        terreno[80] = '#';
        terreno[84] = '#';
        terreno[81] = ' ';
        terreno[83] = ' ';
        tela_jogo(0.25);
        terreno[79] = '#';
        terreno[85] = '#';
        terreno[84] = ' ';
        terreno[80] = ' ';
        tela_jogo(0.25);
        terreno[79] = ' ';
        terreno[85] = ' ';
        tela_jogo(0.25);
        mover_player_auto(pos_atual_player+2);
        for (int i = 0; i < 12; i++)
        {
            char texto[] = {'v','o','c','e',' ','v','e','n','c','e','u','!'};
            terreno[pos_atual_player-1] = texto[i];
            terreno[pos_atual_player] = '\\';
            terreno[pos_atual_player+1] = 'o';
            terreno[pos_atual_player+2] = '/';
            pos_atual_player += 1;
            tela_jogo(0.5);
        }
        mover_player_auto(67);
        timer(2);
        for (int i = 2; i < 70; i+=3)
        {
            terreno[i] = ' ';
        }
        tela_jogo(0.5);
        for (int i = 1; i < 70; i+=3)
        {
            terreno[i] = ' ';
        }
        tela_jogo(0.5);
        for (int i = 0; i < 70; i+=3)
        {
            terreno[i] = ' ';
        }
        tela_jogo(0.5);
        printf("\nObrigado por jogar! Dica: As batalhas tem diversas perguntas escolhidas aleatoriamente, entao considere jogar de novo!");
        break;
    }

}