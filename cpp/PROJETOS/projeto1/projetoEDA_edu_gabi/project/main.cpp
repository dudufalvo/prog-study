#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <sys/time.h>
#define clrscn() cout << "\e[1;1H\e[2J"; // Para versao macOS.

#define MAX 21

using namespace std;

string forca_display[8] = {R"(
                ________
               |        |
                        |
                        |
                        |
                        |
                        |
                        |
              ...........)",
                               R"(
                ________
               |        |
               O        |
                        |
                        |
                        |
                        |
                        |
              ...........)",
                               R"(
                ________
               |        |
               O        |
               |        |
                        |
                        |
                        |
                        |
              ...........)",
                               R"(
                ________
               |        |
               O        |
              \|        |
                        |
                        |
                        |
                        |
              ...........)",
                               R"(
                ________
               |        |
               O        |
              \|/       |
                        |
                        |
                        |
                        |
              ...........)",
                               R"(
                ________
               |        |
               O        |
              \|/       |
               |        |
                        |
                        |
                        |
              ...........)",
                               R"(
                ________
               |        |
               O        |
              \|/       |
               |        |
              /         |
                        |
                        |
              ...........)",
                               R"(
                ________
               |        |
               O        |
              \|/       |
               |        |
              / \       |
                        |
                        |
              ...........)"};

// criacao das estruturas e definicao dos seus membros.
struct timeval before, after;
struct saveJogo {
    char palavra_C[MAX];
    char tema_C[MAX];
    char nome_C[MAX];
    bool emJogo;
    char letrasCertas[MAX];
    char erros[7];
    int tentativas;
    int acertos;
    int pontos;
    int indexPalavrasJogadas[24];
    int palavrasJogadas;
    int tamanho_palavra;
    int dificuldade;
    int modo;
    double tempo;
};


// criacao das classes e definicao dos seus membros.
class Jogo {
private:
    string palavra, tema, nome;
    bool emJogo;
    char letrasCertas[MAX];
    char erros[7];
    int tentativas;
    int acertos;
    int pontos;
    int indexPalavrasJogadas[24];
    int palavrasJogadas;
    int tamanho_palavra;
    int dificuldade;
    int modo;
    double tempo;

public:
    Jogo();
    void menu();
    void novo_jogo();
    void carregar_jogo();
    void salvarjogo();
    void salvarRanking();
    int jogo();
    void avanca_jogo();
    int modo_jogo();
    void historico();
    double printTime(timeval, timeval, int);
    void sair();
    friend class listaRank;
};

class ranking{
    public:
    char nome_C[MAX];
    int pontos;
    ranking *proximo;
};

class listaRank{
    ranking *cabeca;
public:
    listaRank(){cabeca = nullptr;}
    ~listaRank();
    void insereItem(ranking &r);
    void atualizaJogador(int index, Jogo &ultimoJogo);
    void escreveFicheiro();
};

void listaRank::atualizaJogador(int index, Jogo &ultimoJogo){
    /* método que atualiza a pontuação de um jogador ja existente */

    ranking *atual = cabeca;

    if(cabeca == nullptr){
        cout << "SEM RANKINGS" << endl;
    }else{
        while(atual != nullptr){
            
            if(index == 0){
                cout << atual->nome_C << atual->pontos;
                atual->pontos = atual->pontos + ultimoJogo.pontos;
            }
            index--;

            atual = atual->proximo;
        }
    }
}

void listaRank::escreveFicheiro(){
    /* método que escreve no ficheiro binário 
    toda a informação armazenada na linked list */

    ranking *atual = cabeca;
    ranking aux;
    
    ofstream salvarRank;
    salvarRank.open("Ranking.dat", ios::binary | ios::trunc);
    salvarRank.close();
    salvarRank.open("Ranking.dat", ios::binary | ios::app);

    if(!salvarRank.is_open()){
        cout << "ERRO SALVANDO O RANK - ERROR 1" << endl;
        exit(0);
    }

    while(atual != nullptr){
        aux.pontos = atual->pontos;
        strcpy(aux.nome_C , atual->nome_C);
        salvarRank.write((char *) &aux, sizeof(aux));
        atual = atual->proximo;
    }

    salvarRank.close();   
}

listaRank::~listaRank(){
    /* destrutor da linked list */

    ranking *atual, *proximo;
    
    atual = cabeca;
    while(atual != nullptr){
        proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

}

void listaRank::insereItem(ranking &r){
    /* método que insere um jogador 
    com sua pontuação na linked list */

    ranking *novo = new ranking;
    ranking *atual;

    strcpy(novo->nome_C, r.nome_C);
    novo->pontos = r.pontos;
    novo->proximo = nullptr;

    if(cabeca == nullptr ) cabeca = novo;
    else{
        atual = cabeca;
        while(atual->proximo != nullptr) atual = atual -> proximo;
        atual->proximo = novo;
    }

}

Jogo::Jogo(){
    /* construtor por omissão - inicializa os atributos para 
    serem atualizados no novo_jogo ou carregados em carregar_jogo*/

    palavra = tema = nome =  "";
    emJogo = false;
    tentativas = acertos = pontos = tamanho_palavra = palavrasJogadas = tempo = 0;
    modo = 1;
}

void Jogo :: menu() {
    /* método que imprime o menu inicial e chama 
    outro método baseado na escolha do usuário*/
    
    // declaracao da variavel "escolha"
    int escolha;
    char escolha_y_n;

    do{
        //system("CLS");
        clrscn(); // Para versao macOS
        
        // impressao do da parte visual do menu
        for(int i=0; i<40; i++) cout << "=";
        cout << endl;
        cout << setw(27) << "*JOGO DA FORCA*";
        cout << forca_display[7] << endl;
        cout << setw(25) << "1-NOVO JOGO" << endl;
        cout << setw(27) << "2-RETOMAR JOGO" << endl;
        cout << setw(27) << "3-MODO DE JOGO" << endl;
        cout << setw(25) << "4-RANKINGS" << endl;
        cout << setw(23) << "5-SAIR" << endl;
        for(int i=0; i<40; i++) cout << "=";
        cout << endl;

        // pedimos ao usuário escolher uma opção entre as quatro
        cout << "SELECIONE UMA OPCAO ENTRE 1 E 5: ";
        cin >> escolha; // atribuimos a resposta na variável

        if(escolha == 1){
            // chamamos o novo_jogo() para coleta de dados para iniciar 
            if(!emJogo) {
                novo_jogo();
                jogo();
            }
            
            else {
                // avisamsos caso o jogador esteja em um jogo
                cout << "HA UM JOGO EM ANDAMENTO. DESEJA INICIAR UM NOVO JOGO MESMO ASSIM? [y/n] ";
                cin >> escolha_y_n;
                escolha_y_n = toupper(escolha_y_n);
                if(escolha_y_n=='Y') {
                    novo_jogo();
                    jogo();
                }
                else menu();
            }
        }
        else if(escolha == 2){
            if(emJogo){
                carregar_jogo();
                jogo();
            }else{
                cout << "NAO POSSUI JOGO EM ANDAMENTO!!" << endl;
                cout << "ENTRE QUALQUER COISA PRA VOLTAR A ESCOLHER" << endl;
                cin >> escolha_y_n;

            }
        }
        else if(escolha == 3){
            modo = modo_jogo();
        }
        else if(escolha == 4){
            historico();
        }
        else if(escolha == 5){
            sair();
        }

        // resetamos escolha para quando menu() for chamado novamente
        escolha = 0;
    } while(escolha<1 || escolha>5);
    // loop caso a escolha não esteja no intervalo [1,4]

}

void Jogo::novo_jogo(){
    /* método que cria um novo jogo, pergunta ao 
       usuário o tema do jogo, determina aleatoriamente 
       a palavra do jogo, armazena o nome do jogador e 
       inicializa as variaveis pontos e tentativas a zero*/
    
    int i, escolha_tema;
    char string_C[MAX];
    ifstream coletaPalavra;
    time_t t;
    srand((unsigned) time(&t));

    // garantimos que os atributos estão sendo inicializados para não serem sobreescrevidos
    palavra = tema = nome =  "";
    tentativas = pontos = tamanho_palavra = palavrasJogadas = acertos = tempo = 0;
    for(int i=0; i<MAX; i++) letrasCertas[i] = '\0';

    // caso o modo seja 'basico' ou 'medio'
    while((escolha_tema < 1 || escolha_tema > 3) && modo != 1){
        system("CLS"); // limpa o terminal
        clrscn(); // Para versao macOS

        // pergunta ao usuario o tema desejado
        cout << "ESCOLHA O TEMA DO JOGO: " << endl;
        cout << setw(10) << "1-FRUTAS" << endl;
        cout << setw(10) << "2-PAISES" << endl;
        cout << setw(7) << "3-C++" << endl;
        cin >> escolha_tema;

        // pergunta ao usuario a dificuldade desejada
        cout << "ESCOLHA A DIFICULDADE DO JOGO: " << endl;
        cout << "1-FACIL" << endl;
        cout << "2-MEDIO" << endl;
        cout << "3-DIFICL" << endl;
        cin >> dificuldade;

        // atribui um valor a dificuldade baseado na escolha
        switch (dificuldade) { // valores atribuidos se referem ao tempo de jogo
        case 1:
            dificuldade = 8;
            break;
        
        case 2:
            dificuldade = 6;
            break;
        case 3:
            dificuldade = 4;
            break;
        }
    };

    // intervalo de [1,3] para escolha aleatoria do tema, para modos diferentes do elementar
    if(modo == 1){
        escolha_tema = (int) rand() % 3 + 1;
        dificuldade = 0;
    }

    // abre o ficheiro binario no modo leitura
    coletaPalavra.open("Database.dat", ios::in | ios::binary);

    switch(escolha_tema){
        case 1: // caso a escolha seja 1
            // atribuimos a string "FRUTAS" ao atributo "tema"
            this->tema = "FRUTAS";

            // selecionamos a palvara aleatoriamente no intervalo [0,7]
            i = (int) rand() % 8 ;
            break;

        case 2: // caso a escolha seja 2
            // atribuimos a string "PAISES" ao atributo "tema"
            this->tema = "PAISES";

            // selecionamos a palvara aleatoriamente no intervalo [8,15]
            i = (int) (rand() % 8) + 8 ;
            break;

        case 3:// caso a escolha seja 3
            // atribuimos a string "C++" ao atributo "tema"
            this->tema = "C++";
            
            // selecionamos a palvara aleatoriamente no intervalo [16,23]
            i = (int) (rand() % 8) + 16 ;
    }
    
    coletaPalavra.seekg(i*sizeof(string_C), ios::beg);
    coletaPalavra.read((char *) &string_C, sizeof(string_C));
    
    // guardamos a palvra primeiramente em char e depois passamos pra string
    palavra = string_C; // assim não temos problema de leitura binaria
    tamanho_palavra = palavra.length();

    //salva index da palavra jogada, para que nao se repita.
    indexPalavrasJogadas[palavrasJogadas] = escolha_tema*MAX;

    // atualizados os atributos palavra e tamanho_palavra, fechamos o ficheiro
    coletaPalavra.close();

    // guardamos o nome do jogador no atributo nome
    cout<< "DIGA SEU NOME: ";
    cin >> nome;

    // iniciamos os atributos pontos e tentativas
    this->pontos = this->tentativas = 0;
}

void Jogo::carregar_jogo(){
    /* método que quando chamado abre um ficheiro binário 
    contendo os jogos passados em modo leitura salvando os dados 
    na estrutura saveJogo e depois lendo esta para retomar o jogo*/

    ifstream Loadgame;
    saveJogo s;

    // abre o ficheiro para leitura e guarda os dados na estrutura s
    Loadgame.open("Jogos.dat", ios::binary);
    //Loadgame.seekg(sizeof(save));
    Loadgame.read((char*) &s, sizeof(s));

    // passa os dados da estrutura para os atributos da classe
    palavra = s.palavra_C;
    tema = s.tema_C;
    nome = s.nome_C;
    emJogo = s.emJogo;
     for(int i = 0; i < 7; i++) {
        letrasCertas[i] = s.letrasCertas[i];
    }
    for (int i = 0; i < 7; i++) {
        erros[i] = s.erros[i];
    }
    tentativas = s.tentativas;
    acertos = s.acertos;
    pontos = s.pontos;
    for( int i = 0; i < 24; i++) {
        indexPalavrasJogadas[i] = s.indexPalavrasJogadas[i];
    }
    palavrasJogadas = s.palavrasJogadas;
    tamanho_palavra = s.tamanho_palavra;
    dificuldade = s.dificuldade;
    modo = s.modo;
    tempo = s.tempo;

    Loadgame.close();
}

void Jogo::salvarjogo(){
    /* método que quando chamado armazena os 
    valores atuais dos atributos da classe em uma 
    estrutura e guarda a estrutura em um ficheiro 
    binário para acessar futuramente */

    saveJogo s;

    // copia os valores dos atributos para a estrutura
    strcpy(s.palavra_C, palavra.c_str());
    strcpy(s.tema_C, tema.c_str());
    strcpy(s.nome_C, nome.c_str());
    s.emJogo = emJogo;
    for(int i = 0; i < 7; i++){
        s.letrasCertas[i] = letrasCertas[i];
    }
    for (int i = 0; i < 7; i++)
    {
        s.erros[i] = erros[i];
    }
    s.tentativas = tentativas;
    s.acertos = acertos;
    s.pontos = pontos;
    for( int i = 0; i < 24; i++){
        s.indexPalavrasJogadas[i] = indexPalavrasJogadas[i];
    }
    s.palavrasJogadas = palavrasJogadas;
    s.tamanho_palavra = tamanho_palavra;
    s.dificuldade = dificuldade;
    s.modo = modo;
    s.tempo = tempo;
    
    // abre o ficheiro binário para escrita
    ofstream Save;
    Save.open("Jogos.dat", ios::binary);
    // escreve a estrutura no ficheiro
    Save.write((char*) &s , sizeof(s));
}

void Jogo::salvarRanking(){
    /* método que utiliza de linked list acompanhado
    de alocação de memória dinâmica para atualizar as 
    pontuações de jogadores na lista de rankings */

    int index = -1;
    bool jogador_certo = false;
    ranking s;

    // salva dinamicamente o nome do jogador
    char * string_C = new char [MAX];
    strcpy(string_C, nome.c_str());

    listaRank historicoJogadores;
    ifstream buscarJogador;

    // abre o ficheiro binário
    buscarJogador.open("Ranking.dat", ios::binary);
    if(!buscarJogador.is_open()){
        cout << "ERRO SALVANDO O RANK" << endl;
        exit(0);
    }

    do{
        // caso o jogador atual esteja na lista atribui "true" a jogador_certo
        index ++;
        buscarJogador.seekg(index * sizeof(s), ios::beg);
        buscarJogador.read((char * ) &s, sizeof(s));
        if( !strcmp(string_C, s.nome_C))
        jogador_certo = true;

        // verifica se a leitura foi feita corretamente
        if(buscarJogador.gcount() == sizeof(s))
        historicoJogadores.insereItem(s);

    // quando a leitura falhar, não há mais o que ler no ficheiro e o ciclo termina
    }while(( buscarJogador.gcount() == sizeof(s) ) ); 

    if(jogador_certo){
        // atualiza a pontuação do jogador com o método da linked list
        historicoJogadores.atualizaJogador(index, *this);
    }else{
        // adicionamos o jogador na linked list, caso ele não tenha sido encontrado
        strcpy(s.nome_C, string_C);
        s.pontos = pontos;
        historicoJogadores.insereItem(s);
    }

    historicoJogadores.escreveFicheiro();

    buscarJogador.close();
    delete [] string_C;
}

int Jogo :: jogo() {
    /* método que executa o jogo, seja ele novo, 
    existente a partir do método novo_jogo, seja ele 
    um jogo passado, chamado pelo método carrega_jogo() */

    string espaco = "_";
    char letra;
    bool repetida;
    int index, indexAcerto = 0, sec, milisec, nerros = 0;

    // formatação dos espaços da palavra ("... _ _ _ ...")
    for(int i=0; i<tamanho_palavra-1; i++) {
        espaco += " _";
    }

    // formatação do espaco para carregar o jogo
    for(int i = 0; i< MAX; i++){
    index = (int)palavra.find(letrasCertas[i]);

        if(index != -1){
            while(index<tamanho_palavra && index != -1) {
                if(index!=-1) {
                    espaco[index*2] = letrasCertas[i];
                    index++;
                }
            index = (int)palavra.find(letrasCertas[i], index);
            }  
        }
    }

    // atribuimos a estrutura before o horario atual e colocamos emJogo true
    gettimeofday(&before, NULL);
    emJogo = true;

    while(tentativas < 8) {
        //system("CLS"); // limpamos o terminal
        clrscn(); // Para versao macOS

        //se o jogador ja completou a palavra, inicia outra.
        if(acertos==tamanho_palavra){
            
            switch (modo) {
            case 1:
                if(palavrasJogadas == 23){
                    cout << "VOCE GANHOU" << endl;
                    cout << "ENTRE QUALQUER TECLA PARA RETORNAR O MENU" << endl;
                    salvarRanking();
                    emJogo = false;
                    cin >> letra;
                    return 0;
                }
                break;
            
            default:
                if(palavrasJogadas == 7){
                    cout << "VOCE GANHOU" << endl;
                    cout << "ENTRE QUALQUER TECLA PARA RETORNAR O MENU" << endl;
                    for(int i = 0; i < 24; i++){
                    }
                    salvarRanking();
                    emJogo = false;
                    cin >> letra;
                    return 0;
                }
                break;
            }
            
            nerros = 0;
            for(int i = 0; i < 7; i++){
                if(erros[i]!= '\0')
                nerros++;
            }
            if(modo==1) pontos = pontos + (8-nerros);
            else pontos = pontos + (int) tempo;
            
            avanca_jogo();
            
            gettimeofday(&before, NULL);
            indexAcerto = 0;
            
            //formata espaco para nova palvra
            espaco = "_";
            for(int i=0; i<tamanho_palavra-1; i++) {
                espaco += " _";
            }
        }

        // pega novamente o horario e atribui a estrutura after
        gettimeofday(&after, NULL);

        // calcula o intervalo de tempo pelo metodo seguinte
        tempo = printTime(before, after, dificuldade*tamanho_palavra);
        sec = (int) tempo;
        milisec = (int) ((tempo - sec)*100);

        // se o tempo extrapolar os zero segundos significa que o tempo acabou
        if(tempo<=0.0 && modo!=1) {
            tempo = 0.0;
            pontos = pontos + (int) tempo;
            salvarRanking();
            return pontos;
        }

        if(modo==1) {
            sec=milisec=0;
        }

        // print as informações do topo do jogo
        cout << setw(14) << left << "MENU(1)" << internal << "TEMA: " <<
                tema << setw(13) << right << "TEMPO:" << setw(2) << setfill('0') <<
                sec << ":" << setw(2) << setfill('0') << milisec << setfill(' ') << endl;
        cout << forca_display[tentativas] << endl;

        // print dos pontos e erros feitos pelo usuario
        cout << "PONTOS: " << pontos << endl;
        cout << "ERROS: ";
        for (int i=0; i < tentativas; i++){
            cout << erros[i];
        }
        cout << endl << endl;

        // print do espaçamento da palavra
        cout << setw(19+tamanho_palavra) << espaco << endl << endl;

        // esperamos a entrada da letra pelo usuario e colocamos em maiúsuclo
        cin >> letra;
        letra = toupper(letra);

        do{
        // verificamos se a letra colocada ja foi usada    
            repetida = false;
            for(int i=0 ; i < tentativas; i++){
                // percorremos a lista de letras usadas
                if (letra == erros[i])
                    repetida = true; // se ja estiver la, colocamos true
            }
            for(int i = 0; i < indexAcerto; i++){
                // percorremos a lista de letras usadas
                if (letra == letrasCertas[i])
                    repetida = true;// se ja estiver la, colocamos true
            }
            if(repetida){
                cout << "JA TENTOU ESSA LETRA! TENTE OUTRA: ";
                do{
                    cin >> letra;
                    if(letra=='1') break;
                    letra = toupper(letra);
                } while(letra<'A' || letra>'Z');
            }
        // enquanto a letra colocada ja tiver sido usada pedimos outra    
        } while(repetida);

        // garantimos que é mesmo uma letra a ser passada
        if(letra>='A' && letra<='Z') {
            // verificamos o primeiro index da palavra em que a letra dada existe
            index = (int)palavra.find(letra);

            // se find() retornar um valor>=0, atualizamos o "espaço" com a letra
            if(index != -1){
                letrasCertas[indexAcerto] = letra;
                indexAcerto++;
                while(index<tamanho_palavra && index != -1) {
                    if(index!=-1) {
                        espaco[index*2] = letra;
                        acertos++;
                        index++;
                    }
                // somamos um no index e vemos se há outra vez a letra na string
                index = (int)palavra.find(letra, index);
                }  
            }
            // se find() retorna -1, significa que a letra não existe na palavra
            else{
                // atualizamos a tabela de erros com a letra e inteiramos a tentativa
                erros[tentativas] = letra;
                tentativas++;
            }
        }
        if (letra == '1') menu(); // volta pro menu

        salvarjogo();
    }

    emJogo = false;

    salvarRanking();
    return pontos;
}

void Jogo::avanca_jogo(){
    /* método chamado quando a palavra é 
    acertada pelo jogador e precisamos buscar uma 
    nova palavra para dar continuidade ao jogo */

    ifstream coletaPalavra;
    time_t t;
    srand((unsigned) time(&t));
    int random;
    bool repetida = false;
    char string_C[MAX];
    
    // reinicia os acertos, letras certas e os erros
    acertos = 0;
    for(int i = 0; i < MAX; i++)
    letrasCertas[i] = '\0';
    for(int i = 0; i < 7; i++)
    erros[i] = '\0';

    //contabiliza que o jogador acertou uma palavra
    palavrasJogadas++;

    // intervalo de [1,3] para escolha aleatoria do tema, para modos diferentes do elementar
    coletaPalavra.open("Database.dat", ios::in | ios::binary);

    if(!coletaPalavra.is_open()){
        cout << "Erro ao abrir o ficheiro";
        exit(1);
    }

    do{
        repetida = false;

        // se nao for o modo elementar
        if(modo == 1){
            random = (int) rand() % 3 + 1;
            dificuldade = 0;
        }else{
            if(tema == "FRUTAS"){
                random = 1;
            }else if(tema == "PAISES"){
                random = 2;
            }else{
                random = 3;
            }
        }

        switch(random){
            case 1: // caso a escolha seja 1
                // atribuimos a string "FRUTAS" ao atributo "tema"
                this->tema = "FRUTAS";
                // selecionamos a palvara aleatoriamente no intervalo [0,7]
                random = (int) rand() % 8 ;
                coletaPalavra.seekg(random*MAX, ios::beg);
                break;

            case 2: // caso a escolha seja 2
                // atribuimos a string "PAISES" ao atributo "tema"
                this->tema = "PAISES";

                // selecionamos a palvara aleatoriamente no intervalo [8,15]
                random = (int) (rand() % 8) + 8 ;
                coletaPalavra.seekg(random*MAX, ios::beg);
                break;

            case 3:// caso a escolha seja 3
                // atribuimos a string "C++" ao atributo "tema"
                this->tema = "C++";
            
                // selecionamos a palvara aleatoriamente no intervalo [16,23]
                random = (int) (rand() % 8) + 16 ;
                coletaPalavra.seekg(random*MAX, ios::beg);
        }


        for(int i = 0; i < palavrasJogadas; i++){
            if(indexPalavrasJogadas[i] == random*MAX)
                repetida = true;
        }
        

    }while(repetida);

    //salva as palavras ja jogadas.
    indexPalavrasJogadas[palavrasJogadas] = random*MAX;

    // guardamos a palvra primeiramente em char e depois passamos pra string
    coletaPalavra.read((char *) string_C, MAX);
    palavra = string_C; // assim não temos problema de leitura binaria
    tamanho_palavra = palavra.length();

    // atualizados os atributos palavra e tamanho_palavra, fechamos o ficheiro
    coletaPalavra.close();
}

int Jogo :: modo_jogo() {
    /* método que pergunta ao jogador o modo de jogo 
    que este quer jogar e atualiza o atributo modo */

    //system("CLS");
    clrscn();
    int escolha;

    for(int i=0; i<40; i++) cout << "=";
        cout << endl;

        do{ // imprime a parte visual do modo de jogo   
            cout << setw(27) << "*MODOS DE JOGO*"; //14
            cout << forca_display[7] << endl;
            cout << setw(24) << "1-ELEMENTAR" << endl;
            cout << setw(21) << "2-BASICO" << endl;
            cout << setw(20) << "3-MEDIO" << endl;
            cout << setw(30) << "4-VOLTAR PRO MENU" << endl; //17
            for(int i=0; i<40; i++) cout << "=";
            cout << endl;
            cin >> escolha;
        }while(escolha < 1 || escolha > 4);

    if(escolha == 4)
        return modo;

    return escolha;
}

void Jogo :: historico() {
    /* método que quanddo chamado abre o ranking dos melhores 
    jogadores, ordena-os por pontuação, atualiza suas 
    pontuações caso necessário e imprime os primeiros dez */

    int index = -1;
    int inicializados = 0;
    char wait;
    bool change;
    ifstream carregaRanks;
    ranking topJogadores[10], novo, aux;

    // abre o ficheiro binário em formato leitura
    carregaRanks.open("Ranking.dat", ios::binary);
    if(!carregaRanks.is_open()){
        cout << "ERRO OBTENDO O RANKING" << endl;
        goto fim;
    }

    // inicializa o top jogadores com o registro de pontuacao de 10 jogadores.
    do{
        index++;
        carregaRanks.seekg(index * sizeof(novo), ios::beg);
        carregaRanks.read((char *) &novo, sizeof(novo));

        if(carregaRanks.gcount() == sizeof(novo)){
        inicializados++;
        topJogadores[index] = novo; 
        }

    }while(carregaRanks.gcount() == sizeof(novo) && index != 9);


    for(int i = inicializados; i < 10; i++){
        topJogadores[i].pontos = 0;
    }

    // realiza um bubble sort entre o top 10 (inicializados)
    for(int i = 0; i < 10; i++){
        change = false;

        for(int j = 1; j < 10-i; j++)
        if(topJogadores[j].pontos > topJogadores[j-1].pontos){
                aux = topJogadores[j];
                topJogadores[j] = topJogadores[j-1];
                topJogadores[j-1] = aux;
                change = true;
        }

        if(!change)
        break;
        }


    while(carregaRanks.gcount() == sizeof(aux) && index > 9){
        index++;
        carregaRanks.seekg(index * sizeof(novo), ios::beg);
        carregaRanks.read((char *) &novo, sizeof(novo));

        if(carregaRanks.gcount() != sizeof(aux))
            break;
        
        // verifica se o pontos do jogador entra no top 10, e caso sim, o insere
        for(int i = 0; i < 10; i++){
            if(topJogadores[i].pontos < novo.pontos){
                aux = topJogadores[i];
                topJogadores[i] = novo;
                novo = aux;
            }
        } 

    }

    carregaRanks.close();

    for(int i = 0; i < 10 && topJogadores[i].pontos != 0  ; i++)
    cout << i+1 << "- JOGADOR:  " << topJogadores[i].nome_C << endl << "PONTOS: " << topJogadores[i].pontos << endl << endl;

    fim:
    cout << "ENTRE QUALQUER TECLA PARA SAIR." << endl;
    cin >> wait;

}

double Jogo :: printTime(timeval before , timeval after, int i){
    /* método que recebe como parâmetros três 
    estruturas que representam horários e retorna
    a diferença de tempo entre os dois horários */

    return (double) ((before.tv_sec * 1000000 + i*1000000 + before.tv_usec) - (after.tv_sec * 1000000 + after.tv_usec))/1000000;
}

void Jogo :: sair() {
    /* método que finaliza o programa e antes de 
    terminar verifica se há algum jogo em curso, avisa 
    o jogador da situação e pergunta se quer salvar*/

    char escolha;
    if(emJogo) {
        cout << "O JOGO ESTA EM ANDAMENTO, TEM CERTEZA QUE QUER SAIR?? [y/n]";
        cin >> escolha;
        escolha = toupper(escolha);
        if (escolha=='Y') {
            cout << "GOSTARIA DE SALVAR O JOGO ANTES DE SAIR?? [y/n]";
            cin >> escolha;
            if (escolha=='Y'){
                salvarjogo();
            }
            exit(0);}
    }

    exit(1);
}

int main() {
    Jogo Jogada;
    string nome;
    Jogada.menu();

    return 0;
}