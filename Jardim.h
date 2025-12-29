

#ifndef JARDIM_H
#define JARDIM_H
#include "Solo.h"
class Jardim
{
public:
	Jardim(int l, int c);
	void mostraJardim() const;
	int getLinhas() const;
	int getColunas() const;
	Solo & getPosicao(int linha, int coluna);
	Solo* getVizinhoLivre(int l, int c);

	~Jardim();
private:
	int linhas;
	int colunas;
	Solo ** conjunto;

};
#endif //JARDIM_H
