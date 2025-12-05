

#include "Jardim.h"

#include <iostream>
#include <ostream>
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