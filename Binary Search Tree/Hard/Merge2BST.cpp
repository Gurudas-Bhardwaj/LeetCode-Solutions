#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert value into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Print BST inorder (sorted)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


void helper(TreeNode* root, vector<int>&inorder){
    if(root == NULL) return;

    helper(root->left, inorder);

    inorder.push_back(root->val);

    helper(root->right, inorder);
}


TreeNode* buildFromSorted(vector<int>result, int start, int end){
    if(start>end) return NULL;
    
    int mid = start+(end-start)/2;

    TreeNode* root = new TreeNode(result[mid]);

    root->left = buildFromSorted(result, start, mid-1);
    root->right = buildFromSorted(result, mid+1, end);

    return root;
    
}


TreeNode* mergeTwoBSTs(TreeNode* root1, TreeNode* root2) {
    
    vector<int> inorder1, inorder2, result;

    helper(root1, inorder1);
    helper(root2, inorder2);

    int i=0, j=0;

    while(i<inorder1.size() && j<inorder2.size()){
        if(inorder1[i] >= inorder2[j]){
            result.push_back(inorder2[j]);
            j++;
        }
        else if(inorder1[i] <= inorder2[j]){
            result.push_back(inorder1[i]);
            i++;
        }
    }

    while(i<inorder1.size()){
        result.push_back(inorder1[i]);
        i++;
    }

    while(j<inorder2.size()){
        result.push_back(inorder2[j]);
        j++;
    }


    return buildFromSorted(result, 0, result.size()-1);
}

int main() {
    // Create first BST
    TreeNode* bst1 = nullptr;
    vector<int> vals1 = {1,2,5,8,10};
    for (int v : vals1) bst1 = insertBST(bst1, v);

    // Create second BST
    TreeNode* bst2 = nullptr;
    vector<int> vals2 = {1,3,4,5,6,7,8,9};
    for (int v : vals2) bst2 = insertBST(bst2, v);

    cout << "BST1 inorder: ";
    inorder(bst1);
    cout << "\n";

    cout << "BST2 inorder: ";
    inorder(bst2);
    cout << "\n";

    // Merge two BSTs (currently returns nullptr)
    TreeNode* mergedBST = mergeTwoBSTs(bst1, bst2);

    cout << "Merged BST inorder: ";
    if (mergedBST)
        inorder(mergedBST);
    else
        cout << "(empty - merge function not implemented)";
    cout << "\n";

    return 0;
}
