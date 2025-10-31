//
// Created by 1663m on 29/10/2025.
//

#include "Jardim.h"

#include <iostream>
#include <ostream>
using namespace std;
Jardim::Jardim(int agua, int nutrientes, int l, int c) : agua(agua), nutrientes(nutrientes), linhas(l), colunas(c)
{
	cout << "Construindo Jardim " << linhas << " " << colunas << endl;


}
