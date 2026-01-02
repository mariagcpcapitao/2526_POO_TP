

#ifndef JARDIM_H
#define JARDIM_H
#include <string>
class Solo;
class Jardineiro;
class Jardim
{
public:
	Jardim& operator=(const Jardim& outro);
	void colocarFerramentaAleatoria();
	Jardim(int l, int c);
	Jardim(const Jardim& outro);
	void mostraJardim() const;
	int getLinhas() const;
	int getColunas() const;
	void atualizarJardim();
	Solo & getSolo(int linha, int coluna);
	Solo* getVizinhoLivre(int l, int c, bool apenasVazio); // bool pra erva daninha
	Jardineiro* getJardineiro() const { return jardineiro; }
	bool posicionarJardineiro(int l, int c, Jardineiro* j);
	void removerJardineiro();
	bool moverJardineiro(char direcao);
	bool removerPlanta(int l, int c);
	bool adicionarPlanta(int l, int c,char tipo) ;
	void atualiza();
	std::string listarPlantas()const;
	std::string lPlanta(int l, int c)const;
	std::string lArea()const;
	std::string lSolo(int l,int c,int r)const;
	bool removeJardineiro(int l, int c);


	~Jardim();
private:
	int linhas;
	int colunas;
	Solo ** conjunto;
	Jardineiro* jardineiro = nullptr;

};
#endif //JARDIM_H
