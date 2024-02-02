#include <iostream>
#include <vector>
using namespace std;

int lcsLength(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

string lcs(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = m, j = n;
    string result;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            result = X[i - 1] + result;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return result;
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCAB";

    int length = lcsLength(X, Y);
    cout << "Length of LCS: " << length << endl;

    string sequence = lcs(X, Y);
    cout << "LCS: " << sequence << endl;

    return 0;
}
