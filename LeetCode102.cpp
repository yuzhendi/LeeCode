/*************************************************************************
	> File Name: LeetCode102.cpp
	> Author: 果冻
	> Mail: 1316215578@qq.com 
	> Created Time: 2020年02月29日 星期六 15时57分48秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int getDepth(struct TreeNode *root) {
     if(root == NULL) return 0;
     int l = getDepth(root->left);
     int r = getDepth(root->right);
     return (l > r ? l : r) + 1; 
 }
void getCnt(struct TreeNode *root, int k, int *cnt) {
    //求每层节点的个数
    if(root == NULL) return ;
    cnt[k] += 1;
    getCnt(root->left, k + 1, cnt);
    getCnt(root->right, k + 1, cnt);
    return ;
}
void getResult(struct TreeNode *root, int k, int *cnt, int ** ret) {
    if(root == NULL) return ;
    ret[k][cnt[k]++] = root->val;
    getResult(root->left, k + 1, cnt, ret);
    getResult(root->right, k + 1, cnt, ret);  
    return ;
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = getDepth(root);
    int **ret = (int **)malloc(sizeof(int *) * depth);
    int *cnt = (int *)calloc(depth, sizeof(int));
    getCnt(root, 0, cnt);
    //cnt[0] = 1;//第0层节点的个数
    for(int i = 0; i < depth; i++) {
        ret[i] = (int *)malloc(sizeof(int ) * cnt[i]);
        cnt[i] = 0;//重新初始化，防止备用
    }
    getResult(root, 0, cnt, ret);//此时cnt清零了
    *returnSize = depth;
    *returnColumnSizes = cnt;//将数组传出去（int * 表示一个整数的指针， int** 表示数组的指针）
    return ret;
}
