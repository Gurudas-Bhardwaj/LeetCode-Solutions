#include <iostream>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    bool ans = true;
    long long last = LONG_MIN;

    void helper(TreeNode* root){
        if(root == NULL) return;

        helper(root->left);

        if(root->val <= last){
            ans = false;
        }

        last = root->val;

        helper(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return true;

        helper(root);

        return ans;
    }
};

// Main function to test the isValidBST function
int main() {
    // Create a valid BST:
    //        5
    //       / \
    //      3   7
    //     / \   \
    //    2   4   8

    TreeNode* node2 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3, node2, node4);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7, nullptr, node8);
    TreeNode* node5 = new TreeNode(5, node3, node7);

    Solution sol;
    bool result = sol.isValidBST(node5);

    if (result)
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is NOT a valid BST." << endl;

    // Free memory
    delete node2;
    delete node4;
    delete node3;
    delete node8;
    delete node7;
    delete node5;

    return 0;
}
