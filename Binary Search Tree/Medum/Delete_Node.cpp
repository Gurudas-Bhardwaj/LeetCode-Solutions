#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* inorder(TreeNode* root){
        if(root == NULL) return NULL;
        while(root->left != NULL){
            root=root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else{
            if(root->left == NULL){
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            }
            else if(root->right == NULL){
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            }
            else{
                TreeNode* inorderPred = inorder(root->right);
                root->val = inorderPred->val;
                root->right = deleteNode(root->right, inorderPred->val);    
            }
        }

        return root;
    }
    
    // Helper function to insert nodes in BST
    TreeNode* insert(TreeNode* root, int key) {
        if (root == nullptr)
            return new TreeNode(key);
        if (key < root->val)
            root->left = insert(root->left, key);
        else if (key > root->val)
            root->right = insert(root->right, key);
        return root;
    }
    
    // Helper function for inorder traversal print
    void inorderPrint(TreeNode* root) {
        if (!root) return;
        inorderPrint(root->left);
        cout << root->val << " ";
        inorderPrint(root->right);
    }
};

int main() {
    Solution sol;
    TreeNode* root = nullptr;

    // Insert nodes to create BST
    int nodes[] = {5, 3, 6, 2, 4, 7};
    for(int val : nodes) {
        root = sol.insert(root, val);
    }

    cout << "Inorder traversal before deletion: ";
    sol.inorderPrint(root);
    cout << endl;

    int key = 3;
    root = sol.deleteNode(root, key);  // Delete node with value 3

    cout << "Inorder traversal after deletion: ";
    sol.inorderPrint(root);
    cout << endl;

    return 0;
}
