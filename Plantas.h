#ifndef PLANTAS_H
#define PLANTAS_H
#include <iostream>
#include <string>

using namespace std;

class Plantas
{
protected:
	int nutrientes, agua;
	int posLinha, posColuna;
	string beleza;
	char simbolo;
public:
	Plantas(int agua, int nutrientes, string beleza, int posLinha, int posColuna, char simbolo);
	int getPosLinha() const;
	int getPosColuna() const;
	int setPosLinha();
	int setPosColuna();
	string getBeleza() const;

	virtual void absorveAgua(int &agua, int posLinha, int posColuna);
	virtual void absorveNutrientes(int &nutrientes, int posLinha, int posColuna);
	virtual void perdeAgua(int &agua, int posLinha, int posColuna);
	virtual void perdeNutri(int &nutrientes, int posLinha, int posColuna);
	virtual void multiplica(int &nutrientes, int &agua, int posLinha, int posColuna);
	virtual void morre(); // precisa mandar a quantidade de agua e nutri no solo
	virtual ~Plantas();
};

class Cacto : public Plantas
{
private:
	int instantesAguaAlta, instantesNutriZero, nutriAbsorvidos;
	int aguaCacto = 2;
	int nutriCacto = 1;
public:
	Cacto(int linha, int coluna);
	void absorveAgua(int &agua, int posLinha, int posColuna) override;
	void absorveNutrientes(int &nutrientes, int posLinha, int posColuna) override;
	void perdeAgua(int &agua, int posLinha, int posColuna) override;
	void perdeNutri(int &nutrientes, int posLinha, int posColuna) override;
	void multiplica(int &nutrientes, int &agua, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	~Cacto() override;
};

class Roseira : public Plantas
{
public:
	Roseira(int linha, int coluna);
	void absorveAgua(int &agua, int posLinha, int posColuna) override;
	void absorveNutrientes(int &nutrientes, int posLinha, int posColuna) override;
	void perdeAgua(int &agua, int posLinha, int posColuna) override;
	void perdeNutri(int &nutrientes, int posLinha, int posColuna) override;
	void multiplica(int &nutrientes, int &agua, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	~Roseira() override;
};

class ErvaDaninha : public Plantas
{
public:
	ErvaDaninha(int linha, int coluna);
	void absorveAgua(int &agua, int posLinha, int posColuna) override;
	void absorveNutrientes(int &nutrientes, int posLinha, int posColuna) override;
	void perdeAgua(int &agua, int posLinha, int posColuna) override;
	void perdeNutri(int &nutrientes, int posLinha, int posColuna) override;
	void multiplica(int &nutrientes, int &agua, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	~ErvaDaninha() override;
};

class BastaoImperador : public Plantas
{
public:
	BastaoImperador(int linha, int coluna);
	void absorveAgua(int &agua, int posLinha, int posColuna) override;
	void absorveNutrientes(int &nutrientes, int posLinha, int posColuna) override;
	void perdeAgua(int &agua, int posLinha, int posColuna) override;
	void perdeNutri(int &nutrientes, int posLinha, int posColuna) override;
	void multiplica(int &nutrientes, int &agua, int posLinha, int posColuna) override;
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
#endif //PLANTAS_H




