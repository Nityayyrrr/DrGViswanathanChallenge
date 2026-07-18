#include <iostream>
#include <vector>
#include <string>

using namespace std;

string intToRoman(int num) {
    vector<pair<int, string>> roman = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

    string result = "";

    for (auto &p : roman) {
        while (num >= p.first) {
            result += p.second;
            num -= p.first;
        }
    }

    return result;
}

int main() {
    int num;

    cout << "Enter a number (1-3999): ";
    cin >> num;

    if (num < 1 || num > 3999) {
        cout << "Invalid input! Please enter a number between 1 and 3999." << endl;
        return 1;
    }

    cout << "Roman Numeral: " << intToRoman(num) << endl;

    return 0;
}