//=============================================================================
// EDA 2021/22 ficha 10 (arvores binarias de pesquisa)
// Rui P. Rocha (2022.04.26, 2019.04.07, 2017.04.24)
// Paulo Coimbra (2010.05.20, 2008.06.01)
//=============================================================================
// source file: CArvoreBinaria.cpp
//=============================================================================

#include "CArvoreBinaria.h"

//=============================================================================
// classe CArvoreBinaria - codigo dos metodos como na ficha 10 (e slides teoricas)
//=============================================================================

CArvoreBinaria::CArvoreBinaria() {  // Construtor
    raiz = nullptr;
}
//=============================================================================
CArvoreBinaria::CArvoreBinaria(int *tabela, int tamanho){
    raiz = nullptr;
    for(int i = 0; i < tamanho; i++){
        insere(tabela[i]);
    }
}
//=============================================================================
CArvoreBinaria::~CArvoreBinaria() {  // Destrutor
    destroi();    // metodo que elimina todos os nos
}
//=============================================================================

// metodo public para destruir todos os nos da arvore
void CArvoreBinaria::destroi(){
    destroiSubArvore(raiz); // chama o metodo private (recursivo)
    raiz = nullptr;
}
//=============================================================================

// metodo private para destruir uma subarvore
void CArvoreBinaria::destroiSubArvore(CNoArvore *pArvore) {
    if (pArvore != nullptr) {
        destroiSubArvore(pArvore->esq);
        destroiSubArvore(pArvore->dir);
        delete pArvore;
    }
}
//=============================================================================

// metodo public para pesquisar recursivamente toda a arvore
bool CArvoreBinaria::procura(int item) const {
    return procuraRecursiva(raiz, item);
}
//=============================================================================

// metodo private para pesquisar recursivamente numa subarvore
bool CArvoreBinaria::procuraRecursiva(CNoArvore *raiz, int item) const {
    // casos elementares
    if (raiz == nullptr) return false;
    if (raiz->dados == item) return true;

    // caso geral
    if (raiz->dados < item)
        return procuraRecursiva(raiz->dir, item);
    else return procuraRecursiva(raiz->esq, item);
}
//=============================================================================

// metodo public para a travessia da arvore pre-ordem
void CArvoreBinaria::escrevePreOrdem() const {
        escrevePreOrdem(raiz);
        cout << endl;
}
//=============================================================================

// metodo private para a travessia recursiva da subarvore pre-ordem
void CArvoreBinaria::escrevePreOrdem(CNoArvore* raiz) const {
    if (raiz == nullptr) return;
    cout << raiz->dados << endl;
    escrevePreOrdem(raiz->esq);
    escrevePreOrdem(raiz->dir);
}
//=============================================================================

// metodo public para fazer a insercao ordenada de um novo valor
void CArvoreBinaria::insere(int item) {
    if (raiz != nullptr) insere(item, raiz); // chama o metodo private que faz o trabalho
    else {  // cria o primeiro no da arvore
        raiz = new CNoArvore;
        raiz->dados = item;
        raiz->esq = raiz->dir = nullptr;
    }
}
//=============================================================================

// metodo private para fazer a insercao ordenada de um novo valor numa subarvore
void CArvoreBinaria::insere(int item, CNoArvore *raiz) {
    if (item < raiz->dados) {
        if (raiz->esq != nullptr) insere(item, raiz->esq);
        else { // novo no e o primeiro no da subarvore esquerda
            raiz->esq = new CNoArvore;
            raiz->esq->dados = item;
            raiz->esq->esq = raiz->esq->dir = nullptr;
        }
    }
    else if (item > raiz->dados) {
        if (raiz->dir != nullptr) insere(item, raiz->dir);
        else { // novo no e o primeiro no da subarvore direita
            raiz->dir = new CNoArvore;
            raiz->dir->dados = item;
            raiz->dir->esq = raiz->dir->dir = nullptr;
        }
    }
}
//=============================================================================

bool CArvoreBinaria::elimina(int item) {
    CNoArvore *pai, *aux, *filho, *sucessor;
    bool encontrado=false;

    // procura o no a eliminar
    pai = nullptr;
    aux = raiz;
    while ( (aux != nullptr) && (!encontrado) ) {
        if (aux->dados == item) encontrado = true;
        else if (item < aux->dados) {
            pai = aux;
            aux = aux->esq;
        }
        else {
            pai = aux;
            aux = aux->dir;
        }
    }
    // se for encontrado ?aux? aponta para o no
    // a eliminar e ?pai? aponta para o seu pai (se existir)

    if (encontrado) {
        // se no tem no maximo um filho
        if ( (aux->esq == nullptr) || (aux->dir == nullptr) ) {
            if (aux->esq != nullptr)
                filho = aux->esq;
            else filho = aux->dir;
            if (pai == nullptr) // caso especial: apaga raiz
                raiz = filho;
            else {           // atualiza ligacoes
                if (aux->dados < pai->dados) pai->esq = filho;
                else pai->dir = filho;
            }
            delete aux;
        }
        else {  // eliminar no com dois filhos
            // procura sucessor
            sucessor = aux->dir;
            pai = aux;
            while (sucessor->esq != nullptr) {
                pai = sucessor;
                sucessor = sucessor->esq;
            }
            aux->dados = sucessor->dados; // troca val.
            if (sucessor == aux->dir) aux->dir = sucessor->dir;
            else // substitui pelo seu sucessor `a dir.
                pai->esq = sucessor->dir;
            delete sucessor;
        }
        return true;
    }
    return false;
}
//=============================================================================
void CArvoreBinaria::escrevePorOrdem(void) const{
    escrevePorOrdem(raiz);
    cout << endl;
}
//=============================================================================
void CArvoreBinaria::escrevePorOrdem(CNoArvore *raiz) const{
    if(raiz == nullptr) return;
    escrevePorOrdem(raiz->esq);
    cout << raiz->dados << endl;
    escrevePorOrdem(raiz->dir);
}
//=============================================================================
void CArvoreBinaria::escrevePosOrdem(void) const{
    escrevePosOrdem(raiz);
    cout << endl;
}
//=============================================================================
void CArvoreBinaria::escrevePosOrdem(CNoArvore *raiz) const{
    if(raiz == nullptr) return;

    escrevePosOrdem(raiz->esq);
    escrevePosOrdem(raiz->dir);
    cout << raiz->dados << endl;
}
//=============================================================================
void CArvoreBinaria::maxMin(int &max, int &min) const{
    max =  Max(raiz);
    min = Min(raiz);
}
//=============================================================================
int CArvoreBinaria::Max(CNoArvore *raiz) const{
    if(raiz == nullptr) return -100000;
    if(raiz->esq == nullptr) return raiz->dados;
    return Max(raiz->esq);
}
//=============================================================================
int CArvoreBinaria::Min(CNoArvore *raiz) const{
    if(raiz == nullptr) return -100000;
    if(raiz->dir == nullptr) return raiz->dados;
    return Min(raiz->dir);
}
//=============================================================================
void CArvoreBinaria::soma(int &total) const{
    total = Soma(raiz);
}
//=============================================================================
int CArvoreBinaria::Soma(CNoArvore *raiz)const{
    if(raiz == nullptr) return 0;

    return raiz->dados + Soma(raiz->esq) + Soma(raiz->dir);
    
}
//=============================================================================
void CArvoreBinaria::somaFolhas(int & total) const{
    total = SomaFolhas(raiz);
}
//=============================================================================
int CArvoreBinaria::SomaFolhas(CNoArvore *raiz)const {
    if(raiz == nullptr) return 0;
    if(raiz->esq != nullptr || raiz->dir != nullptr) return 0 + SomaFolhas(raiz->esq) + SomaFolhas(raiz->dir);

    return raiz->dados;

}
//=============================================================================
void CArvoreBinaria::somaEsquerda(int & total)const {
    total = SomaEsquerda(raiz, raiz);
}
//=============================================================================
int CArvoreBinaria::SomaEsquerda(CNoArvore *raiz, CNoArvore *pai) const{
    if(raiz == nullptr) return 0;
    

    if(raiz->dados < pai->dados){ 
        pai = raiz;
        return raiz->dados + SomaEsquerda(raiz->esq, pai) + SomaEsquerda(raiz->dir, pai);
    }

    pai = raiz;

    return 0 + SomaEsquerda(raiz->esq, pai) + SomaEsquerda(raiz->dir, pai);

}
//=============================================================================
void CArvoreBinaria::escreveFicheiroPreOrdem(string nome) const {
        escreveFicheiroPreOrdem(raiz, nome);
}
//=============================================================================
void CArvoreBinaria::escreveFicheiroPreOrdem(CNoArvore* raiz, string nomeFicheiro) const {
    if (raiz == nullptr) return;
    ofstream ficheiro;
    int aux;
    ficheiro.open(nomeFicheiro, ios::app | ios::binary);
    if(!ficheiro.is_open()){
        cout << "ERRO ABRINDO FICHEIRO" << endl;
        return;
    }
    aux = raiz->dados;
    ficheiro.write((char *) &aux, sizeof(int));
    escreveFicheiroPreOrdem(raiz->esq, nomeFicheiro);
    escreveFicheiroPreOrdem(raiz->dir, nomeFicheiro);
    ficheiro.close();
}
//=============================================================================
void CArvoreBinaria::leFicheiroPreOrdem(string nomeFicheiro) {
    ifstream ficheiro;
    int aux;
    ficheiro.open(nomeFicheiro);
    if(!ficheiro.is_open()){
        cout << "ERRO ABRINDO FICHEIRO" << endl;
        return;
    }
    
    do{
        ficheiro.read((char *) &aux, sizeof(int));
        insere(aux);
    }while(ficheiro.gcount() == sizeof(int));

    ficheiro.close();
}
//=============================================================================
int CArvoreBinaria::desequilibrio(void) const{
    bool encontrada = false;
    int menor , maior;
    menor = folhaMenosFunda(raiz);
    maior = folhaMaisFunda(raiz);

    return maior - menor;
}
//=============================================================================
int CArvoreBinaria::folhaMenosFunda(CNoArvore* raiz) const{
    if(raiz == nullptr) return 0;
    
    int esquerda = INT8_MAX;
    int direita = INT8_MAX;
    if(raiz->dir != nullptr){
    direita = 1;
    direita = direita + folhaMenosFunda(raiz->dir);
    }
    
    if(raiz->esq != nullptr){
    esquerda = 1;
    esquerda = esquerda + folhaMenosFunda(raiz->esq);
    }
  
    if( raiz->esq == nullptr && raiz->dir == nullptr){
        return 0;
    }

    if(raiz->esq == nullptr && raiz->dir != nullptr){
         return direita;
    }
    if(raiz->esq != nullptr && raiz->dir == nullptr){
        return esquerda;
    }
    if(raiz->esq != nullptr && raiz->dir != nullptr){
        if(esquerda < direita){
            return esquerda;
        }
        return direita;
    }

}
//=============================================================================
int CArvoreBinaria::folhaMaisFunda(CNoArvore* raiz) const{
    if(raiz == nullptr) return 0;

    int esquerda;
    int direita;
    if(raiz->dir != nullptr){
    direita = 1;
    direita = direita + folhaMaisFunda(raiz->dir);
    }

    if(raiz->esq != nullptr){
    esquerda = 1;
    esquerda = esquerda + folhaMaisFunda(raiz->esq);
    }

    if( raiz->dir == nullptr && raiz->dir == nullptr) return 0;

    if(raiz->esq == nullptr && raiz->dir != nullptr) return direita;
    if(raiz->esq != nullptr && raiz->dir == nullptr) return esquerda;

    if(raiz->esq != nullptr && raiz->dir != nullptr){
        if(esquerda > direita) return esquerda;
        return direita;
    }

}
//=============================================================================
bool CArvoreBinaria::caminhoDesdeRaiz(int item, CListaInteiros &cam)const{
    return caminhoDesdeRaiz(raiz, item, cam);
}
//=============================================================================
bool CArvoreBinaria::caminhoDesdeRaiz(CNoArvore *raiz, int item, CListaInteiros &cam) const{
    int aux;
    if(raiz == nullptr) return false;

        aux = raiz->dados;
        cam.insereItem(aux);
    

    if(raiz->dados == item){
        return true;
    }

    if(raiz->dir == nullptr && raiz->esq == nullptr ){
        cam.apagaItem(aux);
        return false;
    }

    if(caminhoDesdeRaiz(raiz->dir, item, cam) || caminhoDesdeRaiz(raiz->esq, item , cam)){
        return true;
    }

    cam.apagaItem(aux);

    return false;
}
//=============================================================================
int CArvoreBinaria::profundidade(int item)const{
    return profundidade(raiz, item);
}
//=============================================================================
int CArvoreBinaria::profundidade(CNoArvore *raiz, int item) const{
    int aux = 0;
    int prof = 1;
    if(raiz == nullptr) return -1;

    if(raiz->dados == item) return 0;

    if(raiz->dir == nullptr && raiz->esq == nullptr) return -1;


    aux = profundidade(raiz->dir, item);

    if(aux >= 0) return prof+aux;

    aux = profundidade(raiz->esq, item);

    if(aux >= 0) return prof+aux;

    return -1;

}
//=============================================================================
int CArvoreBinaria::obtemMinExcetoFolhas(void) const{
    if(raiz == nullptr) return INT32_MAX;
    return obtemMinExcetoFolhas(raiz->esq,raiz);
}
//=============================================================================
int CArvoreBinaria::obtemMinExcetoFolhas(CNoArvore *raiz, CNoArvore *pai) const{
    
    if(raiz == nullptr) return INT32_MAX;

    if(raiz->dir == nullptr && raiz->esq == nullptr) return pai->dados;

    int direita;
    int esquerda;
    
    if(raiz->esq != nullptr && raiz->dir == nullptr) return obtemMinExcetoFolhas(raiz->esq, raiz);

    if(raiz->esq == nullptr && raiz->dir != nullptr) return obtemMinExcetoFolhas(raiz->dir, raiz);


    if(raiz->esq != nullptr && raiz->dir != nullptr){
        direita = obtemMinExcetoFolhas(raiz->dir, raiz);
        esquerda = obtemMinExcetoFolhas(raiz->esq, raiz);

        if (direita == INT32_MAX && esquerda == INT32_MAX ) return raiz->dados;
        if(direita < esquerda) return direita;
        return esquerda;
    }

    return obtemMinExcetoFolhas(raiz->esq, raiz);

}
//=============================================================================
int CArvoreBinaria::valorPai(int n) const{

    CNoArvore *pai;
    pai = ponteiroParaPai(raiz, raiz, n);

    if(pai == nullptr) return INT32_MAX;

    return pai->dados;
}
//=============================================================================
CNoArvore* CArvoreBinaria::ponteiroParaPai(CNoArvore *raiz,CNoArvore *pai,int n)const{
    if(raiz == pai && raiz->dados == n) return nullptr;

    if(raiz->dados == n) return pai;

    if(raiz->esq == nullptr && raiz->dir == nullptr) return nullptr;

    if(raiz->esq != nullptr && raiz->dir != nullptr){
        CNoArvore *esquerda = ponteiroParaPai(raiz->esq, raiz, n);
        CNoArvore *direita = ponteiroParaPai(raiz->dir, raiz, n);

        if(direita != nullptr) return direita;
        return esquerda;
    }

    if(raiz->esq != nullptr && raiz->dir == nullptr) return ponteiroParaPai(raiz->esq, raiz, n);

    if(raiz->esq == nullptr && raiz->dir != nullptr) return ponteiroParaPai(raiz->dir, raiz, n);

}
//=============================================================================

//=============================================================================
CNoArvore* CArvoreBinaria::getNo(CNoArvore *raiz,,int n)const{
    if(raiz->dados == n) return raiz;

    if(raiz->esq == nullptr && raiz->dir == nullptr) return nullptr;

    if(raiz->esq != nullptr && raiz->dir != nullptr){
        CNoArvore *esquerda = ponteiroParaPai(raiz->esq, n);
        CNoArvore *direita = ponteiroParaPai(raiz->dir, n);

        if(direita != nullptr) return direita;
        return esquerda;
    }

    if(raiz->esq != nullptr && raiz->dir == nullptr) return ponteiroParaPai(raiz->esq, raiz, n);

    if(raiz->esq == nullptr && raiz->dir != nullptr) return ponteiroParaPai(raiz->dir, raiz, n);
}
