/*************************************************************************
	> File Name: LeetCode66.cpp
	> Author: 
	> Mail:  
	> Created Time: 2020年03月03日 星期二 19时39分02秒
 ************************************************************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int flag = 0;
    for(int i = 0; i < digitsSize; i++) {
        if(digits[i] == 9) continue;
        flag = 1;break;
    }
    if(flag == 0) {
        //特殊情况 全为9
        int *ans = (int *)malloc(sizeof(int) * (digitsSize + 1));
        for(int i = 0; i < digitsSize + 1; i++) {
            if(!i) ans[i] = 1;
            else ans[i] = 0;
        }
        *returnSize = digitsSize + 1;
        return ans;
    }
    if(digitsSize == 1) {
        digits[0] += 1;
    }
    for(int i = digitsSize - 1; i > 0; i--) {
        if(i == digitsSize - 1) {
            digits[i] += 1;
        }
        if(digits[i] >= 10) {
            digits[i - 1]  += 1;
            digits[i] = digits[i] % 10;
        }
    }
    *returnSize = digitsSize;
    return digits;
}
