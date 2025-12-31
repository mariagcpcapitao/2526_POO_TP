//
// Created by luana on 30/12/2025.
//

#ifndef ADUBO_H
#define ADUBO_H

#include "Ferramenta.h"

class Adubo : public Ferramenta
{
	int capacidade = Settings::Adubo::capacidade;
	int dose = Settings::Adubo::dose;
public:
	Adubo();
	void usar() override;

	~Adubo() override;
	string mostrarDetalhes()const override;
};


#endif //ADUBO_H
