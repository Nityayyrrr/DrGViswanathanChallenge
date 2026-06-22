#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    // nums1 ke valid elements ka last index
    int i = m - 1;

    // nums2 ka last index
    int j = n - 1;

    // nums1 ki last position jahan merged elements store honge
    int k = m + n - 1;

    // Dono arrays ko end se compare karke merge karo
    while (i >= 0 && j >= 0) {

        // Jo element bada hai use end me place kar do
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }

        k--;
    }

    // Agar nums2 me kuch elements bach gaye hain
    // to unhe nums1 me copy kar do
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    int m = 3;
    int n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int num : nums1) {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}