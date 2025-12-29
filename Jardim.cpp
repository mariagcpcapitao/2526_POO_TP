

#include "Jardim.h"

#include <iostream>
#include <ostream>

#include "GestorComandos.h"
using namespace std;
Jardim::Jardim(int l, int c) : linhas(l), colunas(c)
{
	cout << "Construindo Jardim " << linhas << " por " << colunas << endl;
	conjunto = new Solo*[linhas];
	for (int i = 0; i < linhas; i++)
		conjunto[i] = new Solo[colunas];
}
Jardim::Jardim(const Jardim& outro) : linhas(outro.linhas), colunas(outro.colunas) {
	conjunto = new Solo*[linhas];
	for (int i = 0; i < linhas; i++) {
		conjunto[i] = new Solo[colunas];
		for (int j = 0; j < colunas; j++) {
			conjunto[i][j] = outro.conjunto[i][j];
		}
	}
	this->jardineiro = outro.jardineiro;
}
Jardim::~Jardim() {
	if (conjunto != nullptr) {
		for (int i = 0; i < linhas; i++)
			delete[] conjunto[i];

		delete[] conjunto;
		conjunto = nullptr;
	}
}
int Jardim::getLinhas() const{ return linhas; }
int Jardim::getColunas() const{ return colunas; }
void Jardim::atualizarJardim() {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			Solo& s = conjunto[i][j];

			if (s.temPlanta()) {
				Planta* p = s.getPlanta();
				p->absorveAgua(i, j);
				p->absorveNutrientes(i, j);
			}

			if (s.temJardineiro()) {
				Jardineiro* j = s.getJardineiro();


				if (j->temFerramentaAtiva()) {
					j->usarFerramenta(s);
				}
			}
		}
	}
}
Solo & Jardim::getPosicao(int linha, int coluna) {
	return conjunto[linha][coluna];
}

void Jardim::mostraJardim() const {

	cout << " ";
	for (int j = 0; j < colunas; j++) {
		cout << (char)('A' + j);
	}
	cout << "\n";

	for (int i = 0; i < linhas; i++) {
		cout << (char)('A' + i) << " ";

		for (int j = 0; j < colunas; j++) {
			//prioridade: Jardineiro > Planta > Ferramenta

			char simbolo = conjunto[i][j].getConteudo();
			cout << (simbolo == ' ' ? ' ' : simbolo) << " ";
		}
		cout << "\n";
	}
}
bool Jardim::posicionarJardineiro(int l, int c, Jardineiro* j) {
	if (l < 0 || l >= linhas || c < 0 || c >= colunas) return false;

	removerJardineiro();
	this->jardineiro = j;
	conjunto[l][c].setJardineiro(j);

	j->setPosicao(l, c);
	return true;
}

void Jardim::removerJardineiro() {
	if (jardineiro != nullptr) {

		int l = jardineiro->getLinha();
		int c = jardineiro->getColuna();
        

		if (l >= 0 && l < linhas && c >= 0 && c < colunas)
			conjunto[l][c].setJardineiro(nullptr);
        

		this->jardineiro = nullptr;
	}
}
// Retorna um ponteiro para o Solo vizinho livre, ou nullptr se não houver
Solo* Jardim::getVizinhoLivre(int l, int c) {
	// cima, baixo, esquerda, direita
	int dl[] = {-1, 1,  0, 0};
	int dc[] = { 0, 0, -1, 1};

	// Sorteia pra definir ponto de inicio de busca (0 a 3) para dar variedade
	int inicio = rand() % 4;

	for (int i = 0; i < 4; i++) {
		// % garante que o índice da a volta
		int idx = (inicio + i) % 4;

		int nL = l + dl[idx]; // Nova Linha
		int nC = c + dc[idx]; // Nova Coluna

		// verifica se está dentro das bordas do jardim
		if (nL >= 0 && nL < linhas && nC >= 0 && nC < colunas) {

			// verifica se nao tem planta nessa posição
			if (conjunto[nL][nC].getPlanta() == nullptr) {
				return &conjunto[nL][nC];
			}
		}
	}

	return nullptr;
}

