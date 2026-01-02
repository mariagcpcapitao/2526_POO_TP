#include "Planta.h"
#include "Settings.h"
#include <string>

#include "Solo.h"

Planta::Planta(Solo *solo, int agua, int nutrientes, string beleza, int posLinha, int posColuna, char simbolo) : solo_hosp(solo), agua(agua), nutrientes(nutrientes), beleza(beleza), posLinha(posLinha), posColuna(posColuna), simbolo(simbolo)
{

}
Planta::~Planta(){}
void Planta::passaTempo() {
	cout << "planta reage diferente " << endl;
	this->idade++; // Todas as plantas envelhecem
}
void Planta::absorveAgua(int posLinha, int posColuna, int valor) {}
void Planta::absorveNutrientes(int posLinha, int posColuna, int valor) {}
void Planta::perdeAgua(int posLinha, int posColuna){}
void Planta::perdeNutri(int posLinha, int posColuna) {}
void Planta::multiplica(Jardim * j, int posLinha, int posColuna) {}
void Planta::morre() {}
string Planta::mostrarDetalhes ()const {
	std::ostringstream oss;
	oss << "Simbolo: " << simbolo << " | Pos: (" << (char)('a' + posLinha) << (char)('a' + posColuna) << ")"
		 << " | Agua: " << agua << " | Nutri: " << nutrientes<<" | Beleza:"<<beleza<<endl;
	return oss.str();
}