
#include "Solo.h"

#include "Settings.h"
#include "Utilidades.h"

Solo::Solo() : planta(nullptr), ferramenta(nullptr), jardineiro(nullptr)
{

	setNutriSolo();
	setAguaSolo();
	cout << "Solo criado com valores aleatorios -> " << "Nutrientes: " << nutriSolo << ", Agua: " << aguaSolo << endl;}

void Solo::setNutriSolo(double valor, string acao)
{
	if (nutriSolo == -1)
	{
		nutriSolo = Utilidades::obterValorAleatorio(
		   Settings::Jardim::nutrientes_min,
		   Settings::Jardim::nutrientes_max
		   );
		return;
	}
	if (valor != -1 && acao == "perder")
		nutriSolo = nutriSolo - valor;
	if (valor != -1 && acao == "ganhar")
		nutriSolo = nutriSolo + valor;
	// if (nutriSolo <= 0){} ...completar

}
void Solo::setAguaSolo(double valor, string acao)
{
	if (aguaSolo == -1)
	{
		aguaSolo = Utilidades::obterValorAleatorio(
			Settings::Jardim::agua_min,
			Settings::Jardim::agua_max
		);
		return;
	}
	if (valor != -1 && acao == "perder")
		aguaSolo = aguaSolo - valor;
	if (valor != -1 && acao == "ganhar")
		aguaSolo = aguaSolo + valor;

	// if (aguaSolo <= 0){} ...completar
}

void Solo::setPlanta(Planta* p)
{
	this->planta = p;
}
void Solo::setFerramenta(Ferramenta* f)
{
	this->ferramenta = f;
}
void Solo::setJardineiro(Jardineiro* j)
{
	jardineiro = j;
}

Planta* Solo::getPlanta() const
{
	return planta;
}
Ferramenta* Solo::getFerramenta() const
{
	return ferramenta;
}
Jardineiro* Solo::getJardineiro() const
{
	return jardineiro;
}

char Solo::getConteudo() const
{
	if (jardineiro != nullptr)
		return jardineiro->getSimbolo();

	if (planta != nullptr)
		return planta->getSimbolo();

	if (ferramenta != nullptr)
		return ferramenta->getSimbolo();

	return ' ';
}


bool Solo::temPlanta() const
{
	return planta != nullptr;
}
bool Solo::temFerramenta() const
{
	return ferramenta != nullptr;
}
bool Solo::temJardineiro() const
{
	return jardineiro != nullptr;
}

Solo::~Solo(){}