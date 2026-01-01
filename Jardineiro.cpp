

#include "Jardineiro.h"
#include "Ferramenta.h"
#include "Jardim.h"
Jardineiro::Jardineiro()
{
	posLinha = -1;
	posColuna = -1;
	noJardim = false;
	ferramentaNaMao = nullptr;
	entradasNoTurno = 0;
	saidasNoTurno = 0;
}
Jardineiro::~Jardineiro() {

	for (Ferramenta* f : inventario) {
		delete f;
	}
	inventario.clear();

	if (ferramentaNaMao != nullptr) delete ferramentaNaMao;
}


void Jardineiro::resetTurno() {
	movEfetuados = 0;
	entradasNoTurno = 0;
	saidasNoTurno = 0;
	pColhidas = 0;
	pPlantadas = 0;
}

void Jardineiro::adicionarFerramenta(Ferramenta* f) {
	if (f == nullptr) return;
	inventario.push_back(f);
	quant_ferramentas++;
	cout << "Ferramenta " << f->getSimbolo() << " guardada no inventario." << endl;
}
void Jardineiro::usarFerramenta(Solo& s) {
	if (ferramentaNaMao == nullptr) {
		return;
	}
	ferramentaNaMao->usar(s);
}
bool Jardineiro::mover(char direcao, Jardim* jardim) {
	if (jardim == nullptr) return false;

	if (movEfetuados == Settings::Jardineiro::max_movimentos) {
		cout<<"Neste turno ja me movimentei 10 vezes, estou cansado\n";
		return false;
	}

	int proxL = posLinha;
	int proxC = posColuna;

	if (direcao == 'e') proxC--;
	else if (direcao == 'd') proxC++;
	else if (direcao == 'c') proxL--;
	else if (direcao == 'b') proxL++;

	if (jardim->posicionarJardineiro(proxL, proxC, this)) {
		movEfetuados++;
		cout<<movEfetuados<<endl;

		return true;
	}

	return false;
}
bool Jardineiro::sai(Jardim* jardim) {
	if (jardim == nullptr || !noJardim) {
		std::cout << "Erro: O jardineiro ja esta fora do jardim.\n";
		return false;
	}
	if (jardim->removeJardineiro(posLinha, posColuna)) {

		setPosicao(-1,-1);


		std::cout << "Jardineiro: Saia com sucesso. Ferramentas guardadas na mochila.\n";
		return true;
	}

	return false;

}
bool Jardineiro::colher(int l, int c, Jardim* jardim) {
	if (jardim == nullptr) return false;

	if (pColhidas >= Settings::Jardineiro::max_colheitas) {
		cout << "O jardineiro esta cansado de colher ." << endl;
		return false;
	}

	if (jardim->removerPlanta(l, c)) {
		pColhidas++;
		return true;
	}
    
	return false;
}
bool Jardineiro::plantar(int l, int c, char tipo, Jardim* jardim) {
	if (jardim == nullptr) return false;


	if (pPlantadas >= Settings::Jardineiro::max_plantacoes) {
		cout << "O jardineiro esta cansado de plantar ." << endl;
		return false;
	}

	if (jardim->adicionarPlanta(l, c, tipo)) {
		pPlantadas++;
		return true;
	}

	return false;
}
void Jardineiro::atualizaFerramentas() {
	if (ferramentaNaMao != nullptr) {
		ferramentaNaMao->deteriora();
	}
	for (Ferramenta* f : inventario)
		if (f != nullptr) {
			f->deteriora();
		}
}

void Jardineiro::largaFerramenta() {
	if (ferramentaNaMao == nullptr) {
		cout << "Nao tens nenhuma ferramenta na mao para largar." << endl;
		return;
	}

	inventario.push_back(ferramentaNaMao);
	cout << "Ferramenta " << ferramentaNaMao->getSimbolo()
		 << " ID: " << ferramentaNaMao->getId() << " guardada no inventario." << endl;

	ferramentaNaMao = nullptr;
}

bool Jardineiro::pegaFerramenta(int id) {
	auto it=inventario.begin();
	for (; it != inventario.end(); ++it) {
		if ((*it) != nullptr && (*it)->getId() == id) {

			if (ferramentaNaMao != nullptr) {
				largaFerramenta();
			}

			ferramentaNaMao = *it;
			inventario.erase(it);

			std::cout << "Ferramenta (ID: " << id << ") agora esta na tua mao." << std::endl;
			return true;
		}
	}

	std::cout << "Erro: Nao transportas nenhuma ferramenta com o ID " << id << "." << std::endl;
	return false;
}
string Jardineiro::listarFerramentas() const {
	std::ostringstream oss;
	oss << "\nFerramentas do Jardineiro:\n" << endl;

	if (ferramentaNaMao != nullptr) {
		oss << "Na mao:";
		oss<<ferramentaNaMao->mostrarDetalhes();
	} else {
		oss << "Mao vazia" << endl;
	}

	if (inventario.empty()) {
		oss << "Inventario vazio." << endl;
	} else {
		oss << "Inventario: \n" << endl;
		for (auto it = inventario.begin(); it != inventario.end(); ++it) {

			oss<<(*it)->mostrarDetalhes();
		}
	}
	return oss.str();
}

