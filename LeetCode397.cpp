/*************************************************************************
	> File Name: LeetCode397.cpp
	> Author:
	> Mail:  
	> Created Time: 2020年03月11日 星期三 21时37分41秒
 ************************************************************************/

unsigned long dfs(unsigned long n, unsigned long cnt)
{
    while((n % 2) == 0) {
        n = n / 2;
        cnt++;
    }

    if (n == 1) {
        return cnt;
    }

    unsigned long cnt1 = dfs(n+1, cnt + 1);
    unsigned long cnt2 = dfs(n-1, cnt + 1);
    return cnt1 < cnt2 ? cnt1 : cnt2;

}
int integerReplacement(int n){
    return dfs((unsigned int)n, 0);
}
