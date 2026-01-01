//
// Created by luana on 30/12/2025.
//

#include "Roseira.h"
#include "Settings.h"
#include "Solo.h"

Roseira::Roseira(Solo* s, int linha, int coluna) : Planta(s, Settings::Roseira::inicial_agua, Settings::Roseira::inicial_nutrientes, "bonita", linha, coluna, 'r') {
	cout<<"plantei r";
}
void Roseira::absorveAgua(int posLinha, int posColuna)
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
void Roseira::absorveNutrientes(int posLinha, int posColuna)
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
void Roseira::multiplica(Jardim & j, int posLinha, int posColuna)
{
	if (this->nutrientes <= 100) {
		return;
	}

	Solo* vizinho = j.getVizinhoLivre(posLinha, posColuna);

	if (vizinho != nullptr) {

		int metadeAgua = this->agua / 2;

		vizinho->setPlanta(new Roseira(vizinho, 25, metadeAgua));

		this->nutrientes = 100;
		this->agua = metadeAgua;
	}
}
void Roseira::morre()
{
	solo_hosp->setAguaSolo(aguaAbsorvida/2, "ganhar");
	agua = 0;
	solo_hosp->setNutriSolo(nutriAbsorvidos/2, "ganhar");
}
string Roseira::mostrarDetalhes() const {
	std::ostringstream oss;

	oss << "\nNome: Roseira |"<<endl;
	oss<<Planta::mostrarDetalhes();

	return oss.str();
}
Roseira::~Roseira(){}