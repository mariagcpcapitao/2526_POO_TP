#include <iostream>

#include "Ferramenta.h"
#include "GestorComandos.h"
#include "Planta.h"
#include "Solo.h"

int main() {
    Simulador sim;
    GestorComandos gc(&sim);
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
