#include "Utilidades.h"
#include <cstdlib>
#include <random>

// void Utilidades::converteLetras(char linChar, char colChar, int& l, int& c) {
// 	l = linChar - 'a';
// 	c = colChar - 'a';
// }
//
// int Utilidades::calculaIndice(int l, int c, int numColunas)
// {
// 	int indice = l * numColunas + c;
// 	return indice;
// }


int Utilidades::obterValorAleatorio(int min, int max){
	uniform_int_distribution<int> distribution =
			uniform_int_distribution<int>(min, max);
	return distribution(rng);
}
// inicializar membro estático fora da classe
mt19937 Utilidades::rng(random_device{}());