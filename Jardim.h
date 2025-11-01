//
// Created by 1663m on 29/10/2025.
//

#ifndef JARDIM_H
#define JARDIM_H

class Jardim
{
	int agua = 0;
	int nutrientes = 0;
public:
	Jardim(int agua, int nutrientes, int l, int c);
	void mostraJardim() const;
	int getLinhas() const;
	int getColunas() const;

	~Jardim();
private:
	int linhas;
	int colunas;

};
#endif //JARDIM_H
