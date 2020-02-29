/*************************************************************************
	> File Name: LeetCode100.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年02月29日 星期六 14时27分05秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL) return 1;
    if((p == NULL &&  q!= NULL) || (p!= NULL  && q == NULL )) {
        return 0;
    }
    if(p->val == q->val)  {
        return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);

    }else return 0;
}
