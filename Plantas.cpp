#include "Plantas.h"
#include "Settings.h"
#include <string>

Plantas::Plantas(int agua, int nutrientes, string beleza, int posLinha, int posColuna, char simbolo) : agua(agua), nutrientes(nutrientes), beleza(beleza), posLinha(posLinha), posColuna(posColuna), simbolo(simbolo)
{
	cout << "construindo planta";
}
void Plantas::absorveAgua(int &agua) {}
void Plantas::absorveNutrientes(int &nutrientes) {}
void Plantas::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna) {}
void Plantas::morre() {}


Cacto::Cacto(int aguaCacto, int nutriCacto, int linha, int coluna) : Plantas(aguaCacto, nutriCacto, "neutra", linha, coluna, 'c')
{
	cout << "a contruir";
}
void Cacto::absorveAgua(int &agua)
{

}
void Cacto::absorveNutrientes(int &nutrientes) {}
void Cacto::multiplica(int &nutrientes, int &agua, int posLinha, int posColuna){}
void Cacto::morre(){}
Cacto::~Cacto(){}

