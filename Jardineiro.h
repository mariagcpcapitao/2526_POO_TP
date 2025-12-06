

#ifndef JARDINEIRO_H
#define JARDINEIRO_H
#include "Ferramenta.h"


class Jardineiro
{
private:
	int posLinha, posColuna;
	Ferramenta** inventario;
	int quant_ferramentas;
	char simbolo = '*';
	bool noJardim = false;

public:
	Jardineiro();
	char getSimbolo() const{ return simbolo;}
	Solo & getSolo() const;
	void mover(int &posLinha, int &posColuna);
	void comprarFerramenta(Ferramenta *f);
	void adicionarFerramenta(Ferramenta *f);
	void usarFerramenta(int index);
	void removerFerramenta(int id_ferramenta);

	~Jardineiro();
};
#endif //JARDINEIRO_H
