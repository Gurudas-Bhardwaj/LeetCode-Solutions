#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int insertPos = 0;

    // First pass: move all non-zero elements forward
    for (int num : nums) {
        if (num != 0) {
            nums[insertPos++] = num;
        }
    }

    // Second pass: fill the rest with zeros
    while (insertPos < nums.size()) {
        nums[insertPos++] = 0;
    }
}


int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    // Output result
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
