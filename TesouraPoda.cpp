//
// Created by luana on 30/12/2025.
//

#include "TesouraPoda.h"

#include <string.h>

#include "Planta.h"


TesouraPoda::TesouraPoda() : Ferramenta("Tesoura de Poda", 't') {}
TesouraPoda::~TesouraPoda() {}
void TesouraPoda::usar(Solo& s)
{
	if (s.temPlanta()) {
		Planta* p = s.getPlanta();
		if (p->getSimbolo() == 'e') {
			s.removerPlanta();
			cout << "A tesoura eliminou uma Erva Daninha!" << endl;

		} else {
			cout << "O jardineiro nao cortou plantas bonitas ou neutras" << endl;
		}
	} else {
		cout << "Nao ha nada para cortar nesta posicao." << endl;
	}
}
string TesouraPoda::mostrarDetalhes() const {
	std::ostringstream oss;

	oss << Ferramenta::mostrarDetalhes();

	string estado;

	if (durabilidade >= 95) {
		estado = "Lamina de aço cromado, corte cirurgico";
	// } else if (durabilidade >= 75) {
	// 	estado = "Bem afiada, cumpre a funcao";
	// } else if (durabilidade >= 50) {
	// 	estado = "A precisar de ser afiada em breve";
	// } else if (durabilidade >= 20) {
	// 	estado = "Corte dificil, mastiga a planta";
	// } else if (durabilidade > 0) {
	// 	estado = "COMPRA UMA NOVA";
	}

	oss << " | Estado atual: " << estado  << endl;
	return oss.str();
}