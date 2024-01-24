#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    int number;

    cout << "Enter a non-negative integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        cout << "Factorial of " << number << " is: " << factorial(number) << endl;
    }

    return 0;
}
