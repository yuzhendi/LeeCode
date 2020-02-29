 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int head = 0, tail = 0;
    int n = (numsSize == 0 ? 0 : numsSize - k + 1);//自己求出 n
    int *ans = (int *)malloc(sizeof(int) * n);
    int *q = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = n;
    n = 0;
	for(int i = 0; i < numsSize; i++) {
		while(tail - head && nums[i] > nums[q[tail - 1]]) {
			tail--;//按照降序存放下标		
		}
		q[tail++] = i;
		if(i +1 < k) continue;
		if(i - q[head] == k) head++;//判断头部是否过期
        ans[n++] = nums[q[head]]; 

    }
    free(q);
    return ans;
}
