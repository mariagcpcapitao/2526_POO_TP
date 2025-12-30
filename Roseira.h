//
// Created by luana on 30/12/2025.
//

#ifndef ROSEIRA_H
#define ROSEIRA_H

#include "Planta.h"

class Roseira : public Planta
{
public:
	Roseira(int linha, int coluna, Solo* s);
	void absorveAgua(int posLinha, int posColuna) override;
	void absorveNutrientes(int posLinha, int posColuna) override;
	void perdeAgua(int posLinha, int posColuna) override;
	void perdeNutri(int posLinha, int posColuna) override;
	//void multiplica(Jardim & j, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	~Roseira() override;
};


#endif //ROSEIRA_H
