#ifndef SOLO_H
#define SOLO_H
#include "Jardineiro.h"
#include "Ferramenta.h"
#include "Planta.h"
class Solo
{
private:
	int nutriSolo;
	int aguaSolo;

	Planta *planta = nullptr;
	Ferramenta *ferramenta =  nullptr;
	Jardineiro *jardineiro = nullptr;
public:
	Solo();
	int getNutriSolo(){return nutriSolo;}
	int getAguaSolo(){return aguaSolo;}
	void setNutriSolo(int valor=-1, string acao);
	void setAguaSolo(int valor=-1, string acao);

	void setPlanta(Planta* p);
	void setFerramenta(Ferramenta* f);
	void setJardineiro(Jardineiro* j);

	Planta* getPlanta() const;
	Ferramenta* getFerramenta() const;
	Jardineiro* getJardineiro() const;

	bool temPlanta() const;
	bool temFerramenta() const;
	bool temJardineiro() const;

	~Solo();
};
#endif //SOLO_H
