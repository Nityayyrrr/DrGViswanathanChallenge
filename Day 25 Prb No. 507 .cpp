#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;

        int sum = 1;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;

                if (i != num / i)
                    sum += num / i;
            }
        }

        return sum == num;
    }
};

int main() {
    Solution obj;

    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (obj.checkPerfectNumber(num))
        cout << "True";
    else
        cout << "False";

    return 0;
}