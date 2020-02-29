/*************************************************************************
	> File Name: 287.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年02月27日 星期四 18时26分13秒
 ************************************************************************/

int findDuplicate(int* nums, int numsSize){
    // 数字从 1 开始 防止nums[0] = 0 时产生的死循环
    //用快慢指针
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);
    fast = nums[0];//相差一个环的距离
    while(fast != slow) {
        fast = nums[fast];
        slow = nums[slow];
    } 
    return fast;
}
