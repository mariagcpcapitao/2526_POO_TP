

#include "Jardineiro.h"
#include "Ferramenta.h"
Jardineiro::Jardineiro()
{

}
Jardineiro::~Jardineiro(){}


void Jardineiro::resetTurno() {
	movEfetivados = 0;
	jaEntrouNoTurno = false;
	jaSaiuNoTurno = false;
	plantasColhidasTurno = 0;
	plantasPlantadasTurno = 0;
}
void Jardineiro::comprarFerramenta(Ferramenta *f){}
void Jardineiro::adicionarFerramenta(Ferramenta* f){}
void Jardineiro::usarFerramenta(Solo& s){}




