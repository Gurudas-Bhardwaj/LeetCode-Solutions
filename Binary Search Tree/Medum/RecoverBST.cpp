#include <iostream>
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
    void helper(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if (root == NULL) return;

        helper(root->left, first, second, prev);

        if (prev != NULL && prev->val > root->val) {
            if (first == NULL)
                first = prev;
            second = root;
        }
        prev = root;

        helper(root->right, first, second, prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;

        helper(root, first, second, prev);

        swap(first->val, second->val);
    }
};

// Utility function to do in-order traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Test the code
int main() {
    /*
        Construct the following BST:
                 3
                / \
               1   4
                  /
                 2

        Nodes 2 and 3 are swapped to make it:
                 2
                / \
               1   4
                  /
                 3
    */

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);

    cout << "Before recovery (in-order): ";
    inorder(root);
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "After recovery (in-order): ";
    inorder(root);
    cout << endl;

    return 0;
}
