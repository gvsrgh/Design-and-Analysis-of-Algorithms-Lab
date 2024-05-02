#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Function to compute the cost of the given path
int computeCost(const vector<vector<int>>& graph, const vector<int>& path) {
    int cost = 0;
    int n = graph.size();
    for (int i = 0; i < n - 1; ++i) {
        int from = path[i];
        int to = path[i + 1];
        if (graph[from][to] == 0) // If no edge between two nodes, return infinite cost
            return INF;
        cost += graph[from][to];
    }
    // Add cost to return to starting node
    cost += graph[path[n - 1]][path[0]];
    return cost;
}

// Function to recursively explore the search space using Branch and Bound
void branchAndBound(const vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited, int& minCost, int level, int n) {
    if (level == n) { // If all nodes are visited
        minCost = min(minCost, computeCost(graph, path)); // Update minimum cost
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) { // If ith node is not visited
            visited[i] = true; // Mark it as visited
            path[level] = i; // Add it to the current path
            if (computeCost(graph, path) < minCost) // Pruning: if the current path has higher cost than minCost, ignore it
                branchAndBound(graph, path, visited, minCost, level + 1, n);
            visited[i] = false; // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter the adjacency matrix representing the distances between cities:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<int> path(n); // Store the current path
    vector<bool> visited(n, false); // Keep track of visited nodes
    int minCost = INF; // Initialize minimum cost to maximum value

    // Start from city 0
    visited[0] = true;
    path[0] = 0;

    // Call the Branch and Bound algorithm
    branchAndBound(graph, path, visited, minCost, 1, n);

    if (minCost == INF)
        cout << "No feasible solution exists.\n";
    else
        cout << "Minimum cost of the tour: " << minCost << endl;

    return 0;
}
