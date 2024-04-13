#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Building the dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n; // Number of items
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> val(n); // Values of items
    vector<int> wt(n);  // Weights of items

    cout << "Enter the values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter the weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int W; // Maximum weight that the knapsack can carry
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    // Solve the 0/1 Knapsack problem
    int maxVal = knapsack(W, wt, val, n);
    cout << "Maximum value that can be obtained: " << maxVal << endl;

    return 0;
}
