#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int minKey(vector<int>& key, vector<bool>& mstSet) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < key.size(); v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(vector<int>& parent, vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < parent.size(); i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

void primMST(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> parent(n);
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);
    int minCost = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);

    for (int i = 1; i < n; i++)
        minCost += graph[i][parent[i]];

    cout << "Minimum cost of the spanning tree: " << minCost << "\n";
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    primMST(graph);
    return 0;
}
