//
// Created by luana on 30/12/2025.
//

#ifndef BASTAOIMPERADOR_H
#define BASTAOIMPERADOR_H

#include "Planta.h"

class BastaoImperador : public Planta
{
public:
	BastaoImperador(int linha, int coluna, Solo* s);
	void absorveAgua(int posLinha, int posColuna, int valor = 0) override;
	void absorveNutrientes(int posLinha, int posColuna, int valor = 0) override;
	void perdeAgua(int posLinha, int posColuna) override;
	void perdeNutri(int posLinha, int posColuna) override;
	void passaTempo() override;
	void multiplica(Jardim * j, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	string mostrarDetalhes()const override;
	Planta* clone() const override {
		return new BastaoImperador(*this);
	}
	bool estaViva(Jardim* j)const override;
	~BastaoImperador() override;
private:
	static const int inicial_agua = 40;
	static const int inicial_nutrientes = 15;
	static const int perda_agua = 4;
	static const int perda_nutrientes = 4;
	static const int absorcao_agua = 8;
	static const int absorcao_nutrientes = 6;
	static const int morre_agua_menor = 15;
	static const int morre_nutrientes_menor = 4;
	static const int morre_nutrientes_maior = 130;
	static const int multiplica_nutrientes_maior = 50;
	static const int nova_nutrientes = 15;
	static const int nova_agua_percentagem = 50;
	static const int original_nutrientes = 90;
	static const int original_agua_percentagem = 50;
};


#endif //BASTAOIMPERADOR_H
