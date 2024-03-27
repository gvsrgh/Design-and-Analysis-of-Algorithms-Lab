#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void minCoins(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>());
    int n = coins.size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            ans.push_back(coins[i]);
        }
    }

    if (amount > 0) {
        cout << "No solution is possible" << endl;
    } else {
        cout << "The coins needed are: ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int amount, n;
    cout << "Enter the total amount: ";
    cin >> amount;
    cout << "Enter the number of different coins: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter the values of the coins: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    minCoins(coins, amount);
    return 0;
}
