#include <iostream>
using namespace std;

int fib(int n) {

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    int first = 0;
    int second = 1;
    int current;

    for (int i = 2; i <= n; i++) {
        current = first + second;
        first = second;
        second = current;
    }

    return current;
}

int main() {

    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci Number = " << fib(n);

    return 0;
}