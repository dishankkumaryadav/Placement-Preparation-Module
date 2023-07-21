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
    int findPosition(vector<int> in, int element, int n){
        for(int i=0; i<n; i++){
            if(in[i] == element)
                return i;
        }
        return -1;
    }
    TreeNode* solve( vector<int>& in,  vector<int>& pre, int &index, int inOrderStart, int inOrderEnd, int n){
        if(index >= n || inOrderStart > inOrderEnd)
            return NULL;
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(in, element, n);

        root->left = solve(in, pre, index, inOrderStart, position -1, n);
        root->right = solve(in, pre, index, position + 1, inOrderEnd, n);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        TreeNode* ans = solve(inorder, preorder, preOrderIndex, 0, inorder.size() - 1, preorder.size());
        return ans;
    }
};