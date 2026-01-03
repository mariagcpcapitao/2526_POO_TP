//
// Created by luana on 30/12/2025.
//

#ifndef CACTO_H
#define CACTO_H

#include "Planta.h"
#include "Settings.h"
class Cacto : public Planta
{
	int aguaCacto = 2;
	int nutriCacto = 1;
	int diasComMuitaAgua;
	int diasSemNutrientes;
	int contAguaAlta = 0;
	int contSemNutri = 0;
public:
	Cacto(int linha, int coluna, Solo* s);
	void absorveAgua(int posLinha, int posColuna, int valor) override;
	void absorveNutrientes(int posLinha, int posColuna, int valorNutri = 5) override;
	void perdeAgua(int posLinha, int posColuna) override;
	void perdeNutri(int posLinha, int posColuna) override;
	void passaTempo() override;
	void multiplica(Jardim * j, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	bool estaViva(Jardim* j) const override;

	~Cacto() override;
	string mostrarDetalhes()const override;
	Planta* clone() const override{
		return new Cacto(*this);
	}
};




#endif //CACTO_H
