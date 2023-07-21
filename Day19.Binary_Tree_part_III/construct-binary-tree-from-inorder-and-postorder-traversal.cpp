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
    int findPosition(int element, vector<int> inorder, int n){
        for(int i=0; i<n; i++){
            if(inorder[i] == element){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int> inorder, vector<int> postorder, int &index, int inorderStart, int inorderEnd, int n){
        if(index >=  n || inorderStart>inorderEnd)
            return NULL;
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(element, inorder, n);
        root->right = solve(inorder, postorder, index, position + 1, inorderEnd, n);
        root->left = solve(inorder, postorder, index, inorderStart, position - 1, n);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postorderIndex = n-1;
        TreeNode *ans = solve(inorder, postorder, postorderIndex, 0, n-1, n);
        return ans;
        
    }
};