//
// Created by luana on 30/12/2025.
//

#include "Cacto.h"
#include "Solo.h"

Cacto::Cacto(int linha, int coluna, Solo* s) : Planta(s, aguaCacto, nutriCacto, "neutra", linha, coluna, 'c') {
	cout<<"plantei c";
	this->diasComMuitaAgua = 0;
	this->diasSemNutrientes = 0;
	this->nutriAbsorvidos = 0;
}

void Cacto::absorveAgua(int posLinha, int posColuna, int valor = 0)
{
	if (valor > 0) {
		this->agua += valor;
		return;
	}

	if (solo_hosp == nullptr) return;

	int agua_solo = solo_hosp->getAguaSolo();
	if (agua_solo > 0)
	{
		int qtdAbsorver = agua_solo * 0.25;
		solo_hosp->setAguaSolo(qtdAbsorver, "perder");
		this->agua += qtdAbsorver;
	}
}

void Cacto::absorveNutrientes(int posLinha, int posColuna, int valorNutri)
{
	if (valorNutri > 0) {
		this->nutrientes += valorNutri;
		return;
	}

	if (solo_hosp == nullptr) return;

	int nutri_solo = solo_hosp->getNutriSolo();
	if (nutri_solo > 0)
	{
		int qtdAbsorver = 5;
		if (nutri_solo < 5) {
			qtdAbsorver = nutri_solo;
		}

		solo_hosp->setNutriSolo(qtdAbsorver, "perder");

		this->nutrientes += qtdAbsorver;
		this->nutriAbsorvidos += qtdAbsorver;
	}
}

void Cacto::perdeAgua(int posLinha, int posColuna){}
void Cacto::perdeNutri(int posLinha, int posColuna) {}

void Cacto::passaTempo()
{
	Planta::passaTempo();

	// verifica agua alta
	if (solo_hosp->getAguaSolo() > Settings::Cacto::morre_agua_solo_maior)
		contAguaAlta++;
	else
		contAguaAlta = 0;

	// verifica nutrientes zero
	if (solo_hosp->getNutriSolo() < Settings::Cacto::morre_nutrientes_solo_menor)
		contSemNutri++;
	else
		contSemNutri = 0;
}

void Cacto::multiplica(Jardim* j, int posLinha, int posColuna) {
	if (this->nutrientes > Settings::Cacto::multiplica_nutrientes_maior && this->agua > Settings::Cacto::multiplica_agua_maior) {

		Solo* vizinho = j->getVizinhoLivre(posLinha, posColuna, true);

		if (vizinho != nullptr) {
			int metadeAgua = this->agua / 2;
			int metadeNutri = this->nutrientes / 2;

			this->agua = metadeAgua;
			this->nutrientes = metadeNutri;

			Cacto* filho = new Cacto(0, 0, vizinho);

			filho->agua = metadeAgua;
			filho->nutrientes = metadeNutri;

			vizinho->setPlanta(filho);
		}
	}
}
void Cacto::morre()
{
	// deixar no solo os nutrientes absorvidos
	if (solo_hosp != nullptr)
		solo_hosp->setNutriSolo(this->nutriAbsorvidos, "ganhar");

}

string Cacto::mostrarDetalhes() const {
	std::ostringstream oss;

	oss << "\nNome: Cacto |"<<endl;
	oss<<Planta::mostrarDetalhes();

	return oss.str();
}

bool Cacto::estaViva(Jardim* j) const {
	if (contAguaAlta >= Settings::Cacto::morre_agua_solo_instantes) return false;
	if (contSemNutri > Settings::Cacto::morre_nutrientes_solo_instantes) return false;
	return true;
}

Cacto::~Cacto(){}


