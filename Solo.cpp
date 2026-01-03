
#include "Solo.h"
#include "Planta.h"
#include "Jardineiro.h"
#include "Ferramenta.h"
#include "Settings.h"
#include "Utilidades.h"

Solo::Solo() : planta(nullptr), ferramenta(nullptr), jardineiro(nullptr)
{

	setNutriSolo();
	setAguaSolo();
	//cout << "Solo criado com valores aleatorios -> " << "Nutrientes: " << nutriSolo << ", Agua: " << aguaSolo << endl;
}

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
	if (temJardineiro())
		return jardineiro->getSimbolo();

	if (temPlanta())
		return planta->getSimbolo();

	if (temFerramenta())
		return ferramenta->getSimbolo();

	return '.';
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
	return this->jardineiro != nullptr;
}

Solo & Solo::getSolo(int l, int c) {
	return *this;
}

void Solo::removerPlanta() {
	if (this->planta != nullptr) {
		delete this->planta;
		this->planta = nullptr;
	}
}


std::string Solo::mostrarDetalhes() const {
	std::ostringstream oss;

	oss << " Solo:\nAgua: " << aguaSolo << " | Nutrientes: " << nutriSolo ;

	if (temPlanta()) {

		oss << "| Tem planta: " << planta->getSimbolo();
	}
	else
		oss<<"| Nao tem planta ";
	if (temFerramenta()) {

		oss << "| Tem ferramenta: " << ferramenta->getSimbolo();
	}
	else
		oss<<"| Nao tem ferramenta ";

	if (temJardineiro()) {
		oss << "| Jardineiro esta aqui ";
	}
	else
		oss<<"| Nao tem jardineiro";


	return oss.str();
}

Solo& Solo::operator=(const Solo& outro) {
	if (this == &outro) return *this;

	this->aguaSolo = outro.aguaSolo;
	this->nutriSolo = outro.nutriSolo;

	delete this->planta;
	delete this->ferramenta;
	delete this->jardineiro;

	this->planta = nullptr;
	this->ferramenta = nullptr;
	this->jardineiro = nullptr;

	if (outro.planta != nullptr) {
		this->planta = outro.planta->clone();
	}
	if (outro.ferramenta != nullptr) {
		this->ferramenta = outro.ferramenta->clone();
	}

	return *this;
}
Solo::~Solo() {
	delete planta;
	delete ferramenta;
	planta = nullptr;
	ferramenta = nullptr;
	jardineiro = nullptr;
}