/*
 * main.cpp - Classe principal
 * 
 * Esta classe é responsável por controlar todas as chamadas
 * dos três algoritmos implementados:
 * Kruskral;
 * Prim;
 * Dijkstra;
 * 
 * Desenvolvido por:
 * Filipe A.S - https://github.com/filipeas
 * 
 */

// <iostream> permite o uso de fluxos de entrada e saída padrão de dados.
#include <iostream>
// <algorithm> define uma coleção de funções especialmente projetada para serem
// usadas em intervalos de elementos. Um intervalo é qualquer sequência de objetos
// que pode ser acessada por meio de iterações ou ponteiros.
#include <algorithm>
// incluindo algoritmo de kruskral
#include "algorithms/kruskal.cpp"

using namespace std;

int main()
{

    // printa kruskal
    print_kruskal();

    return 0;
}