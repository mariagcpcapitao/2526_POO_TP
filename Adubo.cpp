//
// Created by luana on 30/12/2025.
//

#include "Adubo.h"


Adubo::Adubo() : Ferramenta("Adubo", 'a'){}
Adubo::~Adubo(){}

void Adubo::usar()
{
	capacidade = capacidade - dose;
	if (capacidade <= 0)
		cout << "Acabou o adubo. Nao e possivel usar mais";
}