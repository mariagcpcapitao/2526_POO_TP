

#ifndef FERRAMENTAS_H
#define FERRAMENTAS_H

#include <string>
#include<iostream>
#include<sstream>
#include "Settings.h"
#include "Solo.h"

using namespace std;
class Ferramenta
{
protected:
	string nomeFerr;
	char simbolo;
	int id_ferramenta;
	static int contId;
	int durabilidade=100;
	Solo *solo_onde_esta;

public:
	Ferramenta(const string &nomeFerr, const char &simbolo);
	int getId(){return id_ferramenta;};
	void deteriora();
	char getSimbolo() const{return simbolo;}
	int getDurabilidade() const{return durabilidade;}
	string getNome() const{return nomeFerr;}
	virtual void usar(Solo& s);
	virtual ~Ferramenta();
	virtual string mostrarDetalhes ()const;
	virtual Ferramenta* clone() const = 0;
private:
	void setId();
};

#endif //FERRAMENTAS_H
