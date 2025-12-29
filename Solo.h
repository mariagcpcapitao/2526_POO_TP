#ifndef SOLO_H
#define SOLO_H
#include "Jardineiro.h"
#include "Ferramenta.h"
#include "Planta.h"
class Planta;
class Solo
{
private:
	int nutriSolo = -1;
	int aguaSolo = -1;

	Planta *planta = nullptr;
	Ferramenta *ferramenta =  nullptr;
	Jardineiro *jardineiro = nullptr;
public:
	Solo();
	int getNutriSolo() const {return nutriSolo;}
	int getAguaSolo() const {return aguaSolo;}
	char getConteudo() const;

	Solo & getSolo(int l, int c);

	void setNutriSolo(double valor = -1, std::string acao = "");
	void setAguaSolo(double valor = -1, std::string acao = "");

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
