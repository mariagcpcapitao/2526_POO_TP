//
// Created by luana on 30/12/2025.
//

#include "Roseira.h"
#include "Settings.h"
#include "Solo.h"

Roseira::Roseira(Solo* s, int linha, int coluna) : Planta(s, Settings::Roseira::inicial_agua, Settings::Roseira::inicial_nutrientes, "bonita", linha, coluna, 'r') {
	cout<<"plantei r";
}
void Roseira::absorveAgua(int posLinha, int posColuna, int valor)
{
	if (solo_hosp != nullptr)
	{
		int agua_solo = solo_hosp->getAguaSolo();
		if (agua_solo > 0)
		{
			agua += 5;
			aguaAbsorvida += 5;
			solo_hosp->setAguaSolo(5, "perder");
		}
	}
}
void Roseira::absorveNutrientes(int posLinha, int posColuna, int valor)
{
	if (solo_hosp != nullptr)
	{
		int nutri_solo = solo_hosp->getNutriSolo();
		if (nutri_solo > 0)
		{
			nutrientes += 8;
			nutriAbsorvidos += 8;
			if (nutrientes >= 200)
				morre();
			else
				solo_hosp->setNutriSolo(8, "perder");
		}
	}
}
void Roseira::perdeAgua(int posLinha, int posColuna)
{
	if (solo_hosp != nullptr)
	{
		agua -= 4;
		if (agua <= 0)
			morre();
		else
			solo_hosp->setAguaSolo(5, "ganhar");

	}
}
void Roseira::perdeNutri(int posLinha, int posColuna)
{
	if (solo_hosp != nullptr)
	{
		nutrientes -= 4;
		if (nutrientes <= 0)
			morre();
		else
			solo_hosp->setNutriSolo(5, "ganhar");
	}
}
void Roseira::passaTempo() {
	Planta::passaTempo();
	this->perdeAgua(0,0);
	this->perdeNutri(0,0);
}


void Roseira::multiplica(Jardim * j, int posLinha, int posColuna)
{
	if (this->nutrientes > Settings::Roseira::multiplica_nutrientes_maior) {

		Solo* vizinho = j->getVizinhoLivre(posLinha, posColuna, true);

		if (vizinho != nullptr) {

			int aguaAtual = this->agua;
			int aguaParaFilho = aguaAtual * Settings::Roseira::nova_agua_percentagem / 100;
			int aguaParaPai = aguaAtual - aguaParaFilho;

			this->nutrientes = Settings::Roseira::original_nutrientes;
			this->agua = aguaParaPai;

			Roseira* filha = new Roseira(vizinho, 0, 0);

			filha->nutrientes = Settings::Roseira::nova_nutrientes;
			filha->agua = aguaParaFilho;

			vizinho->setPlanta(filha);
		}
	}
}

void Roseira::morre()
{
	if (solo_hosp != nullptr) {
		int devolverNutri = this->nutrientes / 2;
		int devolverAgua = this->agua / 2;

		solo_hosp->setNutriSolo(devolverNutri, "ganhar");
		solo_hosp->setAguaSolo(devolverAgua, "ganhar");
	}
}
string Roseira::mostrarDetalhes() const {
	std::ostringstream oss;

	oss << "\nNome: Roseira |"<<endl;
	oss<<Planta::mostrarDetalhes();

	return oss.str();
}

bool Roseira::estaViva(Jardim* j) const {
	if (agua <= 0 || nutrientes <= 0) return false;
	if (nutrientes >= Settings::Roseira::morre_nutrientes_maior) return false;

	// Regra: Cercada por vizinhos
	// Se getVizinhoLivre retornar nullptr, é porque estão todos ocupados
	if (j->getVizinhoLivre(posLinha, posColuna, true) == nullptr) {
		return false;
	}
	return true;
}

Roseira::~Roseira(){}