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
	void usar(Solo& s) override;

	~Adubo() override;
	string mostrarDetalhes()const override;
	Ferramenta* clone() const {
		return new Adubo(*this);
	}
};


#endif //ADUBO_H
