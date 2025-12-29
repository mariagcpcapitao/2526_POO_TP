#ifndef SIMULACAO_H
#define SIMULACAO_H


#include "Jardim.h"
#include <map>
#include <string>
using namespace std;
using std::string;
class Jardim;
class Simulador {
    Jardineiro* j;
    Jardim* jardimAtual = nullptr;
    map<string, Jardim*> jardins;


public:
    int instante;
    Simulador();
    ~Simulador();
    void avanca(int i=1);
    void resetaLimitesTurno();
    void criarJardim(int linhas, int colunas);
    void grava(const string& nome);
    void recupera(const string& nome);
    void apaga(const string& nome);
    bool sair();
    bool moverJardineiro(char direcao);
    void setJardim(Jardim* j);
    Jardineiro* getJardineiro() { return j; }

    Jardim* getJardimAtual() const { return jardimAtual; }
};

#endif


