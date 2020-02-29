/*************************************************************************
	> File Name: LeetCode110.cpp
	> Author: 果冻
	> Mail: 1316215578@qq.com 
	> Created Time: 2020年02月29日 星期六 16时55分15秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Depth(struct TreeNode *root) {
    if(root == NULL) return 0;
    int l = Depth(root->left), r = Depth(root->right);
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL) return true;
    int l = Depth(root->left), r = Depth(root->right);
    if(abs(l - r) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

