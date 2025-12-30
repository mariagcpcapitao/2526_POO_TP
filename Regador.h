//
// Created by luana on 30/12/2025.
//

#ifndef REGADOR_H
#define REGADOR_H

#include "Ferramenta.h"

class Regador : public Ferramenta
{
	int capacidade = Settings::Regador::capacidade;
	int dose = Settings::Regador::dose;
public:
	Regador();
	void usar() override;

	~Regador() override;
};


#endif //REGADOR_H
