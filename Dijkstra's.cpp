#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

const int V = 5; 

int minDistance(const vector<int>& dist, const set<int>& sptSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet.count(v) && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(const vector<int>& dist) {
    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "        " << dist[i] << endl;
}

void dijkstra(const vector<vector<int>>& graph, int src) {
    vector<int> dist(V, INT_MAX); 
    set<int> sptSet; 

    dist[src] = 0; 
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet.insert(u);

        for (int v = 0; v < V; v++) {
            if (!sptSet.count(v) && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {0, 0, 3, 8, 5},
        {0, 0, 0, 0, 7},
        {0, 0, 0, 0, 9},
        {0, 0, 0, 0, 0}
    };

    int src = 0; 

    dijkstra(graph, src);

    return 0;
}
