//
//  CJogo.cpp
//  Projeto_2
//
//  Created by Gabriel Santos Correa da Silva on 03/05/22.
//
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#define clrscn() std::cout << "\e[1;1H\e[2J"; // Para versao macOS.

#include "CJogo.h"
#include "CRanking.h"
#include "CTemas.h"
#include "CPalavras.h"
#include "StructAuxiliares.h"

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
//=====================================================================
Jogo::Jogo(){
    /* construtor por omissão - inicializa os atributos para
    serem atualizados no novo_jogo ou carregados em carregar_jogo*/

    palavra = tema = nome =  "";
    tentativas = acertos = pontos = TotalTemas = tamanho_palavra = palavrasJogadas = tempo = 0;
    modo = 1;
}
//=====================================================================
void Jogo::contaQuantosTemas(){
    ifstream coletaTemas;
    Stema temas;
    TotalTemas = 0;
    
    coletaTemas.open("Temas.dat", ios::binary);
    
    if(!coletaTemas.is_open()){
        cout << "ERRO OBTENDO A QUANTIDADE DE TEMAS" << endl;
        exit(-1);
    }
    
    do{
        
        coletaTemas.seekg(TotalTemas * sizeof(Stema), ios::beg);
        coletaTemas.read((char *) &temas, sizeof(Stema));
        
        if(coletaTemas.gcount() == sizeof(Stema)){
            TotalTemas++;
        }
        

    }while(coletaTemas.gcount() == sizeof(Stema));
}
//=====================================================================
void Jogo::adicionaTema(){
    int contador=0;
    char string_C[MAX];

    system("CLS");
    ifstream coletaTemas;
    Stema temas;
    SPalavras aux_palavra;

    cout << "TEMAS ATUAIS:" << endl;

    coletaTemas.open("Temas.dat", ios::binary);

    if(!coletaTemas.is_open()){
        cout << "ERRO ABRINDO ARQUIVO PARA EDITAR TEMAS" << endl;
        exit(-1);
    }

    do{
            coletaTemas.seekg(contador * sizeof(Stema), ios::beg);
            coletaTemas.read((char *) &temas, sizeof(Stema));
            if(coletaTemas.gcount() == sizeof(Stema)){
                cout << contador+1 << "-" << temas.tema << endl;
                contador++;
            }
    }while(coletaTemas.gcount() == sizeof(Stema));
    
    contador=0;

    cout << endl;

    cout << "DIGITE O NOME DO TEMA: ";
    cin >> tema;

    ofstream NovoTema;
    NovoTema.open((tema+".dat"), ios::binary | ios::app);

    if(!NovoTema.is_open())
        cout << "ERRO AO ABRIR ARQUIVO DO NOVO TEMA" << endl;

    contador=0;
    do {
        cout << "DIGITE UMA PALAVRA DO TEMA OU 'FIM' PRA TERMINAR [MIN 8 PALAVRAS]: ";
        cin >> palavra;

        if (palavra!="FIM") {
            strcpy(aux_palavra.Palavra, palavra.c_str());
            aux_palavra.jaJogada = 0;
            NovoTema.write((char *) &aux_palavra, sizeof(aux_palavra));

            contador++;
        }
        system("CLS");
    } while(palavra != "FIM" || contador<8);

    NovoTema.close();

    Stema novo_tema;
    strcpy(novo_tema.tema, tema.c_str());
    novo_tema.elementos = contador;

    ofstream AtualizaTemas;
    AtualizaTemas.open("Temas.dat", ios::binary | ios::app);

    if(!AtualizaTemas.is_open())
        cout << "ERRO AO ABRIR ARQUIVO" << endl;

    AtualizaTemas.write((char*)&novo_tema, sizeof(novo_tema));
    AtualizaTemas.close();
}
//=====================================================================
void Jogo::editaTema(){
    int escolha, count = 0;
    ifstream coletaTemas, coletaPalavras;
    Stema temas;
    listaPalavras_Tema palavrasListadas;
    SPalavras SstructPalavra;
    char string_C[MAX];
    clrscn();
    //system("CLS");

    cout << "TEMAS ATUAIS: " << endl;

    coletaTemas.open("Temas.dat", ios::binary);

    if(!coletaTemas.is_open()){
        cout << "ERRO ABRINDO ARQUIVO PARA EDITAR TEMAS" << endl;
        exit(-1);
    }

     do{
            coletaTemas.seekg(count * sizeof(Stema), ios::beg);
            coletaTemas.read((char *) &temas, sizeof(Stema));
            if(coletaTemas.gcount() == sizeof(Stema)){
                cout << count+1 << "-" << temas.tema << endl;
                count++;
            }
     }while(coletaTemas.gcount() == sizeof(Stema));

     cout << endl << "QUAL TEMA GOSTARIA DE EDITAR?" << endl;
     cin >> escolha;

    clrscn();
    //system("CLS");

    coletaTemas.close();
    coletaTemas.open("Temas.dat", ios::binary);

    if(!coletaTemas.is_open()){
        cout << "ERRO ABRINDO ARQUIVO PARA EDITAR TEMAS" << endl;
        exit(-1);
    }
    

    coletaTemas.seekg((escolha-1) * sizeof(Stema), ios::beg);
    coletaTemas.read((char *) &temas, sizeof(Stema));
    if( coletaTemas.gcount() != sizeof(Stema)){
        cout << "FALHA EDITANDO TEMA" << endl;
        exit(-1);
     }

    this->tema = temas.tema;

    coletaTemas.close();

    cout << "PALAVRAS ATUAIS: " << endl;

    coletaPalavras.open(tema+".dat", ios::binary);
    count = 0;
    do{
        coletaPalavras.seekg(count * sizeof(SstructPalavra), ios::beg);
        coletaPalavras.read((char *) &SstructPalavra, sizeof(SstructPalavra));
        if(coletaPalavras.gcount() == sizeof(SstructPalavra)){
            cout << count+1 << "-" << SstructPalavra.Palavra << endl;
            count++;
            palavrasListadas.insereItem(SstructPalavra.Palavra, SstructPalavra.jaJogada);
            }

    }while(coletaPalavras.gcount() == sizeof(SstructPalavra));
    coletaPalavras.close();

    cout << endl << "O QUE GOSTARIA DE FAZER?" << endl;
    cout << "1- ADICIONAR PALAVRA: " << endl;
    
    cout << "2- REMOVER PALAVRA: ";
    if(count <= 8){
        cout << "NAO DISPONIVEL (MIN 8 PALAVRAS)" ;
    }
    cout << endl;
    cout << "3- EDITAR PALAVRA: " << endl;
    cout << "4- RETORNAR AO MENU" << endl;
    do{
        cin >> escolha;

        if(count <= 8 && escolha == 2 ){
            cout << "OPCAO NAO DISPONIVEL, POR FAVOR SELECIONE OUTRA" << endl;
        }

        if(escolha < 1 || escolha > 4 ){
            cout << "OPCAO NAO VALIDA, POR FAVOR SELECIONE OUTRA" << endl;
        }

    }while(escolha < 1 || escolha > 4 || ( count <= 8 && escolha == 2 ));

    switch (escolha)
    {
    case 1:
        cout << "ENTRE A PALAVRA QUE GOSTARIA DE ADICIONAR: " << endl;
        cin >> string_C; 
        palavrasListadas.insereItem(string_C, 0);
        palavrasListadas.escreveFicheiro(tema);
        break;
    
    case 2:
        cout << "QUAL PALAVRA GOSTARIA DE REMOVER?" << endl;
        do{
            cin >> escolha;
        }while(escolha < 1 || escolha > count);
        if(!(palavrasListadas.removeItem(escolha))){
            cout << "ERRO REMVENDO PALAVRA" << endl;
        }
        palavrasListadas.escreveFicheiro(tema);
        palavrasListadas.reiniciaLista();
        break;
    case 3:
        cout << "QUAL PALAVRA GOSTARIA DE EDITAR?" << endl;
        do{
            cin >> escolha;
        }while(escolha < 1 || escolha > count);
        clrscn();
        cout << "A PALAVRA ATUAL: ";
        coletaPalavras.open(tema+".dat", ios::binary);
        coletaPalavras.seekg((escolha-1) * sizeof(SstructPalavra), ios::beg);
        coletaPalavras.read((char *) &SstructPalavra, sizeof(SstructPalavra));
        coletaPalavras.close();
        cout << SstructPalavra.Palavra << endl;
        cout << "ENTRE O QUE QUER A PALAVRA SEJA: ";
        cin >> string_C;
        palavrasListadas.editaLista(escolha, string_C);
        palavrasListadas.escreveFicheiro(tema);
        break;
    case 4:
        //menu()
        return;
    }
    return;
}
//=====================================================================
void Jogo::excluiTema() {
    int escolha, count = 0;
    ifstream coletaTemas;
    Stema temas;
    listaTemas temasListados;
    string auxiliar;
    char temaParaExcluir[MAX];
    
    clrscn();
    //system("CLS");
    
    cout << "TEMAS ATUAIS: " << endl;

    coletaTemas.open("Temas.dat", ios::binary);

    if(!coletaTemas.is_open()){
        cout << "ERRO ABRINDO ARQUIVO PARA EDITAR TEMAS" << endl;
        exit(-1);
    }

    do{
        coletaTemas.seekg(count * sizeof(Stema), ios::beg);
        coletaTemas.read((char *) &temas, sizeof(Stema));
        if(coletaTemas.gcount() == sizeof(Stema)){
            cout << count+1 << "-" << temas.tema << endl;
            count++;
            temasListados.insereItem(temas);
        }
    }while(coletaTemas.gcount() == sizeof(Stema));

    coletaTemas.close();

    cout << endl << "QUAL TEMA GOSTARIA DE EXCLUIR?" << endl;
    do{
        cin >> escolha;

        if(escolha < 1 || escolha > count){
            cout << "OPCAO NAO DISPONIVEL, POR FAVOR SELECIONE OUTRA" << endl;
        }
    }while(escolha < 1 || escolha > count);

    coletaTemas.open("Temas.dat", ios::binary);
    coletaTemas.seekg((escolha-1) * sizeof(Stema), ios::beg);
    coletaTemas.read((char *) &temas, sizeof(Stema));
    coletaTemas.close();

    auxiliar = temas.tema;
    auxiliar = auxiliar+".dat";

    strcpy(temaParaExcluir, auxiliar.c_str());

    remove(temaParaExcluir);

    if(!(temasListados.removeItem(escolha))){
            cout << "ERRO REMOVENDO TEMA" << endl;
        }
    temasListados.escreveFicheiro();
    temasListados.reiniciaLista();
}
//=====================================================================
void Jogo :: menu() {
    /* método que imprime o menu inicial e chama
    outro método baseado na escolha do usuário*/
    //Carrega jogo para obter a variavel "emjogo"
    carregar_jogo();
    //define modo padrao novamento pro elementar.
    modo = 1;
    // declaracao da variavel "escolha"
    int escolha, escolha_config, count;
    char escolha_y_n;
    char wait;

menu:
    do{
        //system("CLS");
        clrscn(); // Para versao macOS
        
        // impressao do da parte visual do menu
        for(int i=0; i<40; i++) cout << "=";
        cout << endl;
        cout << setw(27) << "*JOGO DA FORCA*";
        cout << forca_display[7] << endl;
        cout << setw(25) << "1-NOVO JOGO" << endl;
        cout << setw(26) << "2-RETOMAR JOGO" << endl;
        cout << setw(26) << "3-MODO DE JOGO" << endl;
        cout << setw(24) << "4-RANKINGS" << endl;
        cout << setw(28) << "5-CONFIGURAR TEMAS" << endl;
        cout << setw(23) << "6-SAIR" << endl;
        for(int i=0; i<40; i++) cout << "=";
        cout << endl;

        // pedimos ao usuário escolher uma opção entre as quatro
        cout << "SELECIONE UMA OPCAO ENTRE 1 E 6: ";
        cin >> escolha; // atribuimos a resposta na variável

    switch (escolha)
    {
    case 1:
        // chamamos o novo_jogo() para coleta de dados para iniciar
        if(emJogo){
            cout << "POSSUI UM JOGO EM ANDAMENTO, INICIAR UM NOVO RESULTARA NA PERDA DO JOGO ATUAL" << endl;
            cout << "DESEJA CONTINUAR? [y/n] " << endl;
            cin >> escolha_y_n;

            if(escolha_y_n == 'y' || escolha_y_n == 'Y'){
            novo_jogo();
            jogo();
            }else{
                goto menu;
            }

        }else{
            novo_jogo();
            jogo();
        }

        break;
    
    case 2:
        if(!emJogo){
            cout << "NAO POSSUI NENHUM JOGO EM ANDAMENTO!" << endl;
            cout << "ENTRE QUALQUER TECLA PARA VOLTAR AO MENU" << endl;
            cin >> wait;
            goto menu;
        }
        carregar_jogo();
        jogo();
        break;

    case 3:
        modo = modo_jogo();
        break;

    case 4:
        historico();
        break;

    case 5: 
        do {
            ifstream coletaTemas;
            Stema temas;

            count=0;
            system("CLS");
            cout << "TEMAS ATUAIS:" << endl;

            coletaTemas.open("Temas.dat", ios::binary);

            if(!coletaTemas.is_open()){
                cout << "ERRO ABRINDO ARQUIVO PARA EDITAR TEMAS" << endl;
                exit(-1);
            }

            do{
                    coletaTemas.seekg(count * sizeof(Stema), ios::beg);
                    coletaTemas.read((char *) &temas, sizeof(Stema));
                    if(coletaTemas.gcount() == sizeof(Stema)){
                        cout << count+1 << "-" << temas.tema << endl;
                        count++;
                    }
            }while(coletaTemas.gcount() == sizeof(Stema));

            cout << endl;

            cout << "ESCOLHA UMA OPCAO: " << endl;
            cout << "1-ADICIONAR TEMA" << endl;
            cout << "2-EDITAR TEMA" << endl;
            cout << "3-EXCLUIR TEMA" << endl;
            cout << "4-VOLTAR MENU" << endl;

            cin >> escolha_config;
        }while(escolha_config<1 || escolha_config>4);

        switch (escolha_config)
        {
        case 1:
            adicionaTema();
            break;
        
        case 2:
            editaTema();
            break;
        case 3:
            excluiTema();
            break;
        case 4:
            break;
        }
        break;

    case 6:
        sair();
        break;
    }
        // resetamos escolha para quando menu() for chamado novamente
        escolha = 0;
    } while(escolha<1 || escolha>6);
    // loop caso a escolha não esteja no intervalo [1,4]

}
//=====================================================================
void Jogo::novo_jogo(){
    /* método que cria um novo jogo, pergunta ao
       usuário o tema do jogo, determina aleatoriamente
       a palavra do jogo, armazena o nome do jogador e
       inicializa as variaveis pontos e tentativas a zero*/
    
    int i, escolha_tema = 0;
    char string_C[MAX];
    bool aprovada = false;
    ifstream coletaPalavra;
    ifstream coletaTemas;
    time_t t;
    Stema temas;
    SPalavras s;
    srand((unsigned) time(&t));



    // garantimos que os atributos estão sendo inicializados para não serem sobreescrevidos
    /* OVERFLOW OPERATOR CRIAÇÃO NA HEAP */
    palavra = tema = nome =  "";
    tentativas = pontos = tamanho_palavra = palavrasJogadas = acertos = tempo = 0;
    for(i=0; i<MAX; i++) letrasCertas[i] = '\0';
    
    //system("CLS"); // limpa o terminal
    clrscn(); // Para versao macOS
    
    //Abrimos o ficheiro dos temas
    coletaTemas.open("Temas.dat", ios::binary);

    if(!coletaTemas.is_open()){
        cout << "ERRO NA COLETA DO TEMA" << endl;
        exit(-1);
    }
    
    //Prepara o jogo baseado no modo escolhido.
    //i servirá de contador de temas para exibicao no menu e o index do tema
    i = 0;
    if(modo != 1){
        cout << "ESCOLHA O TEMA DO JOGO: " << endl;
        do{
            coletaTemas.seekg(i * sizeof(Stema), ios::beg);
            coletaTemas.read((char *) &temas, sizeof(Stema));
            if(coletaTemas.gcount() == sizeof(Stema)){
                cout << i+1 << "-" << temas.tema << endl;
                i++;
            }
            
        
        }while(coletaTemas.gcount() == sizeof(Stema));
        
        do{
            cin >> escolha_tema;
            coletaTemas.seekg( escolha_tema * sizeof(Stema));
            coletaTemas.read((char *) &temas, sizeof(Stema));
        }while(escolha_tema < 1 || escolha_tema > i);
    
        cout << "ESCOLHA A DIFICULDADE DO JOGO: " << endl;
        cout << "1-FACIL" << endl;
        cout << "2-MEDIO" << endl;
        cout << "3-DIFÍCL" << endl;
        
        do{
            cin >> dificuldade;
        }while(dificuldade < 1 || dificuldade > 3);
        
        switch (dificuldade)
        {
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
        
    }

    if(modo == 1) {
        do{
            
            coletaTemas.seekg(i * sizeof(Stema), ios::beg);
            coletaTemas.read((char *) &temas, sizeof(Stema));
            if(coletaTemas.gcount() == sizeof(Stema)){
                i++;
            }
        }while(coletaTemas.gcount() == sizeof(Stema));
        //Intervalo de [0,i] para escolha aleatoria do tema, para modos diferentes do elementar
        escolha_tema = (int) rand() % (i+1);
        dificuldade = 0;
    }
    //Nao sei pq, mas teve que fechar e abrir denovo para funcionar
    coletaTemas.close();

    coletaTemas.open("Temas.dat", ios::binary);

    if(!coletaTemas.is_open()){
        cout << "ERRO NA COLETA DO TEMA" << endl;
        exit(-1);
    }

    coletaTemas.seekg((escolha_tema-1) * sizeof(Stema), ios::beg);
    coletaTemas.read((char *) &temas, sizeof(Stema));

    tema = temas.tema;
    palavrasTotais = temas.elementos;
    
    coletaTemas.close();

    int refMenosJogada;
    if(modo == 5){
    refMenosJogada = this->menosJogada();
    }

    do{
        aprovada = true;
        coletaPalavra.open(tema+".dat", ios::binary);
        
        i = (int) rand() % (temas.elementos-1);
        
        coletaPalavra.seekg(i*sizeof(SPalavras), ios::beg);
        coletaPalavra.read((char *) &s, sizeof(SPalavras));
    
        if(modo == 5){
            if ( rand() % 101 <= s.jaJogada - refMenosJogada ){
                aprovada = false;
            }
        }

        // atualizados os atributos palavra e tamanho_palavra, fechamos o ficheiro
        coletaPalavra.close();
    }while(aprovada == false);

    formaLista(tema, s.Palavra);


    // guardamos a palvra primeiramente em char e depois passamos pra string
    palavra = s.Palavra; // assim não temos problema de leitura binaria
    tamanho_palavra = palavra.length();

    //salva index da palavra jogada, para que nao se repita.
    if(modo != 1)
    indexPalavrasJogadas[palavrasJogadas] = i*sizeof(string_C); //ISSO DA CERTO APENAS SE N FOR O MODO ELEMENTAR

    // guardamos o nome do jogador no atributo nome
    cout<< "DIGA SEU NOME: ";
    cin >> nome;

    // iniciamos os atributos pontos e tentativas
    this->pontos = this->tentativas = 0;
}
//=====================================================================
void Jogo::carregar_jogo(){
   ifstream Loadgame;

   saveJogo s;

    Loadgame.open("Jogos.dat", ios::binary);
    //Loadgame.seekg(sizeof(save));
    Loadgame.read((char*) &s, sizeof(s));

    palavra = s.palavra_C;
    tema = s.tema_C;
    nome = s.nome_C;
    emJogo = s.emJogo;
     for(int i = 0; i < 7; i++){
        letrasCertas[i] = s.letrasCertas[i];
    }
    for (int i = 0; i < 7; i++)
    {
        erros[i] = s.erros[i];
    }
    tentativas = s.tentativas;
    acertos = s.acertos;
    pontos = s.pontos;
    if(modo!= 1){
        for( int i = 0; i < 24; i++){
            indexPalavrasJogadas[i] = s.indexPalavrasJogadas[i];
        }
    }
    palavrasTotais = s.palavrasTotais;
    palavrasJogadas = s.palavrasJogadas;
    tamanho_palavra = s.tamanho_palavra;
    dificuldade = s.dificuldade;
    modo = s.modo;
    tempo = s.tempo;
    contaQuantosTemas();

    Loadgame.close();
}
//=====================================================================
void Jogo::salvarjogo(){
    saveJogo s;

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
    s.palavrasTotais = palavrasTotais;
    s.TotalTemas = TotalTemas;
    s.palavrasJogadas = palavrasJogadas;
    s.tamanho_palavra = tamanho_palavra;
    s.dificuldade = dificuldade;
    s.modo = modo;
    s.tempo = tempo;
    
    ofstream Save;
    Save.open("Jogos.dat", ios::binary);

    Save.write((char*) &s , sizeof(s));
}
//=====================================================================
void Jogo::salvarRanking(){
    int index = -1;
    bool jogador_certo = false;
    ranking s;
    //Salva dinamicamente o nome do jogador
    char * string_C = new char [MAX];
    strcpy(string_C, nome.c_str());

    listaRank historicoJogadores;

    ifstream buscarJogador;
   
    buscarJogador.open("Ranking.dat", ios::binary);
    if(!buscarJogador.is_open()){
        cout << "ERRO SALVANDO O RANK" << endl;
        exit(-1);
    }
    
    do{
        index ++;

        buscarJogador.seekg(index * sizeof(s), ios::beg);
        buscarJogador.read((char * ) &s, sizeof(s));
        if( !strcmp(string_C, s.nome_C))
        jogador_certo = true;

        if(buscarJogador.gcount() == sizeof(s))
        historicoJogadores.insereItem(s);

  }while(( buscarJogador.gcount() == sizeof(s) ) );
    
    cout << jogador_certo << endl;
    
    if(jogador_certo){
        historicoJogadores.atualizaJogador(string_C, *this);
    }else{
        strcpy(s.nome_C, string_C);
        s.pontos = pontos;
        historicoJogadores.insereItem(s);
    }

    historicoJogadores.escreveFicheiro();

    buscarJogador.close();
    delete [] string_C;
}
//=====================================================================
int Jogo ::jogo() {
    /* método que executa o jogo, seja ele novo,
    existente a partir do método novo_jogo, seja ele
    um jogo passado, chamado pelo método carrega_jogo() */
    string espaco = "_";
    char letra;
    char wait;
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

    gettimeofday(&before, NULL);
    emJogo = true;

    while(tentativas < 8) {
        //system("CLS"); // limpamos o terminal
        clrscn(); // Para versao macOS


        //se o jogador ja completou a palavra, inicia outra.
        if(acertos==tamanho_palavra){

            palavrasJogadas++;

            if( (modo == 1 && palavrasJogadas == 24) || (modo != 1 && palavrasJogadas == palavrasTotais) ){
            emJogo = false;
            salvarjogo();
            cout << "VOCE GANHOU!!" << endl;
            cout << "ENTRE QUALQUER TECLA PARA VOLTAR AO MENU" << endl;
            cin >> wait;
            menu();
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

        gettimeofday(&after, NULL);
        tempo = printTime(before, after, dificuldade*tamanho_palavra);
        sec = (int) tempo;
        milisec = (int) ((tempo - sec)*100);

        if(tempo<=0.0 && modo!=1) {
            tempo = 0.0;
            pontos = pontos + (int) tempo;
            salvarRanking();
            emJogo = false;
            return pontos;
        }

        if(modo==1) {
            sec=milisec=0;
        }
        
        // print as informações do topo do jogo
        cout << setw(14) << left << "MENU(1)" << internal << "TEMA: " <<
                tema << setw(13) << right << "TEMPO:" << setw(2) << setfill('0') <<
                sec << ":" << setw(2) << setfill('0') << milisec << setfill(' ');

        switch (modo)
        {
        case 1:
            cout << setw(18) << "MODO : ELEMENTAR" << endl;
            break;
        case 2:
            cout << setw(15)  << "MODO : BASICO" << endl;
            break;
        case 3:
            cout << setw(15) << "MODO : MEDIO" << endl;
            break;
        case 4:
            cout << setw(17)  << "MODO : AVANCADO" << endl;
            break;
        case 5:
            cout << setw(22) << "MODO : PROFISSIONAL" << endl;
            break;
        
        }
        cout << forca_display[tentativas] << endl;

        // print dos erros feitos pelo usuario
        for (int i=0; i < tentativas; i++){
            if(i > 0) cout << " - ";
            cout << erros[i];
        }


        // print do espaçamento da palavra
        cout << endl << setw((42-(tamanho_palavra*2))/2);
        cout << espaco << endl << endl;
        cout << pontos << endl;

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
            for(int i = 0; i < acertos; i++){
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
        if (letra == '1'){
             salvarjogo();
             menu(); // volta pro menu
        }
        salvarjogo();
    }

    emJogo = false;

    salvarRanking();
    return pontos;
}
//=====================================================================
void Jogo::avanca_jogo(){
    ifstream coletaPalavra, coletaTemas;
    time_t t;
    Stema temas;
    SPalavras s;
    srand((unsigned) time(&t));
    int random = 0;
    bool aprovada = false;
    bool repetida;
    
    //reinicia os acetos, letras certas e os erros
    acertos = 0;
    for(int i = 0; i < MAX; i++)
    letrasCertas[i] = '\0';
    for(int i = 0; i < 7; i++)
    erros[i] = '\0';

    //No modo elementar, cada jogada possui um tema aleatorio, logo é preciso "sortear" novamente
    if(modo == 1){
        coletaTemas.open("Temas.dat", ios::binary);
        
        if(!coletaTemas.is_open()){
            cout << "ERRO EM OBTER O TEMA PARA AVANCAR O JOGO" << endl;
            exit(-1);
        }
        
        random = (int) rand() % TotalTemas;

        coletaTemas.seekg(random * sizeof(Stema), ios::beg);
        coletaTemas.read((char *) &temas, sizeof(Stema));
        
        tema = temas.tema;
        palavrasTotais = temas.elementos;
        coletaTemas.close();
    }

    coletaPalavra.open(tema+".dat", ios::binary);

    if(! coletaPalavra.is_open()){
        cout << "Erro ao abrir para coletar a palavra e avancar o jogo!";
        exit(-1);
    }

    int refMenosJogada;
    if(modo == 5)
    refMenosJogada = this->menosJogada();

    do{
        repetida = false;
        aprovada = true;
        random = (int) rand() % palavrasTotais;
        coletaPalavra.seekg(random * sizeof(SPalavras), ios::beg);
        coletaPalavra.read((char *) &s, sizeof(SPalavras));
        
        if(coletaPalavra.gcount() != sizeof(SPalavras)){
            cout << "ERRO LENDO A PALAVRA PARA AVANCAR O JOGO" << endl;
            exit(-1);
        }
        
        if(modo!= 1){
        for(int i = 0; i < palavrasJogadas; i++){
            
            if(indexPalavrasJogadas[i] == random*MAX){
                repetida = true;

            }
        }
        }
        
        if( modo == 5 ){
            if ( rand() % 101 <= s.jaJogada - refMenosJogada ){
            cout << "RAND: " << rand() % 101 << endl;
            cout << s.jaJogada - refMenosJogada << endl;
            aprovada = false;
        }
    }

        //Continua se nao for o modo elementar e a palavra eh repetida
    }while(modo != 1 && repetida == true && aprovada == false);
    
    
    formaLista(tema, s.Palavra);

    //salva as palavras ja jogadas.
    indexPalavrasJogadas[palavrasJogadas] = random*MAX;

    // guardamos a palvra primeiramente em char e depois passamos pra string
    palavra = s.Palavra; // assim não temos problema de leitura binaria
    tamanho_palavra = palavra.length();
    // atualizados os atributos palavra e tamanho_palavra, fechamos o ficheiro
    coletaPalavra.close();
}
//=====================================================================
void Jogo::coutJogo(){
    cout << "Palavra: : " <<  this->palavra << endl;
    cout << "Pontos : " << this->pontos << endl;
    cout << "Tentativas : "  <<this->tentativas << endl;
    cout << "Tema : " <<this->tema << endl;
    cout << "Tempo : " << this->tempo << endl;
    cout << "Modo : " << this->modo << endl;
    cout << "Tamanho da palavra : " <<this->tamanho_palavra << endl;
    cout << "nome : " <<this->nome << endl;
    cout << "Acertos: " << acertos << endl;
    cout << "Letras certas: " << letrasCertas << endl;
    cout << "Palavras jogadas: " << palavrasJogadas << endl;
    cout << "Palavras Totais: " << palavrasTotais << endl;

    for(int i = 0 ; i < 8 ; i++){
        cout << this->erros[i]<< "-" ;
    }
    cout << TotalTemas << endl;
    exit(20);
}
//=====================================================================
int Jogo :: modo_jogo() {
//system("CLS");
    clrscn();
int escolha, count, escolha_config;

for(int i=0; i<40; i++) cout << "=";
        cout << endl;
        do{
            clrscn();
            cout << setw(27) << "*MODOS DE JOGO*";
            cout << forca_display[7] << endl;
            cout << setw(24) << "1-ELEMENTAR" << endl;
            cout << setw(21) << "2-BASICO" << endl;
            cout << setw(20) << "3-MEDIO" << endl;
            cout << setw(23) << "4-AVANCADO" << endl;
            cout << setw(27) << "5-PROFISSIONAL" << endl;
            cout << setw(30) << "6-VOLTAR PRO MENU" << endl;
            for(int i=0; i<40; i++) cout << "=";
            cout << endl;
            cin >> escolha;
        }while(escolha < 1 || escolha > 6);

    if(escolha == 4) {
        do {
            ifstream coletaTemas;
            Stema temas;

            count=0;
            system("CLS");
            cout << "TEMAS ATUAIS:" << endl;

            coletaTemas.open("Temas.dat", ios::binary);

            if(!coletaTemas.is_open()){
                cout << "ERRO ABRINDO ARQUIVO PARA EDITAR TEMAS" << endl;
                exit(-1);
            }

            do{
                    coletaTemas.seekg(count * sizeof(Stema), ios::beg);
                    coletaTemas.read((char *) &temas, sizeof(Stema));
                    if(coletaTemas.gcount() == sizeof(Stema)){
                        cout << count+1 << "-" << temas.tema << endl;
                        count++;
                    }
            }while(coletaTemas.gcount() == sizeof(Stema));

            cout << endl;

            cout << "ESCOLHA UMA OPCAO: " << endl;
            cout << "1-ADICIONAR TEMA" << endl;
            cout << "2-EDITAR TEMA" << endl;
            cout << "3-EXCLUIR TEMA" << endl;

            cin >> escolha_config;
        }while(escolha_config<1 || escolha_config>3);

        switch (escolha_config)
        {
        case 1:
            adicionaTema();
            break;
        
        case 2:
            editaTema();
            break;
        case 3:
            excluiTema();
            break;
        }
    }
    else if(escolha == 5) {
        cout << "A";
    }
    else if(escolha == 6)
        return modo;

    return escolha;
}
//=====================================================================
void Jogo :: historico() {
    int index = -1;
    int inicializados = 0;
    char wait;
    bool change;
    ifstream carregaRanks;
    ranking topJogadores[10], novo, aux;

    carregaRanks.open("Ranking.dat", ios::binary);
    if(!carregaRanks.is_open()){
        cout << "ERRO OBTENDO O RANKING" << endl;
        goto fim;
    }

    //Inicializa o top jogadores com o registro de pontuacao de 10 jogadores.
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

    //realiza um bubble sort entre o top 10 (inicializados).
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
        
        //Verifica se o pontos do jogador entra no top 10, e caso sim, o insere.
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
//=====================================================================
double Jogo :: printTime(timeval before , timeval after, int i){
    return (double) ((before.tv_sec * 1000000 + i*1000000 + before.tv_usec) - (after.tv_sec * 1000000 + after.tv_usec))/1000000;
}
//=====================================================================
void Jogo :: sair() {
    string escolha;
    if(emJogo) {
        cout << "O JOGO ESTA EM ANDAMENTO, TEM CERTEZA QUE QUER SAIR?? [y/n]";
        cin >> escolha;
    }

    exit(1);
}
//=====================================================================
int Jogo::menosJogada()const {

    ifstream ColetaStructs;
    SPalavras aux;
    int menor = 1000000000;
    int count = 0;

    ColetaStructs.open(tema+".dat", ios::binary);
    //Verificar se a função está sendo chamada apena após a definição do tema!

    if(! ColetaStructs.is_open()){
        cout << "ERRO EM OBTER A PALAVRA MENOS JOGADA" << endl;
        exit(-1);
    }

    do{

        ColetaStructs.seekg(count * sizeof(SPalavras));
        ColetaStructs.read( ( char *) &aux, sizeof(SPalavras) );

        if(aux.jaJogada < menor){
            menor = aux.jaJogada;
        }

        count++;

    }while(ColetaStructs.gcount() != sizeof(SPalavras) );

    return menor;

}
//=====================================================================
void Jogo::formaLista(string tema, char *Palavra){
    ifstream coletaPalavras;
    listaPalavras_Tema palavrasListadas;
    SPalavras SstructPalavra;
    int count = 0;

    coletaPalavras.open(tema+".dat", ios::binary);
    do{
        coletaPalavras.seekg(count * sizeof(SstructPalavra), ios::beg);
        coletaPalavras.read((char *) &SstructPalavra, sizeof(SstructPalavra));
        if(coletaPalavras.gcount() == sizeof(SstructPalavra)){
            count++;

            if(!strcmp(Palavra, SstructPalavra.Palavra))
                SstructPalavra.jaJogada++;

            palavrasListadas.insereItem(SstructPalavra.Palavra, SstructPalavra.jaJogada);

            }

    }while(coletaPalavras.gcount() == sizeof(SstructPalavra));
    coletaPalavras.close();

    palavrasListadas.escreveFicheiro(tema);

}
