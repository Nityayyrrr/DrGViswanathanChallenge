#include <iostream>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {

    string ans = "";

    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {

        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';

        if (j >= 0)
            sum += b[j--] - '0';

        ans += (sum % 2) + '0';
        carry = sum / 2;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    string a, b;

    cout << "Enter first binary string: ";
    cin >> a;

    cout << "Enter second binary string: ";
    cin >> b;

    cout << "Sum = " << addBinary(a, b);

    return 0;
}