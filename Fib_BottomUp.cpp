#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;

    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;

    cout << "Enter the value of n for Fibonacci sequence: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        cout << "Fibonacci sequence up to " << n << " terms:" << endl;
        for (int i = 0; i <= n; i++) {
            cout << fibonacci(i) << " ";
        }
        cout << endl;
    }

    return 0;
}
