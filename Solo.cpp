//
// Created by 1663m on 29/10/2025.
//

#include "Solo.h"

#include "Settings.h"
#include "Utilidades.h"

Solo::Solo(int nutri, int agua) : nutriSolo(nutri), aguaSolo(agua)
{
	setNutriSolo();
	setAguaSolo();
	cout << "Solo criado com valores aleatórios -> " << "Nutrientes: " << nutriSolo << ", Água: " << aguaSolo << endl;}

void Solo::setNutriSolo()
{
	nutriSolo = Utilidades::obterValorAleatorio(
	   Settings::Jardim::nutrientes_min,
	   Settings::Jardim::nutrientes_max
   );
}
void Solo::setAguaSolo()
{
	aguaSolo = Utilidades::obterValorAleatorio(
		Settings::Jardim::agua_min,
		Settings::Jardim::agua_max
	);
}
Solo::~Solo(){}