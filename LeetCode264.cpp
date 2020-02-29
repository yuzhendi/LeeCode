/*************************************************************************
	> File Name: LeetCode264.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年02月29日 星期六 14时08分05秒
 ************************************************************************/

int min(int a, int b, int c) {
   if(a > b) {
       a = b;
   }
   if(a > c) {
       a = c;
   }
    return a;
}

int nthUglyNumber(int n){
    if(n <= 0) return 0;
    int ans[n];
   // int *ans = (int *)malloc(sizeof(int) * (n+1));
     ans[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0;
    for(int i = 1; i < n; i++) {
        int ugly1 = ans[p2] * 2;
        int ugly2 = ans[p3] * 3;
        int ugly3 = ans[p5] * 5;
        ans[i] = min(ugly1, ugly2, ugly3);
        if(ugly1 == ans[i]) {
            p2++;
        }
         if(ugly2 == ans[i]) {
            p3++;
        }
        if(ugly3 == ans[i]) {
            p5++;
        }
    }
    int end = ans[n-1];
    //free(ans);
    return end; 
}
