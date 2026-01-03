//
// Created by luana on 30/12/2025.
//

#ifndef ERVADANINHA_H
#define ERVADANINHA_H

#include "Planta.h"

class ErvaDaninha : public Planta
{
	int contadorReproducao = 0;
public:
	ErvaDaninha(int linha, int coluna, Solo* s);
	void absorveAgua(int posLinha, int posColuna, int valor = 0) override;
	void absorveNutrientes(int posLinha, int posColuna, int valor = 0) override;
	void perdeAgua(int posLinha, int posColuna) override;
	void perdeNutri(int posLinha, int posColuna) override;
	void passaTempo() override;
	void multiplica(Jardim * j, int posLinha, int posColuna) override;
	bool estaViva(Jardim* j) const override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	~ErvaDaninha() override;
	string mostrarDetalhes()const override;
	Planta* clone() const override {
		return new ErvaDaninha(*this);
	}
};


#endif //ERVADANINHA_H
