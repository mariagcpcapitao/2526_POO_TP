//
// Created by luana on 30/12/2025.
//

#include "BastaoImperador.h"
#include "Solo.h"


BastaoImperador::BastaoImperador(int linha, int coluna, Solo* s) : Planta(s, inicial_agua, inicial_nutrientes, "bonita", linha, coluna, 'x') {
	cout<<"plantei bi";
}
void BastaoImperador::absorveAgua(int posLinha, int posColuna, int valor)
{
	if (solo_hosp == nullptr) return;
	int aguaDisponivel = solo_hosp->getAguaSolo();

	int aAbsorver = (aguaDisponivel >= absorcao_agua) ? absorcao_agua : aguaDisponivel;

	if (aAbsorver > 0) {
		solo_hosp->setAguaSolo(aAbsorver, "perder");
		this->agua += aAbsorver;
	}
}
void BastaoImperador::absorveNutrientes(int posLinha, int posColuna, int valor)
{
	if (solo_hosp == nullptr) return;

	int nutriDisponivel = solo_hosp->getNutriSolo();
	int aAbsorver = (nutriDisponivel >= absorcao_nutrientes) ? absorcao_nutrientes : nutriDisponivel;

	if (aAbsorver > 0) {
		solo_hosp->setNutriSolo(aAbsorver, "perder");
		this->nutrientes += aAbsorver;
	}
}
void BastaoImperador::perdeAgua(int posLinha, int posColuna)
{
	this->agua -= perda_agua;
}
void BastaoImperador::perdeNutri(int posLinha, int posColuna)
{
	this->nutrientes -= perda_nutrientes;
}
void BastaoImperador::multiplica(Jardim* j, int posLinha, int posColuna)
{
	if (j == nullptr) return;
	if (this->nutrientes <= multiplica_nutrientes_maior) return;

	Solo* vizinho = j->getVizinhoLivre(posLinha, posColuna, true);

	if (vizinho != nullptr) {

		int aguaFilho = this->agua * (nova_agua_percentagem / 100.0);

		this->agua -= aguaFilho;
		this->nutrientes = original_nutrientes;

		BastaoImperador* filho = new BastaoImperador(0, 0, vizinho);

		filho->agua = aguaFilho;
		filho->nutrientes = nova_nutrientes;

		vizinho->setPlanta(filho);
	}
}
void BastaoImperador::morre()
{
	if (solo_hosp != nullptr) {
		solo_hosp->setAguaSolo(this->agua, "ganhar");
		solo_hosp->setNutriSolo(this->nutrientes, "ganhar");
	}
}
string BastaoImperador::mostrarDetalhes() const {
	std::ostringstream oss;

	oss << "\nNome: Bastão Imperador |"<<endl;
	oss<<Planta::mostrarDetalhes();

	return oss.str();
}
void BastaoImperador::passaTempo()
{
	Planta::passaTempo();

	perdeAgua(posLinha, posColuna);
	perdeNutri(posLinha, posColuna);

	absorveAgua(posLinha, posColuna);
	absorveNutrientes(posLinha, posColuna);
}
bool BastaoImperador::estaViva(Jardim* j)const
{
	if (this->agua < morre_agua_menor) {
		cout << "Bastao do Imperador morreu de sede." << endl;
		return false;
	}

	if (this->nutrientes < morre_nutrientes_menor) {
		cout << "Bastao do Imperador morreu de falta de nutrientes." << endl;
		return false;
	}

	if (this->nutrientes > morre_nutrientes_maior) {
		cout << "Bastao do Imperador morreu intoxicado por excesso de nutrientes" << endl;
		return false;
	}

	return true;
}
BastaoImperador::~BastaoImperador(){}