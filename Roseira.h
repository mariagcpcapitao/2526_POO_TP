//
// Created by luana on 30/12/2025.
//

#ifndef ROSEIRA_H
#define ROSEIRA_H

#include "Planta.h"

class Roseira : public Planta
{
public:
	Roseira(Solo* s, int linha, int coluna);
	void absorveAgua(int posLinha, int posColuna, int valorAgua = 0) override;
	void absorveNutrientes(int posLinha, int posColuna, int valorNutri = 0) override;
	void perdeAgua(int posLinha, int posColuna) override;
	void perdeNutri(int posLinha, int posColuna) override;
	void passaTempo() override;
	void multiplica(Jardim * j, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	bool estaViva(Jardim* j) const override;

	~Roseira() override;
	string mostrarDetalhes()const override;
	Planta* clone() const override{
		return new Roseira(*this);
	}
};


#endif //ROSEIRA_H
