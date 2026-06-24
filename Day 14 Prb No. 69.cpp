#include <iostream>
using namespace std;

int mySqrt(int x) {
    long long left = 0, right = x;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == x) {
            return mid;
        } else if (square < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

int main() {
    int x;
    cin >> x;

    cout << mySqrt(x) << endl;

    return 0;
}