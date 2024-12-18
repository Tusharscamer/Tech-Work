#include <iostream>
#include <vector>
using namespace std;
#define INF 1e10
void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist = graph;
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != 1000 && dist[k][j] != 1000 && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V = 4;

    vector<vector<int>> graph = {
        {0, 5, 1000, 10},
        {1000, 0, 3, 1000},
        {1000, 1000, 0, 1},
        {1000, 1000, 1000, 0}
    };

    floydWarshall(graph, V);

    return 0;
}
