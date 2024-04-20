#include <iostream>
#include <vector>

using namespace std;

// Function to print the Hamiltonian cycle
void printSolution(vector<int>& x, int n) {
    cout << "Hamiltonian Cycle: ";
    for (int i = 1; i <= n; ++i)
        cout << x[i] << " ";
    cout << x[1] << endl; // Print the first vertex again to complete the cycle
}

// Function to check if adding vertex j to position k in the path x is valid
bool isValid(int k, int j, vector<int>& x, vector<vector<int>>& graph) {
    if (graph[x[k - 1]][j] == 0) // Check if there's an edge between previous vertex and current vertex
        return false;
    for (int i = 1; i < k; ++i) // Check if the vertex has already been included
        if (x[i] == j)
            return false;
    return true;
}

// Function to find the next valid value for position k in the path x
void nextValue(int k, vector<int>& x, vector<vector<int>>& graph, int n) {
    do {
        x[k] = (x[k] + 1) % (n + 1); // Move to the next vertex
        if (x[k] == 0)
            return; // If no valid vertex is found, return
        if (graph[x[k - 1]][x[k]] != 0) { // Check if there's an edge between previous vertex and current vertex
            int j;
            for (j = 1; j < k; ++j) { // Check if the current vertex is already included
                if (x[j] == x[k])
                    break;
            }
            if (j == k) { // If the current vertex is not already included, return
                if (k < n || (k == n && graph[x[n]][x[1]] != 0))
                    return; // Ensure last vertex is connected to the first vertex
                // If not all vertices are included, then continue searching
            }
        }
    } while (true);
}

// Function to find the Hamiltonian cycle starting from position k in the path x
void hamiltonian(int k, vector<int>& x, vector<vector<int>>& graph, int n) {
    do {
        nextValue(k, x, graph, n); // Find the next valid value for position k
        if (x[k] == 0)
            return; // If no valid vertex is found, return
        if (k == n) {
            printSolution(x, n); // If all vertices are included, print the Hamiltonian cycle
        } else {
            hamiltonian(k + 1, x, graph, n); // Recursively find the Hamiltonian cycle for the next position
        }
    } while (true);
}

int main() {
    int n, Edges;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0)); // Adjacency matrix representation
    cout << "Enter the number of edges: ";
    cin >> Edges;
    for (int i = 0; i < Edges; i++) {
        int src, dest;
        cout << "Enter edge " << i + 1 << " (source destination): ";
        cin >> src >> dest;
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }
    vector<int> x(n, 0); // Initialize the array to store the Hamiltonian cycle
    x[1] = 1; // Start from vertex 1
    hamiltonian(2, x, graph, n); // Find the Hamiltonian cycle starting from position 2
    return 0;
}
