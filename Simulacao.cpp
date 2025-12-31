

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
Simulador::Simulador() {
    jardimAtual=nullptr;
    j = new Jardineiro();


}
void Simulador::setJardim(Jardim* j) {
    if (jardimAtual != nullptr) {
        delete this->jardimAtual;
        std::cout << "Jardim anterior removido da memoria.\n";
    }
    jardimAtual = j;

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
    apaga(nome);


    jardins[nome] = new Jardim(*jardimAtual);

    std::cout << "Jardim gravado com sucesso: " << nome << "\n";
}
void Simulador::recupera(const std::string& nome) {
    if (jardins.find(nome) == jardins.end()) {
        std::cout << "nao existe nenhuma gravacao com o nome '" << nome << "'.\n";
        return;
    }

    delete jardimAtual;

    jardimAtual = new Jardim(*jardins[nome]);


    if (jardimAtual->getJardineiro() != nullptr) {
        this->j = jardimAtual->getJardineiro();
    }

    std::cout << "Estado '" << nome << "' recuperado.\n";
    apaga(nome);
}
void Simulador::apaga(const std::string& nome) {
    auto it = jardins.find(nome);
    if (it != jardins.end()) {
        delete it->second;
        jardins.erase(it);
        std::cout << "Gravacao '" << nome << "' apagada.\n";
    }
    else
        cout<<"Gravacao nao encontrada\n";
}
bool Simulador::sair() {
    if (jardimAtual == nullptr || j == nullptr) return false;

    // Verificar se ele está realmente lá dentro antes de tentar tirar
    if (jardimAtual->getJardineiro() == nullptr) {
        std::cout << "Erro: O jardineiro ja esta fora do jardim.\n";
        return false;
    }

    jardimAtual->removerJardineiro();
    std::cout << "O jardineiro saiu do jardim.\n";
    return true;
}
bool Simulador::executaComandoMover(char dir) {
    // O Simulador apenas ordena ao objeto que se mova no jardim atual
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
    cout<<j->listarFerramentas()<<endl;
}