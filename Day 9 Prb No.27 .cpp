#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0;  // valid elements ko store karne ka index

    for (int i = 0; i < nums.size(); i++) {
        // agar current element val ke equal nahi hai
        if (nums[i] != val) {
            nums[k] = nums[i];  // valid element ko aage shift karo
            k++;
        }
    }

    return k;  // valid elements ki count return karo
}

int main() {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int k = removeElement(nums, val);

    cout << "k = " << k << endl;
    cout << "Modified array: ";

    // sirf pehle k elements print karo
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}