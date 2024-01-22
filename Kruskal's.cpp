#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void unionSets(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalMST(vector<Edge>& edges, int V) {
    vector<Edge> result;
    vector<Subset> subsets(V);

    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    sort(edges.begin(), edges.end(), compare);

    int i = 0;
    int e = 0;

    while (e < V - 1 && i < edges.size()) {
        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            unionSets(subsets, x, y);
            e++;
        }
    }

    cout << "Edges in the MST:" << endl;
    for (int i = 0; i < e; i++)
        cout << result[i].src << " - " << result[i].dest << "   Weight: " << result[i].weight << endl;
}

int main() {
    vector<Edge> edges = { {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
                           {1, 3, 15}, {2, 3, 4}, {1, 2, 7} };

    int V = 4;

    kruskalMST(edges, V);

    return 0;
}
