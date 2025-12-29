

#include "Simulacao.h"
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
    for (int i = 0; i < n; i++) {
        instante++;
        if (jardimAtual != nullptr) {
            jardimAtual->atualizarJardim();
            this->resetaLimitesTurno();
        }
    }
}
Simulador::~Simulador() {
    delete j; // Libertar a memória no fim
    if (jardimAtual) delete jardimAtual;
    for (auto const& [nome, cp] : jardins)
        delete cp;
}
bool Simulador::moverJardineiro(char direcao) {
    if (j == nullptr || jardimAtual == nullptr) {
        cout << "jardim ou jardineiro.\n";
        return false;
    }

    if (!j->podeMover()) {
        cout << "Erro: Limite de movimentos atingido neste turno." << endl;
        return false;
    }

    int nLin = j->getLinha();
    int nCol = j->getColuna();

    if (direcao == 'e') nCol--;
    else if (direcao == 'd') nCol++;
    else if (direcao == 'c') nLin--;
    else if (direcao == 'b') nLin++;


    if (jardimAtual->posicionarJardineiro(nLin, nCol, j)) {
        cout <<"posicionar jardineiro neste turno." << endl;
        j->incrementaMov(); // Só incrementa se o jardim aceitou o movimento
        return true;
    }
    cout<<"posicionar jardim";
    return false;
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