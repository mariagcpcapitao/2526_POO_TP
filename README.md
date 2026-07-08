# Simulação de Jardim - POO

Trabalho prático da unidade curricular **Programação Orientada a Objetos (POO)**, em C++.

## Descrição

Simulação de um jardim com plantas, um jardineiro e ferramentas de manutenção. O sistema modela o crescimento e cuidado de diferentes tipos de plantas (rosas, cactos, ervas daninhas) através de ações como regar, adubar e podar.

## Principais classes

| Classe | Papel |
|---|---|
| `Jardim` | Representa o espaço com as plantas |
| `Jardineiro` | Agente que realiza ações sobre o jardim |
| `Planta` (+ `Roseira`, `Cacto`, `ErvaDaninha`) | Hierarquia de plantas com comportamentos próprios |
| `Ferramenta` (+ `Regador`, `TesouraPoda`, `BastaoImperador`, `FerramentaZ`) | Ferramentas usadas pelo jardineiro |
| `Adubo`, `Solo` | Recursos que afetam o crescimento das plantas |
| `GestorComandos` | Processa comandos/instruções da simulação |
| `Simulacao` | Ciclo principal que corre a simulação |

## Conceitos de POO aplicados

- Herança e polimorfismo (hierarquia `Planta` / `Ferramenta`)
- Encapsulamento
- [outros conceitos usados — ex: composição, interfaces abstratas, sobrecarga de operadores]

## Como compilar

Projeto com `CMakeLists.txt`:

\`\`\`bash
mkdir build && cd build
cmake ..
make
./[nome_do_executável]
\`\`\`

## Autor

Maria Capitão
