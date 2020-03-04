/*************************************************************************
	> File Name: LeetCode961.cpp
	> Author:
	> Mail:
	> Created Time: 2020年03月04日 星期三 21时11分25秒
 ************************************************************************/
int repeatedNTimes(int* A, int ASize){
    int ans[10005] = {0};
    for(int i = 0; i < ASize; i++) {
        int ind = A[i];
        ans[ind] += 1;
        if(ans[ind] == 2) {
            return ind;
        }
    }
    return -1;
}
