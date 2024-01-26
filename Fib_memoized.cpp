#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& memo) {
    if (n <= 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);

    return memo[n];
}

int main() {
    int n;

    cout << "Enter the value of n for Fibonacci sequence: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        vector<int> memo(n + 1, -1);

        cout << "Fibonacci sequence up to " << n << " terms:" << endl;
        for (int i = 0; i <= n; i++) {
            cout << fibonacci(i, memo) << " ";
        }
        cout << endl;
    }

    return 0;
}
