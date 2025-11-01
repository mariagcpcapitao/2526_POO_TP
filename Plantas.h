

#ifndef PLANTAS_H
#define PLANTAS_H
#include <iostream>
#include <string>

using namespace std;

class Plantas
{
protected:
	int nutrientes;
	int agua;
	string beleza;
public:
	Plantas(int nutrientes, int agua, string beleza);
	virtual void absorveAgua(int &agua);
	virtual void absorveNutrientes(int &nutrientes);
	virtual void multiplica(int &nutrientes, int &agua);
	virtual void morre(); // precisa mandar a quantidade de agua e nutri no solo
	~Plantas();
};

class Cacto : public Plantas
{
public:
	void absorveAgua(int &agua) override;
	void absorveNutrientes(int &nutrientes) override;
	void multiplica(int &nutrientes, int &agua) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
};

class Roseira : public Plantas
{
	void absorveAgua(int &agua) override;
	void absorveNutrientes(int &nutrientes) override;
	void multiplica(int &nutrientes, int &agua) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
};

class ErvaDaninha : public Plantas
{
	void absorveAgua(int &agua) override;
	void absorveNutrientes(int &nutrientes) override;
	void multiplica(int &nutrientes, int &agua) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
};

class BastaoImperador : public Plantas
{
	void absorveAgua(int &agua) override;
	void absorveNutrientes(int &nutrientes) override;
	void multiplica(int &nutrientes, int &agua) override;
	void morre() override; // precisa mandar a quantidade de agua e nutri no solo
};
#endif //PLANTAS_H
