#ifndef UTILIDADES_H
#define UTILIDADES_H
#include<random>
#include<iostream>

using namespace std;

class Utilidades{
	static mt19937 rng;
public:
	static int obterValorAleatorio(int min, int max);
	void converteLetras(char linChar, char colChar, int& l, int& c);
	int calculaIndice(int l, int c, int numColunas);
	// numColunas é pego pela funcao getColunas() do Jardim quando chamada!!
};

#endif //UTILIDADES_H
