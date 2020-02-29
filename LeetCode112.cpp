/*************************************************************************
	> File Name: LeetCode112.cpp
	> Author:
	> Mail:  
	> Created Time: 2020年02月29日 星期六 18时36分33秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum){
    if(root == NULL) return false;
    if(!root->left && !root->right) return root->val == sum;

    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

