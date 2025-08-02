#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void helper(TreeNode* root, int k, vector<int>& arr){
        if(root ==  NULL) return;
        helper(root->left, k, arr);
        arr.push_back(root->val);
        helper(root->right, k, arr);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        helper(root, k, arr);
        int i=0, j=arr.size()-1;
        while(i<j){
            int result = arr[i]+arr[j];
            if(result == k) return true;
            else if(k > result) i++;
            else if(k < result) j--;
        }
        return false;
    }
};

// Main function to test the findTarget function
int main() {
    // Create nodes
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2, node1, node3);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(4, node2, node6);

    // Create solution instance
    Solution sol;
    
    int k = 7;
    bool result = sol.findTarget(node4, k);

    if (result)
        cout << "Found two elements in BST that sum to " << k << endl;
    else
        cout << "No elements in BST found that sum to " << k << endl;

    // Free memory
    delete node1;
    delete node3;
    delete node2;
    delete node6;
    delete node4;

    return 0;
}
