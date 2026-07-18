#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int digits = to_string(nums[i]).length();
            if (digits % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {12, 345, 2, 6, 7896};
    cout << "Output: " << sol.findNumbers(nums1) << endl;  // 2

    vector<int> nums2 = {555, 901, 482, 1771};
    cout << "Output: " << sol.findNumbers(nums2) << endl;  // 1

    return 0;
}