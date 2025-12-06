#include "Utilidades.h"
#include <random>

int* Utilidades::converteLetras(int l, int c)
{
	int linha = l - 'a';
	int coluna = c - 'a';
	int pos[2] = {linha, coluna};
	return pos;
}

int Utilidades::calculaIndice(int l, int c, int numColunas)
{
	int indice = l * numColunas + c;
	return indice;
}


int Utilidades::obterValorAleatorio(int min, int max){
	uniform_int_distribution<int> distribution =
			uniform_int_distribution<int>(min, max);
	return distribution(rng);
}
// inicializar membro estático fora da classe
mt19937 Utilidades::rng(random_device{}());