#include "Fila.h"

#include <cstdlib>
#include <iostream>

using namespace std;

// classe No

class No {
private:
    int info;
    No* prox;
public:

    No(int info) // construtor
    {
        this->info = info;
        this->prox = NULL;
    }

    int getInfo() // obtém o valor
    {
        return info;
    }

    void setInfo(int i)
    {
        info = i;
    }
    
    No* getProx() // obtém o próximo No
    {
        return prox;
    }

    void setProx(No* p) // seta o próximo No
    {
        prox = p;
    }
};

// classe Lista

class Lista {
private:
    No* cabeca; // primeiro elemento
    No* cauda; // último elemento

public:

    Lista() {
        // se não passar elemento, então cabeca e cauda são NULL
        cabeca = NULL;
        cauda = NULL;
    }

    Lista(int v) {
        // se passar elemento, então cria novo No
        cabeca = new No(v);
        cauda = cabeca;
    }

    virtual ~Lista() // destrutor
    {
        delete cabeca;
    }

    void mostrar() // mostra todos os elementos da lista
    {
        cout << "\nImprimindo todos os elementos...\n";
        No* c = cabeca;

        if (vazia())
            cout << "A lista NAO possui elementos!!\n";
        else {
            while (c) // percorre a lista
            {
                cout << c->getInfo() << endl;
                c = c->getProx();
            }
            cout << endl;
        }
    }

    bool vazia() // verifica se a lista está vazia
    {
        return (cabeca == NULL);
    }

    // insere no início (semelhante a push_front da list)

    void inserir_inicio(int v) {
        No* novo_no = new No(v);

        if (vazia()) {
            cabeca = novo_no;
            cauda = novo_no;
        } else {
            novo_no->setProx(cabeca);
            cabeca = novo_no;
        }
    }

    // insere no final (semelhante a push_back da list)

    void inserir_final(int v) {
        No* novo_no = new No(v);

        if (vazia()) {
            cabeca = novo_no;
            cauda = novo_no;
        } else {
            cauda->setProx(novo_no);
            cauda = novo_no;
        }
    }

    // retorna o tamanho da lista

    int tamanho() {
        if (vazia()) // se for vazia, entã retorna 0
            return 0;

        No* c = cabeca;
        int tam = 0;

        // percorre a lista
        do {
            c = c->getProx();
            tam++;
        } while (c);

        return tam;
    }

    // verifica se um elemento existe na lista

    bool existe(int v) {
        No* c = cabeca;

        while (c) {
            if (c->getInfo() == v)
                return true;
            c = c->getProx();
        }
        return false;
    }

    // remove da lista, remoção do final (semelhante a pop_back da list)

    void remover() {
        if (!vazia()) {
            // se houver só 1 elemento
            if (cabeca->getProx() == NULL)
                cabeca = NULL;
            else if (cabeca->getProx()->getProx() == NULL) // 2 elementos
                cabeca->setProx(NULL);
            else // > 2 elementos
            {
                No* ant_ant = cabeca;
                No* ant = cabeca->getProx();
                No* corrente = cabeca->getProx()->getProx();

                while (corrente) {
                    No* aux = ant;
                    ant = corrente;
                    ant_ant = aux;
                    corrente = corrente->getProx();
                }
                delete ant_ant->getProx(); // libera memória
                ant_ant->setProx(NULL); // seta o prox como NULL
                cauda = ant_ant; // atualiza a cauda
            }
        }
    }
};

