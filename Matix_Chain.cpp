#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(const vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> dimensions = {10, 30, 5, 60};

    int minMultiplications = matrixChainMultiplication(dimensions);
    cout << "Minimum scalar multiplications needed: " << minMultiplications << endl;

    return 0;
}
