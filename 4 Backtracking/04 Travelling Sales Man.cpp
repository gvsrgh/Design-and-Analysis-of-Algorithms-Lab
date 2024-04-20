#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Define infinity

// Function to generate permutations of cities
void generatePermutations(vector<int>& cities, vector<vector<int>>& permutations, int index) {
    if (index == cities.size()) {
        permutations.push_back(cities);
        return;
    }
    for (int i = index; i < cities.size(); ++i) {
        swap(cities[i], cities[index]);
        generatePermutations(cities, permutations, index + 1);
        swap(cities[i], cities[index]);
    }
}

// Function to calculate the total distance of a path
int calculateTotalDistance(const vector<int>& path, const vector<vector<int>>& distances) {
    int totalDistance = 0;
    for (int i = 0; i < path.size() - 1; ++i) {
        totalDistance += distances[path[i]][path[i + 1]];
    }
    totalDistance += distances[path[path.size() - 1]][path[0]]; // Return to the starting city
    return totalDistance;
}

int main() {
    int n; // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n;

    // Input distances between cities
    vector<vector<int>> distances(n, vector<int>(n));
    cout << "Enter the distances between cities:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> distances[i][j];
        }
    }

    // Generate cities
    vector<int> cities(n);
    for (int i = 0; i < n; ++i) {
        cities[i] = i;
    }

    // Generate permutations of cities
    vector<vector<int>> permutations;
    generatePermutations(cities, permutations, 0);

    int minDistance = INF;
    vector<int> minPath;
    
    // Find the path with minimum total distance
    for (const auto& path : permutations) {
        int totalDistance = calculateTotalDistance(path, distances);
        if (totalDistance < minDistance) {
            minDistance = totalDistance;
            minPath = path;
        }
    }

    // Output the optimal path and its distance
    cout << "Optimal Path: ";
    for (int city : minPath) {
        cout << city << " ";
    }
    cout << minPath[0] << endl; // Return to the starting city
    cout << "Total Distance: " << minDistance << endl;

    return 0;
}
