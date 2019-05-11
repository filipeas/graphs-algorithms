/*
 * Algoritmo de Prim
 *
 * Implementação do algoritmo com estruturas estáticas.
 * 
 * Base teórica:
 * http://www.codcad.com/lesson/45
 * https://www.programiz.com/dsa/prim-algorithm
 * 
 * Bibliotecas necessárias:
 * <iostream>
 * <cstring>
 * 
 * Desenvolvido por:
 * Filipe A.S - https://github.com/filipeas
 * 
 */

using namespace std;

void prim(int tipo)
{

    // instancia do grafo para ser usado no algoritmo
    int grafo_gerado[n][n];

    switch(tipo){
        case 1:
            cout << "grafo completo" << endl;
            /**
             * gerando grafo completo
             */
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i >= j){
                    grafo_gerado[i][j] = 0; 
                    }else{
                        grafo_gerado[i][j] = rand() % 100 + 1;
                    }
                }
            }
            for(int i = 0; i < n; i++){
                cout << "[ ";
                for(int j = 0; j < n; j++){
                    if(i > j){
                    grafo_gerado[i][j] = grafo_gerado[j][i]; 
                    }
                    cout << grafo_gerado[i][j] << " ";
                }
                cout << "], " << endl;
            }
        break;
        case 2:
            cout << "grafo incompleto" << endl;
            /**
             * gerando grafo incompleto
             */
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i >= j){
                    grafo_gerado[i][j] = 0; 
                    }else{
                        grafo_gerado[i][j] = ((rand() % 10) % 2) == 0;
                    }
                }
            }
            for(int i = 0; i < n; i++){
                cout << "[ ";
                for(int j = 0; j < n; j++){
                    if(i > j){
                    grafo_gerado[i][j] = grafo_gerado[j][i]; 
                    }
                    cout << grafo_gerado[i][j] << " ";
                }
                cout << "], " << endl;
            }
        break;
    }



    // REALIZAR CALCULO DE DESEMPENHO A PARTIR DAQUI:



    // número de arestas
    int no_edge;
 
    // criando um array para rastrear o vértices
    // selecionado. Caso encontre, será verdadeiro,
    // se não, falso.
    int selecionado[n];
  
    // inicializando array
    memset (selecionado, false, sizeof (selecionado));
 
    // inicializando o número de arestas
    no_edge = 0;
 
    // OBS: o número de arestas será sempre menor que
    // o número de vértices, (V - 1), onde V é o número
    // de vértices.
 
    // escolhendo o primeiro vértices e setando-o como verdadeiro
    selecionado[0] = true;
 
    int x;            //  número de linhas
    int y;            //  número de colulas
 
    // print para cada aresta seu respectivo peso
    cout << "aresta" << " : " << "peso";
    cout << endl;
    while (no_edge < n - 1) {
 
        // Para cada vértice no conjunto S, encontre todos os vértices adjacentes
        // calcule a distância do vértice selecionado no passo 1.
        // se o vértice já estiver no conjunto S, descarte-o de outra forma
        // escolha outro vértice mais próximo do vértice selecionado no passo 1.
 
        int min = INFINITO;
        x = 0;
        y = 0;
    
        for (int i = 0; i < n; i++) {
            if (selecionado[i]) {
                for (int j = 0; j < n; j++) {
                if (!selecionado[j] && grafo_gerado[i][j]) {
                    if (min > grafo_gerado[i][j]) {
                        min = grafo_gerado[i][j];
                        x = i;
                        y = j;
                    }
        
                }
            }
            }
        }
        // printando resultado
        cout << x <<  " - " << y << " :  " << grafo_gerado[x][y];
        cout << endl;
        selecionado[y] = true;
        no_edge++;
    }
}

/**
 * Função responsável por realizar o calculo e o print do metodo de prim.
 */
void print_prim(int n_vertices, int tipo)
{
    // inicializando vértices e arestas
    n = n_vertices;

    cout << "qtd de vertices = " << n << endl;

    prim(tipo);
}