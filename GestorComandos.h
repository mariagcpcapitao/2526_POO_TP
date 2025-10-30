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

class GestorComandos {
public:
    void processarComando(const std::string& linha);

private:
    std::vector<std::string> dividir(const std::string& linha);
    //Validação geral
    bool validarComando(const std::vector<std::string>& tokens);

    // Funções de validação específicas
    bool validarJardim(const std::vector<std::string>& tokens);
    bool validarPlanta(const std::vector<std::string>& tokens);
    bool validarColhe(const std::vector<std::string>& tokens);
    bool validarAvanca(const std::vector<std::string>& tokens);
    bool validarCompra(const std::vector<std::string>& tokens);
};

#endif //GESTORCOMANDOS_H
