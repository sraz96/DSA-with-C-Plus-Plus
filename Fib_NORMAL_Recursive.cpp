#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
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
