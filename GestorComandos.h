//
// Created by 1663m on 29/10/2025.
//

#ifndef GESTORCOMANDOS_H
#define GESTORCOMANDOS_H
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cctype>
#include "Jardim.h"
using namespace std;
using std::string;

class GestorComandos {
    Jardim* jardim = nullptr;
public:
    void setJardim(Jardim* j) { jardim = j; }
    void processarComando(const string& linha);

private:
    std::vector<string> dividir(const string& linha);
    //Validação geral
    bool validarComando(const std::vector<string>& palavras);
    bool validarPosicao(const string& pos, int linha, int coluna);
    // Funções de validação específicas
    bool validarJardim(const std::vector<string>& palavras);
    bool validarPlanta(const std::vector<string>& palavras);
    bool validarColhe(const std::vector<string>& palavras);
    bool validarLPlanta(const std::vector<string>& palavras);
    bool validarAvanca(const std::vector<string>& palavras);
    bool validarCompra(const std::vector<string>& palavras);
    bool listarPlantas(const std::vector<string>& palavras);
    bool listarFerramentas(const std::vector<string>& palavras);
    bool validarLarga(const std::vector<string>& palavras);
    bool validarPega(const std::vector<string>& palavras);
    bool validarSai(const std::vector<string>& palavras);
    bool validarGrava(const std::vector<string>& palavras);
    bool validarRecupera(const std::vector<string>& palavras);
    bool validarApaga(const std::vector<string>& palavras);
    bool validarExecuta(const std::vector<string>& palavras);
};

#endif //GESTORCOMANDOS_H
