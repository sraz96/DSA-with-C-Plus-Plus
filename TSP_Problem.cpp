#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int calculateTourDistance(const vector<int>& tour, const vector<vector<int>>& graph) {
    int distance = 0;
    int n = tour.size();

    for (int i = 0; i < n - 1; i++) {
        int u = tour[i];
        int v = tour[i + 1];
        distance += graph[u][v];
    }

    distance += graph[tour[n - 1]][tour[0]];

    return distance;
}

void tspBruteForce(const vector<vector<int>>& graph, vector<int>& tour, vector<int>& bestTour, int& minDistance, int city, int n, int& visited) {
    if (visited == (1 << n) - 1) {
        int currentDistance = calculateTourDistance(tour, graph);

        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            bestTour = tour;
        }
        return;
    }

    for (int nextCity = 0; nextCity < n; nextCity++) {
        if ((visited & (1 << nextCity)) == 0) {
            visited |= (1 << nextCity);
            tour.push_back(nextCity);

            tspBruteForce(graph, tour, bestTour, minDistance, nextCity, n, visited);

            visited &= ~(1 << nextCity);
            tour.pop_back();
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = graph.size();

    int startCity = 0;

    vector<int> bestTour;
    int minDistance = INF;

    int visited = 1 << startCity;

    vector<int> tour = {startCity};

    tspBruteForce(graph, tour, bestTour, minDistance, startCity, n, visited);

    cout << "Optimal Tour: ";
    for (int city : bestTour) {
        cout << city << " ";
    }
    cout << startCity << endl;

    cout << "Optimal Tour Distance: " << minDistance << endl;

    return 0;
}
