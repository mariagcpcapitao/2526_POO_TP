//
// Created by luana on 30/12/2025.
//

#include "Regador.h"

Regador::Regador() : Ferramenta("Regador", 'g')
{
	cout << "Regador " <<  id_ferramenta << " com capacidade de: " << capacidade << " unidades de agua " << endl;
}
Regador::~Regador()
{
	cout << "Regador descartado, nao ha mais agua.";
}

void Regador::usar(Solo& s)
{
	if (capacidade >= dose) {
		capacidade = capacidade - dose;
		s.setAguaSolo(dose, "ganhar");
		cout << "Regou o solo (+" << dose << " agua). Restante: " << capacidade << endl;
	} else {
		cout << "Regador vazio." << endl;
	}
}
string Regador::mostrarDetalhes() const {
	std::ostringstream oss;

	oss << Ferramenta::mostrarDetalhes();
	oss << " | Agua: " << capacidade << " ml" << endl;
	return oss.str();
}