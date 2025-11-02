


#include "GestorComandos.h"


int criado =0;
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
        if (cmd == "recupera")return validarRecupera(palavras);

    if(criado == 1) {
        if (cmd == "planta") return validarPlanta(palavras);
        if (cmd == "lplanta") return validarPlanta(palavras);
        if (cmd == "colhe") return validarColhe(palavras);
        if (cmd == "avanca") return validarAvanca(palavras);
        if (cmd == "compra") return validarCompra(palavras);
        if (cmd == "lplantas") return validarLPlantas(palavras);
        if (cmd == "entra") return validarCompra(palavras);
        if (cmd == "lferr") return validarLFerramentas(palavras);
        if (cmd == "pega") return validarPega(palavras);
        if (cmd == "larga") return validarLarga(palavras);
        if (cmd == "larea") return validarLArea(palavras);
        if (cmd == "lsolo") return validarLSolo(palavras);
        if (cmd == "sai") return validarSai(palavras);
        if (cmd == "grava") return validarGrava(palavras);
        if (cmd == "apaga")return validarApaga(palavras);
        if (cmd == "executa")return validarExecuta(palavras);
        if (cmd == "fim") { std::cout << "A fechar o programa...\n"; return true; }
    }
    if (criado==0)
        std::cout << "Erro: Para fazeres o que quer  que seja precisas de um jardim...\n";
    else
        std::cout << "Erro: comando desconhecido.\n";

    return false;
}
bool GestorComandos::validarPosicao(const string& pos, int linhas, int colunas) {
    if (pos.size() != 2 || !islower(pos[0]) || !islower(pos[1])) {
        std::cout << "Erro: formato de posicao invalido.\n";
        return false;
    }

    // Converte letras em índices
    int linha = pos[0] - 'a';
    int coluna = pos[1] - 'a';

    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas) {
        std::cout << "Erro: posição fora dos limites do jardim ("
                  << linhas << "x" << colunas << ").\n";
        return false;
    }

    return true;
}
bool GestorComandos::validarJardim(const std::vector<string>& palavras) {
    int linhas = std::stoi(palavras[1]);
    int colunas = std::stoi(palavras[2]);
    if (palavras.size() != 3) {
        std::cout << "Erro: jardim requer 2 parametros.\n";
        return false;
    }
    try {
        if (linhas <= 0 || colunas <= 0 || linhas > 26 || colunas > 26)
            throw std::out_of_range("fora de limites");
    } catch (...) {
        std::cout << "Erro: parametros invalidos para jardim.\n";
        return false;
    }
    std::cout << "Comando valido: jardim " << palavras[1] << " " << palavras[2] << "\n";
    Jardim* j = new Jardim( linhas, colunas);
    setJardim(j);
    criado =1;
    return true;
}

bool GestorComandos::validarPlanta(const std::vector<string>& palavras) {
    if (palavras.size() != 3) {
        std::cout << "Erro: planta requer posição e tipo.\n";
        return false;
    }
    string pos = palavras[1];
    if (!validarPosicao(pos, jardim->getLinhas(), jardim->getColunas()))
        return false;
    char tipo = palavras[2][0];
    if (string("crex").find(tipo) == string::npos) {
        std::cout << "Erro: tipo de planta inválido (usa c, r, e ou x).\n";
        return false;
    }
    std::cout << "Comando valido: planta " << pos << " " << tipo << "\n";
    return true;
}
bool GestorComandos::validarLPlanta(const std::vector<string>& palavras) {
    if (palavras.size() != 2) {
        std::cout << "Erro: lplanta requer uma posicao.\n";
        return false;
    }
    string pos = palavras[1];
    if (!validarPosicao(pos, jardim->getLinhas(), jardim->getColunas()))
        return false;
    std::cout << "Comando valido: lplanta " << pos << "\n";
    return true;
}
bool GestorComandos::validarEntra(const std::vector<string>& palavras) {
    if (palavras.size() != 2) {
        std::cout << "Erro: entra requer uma posicao.\n";
        return false;
    }
    string pos = palavras[1];
    if (!validarPosicao(pos, jardim->getLinhas(), jardim->getColunas()))
        return false;
    std::cout << "Comando valido: colhe " << pos << "\n";
    return true;
}
bool GestorComandos::validarColhe(const std::vector<string>& palavras) {
    if (palavras.size() != 2) {
        std::cout << "Erro: colhe requer as coordenadas.\n";
        return false;
    }
    string pos = palavras[1];
    if (!validarPosicao(pos, jardim->getLinhas(), jardim->getColunas()))
        return false;

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
bool GestorComandos::validarLPlantas(const std::vector<string>& palavras) {
    if (palavras.size() != 1) {
        std::cout << "Para listar as plantas só precisas de uma palavra.\n";
        return false;
    }
    std::cout << "Comando valido: Listar todas as plantas\n";
    return true;
}
bool GestorComandos::validarLFerramentas(const std::vector<string>& palavras) {
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
bool GestorComandos::validarLArea(const std::vector<string>& palavras) {
    if (palavras.size() != 1) {
        std::cout << "Para lArea só precisas de uma palavra.\n";
        return false;
    }
    std::cout << "Comando valido: Listar conteudo e props\n";
    return true;
}
bool GestorComandos::validarLSolo(const std::vector<string>& palavras) {
    if (palavras.size() > 3) {
        std::cout << "Para lSolo so precisas de 3 palavras no maximo.\n";
        return false;
    }

    string pos = palavras[1];
    if (!validarPosicao(pos, jardim->getLinhas(), jardim->getColunas()))
        return false;
    if (palavras.size() == 3) {
        try {
            int n = std::stoi(palavras[2]);
            if (n <= 0) throw std::invalid_argument("n invalido");
        } catch (...) {
            std::cout << "Erro: parametro invalido em avanca.\n";
            return false;
        }
        std::cout << "Comando valido: Listar solo num raio de "<< palavras[2] << " a partir da posicao"<<pos<<"\n";
        return true;
    }
    std::cout << "Comando valido: Listar solo da posicao"<<pos<<"\n";
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
            int n = std::stoi(palavras[1]);//se o stoi nao conseguir converter porque nao é um num valido manda um std::invalid_argument tambem
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
bool GestorComandos::validarGrava(const std::vector<string>& palavras) {
    if (palavras.size() == 1) {
        std::cout << "Erro: Eu sei que e para gravar mas que nome queres?\n";
        return false;
    }
    if (palavras.size() > 2) {
        std::cout << "Erro: grava tem no maximo 1 parametro.\n";
        return false;
    }
    std::string nome = palavras[1] + ".txt";
    std::ifstream f(nome);
    if (f.good()) {
        std::cout << "Erro: já existe uma cópia chamada '" << palavras[1] << "'.\n";
        return false;
    }
    std::cout << "Comando valido: grava o jardim no ficheiro "<<palavras[1]<<".txt ...\n";
    return true;
}
bool GestorComandos::validarRecupera(const std::vector<string>& palavras) {
    if (palavras.size() == 1) {
        std::cout << "Erro: Eu sei que e para recuperar mas qual das copias queres?\n";
        return false;
    }
    if (palavras.size() > 2) {
        std::cout << "Erro: recupera tem no maximo 1 parametro.\n";
        return false;
    }
    std::string nome = palavras[1] + ".txt";
    std::ifstream f(nome);
    if (!f.good()) {
        std::cout << "Erro: não existe nenhuma cópia chamada '" << palavras[1] << "'.\n";
        return false;
    }
    criado =1;
    std::cout << "Comando valido: recuperar o jardim do ficheiro "<<palavras[1]<<".txt ...\n";
    return true;
}
bool GestorComandos::validarApaga(const std::vector<string>& palavras) {
    if (palavras.size() == 1) {
        std::cout << "Erro: Eu sei que e para apagar mas qual?\n";
        return false;
    }
    if (palavras.size() > 2) {
        std::cout << "Erro: apaga tem no maximo 1 parametro.\n";
        return false;
    }
    std::string nome = palavras[1] + ".txt";
    std::ifstream f(nome);
    if (!f.good()) {
        std::cout << "Erro: não existe nenhuma cópia chamada '" << palavras[1] << "'.\n";
        return false;
    }
    std::cout << "Comando valido: apaga o ficheiro "<<palavras[1]<<".txt ...\n";
    return true;
}
bool GestorComandos::validarExecuta(const std::vector<string>& palavras) {
    if (palavras.size() == 1) {
        std::cout << "Erro: Eu sei que e para executar mas o que?\n";
        return false;
    }
    if (palavras.size() > 2) {
        std::cout << "Erro: executa tem no maximo 1 parametro.\n";
        return false;
    }
    std::string nome = palavras[1] + ".txt";
    std::ifstream f(nome);
    if (!f.good()) {
        std::cout << "Erro: o ficheiro '" << nome << "' não existe.\n";
        return false;
    }
    std::cout << "Comando valido: executar os comandos do ficheiro "<<palavras[1]<<".txt ...\n";
    std::string linha;
    int linhaNum = 1;
    while (std::getline(f, linha)) {
        // Ignorar linhas vazias e comentários
        if (linha.empty() || linha[0] == '#')
            continue;

        std::cout << "\n> Linha " << linhaNum << ": " << linha << "\n";
        processarComando(linha);
        linhaNum++;
    }

    f.close();
    std::cout << "\nExecução do ficheiro concluída.\n";
    return true;
}