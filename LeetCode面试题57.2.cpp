/*************************************************************************
	> File Name: LeetCode面试题57.2.cpp
	> Author:
	> Mail: 
	> Created Time: 2020年03月08日 星期日 21时42分01秒
 ************************************************************************/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int len = target / 2 + 1;
    int i = 1, j = 1, sum = 1;//双指针
    int **ans = (int **)malloc(sizeof(int*)*len);
    *returnColumnSizes = (int *)malloc(sizeof(int) * len);
    int cnt = 0;
    while(i <= len) {
        if(sum < target) {
            j++;
            sum += j;
        }else if(sum >target) {
            sum -= i;
            i++;
        }else {
            (*returnColumnSizes)[cnt] = j - i +1;//每一个符合条件的数组的大小
            ans[cnt] =(int *)malloc(sizeof(int) * (j - i + 1));
            for(int x = i, y =0;x <= j; x++, y++) {
                ans[cnt][y] = x;
            }
            cnt++;
            sum -= i;
            i++;
        }
    }
    *returnSize = cnt;
    return ans;
}
