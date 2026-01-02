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
void Roseira::multiplica(Jardim * j, int posLinha, int posColuna)
{
    if (this->nutrientes > Settings::Roseira::multiplica_nutrientes_maior) {

        Solo* vizinho = j->getVizinhoLivre(posLinha, posColuna);

        if (vizinho != nullptr) {
            int aguaPai = this->agua;
            int aguaFilho = aguaPai * Settings::Roseira::nova_agua_percentagem / 100; // 50%

            this->nutrientes = Settings::Roseira::original_nutrientes;
            this->agua = aguaPai * Settings::Roseira::original_agua_percentagem / 100; // 50%

            Roseira* filha = new Roseira(vizinho, 0, 0);
            filha->absorveNutrientes(0, 0, Settings::Roseira::nova_nutrientes); // 25
            filha->absorveAgua(0,0, aguaFilho);

            vizinho->setPlanta(filha);
            // cout << "Roseira reproduziu-se!\n";
        }
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