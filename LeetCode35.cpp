/*************************************************************************
	> File Name: LeetCode35.cpp
	> Author: 
	> Mail:
	> Created Time: 2020年03月03日 星期二 18时25分25秒
 ************************************************************************/
int searchInsert(int* nums, int numsSize, int target){
    int ind = 0 ;
    if(numsSize == 0) return 0;
    for(; ind < numsSize; ind++) {
        if(nums[ind] >= target) break;    
    }
    return ind;
}
