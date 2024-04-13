#include <iostream>
#include <vector>

using namespace std;

// Function to find the optimal binary search tree
void optimalBST(vector<float>& p, vector<float>& q, int n) {
    vector<vector<float>> w(n + 2, vector<float>(n + 1, 0));
    vector<vector<int>> r(n + 1, vector<int>(n + 1, 0));
    vector<vector<float>> c(n + 2, vector<float>(n + 1, 0));

    // Step 1
    for (int i = 0; i <= n; i++) {
        w[i][i] = q[i];
        r[i][i] = i;
        c[i][i] = 0;
        c[i][i+1] = q[i] + q[i+1] + p[i+1];
        w[i][i+1] = q[i] + q[i+1] + p[i+1];
        r[i][i+1] = i+1;
    }
    w[n+1][n] = q[n];
    r[n][n] = 0;
    c[n+1][n] = 0.0;

    // Step 2
    for (int d = 2; d <= n + 1; d++) {
        for (int i = 0; i <= n - d + 1; i++) {
            int j = i + d - 1;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            int m = r[i][j - 1];
            float min = c[i][m - 1] + c[m][j];
            for (int k = m + 1; k <= r[i + 1][j]; k++) {
                float val = c[i][k - 1] + c[k][j];
                if (val < min) {
                    min = val;
                    m = k;
                }
            }
            c[i][j] = w[i][j] + min;
            r[i][j] = m;
        }
    }

    cout << "Cost of optimal binary search tree: " << c[0][n] << endl;
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;

    vector<float> p(n + 1); // Probability of successful search
    vector<float> q(n + 1); // Probability of unsuccessful search

    cout << "Enter the probabilities of successful search:\n";
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    cout << "Enter the probabilities of unsuccessful search:\n";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    optimalBST(p, q, n);

    return 0;
}
