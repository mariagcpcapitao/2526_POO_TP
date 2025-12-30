

#ifndef FERRAMENTAS_H
#define FERRAMENTAS_H

#include <string>
#include<iostream>
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
	Solo *solo_onde_esta;

public:
	Ferramenta(const string &nomeFerr, const char &simbolo);
	int getId();
	void deteriora();
	char getSimbolo() const{return simbolo;}
	virtual void usar();
	virtual ~Ferramenta();
private:
	void setId();
};

#endif //FERRAMENTAS_H
