//problem number 701 in leetcode : 

#include <iostream>
using namespace std;


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
    void insert(TreeNode* root, int val){
        TreeNode* last = nullptr;
        TreeNode* inserted = new TreeNode(val);

        while(root != nullptr){
            last = root;
            if(val > root->val)
                root = root->right;
            else if(val < root->val)
                root = root->left;
        }

        if(val > last->val)
            last->right = inserted;
        else
            last->left = inserted;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            return new TreeNode(val);
        }

        insert(root, val);

        return root;
    }
};

// In-order traversal to print BST values in sorted order
void inorderTraversal(TreeNode* root) {
    if(root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Free tree memory
void deleteTree(TreeNode* root) {
    if(root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Create initial BST:
    //     4
    //    / \
    //   2   7

    TreeNode* node2 = new TreeNode(2);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* root = new TreeNode(4, node2, node7);

    // Insert value
    int val = 5;

    Solution sol;
    TreeNode* updatedRoot = sol.insertIntoBST(root, val);

    // Print in-order traversal of updated BST
    cout << "In-order traversal after insertion: ";
    inorderTraversal(updatedRoot);
    cout << endl;

    // Free memory
    deleteTree(updatedRoot);

    return 0;
}
