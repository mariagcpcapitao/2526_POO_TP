#include "Ferramenta.h"
int Ferramenta::contId = 0;
Ferramenta::Ferramenta(const string &nome, const char &simbolo) : nomeFerr(nome), simbolo(simbolo)
{
	setId();
}
Ferramenta::~Ferramenta(){}
void Ferramenta::deteriora() {
	cout<<"Ferramenta a deteriorar "<<endl;
}
string Ferramenta::mostrarDetalhes ()const {
	std::ostringstream oss;
	oss << "ID: " << id_ferramenta << " | Simbolo: " << getSimbolo()<< " | Nome da ferramenta:" << getNome();
	return oss.str();
}
void Ferramenta::usar(Solo& s) {}
void Ferramenta::setId()
{
	id_ferramenta = ++contId;
}


