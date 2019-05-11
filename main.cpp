/*
 * main.cpp - Classe principal
 * 
 * como compilar?
 * g++ main.cpp -o main
 * 
 * Esta classe é responsável por controlar todas as chamadas
 * dos três algoritmos implementados:
 * Kruskral;
 * Prim;
 * Dijkstra;
 * 
 * Base teórica:
 * https://www.ime.usp.br/~pf/algoritmos_para_grafos/
 * http://www.inf.ufpr.br/andre/Disciplinas/BSc/CI065/michel/Intro/intro.html#Completo
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
// <queue> biblioteca responsável por chamar métodos de queue.
#include <queue>
// <vector> biblioteca responsável por chamar métodos de vector.
#include <vector>
// <cstdio> biblioteca  C para executar operações de entrada/saída
#include <cstdio>
// <stdlib.h> necessário p/ as funções rand() e srand()
#include <stdlib.h>
// <time.h> necessário p/ função time()
#include<time.h>
//
#include <stdio.h> 
//
#include <limits.h> 
// 
#include <iostream>
// 
#include <cstring>
//
#include "algorithms/helpers/standards.cpp"
// incluindo algoritmo de kruskral
#include "algorithms/kruskal.cpp"
// incluindo algoritmo de prim
#include "algorithms/prim.cpp"
// incluindo algoritmo de djikstra
#include "algorithms/djikstra.cpp"

using namespace std;


int main()
{
    srand(time(NULL));

    // usuário deve entrar com o número de vértices positivo e diferente de 0
    //e dizer se ele quer um grafo completo ou não completo.
    int n_vertices, tipo;
    cout << "Digite a quantidade de vértices desejada: ";
    cin >> n_vertices;
    cout << "Deseja usar grafo: \n1 - completo\n2 - não completo\nR = ";
    cin >> tipo;

    cout << "\n -- CALCULANDO METODO DE KRUSKAL -- " << endl;
    print_kruskal(n_vertices, tipo);
    cout << "\n -- CALCULANDO METODO DE PRIM -- " << endl;
    print_prim(n_vertices, tipo);
    cout << "\n -- CALCULANDO METODO DE DJIKSTRA -- " << endl;
    print_djikstra(n_vertices, tipo);


    // depois disso, deve ser gerado um gráfico de comparação entre os três
    // algoritmos executados com o mesmo grafo.



    //
    // TESTES
    //

    // printa kruskal
    // print_kruskal();

    // printa prim
    // print_prim();

    // printa djikstra
    // print_djikstra();

    return 0;
}