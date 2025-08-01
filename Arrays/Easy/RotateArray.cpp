#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return;       // handle empty array
        k = k % n;                // normalize k

        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    sol.rotate(arr, k);

    cout << "Array after rotating by " << k << " steps: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
