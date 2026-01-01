//
// Created by luana on 30/12/2025.
//

#ifndef FERRAMENTAZ_H
#define FERRAMENTAZ_H

#include "Ferramenta.h"

class FerramentaZ : public Ferramenta
{
public:
	FerramentaZ();
	void usar(Solo& s) override;
	~FerramentaZ() override;
	string mostrarDetalhes()const override;
	Ferramenta* clone() const {
		return new FerramentaZ(*this);
	}
};


#endif //FERRAMENTAZ_H
