/*************************************************************************
	> File Name: LeetCode283.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 18时13分55秒
 ************************************************************************/
void moveZeroes(int* nums, int numsSize){
    int cnt = 0;//表示 0 的数量
    int ind = 0;//表示要插入的位置
    for(int i = 0; ind < numsSize; i++) {
        if(i  >= numsSize ) {
            nums[ind++] = 0;
        }else {
            if(nums[i] == 0) {
                cnt++;
            }else{
                nums[ind++] = nums[i];
            }
        }
    }
}
