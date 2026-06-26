#include <iostream>
using namespace std;

int smallestEvenMultiple(int n) {
    if (n % 2 == 0) {
        return n;
    }
    return n * 2;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Smallest Even Multiple: " << smallestEvenMultiple(n);

    return 0;
}