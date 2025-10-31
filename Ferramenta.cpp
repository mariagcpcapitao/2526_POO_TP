//
// Created by 1663m on 29/10/2025.
//

#include "Ferramenta.h"

Ferramenta::Ferramenta(const string &nome, int id) : nomeFerr(nome), id_ferramenta(id) {}


Regador::Regador(const string &nomeFerr, int id_ferramenta, int qtd_agua) : Ferramenta(nomeFerr, id_ferramenta)
{
	capacidade = qtd_agua;
}
Regador::~Regador()
{
	cout << "Regador descartado, não há mais água.";
}

void Regador::usar()
{
	capacidade = capacidade - dose;
	if (capacidade <= 0)
		Regador::~Regador();
}


Adubo::~Adubo() : Ferramenta(nomeFerr, id_ferramenta)
{
	capacidade = capacidade;
}
