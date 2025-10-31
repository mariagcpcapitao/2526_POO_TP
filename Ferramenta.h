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
	string nomeFerr, representacao;
	int id_ferramenta;

public:
	Ferramenta(const string &nomeFerr, int id_ferramenta, const string &representacao);
	virtual void usar();
	virtual ~Ferramenta();
};

class Regador : public Ferramenta
{
	int capacidade = Settings::Regador::capacidade;
	int dose = Settings::Regador::dose;
public:
	Regador(const string &nomeFerr, int id_ferramenta, int qtd_agua, string representacao);
	virtual void usar() override;

	~Regador() override;
};


class Adubo : public Ferramenta
{
	int capacidade = Settings::Adubo::capacidade;
	int dose = Settings::Adubo::dose;
public:
	Adubo(const string &nomeFerr, int id_ferramenta, int qtd_adubo, const string &representacao);
	virtual void usar() override;

	~Adubo() override;
};

class TesouraPoda : public Ferramenta
{

public:
	TesouraPoda(const string &nomeFerr, int id_ferramenta, const string &representacao);
	virtual void usar() override;
	~TesouraPoda() override;
};

class FerramentaZ : public Ferramenta
{
public:
	FerramentaZ(const string &nomeFerr, int id_ferramenta, const string &representacao);
	virtual void usar() override;
	~FerramentaZ() override;
};

#endif //FERRAMENTAS_H
