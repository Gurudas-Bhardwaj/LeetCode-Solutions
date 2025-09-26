#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    // Function to calculate the minimum cost of jumping on the stones
    // You need to implement this function
    int frogJump(int n, vector<int>& heights) {
        // Your code here: Implement the logic for the frog jump
        vector<int> dp(n, 0); // dp[i] will store the minimum cost to reach stone i
        
        // Base cases: The frog is already on the first stone
        dp[0] = 0;  // No cost to start at the first stone
        
        for (int i = 1; i < n; ++i) {
            // The frog can either come from i-1 or i-2
            int costFromPrev = dp[i-1] + abs(heights[i] - heights[i-1]);
            int costFromPrev2 = (i > 1) ? dp[i-2] + abs(heights[i] - heights[i-2]) : INT_MAX;
            
            // Choose the minimum of the two possible jumps
            dp[i] = min(costFromPrev, costFromPrev2);
        }
        
        return dp[n-1]; // The minimum cost to reach the last stone
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> heights1 = {10, 30, 40, 20};  // Example 1
    int result1 = sol.frogJump(heights1.size(), heights1);
    cout << "Test Case 1 - Minimum cost: " << result1 << endl;
    cout << (result1 == 30 ? "Accepted" : "Rejected") << endl;

    // Test case 2
    vector<int> heights2 = {10, 20, 30, 10};  // Example 2
    int result2 = sol.frogJump(heights2.size(), heights2);
    cout << "Test Case 2 - Minimum cost: " << result2 << endl;
    cout << (result2 == 20 ? "Accepted" : "Rejected") << endl;

    // Test case 3 (edge case - single stone)
    vector<int> heights3 = {10};  // Only one stone
    int result3 = sol.frogJump(heights3.size(), heights3);
    cout << "Test Case 3 - Minimum cost: " << result3 << endl;
    cout << (result3 == 0 ? "Accepted" : "Rejected") << endl;

    // Test case 4 (edge case - two stones)
    vector<int> heights4 = {1, 100};  // Only two stones
    int result4 = sol.frogJump(heights4.size(), heights4);
    cout << "Test Case 4 - Minimum cost: " << result4 << endl;
    cout << (result4 == 99 ? "Accepted" : "Rejected") << endl;

    return 0;
}
