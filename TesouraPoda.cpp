//
// Created by luana on 30/12/2025.
//

#include "TesouraPoda.h"


TesouraPoda::TesouraPoda() : Ferramenta("Tesoura de Poda", 't') {}
void TesouraPoda::usar(Solo& s)
{
	//elimina plantas
}
TesouraPoda::~TesouraPoda() {}
string TesouraPoda::mostrarDetalhes() const {
	std::ostringstream oss;

	oss << Ferramenta::mostrarDetalhes();

	string estado;

	if (durabilidade >= 95) {
		estado = "Lamina impecavel, corte cirurgico";
	} else if (durabilidade >= 75) {
		estado = "Bem afiada, cumpre a funcao";
	} else if (durabilidade >= 50) {
		estado = "A precisar de ser afiada em breve";
	} else if (durabilidade >= 20) {
		estado = "Corte dificil, mastiga a planta";
	} else if (durabilidade > 0) {
		estado = "COMPRA UMA NOVA";
	}

	oss << " | Estado atual: " << estado  << endl;
	return oss.str();
}