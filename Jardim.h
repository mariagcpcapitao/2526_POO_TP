

#ifndef JARDIM_H
#define JARDIM_H
#include "Solo.h"
class Jardim
{
public:
	Jardim(int l, int c);
	void mostraJardim() const;
	int getLinhas() const; //retorna numero de linhas que o jardim tem
	int getColunas() const; //retorna numero de colunas que o jardim tem
	Solo & getPosicao(int linha, int coluna);

	~Jardim();
private:
	int linhas;
	int colunas;
	Solo ** conjunto;

};
#endif //JARDIM_H
