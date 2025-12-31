//
// Created by luana on 30/12/2025.
//

#include "BastaoImperador.h"
#include "Solo.h"


BastaoImperador::BastaoImperador(int linha, int coluna, Solo* s) : Planta(s, inicial_agua, inicial_nutrientes, "bonita", linha, coluna, 'x') {
	cout<<"plantei bi";
}
void BastaoImperador::absorveAgua(int posLinha, int posColuna){}
void BastaoImperador::absorveNutrientes(int posLinha, int posColuna) {}
void BastaoImperador::perdeAgua(int posLinha, int posColuna){}
void BastaoImperador::perdeNutri(int posLinha, int posColuna) {}
void BastaoImperador::multiplica(Jardim & j, int posLinha, int posColuna){}
void BastaoImperador::morre(){}
BastaoImperador::~BastaoImperador(){}