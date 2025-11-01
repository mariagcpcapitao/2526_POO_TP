#ifndef UTILIDADES_H
#define UTILIDADES_H
#include<random>
#include<iostream>

using namespace std;

class Utilidades{
	static mt19937 rng;
public:
	static int obterValorAleatorio(int min, int max);
};

#endif //UTILIDADES_H
