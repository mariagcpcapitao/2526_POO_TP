

#include "Jardim.h"

#include <iostream>
#include <ostream>

#include "Solo.h"
#include "Planta.h"
#include "Cacto.h"
#include "Roseira.h"
#include "ErvaDaninha.h"
#include "BastaoImperador.h"
#include "Jardineiro.h"
#include "GestorComandos.h"
#include "Ferramenta.h"
#include "Adubo.h"
#include "Regador.h"
#include "FerramentaZ.h"
#include "TesouraPoda.h"
#include "Utilidades.h"
using namespace std;
Jardim::Jardim(int l, int c) : linhas(l), colunas(c), conjunto(nullptr)
{
	int numFerrInicial=3;
	if (l*c<3)
		numFerrInicial=l*c;
	conjunto = new Solo*[linhas];
	for (int i = 0; i < linhas; i++)
		conjunto[i] = new Solo[colunas];
	for (int i = 0; i < numFerrInicial; i++) {
		colocarFerramentaAleatoria();
	}
}
void Jardim::colocarFerramentaAleatoria() {
	int l, c;
	do {
		l = Utilidades::obterValorAleatorio(0, linhas - 1);
		c = Utilidades::obterValorAleatorio(0, colunas - 1);
	} while (conjunto[l][c].temFerramenta());

	int tipo = Utilidades::obterValorAleatorio(1, 4);
	Ferramenta* f = nullptr;

	switch (tipo) {
		case 1: f = new Regador(); break;
		case 2: f = new Adubo(); break;
		case 3: f = new TesouraPoda(); break;
		case 4: f = new FerramentaZ(); break;
	}

	if (f != nullptr) {
		conjunto[l][c].setFerramenta(f);
	}
}
Jardim::Jardim(const Jardim& outro) {
	if (&outro == nullptr) {
		throw std::invalid_argument("Tentativa de copiar de ponteiro nulo");
	}

	this->linhas = outro.linhas;
	this->colunas = outro.colunas;


	try {
		this->conjunto = new Solo*[linhas];
		for (int i = 0; i < linhas; i++) {
			this->conjunto[i] = new Solo[colunas];
			for (int j = 0; j < colunas; j++) {

				this->conjunto[i][j] = outro.conjunto[i][j];
			}
		}
	} catch (const std::bad_alloc& e) {
		std::cout << "Falha ao alocar memoria para copia: "
				  << e.what() << std::endl;
		if (this->conjunto != nullptr) {
			for (int i = 0; i < linhas && this->conjunto[i] != nullptr; i++) {
				delete[] this->conjunto[i];
			}
			delete[] this->conjunto;
		}
		throw;
	}

	this->jardineiro = nullptr;

}
Jardim::~Jardim() {

	if (conjunto != nullptr) {
		for (int i = 0; i < linhas; i++)
			delete[] conjunto[i];

		delete[] conjunto;
		conjunto = nullptr;
	}
}
Jardim& Jardim::operator=(const Jardim& outro) {
	if (this == &outro) return *this;

	// Libertar memória atual
	for (int i = 0; i < linhas; i++) {
		delete[] conjunto[i];
	}
	delete[] conjunto;

	this->linhas = outro.linhas;
	this->colunas = outro.colunas;

	this->conjunto = new Solo*[linhas];
	for (int i = 0; i < linhas; i++) {
		this->conjunto[i] = new Solo[colunas];
		for (int j = 0; j < colunas; j++) {
			this->conjunto[i][j] = outro.conjunto[i][j];
		}
	}

	this->jardineiro = nullptr;

	return *this;
}
int Jardim::getLinhas() const{ return linhas; }
int Jardim::getColunas() const{ return colunas; }
void Jardim::atualizarJardim() {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			Solo& s = conjunto[i][j];

			if (s.temPlanta()) {
				Planta* p = s.getPlanta();

				if (p->getIdade() == 0) {
					continue;
				}

				p->absorveAgua(i, j);
				p->absorveNutrientes(i, j);

				if (!p->estaViva(this)) {
					p->morre();
					delete p;
					s.setPlanta(nullptr);
					continue;
				}

				p->multiplica(this, i, j);
			}

			if (s.temJardineiro()) {
				Jardineiro* j = s.getJardineiro();


				if (j->temFerramentaAtiva()) {
					j->usarFerramenta(s);
				}
			}
		}
	}
	this->atualiza();
}

Solo & Jardim::getSolo(int linha, int coluna) {
	return conjunto[linha][coluna];
}

void Jardim::mostraJardim() const {
	if (conjunto == nullptr) {
		cout << "jardim nullptr" << endl;
		return;
	}

	if (linhas <= 0 || colunas <= 0) {
		cout << "Dimensoes invalidas: " << linhas << "x" << colunas << endl;
		return;
	}


	cout << "  ";
	for (int j = 0; j < colunas; j++) {
		cout << (char)('A' + j);
	}
	cout << "\n";

	for (int i = 0; i < linhas; i++) {
		cout << (char)('A' + i) << " ";

		for (int j = 0; j < colunas; j++) {
			//prioridade: Jardineiro > Planta > Ferramenta

			char simbolo = conjunto[i][j].getConteudo();
			cout << (simbolo == ' ' ? ' ' : simbolo);
		}
		cout << "\n";
	}
}
bool Jardim::posicionarJardineiro(int l, int c, Jardineiro* j) {
	if (l < 0 || l >= linhas || c < 0 || c >= colunas) {
		cout<<"Fora dos limtes\n" << endl;
		return false;
	}
	removerJardineiro();
	this->jardineiro = j;
	Solo& s = conjunto[l][c];
	s.setJardineiro(j);
	j->setPosicao(l, c);

	if (s.temFerramenta()) {
		cout<<"Encontrei uma ferramenta aqui\n" << endl;
		j->adicionarFerramenta(s.getFerramenta());
		s.setFerramenta(nullptr);
		colocarFerramentaAleatoria();
	}
	return true;
}

void Jardim::removerJardineiro() {
	if (jardineiro != nullptr) {

		int l = jardineiro->getLinha();
		int c = jardineiro->getColuna();
        

		if (l >= 0 && l < linhas && c >= 0 && c < colunas)
			conjunto[l][c].setJardineiro(nullptr);
        

		this->jardineiro = nullptr;
	}
}
Solo* Jardim::getVizinhoLivre(int l, int c, bool apenasVazio) {
    int listaL[4];
    int listaC[4];
    int total = 0;

   // cima
    if (l > 0) {
        bool temPlanta = (conjunto[l - 1][c].getPlanta() != nullptr);

        if (!apenasVazio || !temPlanta) {
            listaL[total] = l - 1;
            listaC[total] = c;
            total++;
        }
    }

    // baixo
    if (l < linhas - 1) {
        bool temPlanta = (conjunto[l + 1][c].getPlanta() != nullptr);

        if (!apenasVazio || !temPlanta) {
            listaL[total] = l + 1;
            listaC[total] = c;
            total++;
        }
    }

    // esquerda
    if (c > 0) {
        bool temPlanta = (conjunto[l][c - 1].getPlanta() != nullptr);

        if (!apenasVazio || !temPlanta) {
            listaL[total] = l;
            listaC[total] = c - 1;
            total++;
        }
    }

    // direita
    if (c < colunas - 1) {
        bool temPlanta = (conjunto[l][c + 1].getPlanta() != nullptr);

        if (!apenasVazio || !temPlanta) {
            listaL[total] = l;
            listaC[total] = c + 1;
            total++;
        }
    }

    // se não encontrou ninguem, retorna nulo
    if (total == 0) return nullptr;

    // sorteia um index entre 0 e (total - 1)
    int sorteado = rand() % total;

    int linhaEscolhida = listaL[sorteado];
    int colunaEscolhida = listaC[sorteado];

    return &conjunto[linhaEscolhida][colunaEscolhida];
}

bool Jardim::removerPlanta(int l, int c) {
	if (l < 0 || l >= linhas || c < 0 || c >= colunas) return false;

	Solo& s = conjunto[l][c];
	if (!s.temPlanta()) {
		cout << "Nao ha planta em " << (char)('a'+l) << (char)('a'+c) << endl;
		return false;
	}

	delete s.getPlanta();
	s.setPlanta(nullptr);
	return true;
}
bool Jardim::adicionarPlanta(int l, int c, char tipo) {
	if (l < 0 || l >= linhas || c < 0 || c >= colunas) return false;

	Solo& s = conjunto[l][c];
	if (s.temPlanta()) {
		cout << "Ja tens uma planta em " << (char)('a'+l) << (char)('a'+c) << endl;
		return false;
	}
	Planta* p = nullptr;
	char t = toupper(tipo);

	if (t == 'C') p = new Cacto(l,c, &s);
	else if (t == 'R') p = new Roseira(&s, l,c);
	else if (t == 'E') p = new ErvaDaninha(l,c,&s);
	else if (t == 'X') p = new BastaoImperador(l,c,&s);
	else {
		cout << "Tipo de planta desconhecido: " << tipo << endl;
		return false;
	}

	s.setPlanta(p);
	return true;
}
void Jardim::atualiza() {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {

			if (conjunto[i][j].temPlanta()) {
				conjunto[i][j].getPlanta()->passaTempo();
			}
			if (conjunto[i][j].temFerramenta()) {
				conjunto[i][j].getFerramenta()->deteriora();
			}
		}
	}
}
string Jardim::listarPlantas() const {
	int i,j;
	std::ostringstream oss;
	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			if (conjunto[i][j].temPlanta()) {
				oss<<conjunto[i][j].getPlanta()->mostrarDetalhes();
				oss<<conjunto[i][j].mostrarDetalhes()<<endl;

			}
		}
	}

	return oss.str();
}
string Jardim::lPlanta(int l, int c) const {
	std::ostringstream oss;
	Solo& s= conjunto[l][c];
	if (s.temPlanta()) {
		oss << s.getPlanta()->mostrarDetalhes() << endl;
		oss << "Solo : Agua " << s.getAguaSolo() << " | Nutri " << s.getNutriSolo() << endl;
	} else {
		oss << "Nao existe nenhuma planta nesta posicao." << endl;
	}
	return oss.str();
}
string Jardim::lArea() const {
	int i,j;
	std::ostringstream oss;

	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			if (conjunto[i][j].temPlanta()||conjunto[i][j].temJardineiro()||conjunto[i][j].temFerramenta()) {
				oss<<conjunto[i][j].mostrarDetalhes()<<endl;
			}
		}
	}
	return oss.str();
}
string Jardim::lSolo(int l,int c,int r) const {

	std::ostringstream oss;
	for (int i = l - r; i <= l + r; i++) {
		for (int j = c - r; j <= c + r; j++) {
			if (i >= 0 && i < linhas && j >= 0 && j < colunas) {
				const Solo& s = conjunto[i][j];
				oss << "Posicao " << (char)('a' + i) << (char)('a' + j) << ": "
					 << s.mostrarDetalhes() << endl;
			}
			else
				oss << "Posicao " << (char)('a' + i) << (char)('a' + j) <<"fica fora do jardim"<<endl;
		}
	}
	return oss.str();
}
bool Jardim::removeJardineiro(int l, int c) {
	if (l >= 0 && l < linhas && c >= 0 && c < colunas) {
		conjunto[l][c].setJardineiro(nullptr);
		this->jardineiro = nullptr;
		return true;
	}
	return false;
}