#include "Ferramenta.h"
int Ferramenta::contId = 0;
Ferramenta::Ferramenta(const string &nome, const char &simbolo) : nomeFerr(nome), simbolo(simbolo)
{
	setId();
	cout << "Ferramenta com id " << id_ferramenta << " criada" << endl;
}
Ferramenta::~Ferramenta(){}
void Ferramenta::usar() {
	cout << "Usando ferramenta: " << nomeFerr << " (ID: " << id_ferramenta << ")" << endl;
}
void Ferramenta::setId()
{
	id_ferramenta = ++contId;
}


Regador::Regador() : Ferramenta("Regador", 'g')
{
	cout << "Regador " <<  id_ferramenta << " com capaciddade de: " << capacidade << endl;
}
Regador::~Regador()
{
	cout << "Regador descartado, nao ha mais agua.";
}

void Regador::usar()
{
	capacidade = capacidade - dose;
	if (capacidade <= 0)
		cout << "Acabou o adubo. Nao e possivel usar mais";
	else
		cout << "A regar as plantas. Agua restante: " << capacidade << "ml" << endl;
}


Adubo::Adubo() : Ferramenta("Adubo", 'a'){}
Adubo::~Adubo(){}

void Adubo::usar()
{
	capacidade = capacidade - dose;
	if (capacidade <= 0)
		cout << "Acabou o adubo. Nao e possivel usar mais";
}

TesouraPoda::TesouraPoda() : Ferramenta("Tesoura de Poda", 't')
{
	cout << "Ferramenta Tesoura de id: " << id_ferramenta << " criada" << endl;
}
void TesouraPoda::usar()
{
	//elimina plantas
}
TesouraPoda::~TesouraPoda() {}

FerramentaZ::FerramentaZ() : Ferramenta("Luvas", 'z'){}
void FerramentaZ::usar(){}
FerramentaZ::~FerramentaZ(){}



