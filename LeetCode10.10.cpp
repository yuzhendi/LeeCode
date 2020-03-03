/*************************************************************************
	> File Name: LeetCode10.10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 18时12分29秒
 ************************************************************************/
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i,j,t;

    i=m-1;
    j=n-1;
    t=m+n-1;
    //从后往前放
    while (i>=0 && j>=0) {
        if (A[i] > B[j]) {
            A[t--]=A[i];
            i--;
        } else {
            A[t--]=B[j];
            j--;
        }
    }

    while (j>=0) {
        A[t--]=B[j];
        j--;
    }
}
