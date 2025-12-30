//
// Created by luana on 30/12/2025.
//

#include "Regador.h"

Regador::Regador() : Ferramenta("Regador", 'g')
{
	cout << "Regador " <<  id_ferramenta << " com capacidade de: " << capacidade << " unidades de agua " << endl;
}
Regador::~Regador()
{
	cout << "Regador descartado, nao ha mais agua.";
}

void Regador::usar()
{

	capacidade = capacidade - dose;
	if (capacidade <= 0)
		cout << "Acabou a agua. Regador descartado";
	else
		cout << "A regar as plantas. Agua restante: " << capacidade << "ml" << endl;
}