/*************************************************************************
	> File Name: LeetCode26.cpp
	> Author:
	> Mail: 
	> Created Time: 2020年03月03日 星期二 18时08分54秒
 ************************************************************************/
int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    int pre = 0, ind = 0;
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == nums[pre]) continue;
        nums[++pre] = nums[i];
    }
    return pre + 1;
}
