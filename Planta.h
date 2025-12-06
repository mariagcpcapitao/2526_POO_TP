#ifndef PLANTA_H
#define PLANTA_H
#include <iostream>
#include <string>
#include "Simulacao.h"

class Solo;
using namespace std;

class Planta
{
protected:
	int nutrientes, agua, posLinha, posColuna, instantesAguaAlta, instantesNutriZero, nutriAbsorvidos = 0, aguaAbsorvida = 0;
	string beleza;
	char simbolo;
	Solo *solo_hosp;

public:
	Planta(Solo *solo, int agua, int nutrientes, string beleza, int posLinha, int posColuna, char simbolo);
	int getPosLinha() const {return posLinha;}
	int getPosColuna() const {return posColuna;}
	char getSimbolo() const {return simbolo;}
	int setPosLinha();
	int setPosColuna();
	string getBeleza() const;


	virtual void absorveAgua(int posLinha, int posColuna);
	virtual void absorveNutrientes(int posLinha, int posColuna);
	virtual void perdeAgua(int posLinha, int posColuna);
	virtual void perdeNutri(int posLinha, int posColuna);
	virtual void multiplica(int posLinha, int posColuna);
	virtual void morre(); // precisa mandar a quantidade de agua e nutri no solo
	virtual ~Planta();
};

class Cacto : public Planta
{
private:
	int aguaCacto = 2;
	int nutriCacto = 1;
public:
	Cacto(int linha, int coluna);
	void absorveAgua(int posLinha, int posColuna) override;
	void absorveNutrientes(int posLinha, int posColuna) override;
	void perdeAgua(int posLinha, int posColuna) override;
	void perdeNutri(int posLinha, int posColuna) override;
	void multiplica(int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	~Cacto() override;
};

class Roseira : public Planta
{
public:
	Roseira(int linha, int coluna);
	void absorveAgua(int posLinha, int posColuna) override;
	void absorveNutrientes(int posLinha, int posColuna) override;
	void perdeAgua(int posLinha, int posColuna) override;
	void perdeNutri(int posLinha, int posColuna) override;
	void multiplica(int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	~Roseira() override;
};

class ErvaDaninha : public Planta
{
public:
	ErvaDaninha(int linha, int coluna);
	void absorveAgua(int posLinha, int posColuna) override;
	void absorveNutrientes(int posLinha, int posColuna) override;
	void perdeAgua(int posLinha, int posColuna) override;
	void perdeNutri(int posLinha, int posColuna) override;
	void multiplica(int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	~ErvaDaninha() override;
};

class BastaoImperador : public Planta
{
public:
	BastaoImperador(int linha, int coluna);
	void absorveAgua(int posLinha, int posColuna) override;
	void absorveNutrientes(int posLinha, int posColuna) override;
	void perdeAgua(int posLinha, int posColuna) override;
	void perdeNutri(int posLinha, int posColuna) override;
	void multiplica(int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
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
#endif //PLANTA_H




