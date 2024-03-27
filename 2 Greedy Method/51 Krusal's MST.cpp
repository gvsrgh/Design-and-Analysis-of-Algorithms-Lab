#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<int> parent, rank;

void makeSet(int n) {
    parent = vector<int>(n);
    rank = vector<int>(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int findSet(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    int n;
    cout << "Enter the number of edges: ";
    cin >> n;
    vector<Edge> edges(n);
    cout << "Enter the edges (start node, end node, weight):\n";
    for (int i = 0; i < n; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    makeSet(n);
    sort(edges.begin(), edges.end());

    vector<Edge> result;
    int minCost = 0;
    for (Edge e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            minCost += e.weight;
            result.push_back(e);
            unionSets(e.u, e.v);
        }
    }

    cout << "Following are the edges in the constructed MST\n";
    for (Edge e : result) {
        cout << e.u << " -- " << e.v << " == " << e.weight << "\n";
    }
    cout << "Minimum Cost Spanning Tree: " << minCost << "\n";

    return 0;
}
