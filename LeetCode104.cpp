/*************************************************************************
	> File Name: LeetCode104.cpp
	> Author: 果冻
	> Mail: 1316215578@11.com
	> Created Time: 2020年02月29日 星期六 14时58分00秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    if(!root->left && !root->right) return 1;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    if(l > r) return l + 1;
    return   r + 1;
}
