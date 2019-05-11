/*
 * Algoritmo de kruskal
 *
 * Implementação do algoritmo com estruturas estáticas.
 * 
 * Base teórica:
 * https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/kruskal.html
 * http://www.codcad.com/lesson/44
 * 
 * Bibliotecas necessárias:
 * <iostream>
 * <algorithm>
 * 
 * Desenvolvido por:
 * Filipe A.S - https://github.com/filipeas
 * 
 */

using namespace std;

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
 * PARAMETROS:
 * int n: número de vértices
 * 
 * RETORNA:
 * print do resultado.
 */
void print_kruskal(int n, int tipo)
{
    // número de arestas
    int m;

    switch (tipo){
    // caso 1: para grafo completo
    case 1:
        // número de arestas para um grafo completo(usando a fórmula)
        m = (n * (n - 1)) / 2;
        break;
    
    // caso 2: para grafo não completo
    case 2:
        // número de arestas para um grafo completo(modificando a fórmula para gerar 1 aresta a menos)
        m = ((n * (n - 1)) / 2) - 1;
        break;
    default:
        break;
    }

    cout << "qtd de arestas = " << m << endl;
    
    // preenchendo estrutura corretamente, de forma automática.
    // OBS: precisa consertar quando ele estiver gerando os vertices das arestas,
    // pois ele está gerando arestas com vertices inexistentes.
    for(int i = 1; i <= m; i++){
        // armazenando os vértices
        aresta[i].x = i;
        // armazenando as arestas
        aresta[i].y = (i == m ? 1 : (i + 1));
        // armazenando os pesos(de forma aleatória entre 1 e 100)
        aresta[i].dis = rand() % 100 + 1;

        cout << "[" << aresta[i].x << ", " << aresta[i].y << ", " << aresta[i].dis << "]," << endl;
    }


    // REALIZAR CALCULO DE DESEMPENHO A PARTIR DAQUI:
    

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
    int peso_final = 0;
    cout << "aresta \t: " << "peso\t" << endl;
    for(int i = 1; i < n; i++){
        peso_final += mst[i].dis;
        cout << mst[i].x << " - " << mst[i].y << " \t:" << mst[i].dis << "\n";
    }
    cout << "peso final = " << peso_final << endl;
}