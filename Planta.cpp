#include "Planta.h"
#include "Settings.h"
#include <string>

#include "Solo.h"

Planta::Planta(Solo *solo, int agua, int nutrientes, string beleza, int posLinha, int posColuna, char simbolo) : solo_hosp(solo), agua(agua), nutrientes(nutrientes), beleza(beleza), posLinha(posLinha), posColuna(posColuna), simbolo(simbolo)
{

}
Planta::~Planta(){}

void Planta::absorveAgua(int posLinha, int posColuna) {}
void Planta::absorveNutrientes(int posLinha, int posColuna) {}
void Planta::perdeAgua(int posLinha, int posColuna){}
void Planta::perdeNutri(int posLinha, int posColuna) {}
//void Planta::multiplica(int posLinha, int posColuna) {}
void Planta::morre() {}

Cacto::Cacto(int linha, int coluna) : Planta(solo_hosp, aguaCacto, nutriCacto, "neutra", linha, coluna, 'c'){}

void Cacto::absorveAgua(int posLinha, int posColuna)
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

void Cacto::absorveNutrientes(int posLinha, int posColuna)
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

void Cacto::perdeAgua(int posLinha, int posColuna){}
void Cacto::perdeNutri(int posLinha, int posColuna) {}

/*void Cacto::multiplica(Jardim & j, int posLinha, int posColuna)
{
	if (nutrientes <= 100 || agua <= 50) return;
	Solo* vizinho = j.getVizinhoLivre(posLinha, posColuna);

	if (vizinho != nullptr) {
		// Divide os recursos
		this->nutrientes /= 2;
		this->agua /= 2;

		// cria o novo cacto
		vizinho->setPlanta(new Cacto(this->nutrientes, this->agua));
	}
}*/
void Cacto::morre()
{
	// deixar no solo os nutrientes absorvidos
	solo_hosp->setNutriSolo(nutriAbsorvidos, "ganhar");
	nutrientes = 0; //...redundante
}
Cacto::~Cacto(){}


Roseira::Roseira(int linha, int coluna): Planta(solo_hosp, Settings::Roseira::inicial_agua, Settings::Roseira::inicial_nutrientes, "bonita", linha, coluna, 'r'){}
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
/*void Roseira::multiplica(Jardim & j, int posLinha, int posColuna)
{
	if (this->nutrientes <= 100) {
		return;
	}

	Solo* vizinho = j.getVizinhoLivre(posLinha, posColuna);

	if (vizinho != nullptr) {

		int metadeAgua = this->agua / 2;

		vizinho->setPlanta(new Roseira(25, metadeAgua));

		this->nutrientes = 100;
		this->agua = metadeAgua;
	}
}*/
void Roseira::morre()
{
	solo_hosp->setAguaSolo(aguaAbsorvida/2, "ganhar");
	agua = 0;
	solo_hosp->setNutriSolo(nutriAbsorvidos/2, "ganhar");
}
Roseira::~Roseira(){}

ErvaDaninha::ErvaDaninha(int linha, int coluna): Planta(solo_hosp, Settings::ErvaDaninha::inicial_agua, Settings::ErvaDaninha::inicial_nutrientes, "feia", linha, coluna, 'e'){}
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
//void ErvaDaninha::multiplica(int posLinha, int posColuna){}
void ErvaDaninha::morre(){}
ErvaDaninha::~ErvaDaninha(){}

BastaoImperador::BastaoImperador(int linha, int coluna): Planta(solo_hosp, inicial_agua, inicial_nutrientes, "bonita", linha, coluna, 'x'){}
void BastaoImperador::absorveAgua(int posLinha, int posColuna){}
void BastaoImperador::absorveNutrientes(int posLinha, int posColuna) {}
void BastaoImperador::perdeAgua(int posLinha, int posColuna){}
void BastaoImperador::perdeNutri(int posLinha, int posColuna) {}
//void BastaoImperador::multiplica(int posLinha, int posColuna){}
void BastaoImperador::morre(){}
BastaoImperador::~BastaoImperador(){}
