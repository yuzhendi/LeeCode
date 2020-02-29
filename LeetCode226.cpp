/*************************************************************************
	> File Name: LeetCode226.cpp
	> Author: 
	> Mail:  
	> Created Time: 2020年02月29日 星期六 18时47分17秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){

        if (root==NULL) {
            return root;
        } else {
           struct TreeNode* treeNode = root->left;
            root->left = root->right;
            root->right = treeNode;
            root->left = invertTree(root->left);
            root->right =invertTree(root->right);          
        }
        return root;
}
