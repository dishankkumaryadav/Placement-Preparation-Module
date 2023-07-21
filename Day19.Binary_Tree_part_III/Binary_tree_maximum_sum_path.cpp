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
    int solve(TreeNode* root, int &max_sum){
        if(root == NULL)
            return 0;
        int leftSum = max(0, solve(root->left, max_sum));
        int rightSum = max(0, solve(root->right, max_sum));
        max_sum = max(max_sum, leftSum + rightSum + root->val);
        return root->val + max(leftSum, rightSum); // decide which path will it take either it is left or right
    }
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        solve(root,max_sum);
        return max_sum;
    }
};