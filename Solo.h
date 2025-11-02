#ifndef SOLO_H
#define SOLO_H
#include "Jardineiro.h"
#include "Ferramenta.h"
#include "Plantas.h"
class Solo
{
private:
	int nutriSolo;
	int aguaSolo;

	Plantas *planta;
	Ferramenta *ferramenta;
	Jardineiro *jardineiro;
public:
	Solo();
	void getNutriSolo();
	void getAguaSolo();
	void setNutriSolo();
	void setAguaSolo();

	void setPlanta(Plantas* p);
	void setFerramenta(Ferramenta* f);
	void setJardineiro(Jardineiro* j);

	Plantas* getPlanta() const;
	Ferramenta* getFerramenta() const;
	Jardineiro* getJardineiro() const;

	bool temPlanta() const;
	bool temFerramenta() const;
	bool temJardineiro() const;

	~Solo();
};
#endif //SOLO_H
