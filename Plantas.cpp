#include "Plantas.h"
#include "Settings.h"
#include <string>

Plantas::Plantas(int agua, int nutrientes, string beleza, int posLinha, int posColuna, char simbolo) : agua(agua), nutrientes(nutrientes), beleza(beleza), posLinha(posLinha), posColuna(posColuna), simbolo(simbolo)
{
	cout << "construindo planta";
}
Plantas::~Plantas(){}

void Plantas::absorveAgua(int &agua) {}
void Plantas::absorveNutrientes(int &nutrientes) {}
void Plantas::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna) {}
void Plantas::morre() {}


Cacto::Cacto(int linha, int coluna) : Plantas(aguaCacto, nutriCacto, "neutra", linha, coluna, 'c'){}
void Cacto::absorveAgua(int &agua){}
void Cacto::absorveNutrientes(int &nutrientes) {}
void Cacto::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna){}
void Cacto::morre(){}
Cacto::~Cacto(){}


Roseira::Roseira(int linha, int coluna): Plantas(Settings::Roseira::inicial_agua, Settings::Roseira::inicial_nutrientes, "bonita", linha, coluna, 'r'){}
void Roseira::absorveAgua(int &agua){}
void Roseira::absorveNutrientes(int &nutrientes) {}
void Roseira::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna){}
void Roseira::morre(){}
Roseira::~Roseira(){}

ErvaDaninha::ErvaDaninha(int linha, int coluna): Plantas(Settings::ErvaDaninha::inicial_agua, Settings::ErvaDaninha::inicial_nutrientes, "feia", linha, coluna, 'e'){}
void ErvaDaninha::absorveAgua(int &agua){}
void ErvaDaninha::absorveNutrientes(int &nutrientes) {}
void ErvaDaninha::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna){}
void ErvaDaninha::morre(){}
ErvaDaninha::~ErvaDaninha(){}

BastaoImperador::BastaoImperador(int linha, int coluna): Plantas(inicial_agua, inicial_nutrientes, "bonita", linha, coluna, 'x'){}
void BastaoImperador::absorveAgua(int &agua){}
void BastaoImperador::absorveNutrientes(int &nutrientes) {}
void BastaoImperador::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna){}
void BastaoImperador::morre(){}
BastaoImperador::~BastaoImperador(){}
