#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void inorder(BinaryTreeNode<int> *root, vector<int> &ans){
    if(root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

void preorder(BinaryTreeNode<int> *root, vector<int> &ans){
    if(root == NULL)
        return;
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

void postorder(BinaryTreeNode<int> *root, vector<int> &ans){
    if(root == NULL)
        return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> result;
    vector<int> in1, pre, post;
    inorder(root, in1);
    preorder(root, pre);
    postorder(root, post);

    result.push_back(in1);
    result.push_back(pre);
    result.push_back(post);

    return result;
}