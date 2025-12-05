#include "Planta.h"
#include "Settings.h"
#include <string>

#include "Solo.h"

Planta::Planta(Solo *solo, int agua, int nutrientes, string beleza, int posLinha, int posColuna, char simbolo) : solo_hosp(solo), agua(agua), nutrientes(nutrientes), beleza(beleza), posLinha(posLinha), posColuna(posColuna), simbolo(simbolo)
{
	cout << "construindo planta";
}
Planta::~Planta(){}

void Planta::absorveAgua(int &agua, int posLinha, int posColuna) {}
void Planta::absorveNutrientes(int &nutrientes, int posLinha, int posColuna) {}
void Planta::perdeAgua(int &agua, int posLinha, int posColuna){}
void Planta::perdeNutri(int &nutrientes, int posLinha, int posColuna) {}
void Planta::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna) {}
void Planta::morre() {}

Cacto::Cacto(int linha, int coluna) : Planta(solo_hosp, aguaCacto, nutriCacto, "neutra", linha, coluna, 'c'){}

void Cacto::absorveAgua(int &agua, int posLinha, int posColuna)
{
	int agua_solo;
	if (solo_hosp != nullptr)
	{
		// Acessar as propriedades do Solo através do ponteiro:
		agua_solo = solo_hosp->getAguaSolo();
		if (agua_solo > 100 && instantesAguaAlta == 3)
			morre();
		else if (agua_solo > 0)
		{
			agua = agua + agua_solo*0.25;
			solo_hosp->setAguaSolo(agua_solo*0.25, "perder");
		}
	}
}

void Cacto::absorveNutrientes(int &nutrientes, int posLinha, int posColuna)
{
	int nutri_solo;
	if (solo_hosp != nullptr)
	{
		nutri_solo = solo_hosp->getNutriSolo();
		if (nutri_solo == 0 && instantesNutriZero > 3)
			morre();
		else if (nutri_solo >= 5)
		{
			nutrientes = nutrientes + 5;
			nutriAbsorvidos += 5;
			solo_hosp->setNutriSolo(5, "perder");
		}
	}
}
void Cacto::perdeAgua(int &agua, int posLinha, int posColuna){}
void Cacto::perdeNutri(int &nutrientes, int posLinha, int posColuna) {}
void Cacto::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna){}
void Cacto::morre()
{
	// deixar no solo os nutrientes absorvidos
	solo_hosp->setNutriSolo(nutriAbsorvidos, "ganhar");
	// nutriCacto = 0; ...redundante
}
Cacto::~Cacto(){}


Roseira::Roseira(int linha, int coluna): Planta(solo_hosp, Settings::Roseira::inicial_agua, Settings::Roseira::inicial_nutrientes, "bonita", linha, coluna, 'r'){}
void Roseira::absorveAgua(int &agua, int posLinha, int posColuna)
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
void Roseira::absorveNutrientes(int &nutrientes, int posLinha, int posColuna)
{
	if (solo_hosp != nullptr)
	{
		int nutri_solo = solo_hosp->getNutriSolo();
		if (nutri_solo > 0)
		{
			nutrientes += 8;
			if (nutrientes >= 200)
				morre();
			else
				solo_hosp->setNutriSolo(8, "perder");
		}
	}
}
void Roseira::perdeAgua(int &agua, int posLinha, int posColuna)
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
void Roseira::perdeNutri(int &nutrientes, int posLinha, int posColuna)
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
void Roseira::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna){}
void Roseira::morre(){}
Roseira::~Roseira(){}

ErvaDaninha::ErvaDaninha(int linha, int coluna): Planta(solo_hosp, Settings::ErvaDaninha::inicial_agua, Settings::ErvaDaninha::inicial_nutrientes, "feia", linha, coluna, 'e'){}
void ErvaDaninha::absorveAgua(int &agua, int posLinha, int posColuna){}
void ErvaDaninha::absorveNutrientes(int &nutrientes, int posLinha, int posColuna) {}
void ErvaDaninha::perdeAgua(int &agua, int posLinha, int posColuna){}
void ErvaDaninha::perdeNutri(int &nutrientes, int posLinha, int posColuna) {}
void ErvaDaninha::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna){}
void ErvaDaninha::morre(){}
ErvaDaninha::~ErvaDaninha(){}

BastaoImperador::BastaoImperador(int linha, int coluna): Planta(solo_hosp, inicial_agua, inicial_nutrientes, "bonita", linha, coluna, 'x'){}
void BastaoImperador::absorveAgua(int &agua, int posLinha, int posColuna){}
void BastaoImperador::absorveNutrientes(int &nutrientes, int posLinha, int posColuna) {}
void BastaoImperador::perdeAgua(int &agua, int posLinha, int posColuna){}
void BastaoImperador::perdeNutri(int &nutrientes, int posLinha, int posColuna) {}
void BastaoImperador::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna){}
void BastaoImperador::morre(){}
BastaoImperador::~BastaoImperador(){}
