

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
	char simbolo;
	int id_ferramenta;
	static int contId;

public:
	Ferramenta(const string &nomeFerr, const char &simbolo);
	int getId();
	virtual void usar();
	virtual ~Ferramenta();
private:
	void setId();
};

class Regador : public Ferramenta
{
	int capacidade = Settings::Regador::capacidade;
	int dose = Settings::Regador::dose;
public:
	Regador();
	void usar() override;

	~Regador() override;
};


class Adubo : public Ferramenta
{
	int capacidade = Settings::Adubo::capacidade;
	int dose = Settings::Adubo::dose;
public:
	Adubo();
	void usar() override;

	~Adubo() override;
};

class TesouraPoda : public Ferramenta
{

public:
	TesouraPoda();
	void usar() override;
	~TesouraPoda() override;
};

class FerramentaZ : public Ferramenta
{
public:
	FerramentaZ();
	void usar() override;
	~FerramentaZ() override;
};

#endif //FERRAMENTAS_H
