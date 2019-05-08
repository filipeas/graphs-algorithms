/*
 * Algoritmo de kruskal
 *
 * Implementação do algoritmo com estruturas estáticas.
 * 
 * Base teórica:
 * https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/kruskal.html
 * http://www.codcad.com/lesson/44
 * 
 * Desenvolvido por:
 * Filipe A.S - https://github.com/filipeas
 * 
 */

using namespace std;

// máximo de vértices:
#define MAXN 50500
// máximo de arestas:
#define MAXM 200200

/**
 * Estrutura que representa uma aresta.
 * dis = peso.
 * x = vértice x.
 * y = vértice y.
 */
struct t_aresta
{
    int dis;
    int x;
    int y;
};

/**
 * Função que verifica se a distancia da aresta a é
 * menor que a de b.
 * 
 * return bool = menor peso.
 */
bool comp(t_aresta a, t_aresta b)
{
    return a.dis < b.dis;
}

// Estrutura estática da classe
t_aresta aresta[MAXM];

// Para utilizar o union find
int pai[MAXN];
int peso[MAXN];

// instanciando a arvore
t_aresta mst[MAXM];

/**
 * Funções do union find.
 */

int find(int x)
{
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);

    if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }
}

/**
 * Método que faz todo o processo de entrada e tratamento de dados.
 * 
 * Retorna print do resultado.
 */
void print_kruskal()
{
    // número de vértices e arestas
    int n, m;

    // lendo as entradas para teste
    cin >> n >> m;
    
    // percorrer a quantidade de arestas.
    // enquanto tiver, preencha a estrutura
    for(int i = 1; i <= m; i++){
        cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
    }

    // inicializar os pais para o union find:
    for(int i = 1; i <= n; i++){
        pai[i] = i;
    }

    // ordenando as arestas pelo menor peso
    sort(aresta + 1, aresta + m + 1, comp);

    int size = 0;

    for(int i = 1; i <= m; i++){
        // se estiverem em componentes distintas:
        if(find(aresta[i].x) != find(aresta[i].y)){
            join(aresta[i].x, aresta[i].y);

            mst[++size] = aresta[i];
        }
    }

    // printando resultado final, linha a linha
    // formato:
    // vertice_x vertice_y peso_da_aresta
    for(int i = 1; i < n; i++){
        cout << mst[i].x << " " << mst[i].y << " " << mst[i].dis << "\n";
    }
}