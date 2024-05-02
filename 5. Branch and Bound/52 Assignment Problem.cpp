#include <iostream>
#include <vector>

using namespace std;

// Function to print the assignment matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Function to find the maximum value in the matrix
int findMaxValue(const vector<vector<int>>& matrix) {
    int maxValue = matrix[0][0];
    for (const auto& row : matrix) {
        for (int val : row) {
            maxValue = max(maxValue, val);
        }
    }
    return maxValue;
}

// Function to find the minimum value in the matrix
int findMinValue(const vector<vector<int>>& matrix) {
    int minValue = matrix[0][0];
    for (const auto& row : matrix) {
        for (int val : row) {
            minValue = min(minValue, val);
        }
    }
    return minValue;
}

int main() {
    int n;
    cout << "Enter the number of workers and tasks: ";
    cin >> n;

    cout << "Enter the assignment matrix:\n";
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Assignment Matrix:\n";
    printMatrix(matrix);

    int maxValue = findMaxValue(matrix);
    int minValue = findMinValue(matrix);
    cout << "Maximum value in the matrix: " << maxValue << endl;
    cout << "Minimum value in the matrix: " << minValue << endl;

    return 0;
}
