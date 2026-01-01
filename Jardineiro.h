

#ifndef JARDINEIRO_H
#define JARDINEIRO_H
#include <vector>
#include <string>
class Ferramenta;
class Jardim;
class Solo;

class Jardineiro
{
	int posLinha, posColuna;
	std::vector<Ferramenta*> inventario;
	int quant_ferramentas=0;
	char simbolo = '*';
	bool noJardim = false;
	Ferramenta* ferramentaNaMao = nullptr;
	int movEfetuados = 0;      // max 10
	int entradasNoTurno;
	int saidasNoTurno;
	int pColhidas = 0;  //max  5
	int pPlantadas = 0; //max 2

public:
	Jardineiro();
	void resetTurno();
	int getLinha() const { return posLinha; }
	int getColuna() const { return posColuna; }
	void largaFerramenta();
	bool pegaFerramenta(int id);

	void setPosicao(int l, int c) {
		posLinha = l;
		posColuna = c;
	}
	bool getNoJardim() const { return noJardim; }
	int getEntradasNoTurno() const { return entradasNoTurno; }
	int getSaidasNoTurno() const { return saidasNoTurno; }
	void marcarEntrada() { entradasNoTurno++; noJardim = true; }
	void marcarSaida() { saidasNoTurno++; noJardim = false; }



	int getMovimentosRestantes() const { return 10 - movEfetuados; }

	char getSimbolo() const{ return simbolo;}
	bool sai() const;
	void adicionarFerramenta(Ferramenta *f);
	bool temFerramentaAtiva() const { return ferramentaNaMao != nullptr; }
	void usarFerramenta(Solo& s);
	//void removerFerramenta(int id_ferramenta);
	bool mover(char direcao, Jardim* jardim);
	bool plantar(int l, int c, char tipo, Jardim* jardim);
	bool colher(int l, int c, Jardim* jardim);
	void atualizaFerramentas();
	bool sai(Jardim* jardim) ;
	std::string listarFerramentas() const;

	~Jardineiro();
};
#endif //JARDINEIRO_H
