#include <iostream>
#include <climits>
using namespace std;

const int INF = INT_MAX;
const int V = 12; 
const int stages = 3; 

int shortestPath(int graph[V][V]) {
    int dist[V][stages + 1];

    for (int i = 0; i < V; i++)
        for (int j = 0; j <= stages; j++)
            dist[i][j] = INF;

    for (int i = 1; i <= V; i++)
        dist[i][stages] = 0;

    for (int stage = stages - 1; stage >= 1; stage--) {
        for (int vertex = 1; vertex <= V; vertex++) {
            for (int i = 1; i <= V; i++) {
                if (graph[vertex - 1][i - 1] != INF) {
                    dist[vertex][stage] = min(dist[vertex][stage], graph[vertex - 1][i - 1] + dist[i][stage + 1]);
                }
            }
        }
    }

    return dist[1][1];
}

int main() {
    int graph[V][V] = {
        {INF, 2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, 3, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, 1, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, 5, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, 2, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, 1, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, 2, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}
    };

    int result = shortestPath(graph);

    cout << "Shortest Path Cost: " << result << endl;

    return 0;
}
