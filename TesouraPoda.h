//
// Created by luana on 30/12/2025.
//

#ifndef TESOURAPODA_H
#define TESOURAPODA_H

#include "Ferramenta.h"

class TesouraPoda : public Ferramenta
{

public:
	TesouraPoda();
	void usar(Solo& s) override;
	~TesouraPoda() override;
	string mostrarDetalhes()const override;
	Ferramenta* clone() const {
		return new TesouraPoda(*this);
	}
	bool deveDescartar() const override {
		return false;
	}
};


#endif //TESOURAPODA_H
