//
// Created by 1663m on 29/10/2025.
//

#include "GestorComandos.h"
std::vector<string> GestorComandos::dividir(const string& linha) {
    std::istringstream iss(linha);
    std::vector<string> palavras;
    string palavra;
    while (iss >> palavra)
        palavras.push_back(palavra);
    return palavras;
}

void GestorComandos::processarComando(const string& linha) {
    auto palavras = dividir(linha);

    if (palavras.empty()) return;

    if (!validarComando(palavras))
        std::cout << "Erro: comando invalido.\n";
}

bool GestorComandos::validarComando(const std::vector<string>& palavras) {
    string cmd = palavras[0];

    if (cmd == "jardim") return validarJardim(palavras);
    if (cmd == "planta") return validarPlanta(palavras);
    if (cmd == "colhe") return validarColhe(palavras);
    if (cmd == "avanca") return validarAvanca(palavras);
    if (cmd == "compra") return validarCompra(palavras);
    if (cmd == "lplantas") return listarPlantas(palavras);
    if (cmd == "lferr") return listarFerramentas(palavras);
    if (cmd == "pega") return validarPega(palavras);
    if (cmd == "larga") return validarLarga(palavras);
    if (cmd == "sai") return validarSai(palavras);
    if (cmd == "fim") { std::cout << "A fechar o programa...\n"; return true; }

    std::cout << "Erro: comando desconhecido.\n";
    return false;
}
bool GestorComandos::validarJardim(const std::vector<string>& palavras) {
    if (palavras.size() != 3) {
        std::cout << "Erro: jardim requer 2 parametros.\n";
        return false;
    }
    try {
        int linhas = std::stoi(palavras[1]);
        int colunas = std::stoi(palavras[2]);
        if (linhas <= 0 || colunas <= 0 || linhas > 26 || colunas > 26)
            throw std::out_of_range("fora de limites");
    } catch (...) {
        std::cout << "Erro: parametros invalidos para jardim.\n";
        return false;
    }
    std::cout << "Comando valido: jardim " << palavras[1] << " " << palavras[2] << "\n";
    return true;
}

bool GestorComandos::validarPlanta(const std::vector<string>& palavras) {
    if (palavras.size() != 3) {
        std::cout << "Erro: planta requer posição e tipo.\n";
        return false;
    }
    string pos = palavras[1];
    if (pos.size() != 2 || !isalpha(pos[0]) || !isalpha(pos[1]) ||
        !islower(pos[0]) || !islower(pos[1])) {
        std::cout << "Erro: posicao invalida.\n";
        return false;
    }
    char tipo = palavras[2][0];
    if (string("crex").find(tipo) == string::npos) {
        std::cout << "Erro: tipo de planta inválido (usa c, r, e ou x).\n";
        return false;
    }
    std::cout << "Comando valido: planta " << pos << " " << tipo << "\n";
    return true;
}

bool GestorComandos::validarColhe(const std::vector<string>& palavras) {
    if (palavras.size() != 2) {
        std::cout << "Erro: colhe requer uma posicao.\n";
        return false;
    }
    string pos = palavras[1];
    if (pos.size() != 2 || !islower(pos[0]) || !islower(pos[1])) {
        std::cout << "Erro: posicao invalida.\n";
        return false;
    }
    std::cout << "Comando valido: colhe " << pos << "\n";
    return true;
}

bool GestorComandos::validarAvanca(const std::vector<string>& palavras) {
    if (palavras.size() > 2) {
        std::cout << "Erro: avanca tem no maximo 1 parametro.\n";
        return false;
    }

    if (palavras.size() == 2){
        try {
            int n = std::stoi(palavras[1]);
            if (n <= 0) throw std::invalid_argument("n invalido");
        } catch (...) {
            std::cout << "Erro: parametro invalido em avanca.\n";
            return false;
        }
    }
    std::cout << "Comando valido: avanca\n";
    return true;
}

bool GestorComandos::validarCompra(const std::vector<string>& palavras) {
    if (palavras.size() != 2) {
        std::cout << "Erro: compra requer o tipo de ferramenta.\n";
        return false;
    }
    char tipo = palavras[1][0];
    if (string("gat z").find(tipo) == string::npos) {
        std::cout << "Erro: ferramenta invalida (usa g, a, t ou z).\n";
        return false;
    }
    std::cout << "Comando valido: compra " << tipo << "\n";
    return true;
}
bool GestorComandos::listarPlantas(const std::vector<string>& palavras) {
    if (palavras.size() != 1) {
        std::cout << "Para listar as plantas só precisas de uma palavra.\n";
        return false;
    }
    std::cout << "Comando valido: Listar todas as plantas\n";
    return true;
}
bool GestorComandos::listarFerramentas(const std::vector<string>& palavras) {
    if (palavras.size() != 1) {
        std::cout << "Para listar as ferramentas só precisas de uma palavra.\n";
        return false;
    }
    std::cout << "Comando valido: Listar todas as ferramentas\n";
    return true;
}
bool GestorComandos::validarLarga(const std::vector<string>& palavras) {
    if (palavras.size() != 1) {
        std::cout << "Para largar a ferramenta só precisas de uma palavra.\n";
        return false;
    }
    std::cout << "Comando valido: Largar a ferramenta que tem na mao\n";
    return true;
}
bool GestorComandos::validarPega(const std::vector<string>& palavras) {
    if (palavras.size() == 1) {
        std::cout << "Erro: Eu sei que e para pegar mas em qual ferramenta?\n";
        return false;
    }
    if (palavras.size() > 2) {
        std::cout << "Erro: pega tem no maximo 1 parametro.\n";
        return false;
    }
    if (palavras.size() == 2) {
        try {
            int n = std::stoi(palavras[1]);//se o stoi nao conseguir converter pq nao é um num valido manda um std::invalid_argument tbm
            if (n <= 0) throw std::invalid_argument("n invalido");
        } catch (...) {
            std::cout << "Erro: parametro invalido em pega.\n";
            return false;
        }
    }
    std::cout << "Comando valido: pega na ferramenta de ID ...\n";
    return true;
}
bool GestorComandos::validarSai(const std::vector<string>& palavras) {
    if (palavras.size() != 1) {
        std::cout << "Para sair so precisas de uma palavra.\n";
        return false;
    }
    std::cout << "Comando valido: O jardineiro vai embora... \n";
    return true;
}