#include <iostream>
#include <cstring>
using namespace std;

class CNoArvore {
    int dados;
    CNoArvore *esq; // ponteiro para subárvore esquerda
    CNoArvore *dir; // ponteiro para subárvore direita
    friend class CArvoreBinaria; // esta classe pode aceder a atributos private
};
class CArvoreBinaria {
    CNoArvore *raiz;
    // ponteiro para a raiz da árvore
    bool procuraRecursiva(CNoArvore*, int) const;
    void escrevePreOrdem(CNoArvore*) const;
    void insere(int, CNoArvore*);
    void destroi(CNoArvore*);
    void escrevePorOrdem(CNoArvore*) const;
    void escrevePosOrdem(CNoArvore*) const;
    int getMax(CNoArvore *pArvore) const;
    int getMin(CNoArvore *pArvore) const;
    int somaElementos(CNoArvore *pArvore);
    int somaFolhas(CNoArvore *pArvore);
    int somaFolhasEsq(CNoArvore *, CNoArvore *);
    int folhaMenosFunda(CNoArvore*)const;
    int folhaMaisFunda(CNoArvore*)const;
    int profundidade(CNoArvore*, int)const;
    void percorre(CNoArvore *raiz);
    CNoArvore* getNo(CNoArvore *, int)const;
    int altura(CNoArvore *pArvore) const;
    CNoArvore* ponteiroParaPai(CNoArvore *raiz,CNoArvore *pai, int n)const;
    public:
        CArvoreBinaria();
        CArvoreBinaria(int *, int);
        ~CArvoreBinaria();
        bool procura(int) const;
        void escrevePreOrdem() const;
        void insere(int);
        bool elimina(int);
        void destroi();
        void escrevePorOrdem() const;
        void escrevePosOrdem() const;
        void maiorEmenorR(int &, int &) const;
        void maiorEmenorI(int &, int &) const;
        int somaElementos();
        int somaFolhas();
        int somaFolhasEsq();
        int desequilibrio(void)const;
        int profundidade(int)const;
        int altura(int) const;
        int valorPai(int n)const;
};

// Construtor
CArvoreBinaria::CArvoreBinaria() { raiz = nullptr; }

// Destrutor
CArvoreBinaria::~CArvoreBinaria() { destroi(); }

CArvoreBinaria::CArvoreBinaria(int *tab, int n_elem) {
    if(n_elem == 0) raiz == nullptr;
    else {
        for(int i=0; i<n_elem; i++) {
            insere(tab[i]);
        }
    }
}

void CArvoreBinaria::destroi() {
    destroi(raiz);
    raiz = nullptr;
}

void CArvoreBinaria::destroi(CNoArvore *pArvore) {
    if(pArvore != nullptr) {
        destroi(pArvore->esq);
        destroi(pArvore->dir);
        delete pArvore;
    }
}

bool CArvoreBinaria::elimina(int item) {
    CNoArvore *pai, *aux, *filho, *sucessor;
    bool encontrado=false;
    // procura o nó a eliminar
    pai = nullptr; aux = raiz;
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
    // se for encontrado ‘aux’ aponta para o nó
    // a eliminar e ‘pai’ aponta para o seu pai (se existir)
    if (encontrado) {
        // se nó tem no máximo um filho
        if ( (aux->esq == nullptr) || (aux->dir == nullptr) ) {
            if (aux->esq != nullptr) filho = aux->esq;
            else filho = aux->dir;
            if (pai == nullptr) // caso especial: apaga raiz
            raiz = filho;
            else { // atualiza ligações
                if (aux->dados < pai->dados) pai->esq = filho;
                else pai->dir = filho;
            }
            delete aux;
        }
        else { // eliminar nó com dois filhos
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

void CArvoreBinaria::insere(int item) {
    if (raiz != nullptr) insere(item, raiz);
    else {
        raiz = new CNoArvore;
        raiz->dados = item;
        raiz->esq = raiz->dir = nullptr;
    }
}

void CArvoreBinaria::insere(int item, CNoArvore *raiz) {
    if (item < raiz->dados) {
        if (raiz->esq != nullptr) insere(item, raiz->esq);
        else {
            raiz->esq = new CNoArvore;
            raiz->esq->dados = item;
            raiz->esq->esq = raiz->esq->dir = nullptr;
        }
    }
    else if (item > raiz->dados) {
        if (raiz->dir != nullptr) insere(item, raiz->dir);
        else {
            raiz->dir = new CNoArvore;
            raiz->dir->dados = item;
            raiz->dir->esq = raiz->dir->dir = nullptr;
        }
    }
}

bool CArvoreBinaria::procura(int item) const {
    return procuraRecursiva(raiz, item);
}

bool CArvoreBinaria::procuraRecursiva(CNoArvore *raiz, int item) const {
    if (raiz == nullptr) return false;
    if (raiz->dados == item) return true;

    if (raiz->dados < item) return procuraRecursiva(raiz->dir, item);
    else return procuraRecursiva(raiz->esq, item);
}

void CArvoreBinaria::escrevePreOrdem() const {
    if(raiz == nullptr){
        cout << "Árvore vazia!" << endl;
        return;
    }
    escrevePreOrdem(raiz);
}

void CArvoreBinaria::escrevePreOrdem(CNoArvore *pArvore) const {
    if (pArvore == nullptr) return;
    cout << pArvore->dados << " ";
    if (pArvore->esq != NULL) escrevePreOrdem(pArvore->esq);
    if (pArvore->dir != NULL) escrevePreOrdem(pArvore->dir);
}

void CArvoreBinaria::escrevePorOrdem() const {
    if(raiz == nullptr){
        cout << "Árvore vazia!" << endl;
        return;
    }
    escrevePorOrdem(raiz);
}

void CArvoreBinaria::escrevePorOrdem(CNoArvore *pArvore) const {
    if (pArvore == nullptr) return;
    if (pArvore->esq != NULL) escrevePorOrdem(pArvore->esq);
    cout << pArvore->dados << " ";
    if (pArvore->dir != NULL) escrevePorOrdem(pArvore->dir);
}

void CArvoreBinaria::escrevePosOrdem() const {
    if(raiz == nullptr){
        cout << "Árvore vazia!" << endl;
        return;
    }
    escrevePosOrdem(raiz);
}

void CArvoreBinaria::escrevePosOrdem(CNoArvore *pArvore) const {
    if (pArvore == nullptr) return;
    if (pArvore->esq != NULL) escrevePosOrdem(pArvore->esq);
    if (pArvore->dir != NULL) escrevePosOrdem(pArvore->dir);
    cout << pArvore->dados << " ";
}

int CArvoreBinaria::getMax(CNoArvore *pArvore) const {
    if(pArvore == nullptr) return 0;
    if(pArvore->dir == nullptr) return pArvore->dados;

    return getMax(pArvore->dir);
}

int CArvoreBinaria::getMin(CNoArvore *pArvore) const {
    if(pArvore == nullptr) return 0;
    if(pArvore->esq == nullptr) return pArvore->dados;

    return getMin(pArvore->esq);
}

void CArvoreBinaria::maiorEmenorR(int &maior, int &menor) const {
    maior = getMax(raiz);
    menor = getMin(raiz);
}

void CArvoreBinaria::maiorEmenorI(int &maior, int &menor) const {
    CNoArvore *atual;

    atual = raiz;
    if(raiz == nullptr) {
        maior = 1;
        menor = 0;
        return;
    }

    while(atual != nullptr) {
        maior = atual->dados;
        atual = atual->dir;
    }

    atual = raiz;
    while(atual != nullptr) {
        menor = atual->dados;
        atual = atual->esq;
    }
}

int CArvoreBinaria::somaFolhas(CNoArvore *pArvore) {
    if(pArvore == nullptr) return 0;
    if(pArvore->esq == nullptr && pArvore->dir == nullptr) return pArvore->dados;

    return somaFolhas(pArvore->esq) + somaFolhas(pArvore->dir);
}

int CArvoreBinaria::somaFolhas() {
    return somaFolhas(raiz);
}

int CArvoreBinaria::somaElementos(CNoArvore *pArvore) {
    if(pArvore == nullptr) return 0;
    return pArvore->dados + somaElementos(pArvore->esq) + somaElementos(pArvore->dir);
}

int CArvoreBinaria::somaElementos() {
    return somaElementos(raiz);
}

int CArvoreBinaria::somaFolhasEsq(CNoArvore *filho, CNoArvore *pai) {
    if(filho == nullptr) return 0;

    if(pai->dados > filho->dados) {
        return filho->dados + somaFolhasEsq(filho->esq, filho) + somaFolhasEsq(filho->dir, filho);
    }
    return somaFolhasEsq(filho->esq, filho) + somaFolhasEsq(filho->dir, filho);
}

int CArvoreBinaria::somaFolhasEsq() {
    return somaFolhasEsq(raiz, raiz);
}

int CArvoreBinaria::desequilibrio()const {
    int menor , maior;
    menor = folhaMenosFunda(raiz);
    maior = folhaMaisFunda(raiz);

    cout << maior << " - " << menor << " - ";

    return maior - menor;
}

int CArvoreBinaria::folhaMaisFunda(CNoArvore *raiz) const {
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

int CArvoreBinaria::folhaMenosFunda(CNoArvore *raiz) const {
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


int CArvoreBinaria::profundidade(int item)const{
    return profundidade(raiz, item);
}

int CArvoreBinaria::profundidade(CNoArvore *raiz, int item)const{
    int contador;
    
    if (raiz == nullptr || raiz->dados == item) return 0;
    
    if(raiz->dir == nullptr && raiz->esq == nullptr) {
        contador = 0;
        return -1;
    }

    if (raiz->dados < item) {
        contador = 1 + profundidade(raiz->dir, item);
    }
    else {
        contador = 1 + profundidade(raiz->esq, item);
    }
}

CNoArvore* CArvoreBinaria::getNo(CNoArvore *raiz, int item)const{
    if(raiz == nullptr) return nullptr;
    if(raiz->dados == item) return raiz;

    if(raiz->dados < item)
    return getNo(raiz->dir, item);
    return getNo(raiz->esq, item);
}

int CArvoreBinaria::valorPai(int n) const{ 
    CNoArvore *pai;
    if(raiz == nullptr || raiz->dados == n) return 0;
    pai = ponteiroParaPai(raiz, raiz, n);
    return pai->dados;
}

CNoArvore* CArvoreBinaria::ponteiroParaPai(CNoArvore *raiz,CNoArvore *pai, int n)const {
    if(raiz == nullptr || raiz == pai && raiz->dados == n) return nullptr;

    if(raiz->dados == n) {
        return pai;
    }

    if(raiz->dados < n) return ponteiroParaPai(raiz->dir, raiz, n);
    else return ponteiroParaPai(raiz->esq, raiz, n);
}

int main() {
    int maior, menor;
    CArvoreBinaria tree1;
    tree1.insere(6);
    tree1.insere(3);
    tree1.insere(2);
    tree1.insere(12);
    tree1.insere(10);
    tree1.insere(7);
    tree1.insere(11);
    tree1.insere(15);
    tree1.insere(20);
    tree1.escrevePosOrdem();
    cout << endl;
    //tree1.maiorEmenorR(maior, menor);
    //cout << maior << " - " << menor << endl;
    tree1.maiorEmenorI(maior, menor);
    //cout << maior << " - " << menor << endl;
    //cout << tree1.somaFolhas() << endl;
    //cout << tree1.somaElementos() << endl;
    //cout << tree1.somaFolhasEsq() << endl;

    //cout << tree1.desequilibrio() << endl;
    //cout << tree1.profundidade(27) << endl;
    cout << tree1.valorPai(10);
    return 0;
}