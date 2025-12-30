

#ifndef JARDINEIRO_H
#define JARDINEIRO_H
class Ferramenta;
class Jardim;
class Solo;

class Jardineiro
{
	int posLinha, posColuna;
	Ferramenta** inventario=nullptr;
	int quant_ferramentas=0;
	char simbolo = '*';
	bool noJardim = false;
	Ferramenta* ferramentaNaMao = nullptr;
	int movEfetuados = 0;      // max 10
	bool jaEntrouNoTurno = false;
	bool jaSaiuNoTurno = false;
	int pColhidas = 0;  //max  5
	int pPlantadas = 0; //max 2

public:
	Jardineiro();
	void resetTurno();
	int getLinha() const { return posLinha; }
	int getColuna() const { return posColuna; }

	void setPosicao(int l, int c) {
		posLinha = l;
		posColuna = c;
	}

	void incrementaMov() { movEfetuados++; }

	bool podeEntrar() const { return !jaEntrouNoTurno; }
	void marcarEntrada() { jaEntrouNoTurno = true; noJardim = true; }

	bool podeSair() const { return !jaSaiuNoTurno; }
	void marcarSaida() { jaSaiuNoTurno = true; noJardim = false; }

	bool isNoJardim() const { return noJardim; }
	void setNoJardim(bool estado) { noJardim = estado; }

	int getMovimentosRestantes() const { return 10 - movEfetuados; }

	char getSimbolo() const{ return simbolo;}

	void comprarFerramenta(Ferramenta *f);
	void adicionarFerramenta(Ferramenta *f);
	bool temFerramentaAtiva() const { return ferramentaNaMao != nullptr; }
	void usarFerramenta(Solo& s);
	void removerFerramenta(int id_ferramenta);
	bool mover(char direcao, Jardim* jardim);
	bool plantar(int l, int c, char tipo, Jardim* jardim);
	bool colher(int l, int c, Jardim* jardim);
	void atualizaFerramentas();

	~Jardineiro();
};
#endif //JARDINEIRO_H
