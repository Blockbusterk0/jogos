/*                                                                                                                                                                                                            
          JJJJJJJJJJJ                                                                    CCCCCCCCCCCCC
          J:::::::::J                                                                 CCC::::::::::::C
          J:::::::::J                                                               CC:::::::::::::::C
          JJ:::::::JJ                                                              C:::::CCCCCCCC::::C
            J:::::J   ooooooooooo      ggggggggg   ggggg   ooooooooooo            C:::::C       CCCCCC
            J:::::J oo:::::::::::oo   g:::::::::ggg::::g oo:::::::::::oo         C:::::C              
            J:::::Jo:::::::::::::::o g:::::::::::::::::go:::::::::::::::o        C:::::C              
            J:::::jo:::::ooooo:::::og::::::ggggg::::::ggo:::::ooooo:::::o        C:::::C              
            J:::::Jo::::o     o::::og:::::g     g:::::g o::::o     o::::o        C:::::C              
JJJJJJJ     J:::::Jo::::o     o::::og:::::g     g:::::g o::::o     o::::o        C:::::C              
J:::::J     J:::::Jo::::o     o::::og:::::g     g:::::g o::::o     o::::o        C:::::C              
J::::::J   J::::::Jo::::o     o::::og::::::g    g:::::g o::::o     o::::o         C:::::C       CCCCCC
J:::::::JJJ:::::::Jo:::::ooooo:::::og:::::::ggggg:::::g o:::::ooooo:::::o          C:::::CCCCCCCC::::C
 JJ:::::::::::::JJ o:::::::::::::::o g::::::::::::::::g o:::::::::::::::o ......    CC:::::::::::::::C
   JJ:::::::::JJ    oo:::::::::::oo   gg::::::::::::::g  oo:::::::::::oo  .::::.      CCC::::::::::::C
     JJJJJJJJJ        ooooooooooo       gggggggg::::::g    ooooooooooo    ......         CCCCCCCCCCCCC
                                                g:::::g                                               
                                    gggggg      g:::::g                                               
                                    g:::::gg   gg:::::g                                               
                                     g::::::ggg:::::::g                                               
                                      gg:::::::::::::g                                                
                                        ggg::::::ggg                                                  
                                           gggggg                                                     



  ______     _ _                         _ _                   _   _  /\/|             _                                                 _             
 |  ____|   (_) |                       (_) |                 | \ | ||/\/             | |                                               (_)            
 | |____   ___| |_ ___   ___ _ __   ___  _| | ___ _ __ ___    |  \| | __ _  ___     __| | ___  ___  ___ __ _    __ _   _ __   __ _  __ _ _ _ __   __ _ 
 |  __\ \ / / | __/ _ \ / __| '_ \ / _ \| | |/ _ \ '__/ __|   | . ` |/ _` |/ _ \   / _` |/ _ \/ __|/ __/ _` |  / _` | | '_ \ / _` |/ _` | | '_ \ / _` |
 | |___\ V /| | ||  __/ \__ \ |_) | (_) | | |  __/ |  \__ \_  | |\  | (_| | (_) | | (_| |  __/\__ \ (_| (_| | | (_| | | |_) | (_| | (_| | | | | | (_| |
 |______\_/ |_|\__\___| |___/ .__/ \___/|_|_|\___|_|  |___(_) |_| \_|\__,_|\___/   \__,_|\___||___/\___\__,_|  \__,_| | .__/ \__,_|\__, |_|_| |_|\__,_|
                            | |                                                                     )_)               | |           __/ |              
                            |_|                                                                                       |_|          |___/               







*/

//COPYPASTE

//   printf("texto\n");
//   printf("[1] texto     [2] texto\n");
/*
switch (escolha)
    {
        case 1:
            texto
            break;
        case 2:
            texto
            break;
    }
*/
#include <stdio.h>


int opcao()
{
    int escolha;
    scanf("%d", &escolha);
    while (escolha < 1 || escolha > 2) {scanf("%d", &escolha);}
    return escolha;
}


int timer()
{

    for(int n=0; n <= 1000000000; n++)
    {
        if (n ==250000000 || n ==500000000 || n ==750000000)
        {
            printf(".");
        }

    }
    printf("\n");
}

int main()
{   
    int escolha_acordar, escolha_iracad, escolha_banho, escolha_tenis, escolha_hipotenusa, escolha_lugar, escolha_zap, escolha_pos, escolha16A, dia_ruim;
    printf("O despertador toca, voce esta na cama. Escolha [1] para levantar agora juntando a motivacao de 8 castores ou [2] para ficar mais 5 minutos na cama esperando que a tontura passe.\n");
    escolha_acordar = opcao();
    switch(escolha_acordar)
    {
        case 1:
            printf("Com muita forca de vontade, voce ascende de sua cama e move-se para o banheiro pra comecar sua rotina.\n");
            printf("Escolha: [1] ir ate a academia. [2] ficar em casa para estudar\n");
            escolha_iracad = opcao();
            switch(escolha_iracad)
            {
                case 1: 
                    printf("Voce foi ate a academia, contou quantos exercicios faltavam a cada serie que fazia, tomou 1/4 da agua que devia e fez a prancha toda torta, mas o dia ta pago. Voce volta pra casa.\n");
                    printf("Escolha: voce vai tomar banho?\n");
                    printf("[1] sim    [2] nao \n");
                    escolha_banho = opcao();
                    switch(escolha_banho)
                    {
                        case 1:
                            printf("Como voce eh limpinho.\n");
                            break;
                        case 2:
                            printf("Seu sujo. Eca\n");
                            break;
                    }
                    printf("Hora do pos treino. Coloque os ingredientes na ordem correta: [1] banana  [2] agua  [3] whey (digitar apenas 3 caracteres)\n");
                    int montagem;
                    while(montagem != 213)
                    {
                        scanf("%d", &montagem);
                    }
                    printf("Voce conseguiu. Estava saboroso.\n");
                    break;

                case 2: 
                    printf("Mais uma vez voce caiu no conto do vigario. Sua necessidade por dopamina e insaciavel, e voce gasta seu tempo em feeds futeis e nao chega nem a 5 metros de distancia do seu caderno\n");
                    printf("Sua manha foi uma porcaria e voce vai se arrepender amargamente disso.\n");
            }
            break;
        case 2:
            printf("Voce caiu no cliche do dorminhoco. Apos seu corpo entrar repentinamente em estado de alerta, voce em um movimento brusco liga a tela do celular e observa que se passaram noventa e sete minutos desde que soou o alarme. Nao resta escolha senao faltar a academia.\n");
            printf("Porem, voce ainda tem tempo de ir ate a parada de onibus.\n");
            break;
    }
    printf("Chegou a hora de ir a escola, digo, universidade. Escolha se voce vai com o tenis preto ou branco:\n");
    printf("[1] Preto     [2] Branco\n");
    escolha_tenis = opcao();
    switch (escolha_tenis)
    {
        case 1:
            printf("Pelo menos nao eh descalco ne.\n");
            break;
        case 2:
            printf("Boa escolha, essa cor fica melhor com as outras que voce esta vestindo.\n");
            break;
    }
    printf("Voce vai caminhando ate o ponto de onibus\n");
    timer();
    printf("E entra no onibus\n");
    printf("Voce vai ler o seu livro do momento ou ficar no celular?\n");
    printf("[1] Celular     [2] Livro\n");
    int escolha_livro = opcao();
    switch (escolha_livro)
    {
        case 1:
            if(escolha_iracad == 2)
            {
                printf("Ja nao ficou o suficiente no celular hoje? Voce alcanca 2h de tela ainda no comeco do dia. Vagabundo e foda.\n");
            }
            else
            {
                printf("Voce nao sentiu vontade de ler. Que pena. Tomara que tenha video bom no reels\n");
            }
            break;
        case 2:
            printf("Voce optou pela opcao bela e moral. Parabens intelectual, espero que as palavras que voce ler nao passem como o vento por sua cabeca oca\n");
            break;
    }
    printf("Voce foi ate o predio 16A pq eh manha e voce so tem calculo de manha. 30 minutos separam voce da aula.\n");
    timer();
    printf("Voce entra na sala, tem a aula, os gemeos competem quem tira mais duvida com o professor, voce se sente como em uma corda, qualquer desvio de atencao todo seu entendimento some.\n");
    if (escolha_iracad == 2 || escolha_livro == 1)
    {
        printf("Na verdade voce nem chegou a entender uma coisa sequer pq voce nao tirou a cabeca das migalhas de conteudo que voce ainda lembra do tempo gasto no celular hoje mais cedo.\n");
    }
    printf("Ate que chega o fim da aula e eh hora de ir pro RU.\n");
    printf("Voce quer atalhar pela hipotenusa da grama?\n");
    printf("[1] Sim     [2] Nao\n");
    escolha_hipotenusa = opcao();
    switch (escolha_hipotenusa)
    {
        case 1:
            if (escolha_tenis == 2)
            {
                printf("Parabens. Choveu ontem e agora cada passo que tu da teu tenis branco chega mais perto da cor da gasolina.\n");
            }
            else
            {
                printf("Justo. Teus amigos vao por ali entao meio que nao tem escolha\n");
            }
            break;
        case 2:
            if (escolha_tenis == 2)
            {
                printf("Ok. Um pouco de cuidado com seu tenis branco nao faz mal. Voce reencontra seus amigos assim que possivel\n");
            }
            else
            {
                printf("Uma escolha terrivel, nefasta, problematica. Assim que chega na curva, sobe ante sua consciencia a pessima decisao sua. Seria ridiculo sequer pensar em uma explicacao para essa decisao. Diante disso, voce toma rumo ao Cosmopolita e almoca um milkshake de 40 minutos com tempo de espera de ovomaltine.\n");
            }
            break;
    }
    if (escolha_hipotenusa == 2 && escolha_tenis == 1  && escolha_acordar == 2 && escolha_livro == 1)
    {
        printf("Depois de tomar suas 1000kcal no copo, voce comeca a repensar seus atos: Perdeu a manha dormindo e o resto no celular, faltou a academia, nao aprendeu nada em calculo e nao almocou com seus amigos. Que dia horrivel. \n");
        dia_ruim = 1;
    }
    else if(escolha_hipotenusa == 1 || escolha_hipotenusa == 2 && escolha_tenis == 2)
    {
        printf("Minigame do RU\n");
        printf("Aperte a sequencia correta das acoes: [1] Comer  [2] Pegar a e-carteira  [3] Lotar o prato de feijao  [4] Pegar a proteina  [5] Pegar os talheres  [6] Pegar a bandeja e prato  [7] Lotar o prato de arroz  [8] Procurar lugar\n");
        int ru;
        scanf("%d", &ru);
        if(ru == 26573481)
        {
            printf("Bom trabalho. Estas satisfeito.\n");
        }
        else
        {
            printf("Voce errou, mas vai servir.\n");
        }
        
    }
    printf("Tendo em vista que hoje eh sexta, em breve voce tera a aula menos esperada e mais evitada da semana. Geometria Analitica! Voce naturalmente eh capaz de conter toda sua emocao\n");
    printf("Escolha para onde voce vai agora. (Sao 13:05)\n");
    printf("[1] CT     [2] 16A\n");
    int escolha_after = opcao();
    switch (escolha_after)
    {
        case 1:
            printf("Voce decide ir para o CT. \"Mas a aula nao eh no 16A?\". Sim mas nao agora ne. Visto que hoje eh a ultima aula do PET no curso de Spotify, voce dirige-se ate a sala do ncc em busca de suas suadas 5 horas de acg. \n");
            break;
        case 2:
            printf("Vai fazer oq la agora?\n");
            printf("[1] dormir     [2] lembrar que nesse horario tem o curso do PET");
            if (escolha_tenis == 2 && escolha_hipotenusa == 1)
            {
                printf("     [3] Limpar o tenis branco\n");
                while (escolha16A < 1 || escolha16A > 3) {scanf("%d", &escolha16A);}
            }
            else
            {
                printf("\n");
                escolha16A = opcao();    
            }
            switch (escolha16A)
                {
                    case 1:
                        printf("Voce dorme.\n");
                        timer();
                        break;
                    case 2:
                        printf("Visto que hoje eh a ultima aula do PET no curso de Spotify, voce dirige-se ate a sala do ncc em busca de suas suadas 5 horas de acg.\n");
                        timer();
                        printf("Por sorte rapido o suficiente, entao voce nao perdeu a chamada.\n");
                        break;
                    case 3:
                        printf("Voce gasta meio rolo de papel e 5 litros de agua do banheiro, mas agora seus tenis foram de vaca malhada pra bege.\n");
                        break;
                    
                }      
            break;
    }
    printf("Chegou a hora de voce ver o fidelis.\n");
    printf("Voce vai sentar na frente ou no fundo?\n");
    printf("[1] frente     [2] fundo\n");
    escolha_lugar = opcao();
    switch (escolha_lugar)
    {
        case 1:
            printf("Voce escolheu sentar na frente, um lugar melhor pra tirar foto do quadro.\n");
            break;
        case 2:
            if (dia_ruim == 1)
            {
                printf("Voce pensa bem e muda de ideia ja que seu dia esta ruim de mais e talvez prestar atencao na aula melhore um pouco.\n");
                escolha_lugar = 1;
            }
            printf("Voce escolheu sentar no fundo, um lugar otimo pra qualquer coisa menos prestar atencao na aula.\n");
            break;
        
    }
    printf("~~~~~~~~\n");
    printf("Voce sente seu celular vibrar no seu bolso.\n");
    printf("[1] ver     [2] deixa pra la\n");
    escolha_zap = opcao();
    switch (escolha_zap)
    {
        case 1:
            printf("Eh uma mensagem no whatsapp do CC 2024.\n");

            break;
        case 2:
            printf("Quanta dedicacao com a aula. Parabens\n");
            timer();
            printf("Nao fosse sua curiosidade apos ouvir umas risadas sutis ao seu redor.\n");
            break;
    }
    printf("Acabaram de escrever um comentario funny sobre a aula que sera o inicio da ruina da sua concentracao na aula.\n");
    printf("Voce responde com outra coisa engracada\n");
    printf("Isso cria um efeito domino e esta cada vez mais dificil de esconder sua vontade de dar um berro rindo.\n");
    printf("Que junto a temperatura da sala beirando aos 30 graus te da um calor imenso\n");
    switch (escolha_banho)
    {
        case 1:
            printf("Sorte que voce tomou banho de manha, senao ja eras.\n");
            break;
        case 2:
            printf("E o porco que voce eh nao tomou banho de manha, entao a caatinga ta comecando a subir intensamente.\n");
            break;
        
    }
    printf("Obviamente agora nao tinha volta. O maximo que voce pode fazer eh torcer que o conteudo no quadro fosse facil.\n");
    if (dia_ruim == 1)
    {
        printf("Alem de ficar irritado com sua tendencia ridicula de perder o foco com tamanhas besteiras.\n");
    }
    switch (escolha_lugar)
    {
        case 1:
            printf("Por sorte voce sentou na frente, entao sem dificuldades tirou foto dos quadros\n");
            break;
        case 2:
            printf("E ja que voce sentou no fundo voce nao consegue tirar foto do quadro. Tomara que o Fidelios envie o moodle depois\n");
            break;
    }
    printf("A aula de geometria chega ao fim. Como eh sexta nao tem nada depois dela, entao voce pode escolher o que fazer\n");
    printf("[1] Ir para casa     [2] Ir estudar na biblioteca     [3] Tentar a sorte\n");
    scanf("%d", &escolha_after);
    while (escolha_after < 1 || escolha_after > 3) {scanf("%d", &escolha_after);}
    switch (escolha_after)
    {
        case 1:
            if (dia_ruim == 1)
            {
                printf("Finalmente o dia acabou, voce ja nao estava mais aguentando o lugar, indo rapidamente ate o terminal e esperando o seu onibus.");
                printf("O onibus chegou\n");
                timer();
                printf("\"Que caminho eh esse que o onibus esta fazendo\", voce se pergunta.\n");
                printf("Voce pegou o onibus errado\n");
                printf("Que os deuses do final de semana tenham misericordia de sua alma.\n");
                printf("Fim.\n");
            }
            else
            {
                printf("Sextou! Voce saca seu fantastico cartao de estudante e dirige-se ate o terminal na frente do husm, espera o onibus chegar e senta-se. Voce perde-se em sua imaginacao elaborando as melhores agendas possiveis para voce aproveitar ao maximo o sabado e o domingo, aquelas que voce, no fundo, sabe que nao vai seguir. Mas quem sabe, quem sabe, amanha seja um dia diferente.\n");
                if (escolha_tenis == 2 && escolha_hipotenusa == 1 && escolha16A != 3)
                {
                    printf("Mas uma das coisas que vai acontecer certamente sera voce limpar seu tenis, por obsequio.\n");
                } 
                printf("Fim\n");
            }
            break;
        case 2:
            
            printf("Voce vai ate a biblioteca do CT\n");
            printf("Ela esta em greve\n");
            printf("\"Meu deus que odio\", voce pensa\n");
            printf("Ai voce lembra que ali perto tem uma sala de estudos. Voce vai ate la, senta-se, e abre o caderno\n");
            timer();
            if ( escolha_livro == 2 )
            {
                printf("\"Chega de ler por hoje\", voce fala apos 3 palavras e um sinal grego\n");       
                printf("E vai de onibus ate sua casa.\n");
                printf("Porque palavras ouvidas pesam bem menos que um monte de letra escrita.\n");
                printf("Fim\n");    
            }
            else
            {
                printf("Passam algumas dezenas de minutos e voce paira seus olhos sobre algumas anotacoes e percebe que nao tem motivo de estar ali e nao em casa.\n");
                printf("Voce pensa consigo mesmo: Se ao menos eu pudesse voltar no tempo e optar por algo melhor do que vir ate aqui.\n");
                printf("Agora voce tem que esperar 20 minutos na parada.\n");
                printf("Aproveite o caminho de volta.\n");
                printf("Fim\n");
            }
            break;
        case 3:
            printf("Pois eh.\n");
            printf("Voce sabe que 100%% das chances que voce aproveita voce perde.\n");
            timer();
            printf("E tem aquela guria que voce esta ciente que so nesse curso voce vai ver gente do tipo dela.\n");
            printf("Mas ela eh mais bonitinha que as outras.\n");
            timer();
            if (dia_ruim != 1)
            {
                printf("Entao voce aposta suas fichas e da uma olhada ao seu redor, encontra ela, e vai falar com ela\n");
                printf("- oi - voce diz, e recebe de volta.\n");
                printf("- agora que acabou a aula eu ia ali no Cosmopolita. Eu queria saber se voce quer ir comigo?\n");
                if (escolha_banho == 2 )
                {
                    printf("- Na verdade eu tenho que ir pra casa agora mesmo, tenho bastante coisa pra fazer - ela diz.\n");
                    printf("Voce aceita e da tchau pra ela\n");
                    printf("Minutos depois voce nota que seu mau cheiro estava insuportavel, e pode ter sido isso o motivo de ter dado errado.\n");
                    printf("Agora voce aprendeu que higiene basica eh importante, e torce para que esse evento medonho nao influencie na opiniao alheia sobre voce.\n");
                    printf("Fim\n");
                }
                else
                {
                    printf("- Ah, boa ideia, eu topo - ela diz.\n");
                    printf("Entao voces dois vao andando ate la, trocando ideias e, ao menos voce, alimentando a ilusao de que voce esta falando com um anjo caido.\n");
                    printf("Se vai dar certo?\n");
                    printf("O que vale eh o aprendizado.\n");
                    printf("Fim\n");
                }
            }
            else
            {
                printf("Naaaah.\n");
                printf("Seu dia nao foi bom. Com essa baixa estima que voce esta ate um poste vai ficar entediado com voce.\n");
                printf("Entao voce segue com seu coracao solitario apertado, mas nunca vai desistir de faze-lo, algum dia, ter seu amor correspondido.\n");
                printf("Fim\n");
            }
            break;
    }
} 

/*
   ___  _        _              _                         _                    _ 
  / _ \| |__ _ _(_)__ _ __ _ __| |___   _ __  ___ _ _    (_)___  __ _ __ _ _ _| |
 | (_) | '_ \ '_| / _` / _` / _` / _ \ | '_ \/ _ \ '_|   | / _ \/ _` / _` | '_|_|
  \___/|_.__/_| |_\__, \__,_\__,_\___/ | .__/\___/_|    _/ \___/\__, \__,_|_| (_)
                  |___/                |_|             |__/     |___/            
*/