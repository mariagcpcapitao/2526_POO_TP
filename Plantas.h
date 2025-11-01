#ifndef PLANTAS_H
#define PLANTAS_H
#include <iostream>
#include <string>

using namespace std;

class Plantas
{
protected:
	int nutrientes, agua, posLinha, posColuna;
	string beleza;
	char simbolo;
public:
	Plantas(int agua, int nutrientes, string beleza, int posLinha, int posColuna, char simbolo);
	int getPosLinha() const;
	int getPosColuna() const;
	int setPosLinha();
	int setPosColuna();
	string getBeleza() const;

	virtual void absorveAgua(int &agua);
	virtual void absorveNutrientes(int &nutrientes);
	virtual void multiplica(int &nutrientes, int &agua, int posLinha, int posColuna);
	virtual void morre(); // precisa mandar a quantidade de agua e nutri no solo
	virtual ~Plantas() = default;
};

class Cacto : public Plantas
{
private:
	int instantesAguaAlta, instantesNutriZero, nutriAbsorvidos;
	int aguaCacto = 2, nutriCacto = 1;
public:
	Cacto(int aguaCacto, int nutriCacto, int linha, int coluna);
	void absorveAgua(int &agua) override;
	void absorveNutrientes(int &nutrientes) override;
	void multiplica(int &nutrientes, int &agua, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
	~Cacto() override;
};

class Roseira : public Plantas
{
	void absorveAgua(int &agua) override;
	void absorveNutrientes(int &nutrientes) override;
	void multiplica(int &nutrientes, int &agua, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
};

class ErvaDaninha : public Plantas
{
	void absorveAgua(int &agua) override;
	void absorveNutrientes(int &nutrientes) override;
	void multiplica(int &nutrientes, int &agua, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
};

class BastaoImperador : public Plantas
{
	void absorveAgua(int &agua) override;
	void absorveNutrientes(int &nutrientes) override;
	void multiplica(int &nutrientes, int &agua, int posLinha, int posColuna) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
};
#endif //PLANTAS_H




