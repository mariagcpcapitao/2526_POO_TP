//
// Created by 1663m on 29/10/2025.
//

#ifndef FERRAMENTAS_H
#define FERRAMENTAS_H

#include <string>
#include<iostream>
#include "Settings.h"

using namespace std;
class Ferramenta
{
protected:
	string nomeFerr;
	int id_ferramenta;

public:
	Ferramenta(const string &nomeFerr, int id_ferramenta);
	virtual void usar();
	virtual ~Ferramenta();
};

class Regador : public Ferramenta
{
public:
	Regador(const string &nomeFerr, int id_ferramenta, int capacidade);
	virtual void usar() override;

	~Regador() override;
private:
	int capacidade = Settings::Regador::capacidade;
	int dose = Settings::Regador::dose;
};

class

#endif //FERRAMENTAS_H
