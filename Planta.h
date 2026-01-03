#ifndef PLANTA_H
#define PLANTA_H
#include <iostream>
#include <string>
#include <sstream>
#include "Jardim.h"

class Solo;
using namespace std;

class Planta
{
protected:
	int nutrientes, agua, posLinha, posColuna, instantesAguaAlta, instantesNutriZero, nutriAbsorvidos = 0, aguaAbsorvida = 0, idade = 0;
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
	int getIdade() const{return idade;}

	virtual Planta* clone() const = 0;
	virtual void passaTempo();
	virtual void absorveAgua(int posLinha, int posColuna, int valor = 0);
	virtual void absorveNutrientes(int posLinha, int posColuna, int valor = 0);
	virtual void perdeAgua(int posLinha, int posColuna);
	virtual void perdeNutri(int posLinha, int posColuna);
	virtual void multiplica(Jardim * j, int posLinha, int posColuna);
	virtual void morre(); // precisa mandar a quantidade de agua e nutri no solo
	virtual bool estaViva(Jardim* j) const { return true;}

	virtual ~Planta();
	virtual string mostrarDetalhes ()const;
};

#endif //PLANTA_H




