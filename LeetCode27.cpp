/*************************************************************************
	> File Name: LeetCode27.cpp
	> Author:
	> Mail:
	> Created Time: 2020年03月03日 星期二 18时16分40秒
 ************************************************************************/
int removeElement(int* nums, int numsSize, int val){
    int ind = 0;//表示插入的位置
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == val) continue;
        nums[ind++] = nums[i];
    }
    return ind;
}
