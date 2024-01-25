#include <iostream>
#include <vector>
using namespace std;

int countWays(int amount, const vector<int>& coins) {
    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
        }
    }

    return dp[n][amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 6;

    cout << "Number of ways to make change: " << countWays(amount, coins) << endl;

    return 0;
}
