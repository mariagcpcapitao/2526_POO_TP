

#include "Jardim.h"

#include <iostream>
#include <ostream>
using namespace std;
Jardim::Jardim(int l, int c) : linhas(l), colunas(c)
{
	cout << "Construindo Jardim " << linhas << " por " << colunas << endl;
}
int Jardim::getLinhas() const{ return linhas; }
int Jardim::getColunas() const{ return colunas; }