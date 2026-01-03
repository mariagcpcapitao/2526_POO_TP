//
// Created by luana on 30/12/2025.
//

#include "FerramentaZ.h"

FerramentaZ::FerramentaZ() : Ferramenta("Luvas", 'z'){}
void FerramentaZ::usar(Solo& s) {
    if (s.temPlanta()) {
        s.removerPlanta();
        cout << "Usou as luvas para arrancar a planta do solo." << endl;

        this->durabilidade -= 5;
    } else {
        cout << "Nao ha planta para arrancar aqui." << endl;
    }
    if (this->durabilidade < 0) this->durabilidade = 0;
}

FerramentaZ::~FerramentaZ(){}
string FerramentaZ::mostrarDetalhes() const {
    std::ostringstream oss;

    oss << Ferramenta::mostrarDetalhes();
    string estado;
    if (durabilidade >= 90) {
        estado = "Praticamente novas";
    } else if (durabilidade >= 70) {
        estado = "Sujas, mas dao para o gasto";
    } else if (durabilidade >= 40) {
        estado = "Com alguns buracos";
    } else if (durabilidade >= 10) {
        estado = "Gastas e a precisar de reforma";
    } else {
        estado = "COMPRA MAIS";
    }
    oss << " | Estado atual : " << estado << endl;
    return oss.str();
}