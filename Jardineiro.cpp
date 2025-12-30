

#include "Jardineiro.h"
#include "Ferramenta.h"
#include "Jardim.h"
Jardineiro::Jardineiro()
{

}
Jardineiro::~Jardineiro(){}


void Jardineiro::resetTurno() {
	movEfetuados = 0;
	jaEntrouNoTurno = false;
	jaSaiuNoTurno = false;
	pColhidas = 0;
	pPlantadas = 0;
}
void Jardineiro::comprarFerramenta(Ferramenta *f){}
void Jardineiro::adicionarFerramenta(Ferramenta* f){}
void Jardineiro::usarFerramenta(Solo& s){}
bool Jardineiro::mover(char direcao, Jardim* jardim) {
	if (jardim == nullptr) return false;

	if (movEfetuados > 10) {
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
		return true;
	}

	return false;
}
bool Jardineiro::colher(int l, int c, Jardim* jardim) {
	if (jardim == nullptr) return false;

	if (pColhidas >= 5) {
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


	if (pPlantadas >= 2) {
		cout << "O jardineiro ja plantou 2 neste turno, esta cansado." << endl;
		return false;
	}

	// 2. O Jardineiro tenta colocar a planta no Jardim
	if (jardim->adicionarPlanta(l, c, tipo)) {
		pPlantadas++;
		return true;
	}

	return false;
}
void Jardineiro::atualizaFerramentas() {
	ferramentaNaMao->deteriora();
	for (int i=0; i<quant_ferramentas;++i) {
		inventario[i]->deteriora();
	}
}



