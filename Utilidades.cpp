#include "Utilidades.h"

int Utilidades::obterValorAleatorio(int min, int max){
	uniform_int_distribution<int> distribution =
			uniform_int_distribution<int>(min, max);
	return distribution(rng);
}
// inicializar membro estático fora da classe
mt19937 Utilidades::rng(random_device{}());