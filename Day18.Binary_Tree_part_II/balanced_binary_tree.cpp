/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

int treeHeight(TreeNode * root){
    if(root == NULL)
        return 0;
    int left = treeHeight(root->left);
    int right = treeHeight(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(treeHeight(root->left) - treeHeight(root->right)) <= 1;
        if(left && right && diff)
            return true;
        else
            return false;
    }
};