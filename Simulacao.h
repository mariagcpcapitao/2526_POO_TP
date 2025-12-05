#ifndef SIMULACAO_H
#define SIMULACAO_H
#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "Jardim.h"
#include <map>
#include <string>
using namespace std;
using std::string;

class Simulador {
    Jardim* jardimAtual = nullptr;
    //std::map< string, Jardim*> copias;

public:
    int instante;
    ~Simulador();

    void criarJardim(int linhas, int colunas);
    void grava(const string& nome);
    void recupera(const string& nome);
    void apaga(const string& nome);
    void executa(const string& ficheiro);

    Jardim* getJardimAtual() const { return jardimAtual; }
};

#endif

#endif //SIMULACAO_H
