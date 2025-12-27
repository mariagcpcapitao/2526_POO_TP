

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