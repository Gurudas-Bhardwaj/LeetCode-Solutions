#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void helper(TreeNode* root, TreeNode* target, TreeNode*& pred, TreeNode*& succ, TreeNode*& prev, bool& found){
        if(root == NULL) return;   

        helper(root->left, target, pred, succ, prev, found);

        if(found){
            succ = root;
            found = false;
            return;
        }

        if(root->val == target->val){
            pred = prev;
            found = true;
        }
        

        prev = root;

        helper(root->right, target, pred, succ, prev, found);
        
    }

    pair<TreeNode*, TreeNode*> findPreSuc(TreeNode* root, TreeNode* target) {
        TreeNode* pred = NULL;
        TreeNode* succ = NULL;
        TreeNode* prev = NULL;
        bool found = false;

        helper(root, target, pred, succ, prev, found);

        return {pred, succ};
        
    }
};

// Helper to insert into BST (used to construct the BST)
TreeNode* insertBST(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insertBST(root->left, key);
    else root->right = insertBST(root->right, key);
    return root;
}

// Helper to build BST from vector (level-order null as -1)
TreeNode* buildBST(const vector<int>& vals) {
    TreeNode* root = nullptr;
    for (int val : vals) {
        if (val != -1)
            root = insertBST(root, val);
    }
    return root;
}

// Helper to find node with value == target
TreeNode* findNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (root->val == key) return root;
    if (key < root->val) return findNode(root->left, key);
    return findNode(root->right, key);
}

void printResult(TreeNode* pre, TreeNode* suc) {
    cout << "Predecessor: " << (pre ? to_string(pre->val) : "null")
         << ", Successor: " << (suc ? to_string(suc->val) : "null") << endl;
}

int main() {
    Solution sol;

    // Existing test cases
    vector<int> vals1 = {20, 8, 22, 4, 12, -1, -1, -1, -1, 10, 14};
    TreeNode* root1 = buildBST(vals1);
    TreeNode* target1 = findNode(root1, 4);   // Minimum node (no predecessor)
    auto res1 = sol.findPreSuc(root1, target1);
    printResult(res1.first, res1.second);

    vector<int> vals2 = {50, 30, 70, 20, 40, 60, 80};
    TreeNode* root2 = buildBST(vals2);
    TreeNode* target2 = findNode(root2, 80);  // Maximum node (no successor)
    auto res2 = sol.findPreSuc(root2, target2);
    printResult(res2.first, res2.second);

    vector<int> vals3 = {15, 10, 20, 8, 12, 16, 25};
    TreeNode* root3 = buildBST(vals3);
    TreeNode* target3 = findNode(root3, 12);  // Node with predecessor and successor
    auto res3 = sol.findPreSuc(root3, target3);
    printResult(res3.first, res3.second);

    // Additional test case 4: Target is root node
    vector<int> vals4 = {40, 20, 60, 10, 30, 50, 70};
    TreeNode* root4 = buildBST(vals4);
    TreeNode* target4 = findNode(root4, 40);  // Root node
    auto res4 = sol.findPreSuc(root4, target4);
    printResult(res4.first, res4.second);

    // Additional test case 5: Target is leaf node with both predecessor and successor
    vector<int> vals5 = {25, 15, 35, 10, 20, 30, 40};
    TreeNode* root5 = buildBST(vals5);
    TreeNode* target5 = findNode(root5, 20);
    auto res5 = sol.findPreSuc(root5, target5);
    printResult(res5.first, res5.second);

    // Additional test case 6: Target node with only one child
    vector<int> vals6 = {10, 5, 15, -1, -1, 12};
    TreeNode* root6 = buildBST(vals6);
    TreeNode* target6 = findNode(root6, 15);
    auto res6 = sol.findPreSuc(root6, target6);
    printResult(res6.first, res6.second);

    return 0;
}
