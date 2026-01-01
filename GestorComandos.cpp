


#include "GestorComandos.h"

#include "Settings.h"


GestorComandos::GestorComandos(Simulador* s) : simulador(s){
    inicializarMap();
}
GestorComandos::~GestorComandos() {
}
std::vector<string> GestorComandos::dividir(const string& linha) {
    std::istringstream iss(linha);
    std::vector<string> palavras;
    string palavra;
    while (iss >> palavra)
        palavras.push_back(palavra);
    return palavras;
}
void GestorComandos::inicializarMap() {
    mapComandos["jardim"] = 1;
    mapComandos["planta"] = 2;
    mapComandos["colhe"] = 3;
    mapComandos["entra"] = 4;
    mapComandos["sai"] = 5;
    mapComandos["avanca"] = 6;
    mapComandos["grava"] = 7;
    mapComandos["recupera"] = 8;
    mapComandos["apaga"] = 9;
    mapComandos["executa"] = 10;
    mapComandos["larea"] = 11;
    mapComandos["lsolo"] = 12;
    mapComandos["lplantas"] = 13;
    mapComandos["lferr"] = 14;
    mapComandos["pega"] = 15;
    mapComandos["larga"] = 16;
    mapComandos["e"] = 17;
    mapComandos["d"] = 18;
    mapComandos["c"] = 19;
    mapComandos["b"] = 20;
    mapComandos["compra"] = 21;
}
void GestorComandos::processarComando(const string& linha) {
    try {
        auto palavras = dividir(linha);
        if (palavras.empty()) return;
        if (linha == "fim") {
            std::cout << "A encerrar o simulador e a libertar memoria...\n";
            exit(0);
        }
        string cmd = palavras[0];
        if (mapComandos.find(cmd) == mapComandos.end()) {
            throw std::runtime_error("Comando desconhecido.");
        }

        int id = mapComandos[cmd];
        if (simulador == nullptr) throw std::runtime_error("Simulador nao inicializado.");

        Jardim* j = simulador->getJardimAtual();
        if (j == nullptr && id != 1 && id != 10) {
            throw std::logic_error("Precisa de criar um jardim primeiro (comando 'jardim').");
        }
        switch (id) {
            case 1:  validarJardim(palavras); break;
            case 2:  validarPlanta(palavras); break;
            case 3:  validarColhe(palavras); break;
            case 4:  validarEntra(palavras); break;
            case 5:  validarSai(palavras); break;
            case 6:  validarAvanca(palavras); break;
            case 7:  validarGrava(palavras); break;
            case 8:  validarRecupera(palavras); break;
            case 9:  validarApaga(palavras); break;
            case 10: validarExecuta(palavras); break;
            case 11: validarLArea(palavras); break;
            case 12: validarLSolo(palavras); break;
            case 13: validarLPlantas(palavras); break;
            case 14: validarLFerramentas(palavras); break;
            case 15: validarPega(palavras); break;
            case 16: validarLarga(palavras); break;
            case 17: validarE(palavras); break;
            case 18: validarD(palavras); break;
            case 19: validarC(palavras); break;
            case 20: validarB(palavras); break;
            case 21:validarCompra(palavras); break;
        }
        if (j != nullptr && id!=8 && id!=1 ) {
            j->mostraJardim();
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
}
bool GestorComandos::validarPosicao(const string& pos, int linhas, int colunas) {

    try {
        if (pos.size() != 2|| !islower(pos[0]) || !islower(pos[1])) throw std::invalid_argument("Formato de coordenadas invalido.");

        int linha = pos[0] - 'a';
        int coluna = pos[1] - 'a';

        if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas)
            throw std::out_of_range("Coordenadas fora dos limites do jardim.");

        return true;
    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << "\n";
        return false;
    }
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
    simulador->setJardim(j);
    j->mostraJardim();
    return true;
}

bool GestorComandos::validarPlanta(const std::vector<string>& palavras) {
    if (palavras.size() != 3) {
        std::cout << "Erro: planta requer posicao e tipo.\n";
        return false;
    }
    string pos = palavras[1];
    Jardim* j=simulador->getJardimAtual();
    if (!validarPosicao(pos, j->getLinhas(), j->getColunas()))
        return false;
    char tipo = palavras[2][0]; //primeiro caracter da 3a palavra
    if (string("crex").find(tipo) == string::npos) {
        std::cout << "Erro: tipo de planta invalido (usa c, r, e ou x).\n";
        return false;
    }
    std::cout << "Comando valido: planta " << pos << " " << tipo << "\n";
    simulador->executaPlanta(pos[0] - 'a',pos[1] - 'a',tipo);
    return true;
}
bool GestorComandos::validarLPlanta(const std::vector<string>& palavras) {
    if (palavras.size() != 2) {
        std::cout << "Erro: lplanta requer uma posicao.\n";
        return false;
    }
    string pos = palavras[1];
    Jardim* j=simulador->getJardimAtual();
    if (!validarPosicao(pos, j->getLinhas(), j->getColunas()))
        return false;
    std::cout << "Comando valido: lplanta " << pos << "\n";
    simulador->executaLPlanta(pos[0] - 'a',pos[1] - 'a');
    return true;
}
bool GestorComandos::validarEntra(const std::vector<string>& palavras) {
    Jardineiro* j = simulador->getJardineiro();
    Jardim* jm=simulador->getJardimAtual();
    if (palavras.size() != 2) {
        std::cout << "Erro: entra requer uma posicao.\n";
        return false;
    }
    if (j == nullptr)
        return false;

    if (j->getEntradasNoTurno()>=Settings::Jardineiro::max_entradas_saidas && !j->getNoJardim()) {
        std::cout << "Erro: O jardineiro ja entrou este turno e nao pode reentrar.\n";
        return false;
    }

    int l = palavras[1][0] - 'a';
    int c = palavras[1][1] - 'a';

    if (jm->posicionarJardineiro(l, c, j)) {
        j->marcarEntrada();
        std::cout << "Chamada ao Jardim feita com sucesso.\n";
        return true;
    }
    return false;
}
bool GestorComandos::validarColhe(const std::vector<string>& palavras) {
    if (palavras.size() != 2) {
        std::cout << "Erro: colhe requer as coordenadas.\n";
        return false;
    }
    string pos = palavras[1];
    Jardim* j=simulador->getJardimAtual();
    if (!validarPosicao(pos, j->getLinhas(), j->getColunas()))
        return false;

    std::cout << "Comando valido: colhe " << pos << "\n";
    return simulador->executaColhe(pos[0] - 'a', pos[1] - 'a');
}

bool GestorComandos::validarAvanca(const std::vector<string>& palavras) {
    int n = 1;
    if (palavras.size() > 2) {
        std::cout << "Erro: avanca tem no maximo 1 parametro.\n";
        return false;
    }

    if (palavras.size() == 2){
        try {
             n = std::stoi(palavras[1]);
            if (n <= 0) throw std::invalid_argument("n invalido");
        } catch (...) {
            std::cout << "Erro: parametro invalido em avanca.\n";
            return false;
        }
    }
    simulador->avanca(n);
    std::cout << "Comando valido: avanca\n";
    return true;
}

bool GestorComandos::validarCompra(const std::vector<string>& palavras) {
    if (palavras.size() != 2) {
        std::cout << "Erro: compra requer o tipo de ferramenta.\n";
        return false;
    }
    char tipo = palavras[1][0];
    if (simulador->comprarFerramenta(tipo)) {
        cout << "Comando valido: ferramenta comprada e enviada para o inventario." << endl;
        return true;
    }
    cout << "Erro: Tipo de ferramenta desconhecido." << endl;
    return false;
}
bool GestorComandos::validarLPlantas(const std::vector<string>& palavras) {
    if (palavras.size() != 1) {
        std::cout << "Para listar as plantas so precisas de uma palavra.\n";
        return false;
    }
    std::cout << "Comando valido: Listar todas as plantas\n";
    simulador->listarPlantas();
    return true;
}
bool GestorComandos::validarLFerramentas(const std::vector<string>& palavras) {
    if (palavras.size() != 1) {
        std::cout << "Para listar as ferramentas so precisas de uma palavra.\n";
        return false;
    }
    simulador->listarInfoFerr();
        return true;
}
bool GestorComandos::validarLarga(const std::vector<string>& palavras) {
    if (palavras.size() != 1) {
        std::cout << "Para largar a ferramenta so precisas de uma palavra.\n";
        return false;
    }

    std::cout << "Comando valido: Largar a ferramenta que tem na mao\n";
    simulador->getJardineiro()->largaFerramenta();
    return true;
}
bool GestorComandos::validarLArea(const std::vector<string>& palavras) {
    if (palavras.size() != 1) {
        std::cout << "Para lArea so precisas de uma palavra.\n";
        return false;
    }
    std::cout << "Comando valido: Listar conteudo e props\n";
    simulador->executaLArea();
    return true;
}
bool GestorComandos::validarLSolo(const std::vector<string>& palavras) {
    int r=0;
    if (palavras.size() > 3) {
        std::cout << "Para lSolo so precisas de 3 palavras no maximo.\n";
        return false;
    }

    string pos = palavras[1];
    Jardim* j=simulador->getJardimAtual();
    if (!validarPosicao(pos, j->getLinhas(), j->getColunas()))
        return false;
    if (palavras.size() == 3) {
        try {
            r = std::stoi(palavras[2]);
            if (r <= 0) throw std::invalid_argument("n invalido");
        } catch (...) {
            std::cout << "Erro: parametro invalido em LSolo.\n";
            return false;
        }
        std::cout << "Comando valido: Listar solo num raio de "<< palavras[2] << " a partir da posicao"<<pos<<"\n";

    }
    std::cout << "Comando valido: Listar solo da posicao"<<pos<<"\n";
    simulador->executaLSolo(pos[0]-'a',pos[1]-'a',r);
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
            int id = std::stoi(palavras[1]);
            return simulador->getJardineiro()->pegaFerramenta(id);
        } catch (...) {
            cout << "Erro: ID invalido." << endl;
            return false;
        }
    }
    std::cout << "Comando valido: pega na ferramenta de ID ...\n";
    return true;
}
bool GestorComandos::validarSai(const std::vector<string>& palavras) {
    Jardineiro* j= simulador->getJardineiro();
    if (palavras.size() != 1) {
        std::cout << "Para sair so precisas de uma palavra.\n";
        return false;
    }
    if (!j->getNoJardim()) {
        std::cout << "Erro: O jardineiro nao esta no jardim para poder sair.\n";
        return false;
    }
    if (j->getSaidasNoTurno()>=Settings::Jardineiro::max_entradas_saidas) {
        std::cout << "Erro: Ja utilizaste o comando sai este turno.\n";
        return false;
    }
    if (simulador->sair()) {
        j->marcarSaida();
        return true;
    }
    return false;
}
bool GestorComandos::validarGrava(const std::vector<string>& palavras) {
    if (palavras.size() == 1) {
        std::cout << "Erro: Eu sei que e para gravar mas que nome queres?\n";
        return false;
    }
    if (palavras.size() > 2) {
        std::cout << "Erro: grava tem no maximo 2 parametros.\n";
        return false;
    }
    string nome = palavras[1];

    simulador->grava(nome);
    return true;
}
bool GestorComandos::validarRecupera(const std::vector<string>& palavras) {
    if (palavras.size() == 1) {
        std::cout << "Erro: Eu sei que e para recuperar mas qual das copias queres?\n";
        return false;
    }
    if (palavras.size() > 2) {
        std::cout << "Erro: recupera tem no maximo 2 parametros.\n";
        return false;
    }
    std::string nome = palavras[1] ;
    simulador->recupera(nome);
    return true;
}
bool GestorComandos::validarApaga(const std::vector<string>& palavras) {

    if (palavras.size() != 2) {
        std::cout << "Erro: apaga requer o nome da copia.\n";
        return false;
    }

    string nome = palavras[1];


    simulador->apaga(nome);
    //false aqui porque apagar uma cópia não altera o jardim visível
    return false;
}
bool GestorComandos::validarExecuta(const std::vector<string>& palavras) {
    if (palavras.size() == 1) {
        std::cout << "Eu sei que e para executar mas o que?\n";
        return false;
    }
    if (palavras.size() > 2) {
        std::cout << "executa tem no maximo 1 parametro.\n";
        return false;
    }
    std::string nome = palavras[1] + ".txt";
    std::ifstream f(nome);
    if (!f.good()) {
        std::cout << "Erro: o ficheiro '" << nome << "' nao existe.\n";
        return false;
    }
    std::cout << " executar os comandos do ficheiro "<<palavras[1]<<".txt ...\n";
    std::string linha;
    int linhaNum = 1;
    while (std::getline(f, linha)) {
        // Ignorar linhas vazias
        if (linha.empty() )
            continue;

        std::cout << "\n> Linha " << linhaNum << ": " << linha << "\n";
        processarComando(linha);
        linhaNum++;
    }

    f.close();
    std::cout << "\nExecucao do ficheiro concluida.\n";
    return true;
}
bool GestorComandos::validarE(const std::vector<string>& palavras) {
    Jardineiro* j = simulador->getJardineiro();
    if (palavras.size() != 1) {
        std::cout << "Para esquerda so precisas de uma letra.\n";
        return false;
    }
    if (j == nullptr) {
        std::cout << "Erro: O jardineiro nao esta no jardim.\n";
        return false;
    }

    if (simulador->executaComandoMover('e'))
        return true;
    return false;
}
bool GestorComandos::validarD(const std::vector<string>& palavras) {
    Jardineiro* j = simulador->getJardineiro();
    if (palavras.size() != 1) {
        std::cout << "Para direita so precisas de uma letra.\n";
        return false;
    }
    if (j == nullptr) {
        std::cout << "Erro: O jardineiro nao esta no jardim.\n";
        return false;
    }

    if (simulador->executaComandoMover('d'))
        return true;
    return false;
}
bool GestorComandos::validarC(const std::vector<string>& palavras) {
    Jardineiro* j = simulador->getJardineiro();
    if (palavras.size() != 1) {
        std::cout << "Para cima so precisas de uma letra.\n";
        return false;
    }
    if (j == nullptr) {
        std::cout << "Erro: O jardineiro nao esta no jardim.\n";
        return false;
    }

    if (simulador->executaComandoMover('c'))

        return true;

    return false;
}
bool GestorComandos::validarB(const std::vector<string>& palavras) {
    Jardineiro* j = simulador->getJardineiro();
    if (palavras.size() != 1) {
        std::cout << "Para baixo so precisas de uma letra.\n";
        return false;
    }
    if (j == nullptr) {
        std::cout << "Erro: O jardineiro nao esta no jardim.\n";
        return false;
    }


    if (simulador->executaComandoMover('b'))
        return true;

    return false;
}