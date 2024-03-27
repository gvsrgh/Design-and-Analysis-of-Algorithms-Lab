#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
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
    int result = minCoins(coins, amount);
    if (result != -1) {
        cout << "The minimum number of coins required is: " << result << endl;
    } else {
        cout << "No combination can sum to the given amount" << endl;
    }
    return 0;
}
