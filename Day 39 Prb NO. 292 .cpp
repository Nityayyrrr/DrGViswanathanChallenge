#include <iostream>

using namespace std;

bool canWinNim(int n) {

    return n % 4 != 0;

}

int main() {

    int n;

    cout << "Enter number of stones: ";
    cin >> n;

    if(canWinNim(n))
        cout << "true";
    else
        cout << "false";

    return 0;
}