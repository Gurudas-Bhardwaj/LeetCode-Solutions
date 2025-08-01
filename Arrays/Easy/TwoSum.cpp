#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < arr.size(); i++) {
            int first = arr[i];
            int second = target - first;

            if (hash.find(second) != hash.end()) {
                return {i, hash[second]};
            } else {
                hash[first] = i;
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    if (result[0] != -1) {
        cout << "Indices found: " << result[0] << " and " << result[1] << endl;
        cout << "Numbers are: " << nums[result[0]] << " and " << nums[result[1]] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }

    return 0;
}
