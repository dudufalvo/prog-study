#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

#define MAX 51

struct Stema
{
    char tema[MAX];
    int elementos;
};

class Temas
{
public:
    Stema tema;
    Temas *proximo;
};
//=====================================================================
class listaTemas
{
    Temas *cabeca;

public:
    listaTemas() { cabeca = nullptr; }
    ~listaTemas();
    void insereItem(Stema tema);
    bool removeItem(int);
    void escreveLista(void);
    void escreveFicheiro(void);
};
listaTemas::~listaTemas(){
    Temas *atual, *proximo;
    atual = cabeca;
    while(atual != nullptr){
        proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}
bool listaTemas::removeItem(int index)
{
    Temas *anterior, *atual;
    atual = anterior = cabeca;

    if (index == 1)
    {
        cabeca = atual->proximo;
        delete atual;
        return true;
    }

    while (atual != nullptr)
    {
        index--;

        if (index == 0)
        {
            anterior->proximo = atual->proximo;
            delete atual;
            return true;
        }

        if (atual != cabeca)
        {
            anterior = anterior->proximo;
        }

        atual = atual->proximo;
    }

    return false;
}
void listaTemas::insereItem(Stema tema)
{
    Temas *novo = new Temas;
    Temas *atual;

    novo->tema = tema;
    novo->proximo = nullptr;

    if (cabeca == nullptr)
        cabeca = novo;
    else
    {
        atual = cabeca;
        while (atual->proximo != nullptr)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}
void listaTemas::escreveLista()
{
    Temas *atual = cabeca;
    if (atual == nullptr)
    {
        cout << "Lista Vazia..." << endl;
        return;
    }
    while (atual != nullptr)
    {
        cout << atual->tema.tema << endl;
        atual = atual->proximo;
    }
}
//=====================================================================
void listaTemas::escreveFicheiro(){
    Temas *atual = cabeca;
    
    ofstream salvarTemas;
    salvarTemas.open("Temas.dat", ios::binary | ios::trunc);
    salvarTemas.close();
    salvarTemas.open("Temas.dat", ios::binary | ios::app);

    if(!salvarTemas.is_open()){
        cout << "ERRO SALVANDO OS TEMAS" << endl;
        exit(0);
    }

    while(atual != nullptr){
        salvarTemas.write((char*)&atual->tema, sizeof(atual->tema));
        atual = atual->proximo;
    }

    salvarTemas.close();
}
int main()
{
    int count = 0;
    ifstream coletaTemas;
    Stema temas;

    listaTemas lista1;
    Stema tema1;
    Stema tema2;
    Stema tema3;
    Stema tema4;


    strcpy(tema1.tema, "FRUTAS");
    tema1.elementos = 8;
    strcpy(tema2.tema, "ESCOLAS");
    tema2.elementos = 28;
    strcpy(tema3.tema, "CURSOS");
    tema3.elementos = 84;
    strcpy(tema4.tema, "FACULDADES");
    tema4.elementos = 63;



    lista1.insereItem(tema1);
    lista1.insereItem(tema2);
    lista1.insereItem(tema3);
    lista1.insereItem(tema4);

    lista1.escreveLista();
    lista1.removeItem(1);
    cout << endl;
    lista1.escreveLista();
    lista1.escreveFicheiro();

    cout << "PRINT FICHEIRO: " << endl;

    coletaTemas.open("Temas.dat", ios::binary);

    if(!coletaTemas.is_open()){
        cout << "ERRO ABRINDO ARQUIVO PARA EDITAR TEMAS" << endl;
        exit(-1);
    }

    coletaTemas.seekg(1 * sizeof(Stema), ios::beg);
    coletaTemas.read((char *) &temas, sizeof(Stema));
    if(coletaTemas.gcount() == sizeof(Stema)){
        cout << count+1 << "-" << temas.tema << endl;
    }
    return 0;
}
