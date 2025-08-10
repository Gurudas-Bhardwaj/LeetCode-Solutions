#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL) return NULL;

    if(root->val == val) return root;

    else if(root->val < val) return searchBST(root->right, val);
    
    return searchBST(root->left, val);

}

int main() {
    // Example BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* result = searchBST(root, 2);
    if (result) cout << "Found: " << result->val << endl;
    else cout << "Not Found" << endl;

    return 0;
}
