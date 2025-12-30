//
// Created by luana on 30/12/2025.
//

#ifndef CACTO_H
#define CACTO_H

#include "Planta.h"

class Cacto : public Planta
{
private:
	int aguaCacto = 2;
	int nutriCacto = 1;
public:
	Cacto(int linha, int coluna, Solo* s);
	void absorveAgua(int posLinha, int posColuna) override;
	void absorveNutrientes(int posLinha, int posColuna) override;
	void perdeAgua(int posLinha, int posColuna) override;
	void perdeNutri(int posLinha, int posColuna) override;
	//void multiplica(Jardim & j, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	~Cacto() override;
};




#endif //CACTO_H
