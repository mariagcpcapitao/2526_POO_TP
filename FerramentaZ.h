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
	void usar() override;
	~FerramentaZ() override;
};


#endif //FERRAMENTAZ_H
