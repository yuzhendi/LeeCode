/*************************************************************************
	> File Name: LeetCode53.cpp
	> Author:
	> Mail: 
	> Created Time: 2020年03月03日 星期二 18时55分37秒
 ************************************************************************/
int maxSubArray(int* nums, int numsSize){
    int max = nums[0];
    int b = 0;
    for(int i = 0; i < numsSize; i++) {
        b += nums[i];
        if(b > max) max = b;
        if(b < 0) b = 0;// 重新计数
    }
  return max;
}

