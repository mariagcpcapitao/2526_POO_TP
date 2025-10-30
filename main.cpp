#include <iostream>
#include "GestorComandos.h"

int main() {
    GestorComandos gc;
    std::string linha;

    std::cout << "Simulador de Jardim \n";
    std::cout << "Introduzir comandos ('fim' para sair)\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, linha);
        if (linha.empty()) continue;

        gc.processarComando(linha);
        if (linha == "fim") break;
    }

    std::cout << "Programa terminado.\n";
    return 0;
}
