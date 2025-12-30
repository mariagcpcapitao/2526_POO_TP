#include "Planta.h"
#include "Settings.h"
#include <string>

#include "Solo.h"

Planta::Planta(Solo *solo, int agua, int nutrientes, string beleza, int posLinha, int posColuna, char simbolo) : solo_hosp(solo), agua(agua), nutrientes(nutrientes), beleza(beleza), posLinha(posLinha), posColuna(posColuna), simbolo(simbolo)
{

}
Planta::~Planta(){}
void Planta::passaTempo() {
	cout << "planta reage nsei como " << endl;
}
void Planta::absorveAgua(int posLinha, int posColuna) {}
void Planta::absorveNutrientes(int posLinha, int posColuna) {}
void Planta::perdeAgua(int posLinha, int posColuna){}
void Planta::perdeNutri(int posLinha, int posColuna) {}
//void Planta::multiplica(int posLinha, int posColuna) {}
void Planta::morre() {}
