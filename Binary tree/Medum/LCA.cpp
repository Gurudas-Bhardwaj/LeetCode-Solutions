
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
        if(p->val == root->val || q->val == root->val) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL && right == NULL) return NULL;
        if(left != NULL && right != NULL) return root;

        return left == NULL ? right : left;
}



int main() {
    /*
           3
          / \
         5   1
        / \ / \
       6  2 0  8
         / \
        7   4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;        // node 5
    TreeNode* q = root->left->right->right; // node 4

    TreeNode* ans = lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << ans->val << endl;

    return 0;
}
