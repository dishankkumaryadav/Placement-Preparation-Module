#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

*************************************************************/
void solve(BinaryTreeNode<int>* root,BinaryTreeNode<int>* &head,BinaryTreeNode<int>* &prev){
    if(!root) return;
    solve(root->left,head,prev);
    if(prev==NULL){
        head=root;
        prev=root;
    }
    else{
    prev->right=root;
    root->left=prev;
    prev=root;
    }
    solve(root->right,head,prev);  
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* head=NULL,*prev=NULL;

    solve(root,head,prev);

    return head;
}