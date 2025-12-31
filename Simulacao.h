#ifndef SIMULACAO_H
#define SIMULACAO_H


#include "Jardim.h"
#include "Jardineiro.h"
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
    void avanca(int n);
    void resetaLimitesTurno();
    void criarJardim(int linhas, int colunas);
    void grava(const string& nome);
    void recupera(const string& nome);
    void apaga(const string& nome);
    bool sair();
    bool executaComandoMover(char dir);
    bool executaColhe(int l, int c);
    bool executaPlanta(int l, int c, char tipo);
    void setJardim(Jardim* j);
    Jardineiro* getJardineiro() { return j; }
    bool comprarFerramenta(char tipo);
    void listarInfoFerr();

    Jardim* getJardimAtual() const { return jardimAtual; }
};

#endif


