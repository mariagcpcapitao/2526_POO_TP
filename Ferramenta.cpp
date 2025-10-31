//
// Created by 1663m on 29/10/2025.
//

#include "Ferramenta.h"

Ferramenta::Ferramenta(const string &nome, int id) : nomeFerr(nome), id_ferramenta(id) {}
Ferramenta::~Ferramenta(){}
void Ferramenta::usar() {
	cout << "Usando ferramenta: " << nomeFerr << " (ID: " << id_ferramenta << ")" << endl;
}


Regador::Regador(const string &nomeFerr, int id_ferramenta, int qtd_agua) : Ferramenta(nomeFerr, id_ferramenta), capacidade(qtd_agua){}
Regador::~Regador()
{
	cout << "Regador descartado, não há mais água.";
}

void Regador::usar()
{
	capacidade = capacidade - dose;
	if (capacidade <= 0)
		cout << "Acabou o adubo. Não é possível usar mais";
	else
		cout << "Regando plantas. Água restante: " << capacidade << "ml" << endl;

}


Adubo::Adubo(const string &nomeFerr, int id_ferramenta, int qtd_adubo) : Ferramenta(nomeFerr, id_ferramenta)
{
	capacidade = qtd_adubo;
}
Adubo::~Adubo(){}

void Adubo::usar()
{
	capacidade = capacidade - dose;
	if (capacidade <= 0)
		cout << "Acabou o adubo. Não é possível usar mais";
}