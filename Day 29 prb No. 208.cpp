#include <iostream>
using namespace std;

int findIndex(string haystack, string needle) {

    int n = haystack.length();
    int m = needle.length();

    for (int i = 0; i <= n - m; i++) {

        int j = 0;

        while (j < m && haystack[i + j] == needle[j]) {
            j++;
        }

        if (j == m)
            return i;
    }

    return -1;
}

int main() {

    string haystack, needle;

    cout << "Enter haystack: ";
    cin >> haystack;

    cout << "Enter needle: ";
    cin >> needle;

    cout << "Index = " << findIndex(haystack, needle);

    return 0;
}