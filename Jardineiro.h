

#ifndef JARDINEIRO_H
#define JARDINEIRO_H
#include "Ferramenta.h"


class Jardineiro
{
	int posLinha, posColuna;
	Ferramenta** inventario;
	int quant_ferramentas;
	char simbolo = '*';
	bool noJardim = false;
	Ferramenta* ferramentaNaMao = nullptr;
	int movEfetivados = 0;      // max 10
	bool jaEntrouNoTurno = false;
	bool jaSaiuNoTurno = false;
	int plantasColhidasTurno = 0;  //max  5
	int plantasPlantadasTurno = 0; //max 2

public:
	Jardineiro();
	void resetTurno();
	int getLinha() const { return posLinha; }
	int getColuna() const { return posColuna; }

	void setPosicao(int l, int c) {
		posLinha = l;
		posColuna = c;
	}

	bool podeMover() const { return movEfetivados < 10; }
	void incrementaMov() { movEfetivados++; }

	bool podeEntrar() const { return !jaEntrouNoTurno; }
	void marcarEntrada() { jaEntrouNoTurno = true; noJardim = true; }

	bool podeSair() const { return !jaSaiuNoTurno; }
	void marcarSaida() { jaSaiuNoTurno = true; noJardim = false; }

	bool isNoJardim() const { return noJardim; }
	void setNoJardim(bool estado) { noJardim = estado; }

	int getMovimentosRestantes() const { return 10 - movEfetivados; }

	char getSimbolo() const{ return simbolo;}

	void comprarFerramenta(Ferramenta *f);
	void adicionarFerramenta(Ferramenta *f);
	bool temFerramentaAtiva() const { return ferramentaNaMao != nullptr; }
	void usarFerramenta(Solo& s);
	void removerFerramenta(int id_ferramenta);

	~Jardineiro();
};
#endif //JARDINEIRO_H
