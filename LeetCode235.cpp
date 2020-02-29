/*************************************************************************
	> File Name: LeetCode235.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年02月29日 星期六 14时08分58秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 bool is_searve(struct TreeNode *root, struct TreeNode *p) {
     if(root == NULL) return 0;
        if(root == p) return 1;
        return is_searve(root->left, p) || is_searve(root->right, p);

 }
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
   struct TreeNode *ans = root;
   while(ans) {
       if(ans->val > p->val  && ans->val > q->val) {
           ans = ans->left;
       }else if(ans->val < p->val  && ans->val < q->val) {
           ans = ans->right;
       }else {
           return ans;
       }
   }
    return ans;
   
}
