//
// Created by 1663m on 29/10/2025.
//

#include "Solo.h"

#include "Settings.h"
#include "Utilidades.h"

Solo::Solo() : planta(nullptr), ferramenta(nullptr), jardineiro(nullptr)
{
	setNutriSolo();
	setAguaSolo();
	cout << "Solo criado com valores aleatorios -> " << "Nutrientes: " << nutriSolo << ", Aagua: " << aguaSolo << endl;}

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

void Solo::setPlanta(Plantas* p)
{
	planta = p;
}
void Solo::setFerramenta(Ferramenta* f)
{
	ferramenta = f;
}
void Solo::setJardineiro(Jardineiro* j)
{
	jardineiro = j;
}

Plantas* Solo::getPlanta() const
{
	return planta;
}
Ferramenta* Solo::getFerramenta() const
{
	return ferramenta;
}
Jardineiro* Solo::getJardineiro() const
{
	return jardineiro;
}
bool Solo::temPlanta() const
{
	return planta != nullptr;
}
bool Solo::temFerramenta() const
{
	return ferramenta != nullptr;
}
bool Solo::temJardineiro() const
{
	return jardineiro != nullptr;
}

Solo::~Solo(){}