#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool checkPrimeFrequency(vector<int>& nums) {
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    for (auto it : freq) {
        if (isPrime(it.second))
            return true;
    }

    return false;
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (checkPrimeFrequency(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}