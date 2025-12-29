

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
int Jardim::getLinhas() const{ return linhas; }
int Jardim::getColunas() const{ return colunas; }
Solo & Jardim::getPosicao(int linha, int coluna) {
	return conjunto[linha][coluna];
}
// No Jardim.cpp
void Jardim::mostraJardim() const {
	// 1. Régua Superior (Letras das colunas em Maiúsculas)
	std::cout << " "; // Espaço para alinhar com a régua lateral
	for (int j = 0; j < colunas; j++) {
		std::cout << (char)('A' + j);
	}
	std::cout << "\n";

	for (int i = 0; i < linhas; i++) {
		std::cout << (char)('A' + i) << " ";

		for (int j = 0; j < colunas; j++) {
			//prioridade: Jardineiro > Planta > Ferramenta

			char simbolo = conjunto[i][j].getConteudo();
			cout << (simbolo == ' ' ? ' ' : simbolo) << " ";
		}
		std::cout << "\n";
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