#ifndef SOLO_H
#define SOLO_H

#include <string>
class Planta;
class Ferramenta;
class Jardineiro;

class Solo
{

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
	std::string mostrarDetalhes() const;

	Solo & getSolo(int l, int c);

	void setNutriSolo(double valor = -1, std::string acao = "");
	void setAguaSolo(double valor = -1, std::string acao = "");

	void setPlanta(Planta* p);
	void setFerramenta(Ferramenta* f);
	void setJardineiro(Jardineiro* j){this->jardineiro = j;};

	Planta* getPlanta() const;
	Ferramenta* getFerramenta() const;
	Jardineiro* getJardineiro() const;

	bool temPlanta() const;
	bool temFerramenta() const;
	bool temJardineiro() const;

	void removerPlanta();
	Solo& operator=(const Solo& outro);

	~Solo();
};
#endif //SOLO_H
