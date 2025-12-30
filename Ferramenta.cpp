#include "Ferramenta.h"
int Ferramenta::contId = 0;
Ferramenta::Ferramenta(const string &nome, const char &simbolo) : nomeFerr(nome), simbolo(simbolo)
{
	setId();
}
Ferramenta::~Ferramenta(){}
void Ferramenta::deteriora() {
	cout<<"Ferramenta a deteriorar "<<endl;
}
void Ferramenta::usar() {}
void Ferramenta::setId()
{
	id_ferramenta = ++contId;
}


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


Adubo::Adubo() : Ferramenta("Adubo", 'a'){}
Adubo::~Adubo(){}

void Adubo::usar()
{
	capacidade = capacidade - dose;
	if (capacidade <= 0)
		cout << "Acabou o adubo. Nao e possivel usar mais";
}

TesouraPoda::TesouraPoda() : Ferramenta("Tesoura de Poda", 't') {}
void TesouraPoda::usar()
{
	//elimina plantas
}
TesouraPoda::~TesouraPoda() {}

FerramentaZ::FerramentaZ() : Ferramenta("Luvas", 'z'){}
void FerramentaZ::usar(){}
FerramentaZ::~FerramentaZ(){}



