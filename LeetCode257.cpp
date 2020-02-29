/*************************************************************************
	> File Name: LeetCode257.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年02月29日 星期六 14时09分52秒
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(struct TreeNode *root, char ** bin_tree_paths, int *path, int *returnSize, int depth) {
    if(root == NULL) return ;
    int i = 0;
    path[depth++] = root->val;//记录路径的值
    if(!root->left &&  !root->right) {
        bin_tree_paths[*returnSize] = (char *)malloc(100);
        bin_tree_paths[*returnSize][0] = 0;//????
        for(i = 0; i < depth-1; i++) {
            sprintf(bin_tree_paths[*returnSize],"%s%d->", bin_tree_paths[*returnSize],path[i]);//从后面接入
        }
        sprintf(bin_tree_paths[*returnSize],"%s%d", bin_tree_paths[*returnSize],path[i]);//最后一个不要箭头
        (*returnSize) += 1;
        return ; 
    }
    if(root->left != NULL)
    {
        dfs(root->left, bin_tree_paths, path, returnSize, depth);
    }
    
    if(root->right != NULL)
    {
        dfs(root->right, bin_tree_paths,path, returnSize, depth);
    }
    return;  
}   




char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int path[100] = {0}, depth = 0;
    char** bin_tree_paths = (char**)malloc(sizeof(char*) * 100);
    if(root == NULL)
    {
        *returnSize = 0;
        return root;
    }
    *returnSize = 0;
    dfs(root, bin_tree_paths, path, returnSize, depth);
    return bin_tree_paths;
}
