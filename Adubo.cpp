//
// Created by luana on 30/12/2025.
//

#include "Adubo.h"


Adubo::Adubo() : Ferramenta("Adubo", 'a'){}
Adubo::~Adubo(){}

void Adubo::usar(Solo& s)
{
	if (capacidade >= dose) {
		capacidade = capacidade - dose;
		s.setNutriSolo(dose, "ganhar");

		cout << "Adubou o solo (+" << dose << " nutri). Restante: " << capacidade << endl;
	} else {
		cout << "Saco de adubo vazio." << endl;
	}
}
string Adubo::mostrarDetalhes() const {
	std::ostringstream oss;

	oss << Ferramenta::mostrarDetalhes();
	oss << " | Capacidade: " << capacidade << " kg" << endl;
	return oss.str();
}