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
void Ferramenta::usar() {}
void Ferramenta::setId()
{
	id_ferramenta = ++contId;
}


