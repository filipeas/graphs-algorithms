/*
 * arquivo responsável por armazenar variáveis e estruturas
 * iguais para todos os algoritmos usados no trabalho.
 *
 * Implementação do algoritmo com estruturas estáticas.
 * 
 * Base teórica:
 * 
 * Bibliotecas necessárias:
 * 
 * Desenvolvido por:
 * Filipe A.S - https://github.com/filipeas
 * 
 */

// estabelecendo definições estáticas para os algoritmos
// máximo de vértices:
#define MAXN 50500
// // máximo de arestas:
#define MAXM 200200
// // valor hipoteticamente infinito
#define INFINITO 999999999

using namespace std;

/**
 * essas instâncias são para usar nos algoritmos de djikstra e prim.
 */
// medida de organização
// typedef pair<int, int> pii;
// número de vértices e arestas
int n, m;
// aray de distância(peso) á fonte
// int distancia[MAXN];
// o array que guarda se um vértice foi processado
// int processado[MAXN];
// nossas listas de adjacência. O primeiro elemento do par representa
// a distância e o segundo representa o vértice
// vector<pii> vizinhos[MAXN];