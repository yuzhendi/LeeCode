/*************************************************************************
	> File Name: LeetCode543.cpp
	> Author: 
	> Mail:  
	> Created Time: 2020年03月11日 星期三 21时34分53秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max_dep(struct TreeNode *root) {
    if(root == NULL) return 0;
    int l = max_dep(root->left), r = max_dep(root->right);
    return l > r ? (l + 1) : (r + 1);
}

int diameterOfBinaryTree(struct TreeNode* root){
    int ans = 0;
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;
    int l = max_dep(root->left), r = max_dep(root->right);
    ans = l + r;//等于左右子树的最大高度和
    int l_ans = diameterOfBinaryTree(root->left), r_ans = diameterOfBinaryTree(root->right);
    int temp = l_ans > r_ans ? l_ans : r_ans;
    return ans > temp ? ans : temp;
}
