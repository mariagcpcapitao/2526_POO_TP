//
// Created by 1663m on 29/10/2025.
//

#include "Ferramenta.h"

Ferramenta::Ferramenta(const string &nome, int id, const string &representacao) : nomeFerr(nome), id_ferramenta(id), representacao(representacao) {}
Ferramenta::~Ferramenta(){}
void Ferramenta::usar() {
	cout << "Usando ferramenta: " << nomeFerr << " (ID: " << id_ferramenta << ")" << endl;
}


Regador::Regador(const string &nomeFerr, int id_ferramenta, int qtd_agua, string representacao) : Ferramenta(nomeFerr, id_ferramenta, "g"), capacidade(qtd_agua){}
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


Adubo::Adubo(const string &nomeFerr, int id_ferramenta, int qtd_adubo, const string &representacao) : Ferramenta(nomeFerr, id_ferramenta, "a")
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

TesouraPoda::TesouraPoda(const string &nomeFerr, int id_ferramenta, const string &representacao) : Ferramenta(nomeFerr, id_ferramenta, "t") {}
void TesouraPoda::usar()
{
	//elimina plantas
}
TesouraPoda::~TesouraPoda() {}



