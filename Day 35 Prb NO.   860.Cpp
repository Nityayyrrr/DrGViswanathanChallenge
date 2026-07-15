#include <iostream>
#include <vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0;
    int ten = 0;

    for (int bill : bills) {
        if (bill == 5) {
            five++;
        }
        else if (bill == 10) {
            if (five == 0)
                return false;

            five--;
            ten++;
        }
        else { // bill == 20
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            }
            else if (five >= 3) {
                five -= 3;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter number of customers: ";
    cin >> n;

    vector<int> bills(n);

    cout << "Enter the bills (5, 10, or 20): ";
    for (int i = 0; i < n; i++) {
        cin >> bills[i];
    }

    if (lemonadeChange(bills))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}