/*
 * Algoritmo de djikstra
 *
 * Implementação do algoritmo com estruturas estáticas.
 * 
 * Base teórica:
 * http://www.codcad.com/lesson/43
 * https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/dijkstra.html
 * https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
 * 
 * Bibliotecas necessárias:
 * 
 * 
 */

using namespace std;

// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 
   
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[], int n_vertices) 
{ 
   // Initialize min value 
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < n_vertices; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 
   
// A utility function to print the constructed distance array 
void printSolution(int dist[], int n, int n_vertices) 
{ 
   printf("vertice   Distancia ate a origem(definida como 0)\n"); 
   for (int i = 0; i < n_vertices; i++) 
      printf("%d - %d\n", i, dist[i]); 
} 
   
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int src, int n_vertices, int tipo) 
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




     int dist[n_vertices];     // The output array.  dist[i] will hold the shortest 
                      // distance from src to i 
   
     bool sptSet[n_vertices]; // sptSet[i] will be true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
   
     // Initialize all distances as INFINITE and stpSet[] as false 
     for (int i = 0; i < n_vertices; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
   
        // Distance of source vertex from itself is always 0 
        dist[src] = 0; 
   
        // Find shortest path for all vertices 
        for (int count = 0; count < n_vertices-1; count++) 
        { 
            // Pick the minimum distance vertex from the set of vertices not 
            // yet processed. u is always equal to src in the first iteration. 
            int u = minDistance(dist, sptSet, n_vertices); 
   
            // Mark the picked vertex as processed 
            sptSet[u] = true; 
   
            // Update dist value of the adjacent vertices of the picked vertex. 
            for (int v = 0; v < n_vertices; v++) 
        
                // Update dist[v] only if is not in sptSet, there is an edge from  
                // u to v, and total weight of path from src to  v through u is  
                // smaller than current value of dist[v] 
                if (!sptSet[v] && grafo_gerado[u][v] && dist[u] != INT_MAX  
                                            && dist[u]+grafo_gerado[u][v] < dist[v]) 
                    dist[v] = dist[u] + grafo_gerado[u][v]; 
        } 
   
        // print the constructed distance array 
        printSolution(dist, n_vertices, n_vertices); 
} 
   
// driver program to test above function 
void print_djikstra(int n_vertices, int tipo)
{
    dijkstra(0, n_vertices, tipo);
}