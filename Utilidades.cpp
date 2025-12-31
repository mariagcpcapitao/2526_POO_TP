#include "Utilidades.h"
#include <cstdlib>
#include <random>

void Utilidades::converteLetras(char linChar, char colChar, int& l, int& c) {
	l = linChar - 'a';
	c = colChar - 'a';
}

int Utilidades::calculaIndice(int l, int c, int numColunas)
{
	int indice = l * numColunas + c;
	return indice;
}

Solo* Utilidades::getVizinhoLivre(Jardim& jardim, int l, int c) {
	int linhas[] = {-1, 1,  0, 0};
	int colunas[] = { 0, 0, -1, 1};
	int inicio = rand() % 4; //faz com que a planta se multiplique para um lado aleatorio

	for (int i = 0; i < 4; i++) {
		int idx, nL, nC;
		idx = (inicio + i) % 4;
		nL = l + linhas[idx];
		nC = c + colunas[idx];

		if (nL >= 0 && nL < jardim.getLinhas() && nC >= 0 && nC < jardim.getColunas()) {

			// 2. Pede ao jardim o ponteiro para o solo naquela posição
			// Você precisa ter criado o método 'getSolo' no Jardim
			Solo* soloVizinho = &jardim.getSolo(nL, nC);

			// 3. Verifica se o ponteiro é válido e se não tem planta
			if (soloVizinho != nullptr) //incluir verificacao soloVizinho->temPlanta() == false
				return soloVizinho;
		}
	}
	return nullptr;
}


int Utilidades::obterValorAleatorio(int min, int max){
	uniform_int_distribution<int> distribution =
			uniform_int_distribution<int>(min, max);
	return distribution(rng);
}
// inicializar membro estático fora da classe
mt19937 Utilidades::rng(random_device{}());