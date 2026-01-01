

#include "Simulacao.h"
#include <iostream>
#include <ostream>
#include "Simulacao.h"
#include "Jardim.h"
#include "Jardineiro.h"
#include "Adubo.h"
#include "TesouraPoda.h"
#include "Regador.h"
#include "FerramentaZ.h"
#include "Planta.h"
Simulador::Simulador() {
    jardimAtual=nullptr;
    j = new Jardineiro();


}
void Simulador::setJardim(Jardim* nj) {
    if (jardimAtual != nullptr) {
        // Se há jardineiro no jardim atual, removê-lo
        if (nj != nullptr && j->getNoJardim()) {
            jardimAtual->removerJardineiro();
        }
        delete jardimAtual;
        cout << "Jardim anterior removido da memoria.\n";
    }

    jardimAtual = nj;


}
void Simulador::resetaLimitesTurno() {
    if (jardimAtual != nullptr) {
        Jardineiro* j = jardimAtual->getJardineiro();
        if (j != nullptr) {
            j->resetTurno();
        }
    }

    std::cout << "Limites de turno reiniciados.\n";
}
void Simulador::avanca(int n) {
    if (j == nullptr || jardimAtual == nullptr) return;

    for (int i = 0; i < n; ++i) {
        j->resetTurno();
        jardimAtual->atualiza();
        j->atualizaFerramentas();
        Solo& s = jardimAtual->getSolo(j->getLinha(), j->getColuna());
        j->usarFerramenta(s);
    }
    cout << "O jardineiro descansou. Limites reiniciados." << endl;
    cout << "Avancaram " << n << " instantes no tempo." << endl;
}
Simulador::~Simulador() {
    delete j; // Libertar a memória no fim
    if (jardimAtual) delete jardimAtual;
    for (auto const& [nome, cp] : jardins)
        delete cp;
}

void Simulador::grava(const std::string& nome) {
    if (jardimAtual == nullptr) {
        std::cout << "Erro: Nao ha jardim para gravar.\n";
        return;
    }

    // Verificar se o jardim atual é válido
    if (jardimAtual->getLinhas() <= 0 || jardimAtual->getColunas() <= 0) {
        std::cout << "Erro: Jardim atual tem dimensões inválidas.\n";
        return;
    }

    auto it = jardins.find(nome);
    if (it != jardins.end()) {
        std::cout << "Esse nome ja existe\n";
        return;
    }

    try {
        Jardim* copia = new Jardim(*jardimAtual);
        jardins[nome] = copia;

        std::cout << "Jardim gravado com sucesso: " << nome << "\n";
    } catch (const std::exception& e) {
        std::cout << "Erro ao gravar jardim: " << e.what() << "\n";
    }
}
void Simulador::recupera(const std::string& nome) {
    auto it = jardins.find(nome);
    if (it == jardins.end()) {
        std::cout << "Gravacao nao encontrada.\n";
        return;
    }

    // Verificar se a cópia é válida
    if (it->second == nullptr) {
        std::cout << "Gravacao corrompida (nullptr).\n";
        return;
    }


    try {
        Jardim* novoJardim = new Jardim(*it->second);

        delete jardimAtual;
        jardimAtual = novoJardim;


        if (jardimAtual != nullptr) {
            if (j->getNoJardim()) {
                jardimAtual->getSolo(j->getLinha(), j->getColuna()).setJardineiro(j);
                jardimAtual->posicionarJardineiro(j->getLinha(), j->getColuna(), j);
            }
            jardimAtual->mostraJardim();
        }

    } catch (const std::exception& e) {
        std::cout << "Erro ao recuperar jardim: " << e.what() << "\n";
    }
    apaga(nome);
}
void Simulador::apaga(const std::string& nome) {
    auto it = jardins.find(nome);
    if (it != jardins.end()) {
        if (jardimAtual != it->second) {
            delete it->second;
        }
        jardins.erase(it);
        std::cout << "Gravacao '" << nome << "' apagada.\n";
    }
    else {
        cout << "Gravacao nao encontrada\n";
    }
}
bool Simulador::sair() {
    if (j == nullptr || jardimAtual == nullptr) return false;
     if (!j->sai(jardimAtual))return false;
    j->marcarSaida();
    return true;
}
bool Simulador::executaComandoMover(char dir) {
    return j->mover(dir, jardimAtual);
}
bool Simulador::executaColhe(int l, int c) {

    return j->colher(l, c, jardimAtual);
}
bool Simulador::executaPlanta(int l, int c, char tipo){

    return j->plantar(l, c, tipo, jardimAtual);
}
bool Simulador::comprarFerramenta(char tipo) {
    if (j == nullptr) return false;

    Ferramenta* nova = nullptr;
    char t = (char)tolower(tipo);

    if (t == 'g') nova = new Regador();
    else if (t == 'a') nova = new Adubo();
    else if (t == 't') nova = new TesouraPoda();
    else if (t == 'z') nova = new FerramentaZ();

    if (nova != nullptr) {
        j->adicionarFerramenta(nova); // O jardineiro guarda no inventário
        return true;
    }
    return false;
}
void Simulador::listarInfoFerr() {
    if (jardimAtual == nullptr) return;
    cout<<j->listarFerramentas()<<endl;
}
void Simulador::listarPlantas() {
    if (jardimAtual == nullptr) return;
    cout<<jardimAtual->listarPlantas()<<endl;
}
void Simulador::executaLPlanta(int l, int c) {
    if (jardimAtual == nullptr) return;
    cout<<jardimAtual->lPlanta(l,c);
}
void Simulador::executaLArea() {
    if (jardimAtual == nullptr) return;
    cout<<jardimAtual->lArea();
}
void Simulador::executaLSolo(int l, int c, int r) {
    cout<<"entrei no simulaador";
    if (jardimAtual == nullptr) return;
    cout<<jardimAtual->lSolo(l,c,r);
}