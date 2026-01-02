//
// Created by luana on 30/12/2025.
//

#include "Cacto.h"
#include "Solo.h"

Cacto::Cacto(int linha, int coluna, Solo* s) : Planta(s, aguaCacto, nutriCacto, "neutra", linha, coluna, 'c') {
	cout<<"plantei c";
}

void Cacto::absorveAgua(int posLinha, int posColuna, int valor = 0)
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

void Cacto::absorveNutrientes(int posLinha, int posColuna, int valorNutri)
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

void Cacto::multiplica(Jardim* j, int posLinha, int posColuna) {

	if (this->nutrientes > Settings::Cacto::multiplica_nutrientes_maior &&
		this->agua > Settings::Cacto::multiplica_agua_maior) {

		Solo* vizinho = j->getVizinhoLivre(posLinha, posColuna);

		if (vizinho != nullptr) {
			int metadeAgua = this->agua / 2;
			int metadeNutri = this->nutrientes / 2;

			this->agua = metadeAgua;
			this->nutrientes = metadeNutri;

			Cacto* filho = new Cacto(0, 0, vizinho);
			filho->absorveAgua(0,0,metadeAgua);
			filho->absorveNutrientes(0, 0, metadeNutri);

			vizinho->setPlanta(filho);
			// cout << "Cacto se reproduziu\n";
		}
		}
}
void Cacto::morre()
{
	// deixar no solo os nutrientes absorvidos
	solo_hosp->setNutriSolo(nutriAbsorvidos, "ganhar");
	nutrientes = 0; //...redundante
}
string Cacto::mostrarDetalhes() const {
	std::ostringstream oss;

	oss << "\nNome: Cacto |"<<endl;
	oss<<Planta::mostrarDetalhes();

	return oss.str();
}
Cacto::~Cacto(){}


