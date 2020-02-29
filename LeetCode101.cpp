/*************************************************************************
	> File Name: LeetCode101.cpp
	> Author: 果冻
	> Mail: ma6174@163.com 
	> Created Time: 2020年02月29日 星期六 14时48分25秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool ismirror(struct TreeNode *p, struct TreeNode *q) {
    if(!p && !q) {
        return true;
    }
    if(!p || !q) {
        return false;//有一个为空
    }
    if(p->val == q->val) {
        return ismirror(p->left, q->right) && ismirror(p->right , q->left);
    }
    return false;
}

bool isSymmetric(struct TreeNode* root){
    return ismirror(root, root);
}
