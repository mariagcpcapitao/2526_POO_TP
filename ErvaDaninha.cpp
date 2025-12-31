//
// Created by luana on 30/12/2025.
//

#include "ErvaDaninha.h"
#include "Solo.h"
#include "Settings.h"

ErvaDaninha::ErvaDaninha(int linha, int coluna, Solo* s) : Planta(s, Settings::ErvaDaninha::inicial_agua, Settings::ErvaDaninha::inicial_nutrientes, "feia", linha, coluna, 'e') {
	cout<<"plantei ed";
}
void ErvaDaninha::absorveAgua(int posLinha, int posColuna)
{
	if (solo_hosp != nullptr)
	{
		int agua_solo = solo_hosp->getAguaSolo();
		if (agua_solo > 0)
		{
			agua++;
			aguaAbsorvida++;
			solo_hosp->setAguaSolo(1, "perder");
		}
	}
}
void ErvaDaninha::absorveNutrientes(int posLinha, int posColuna)
{
	if (solo_hosp != nullptr)
	{
		int nutri_solo = solo_hosp->getNutriSolo();
		if (nutri_solo > 0)
		{
			nutrientes++;
			nutriAbsorvidos++;
			solo_hosp->setNutriSolo(1, "perder");
		}
	}
}
void ErvaDaninha::perdeAgua(int posLinha, int posColuna){}
void ErvaDaninha::perdeNutri(int posLinha, int posColuna) {}
void ErvaDaninha::multiplica(Jardim & j, int posLinha, int posColuna){}
void ErvaDaninha::morre(){}
ErvaDaninha::~ErvaDaninha(){}