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

/*
 * /**
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
 int getPathCnt(struct TreeNode *root) {
     //得到叶子节点的个数
     if(root == NULL) return 0;
     if(!root->left && !root->right) return 1;
     return getPathCnt(root->left) + getPathCnt(root->right);
 }
 int getResult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
     if(root == NULL) return 0;
     len += sprintf(buff + len, "%d", root->val);//先传值到一个数组中
     buff[len] = 0;//清空
    if(root->left == NULL && root->right == NULL) {
            ret[k] = strdup(buff);// k 表示路径的下标
            return 1;
        }
    len += sprintf(buff + len,"->");
    int cnt = getResult(root->left, len, k, ret, buff);//cnt 表示偏移量，及以此层k为基准来存放下面的路径
    cnt += getResult(root->right, len, k + cnt, ret, buff);
    return cnt;
 }
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathCnt = getPathCnt(root);//路径的数量；
    char **ret = (char **)malloc(sizeof(char *) * pathCnt);
    int max_len = 1024;
    char *buff = (char *)malloc(sizeof(char) * max_len);
    getResult(root, 0, 0, ret, buff);
    *returnSize = pathCnt;
    return ret;
}
