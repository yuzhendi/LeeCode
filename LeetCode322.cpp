/*************************************************************************
	> File Name: LeetCode322.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月08日 星期日 22时12分14秒
 ************************************************************************/

#define min(a,b) ((a) < (b) ? (a) : (b))
int coinChange(int* coins, int coinsSize, int amount){
    //假设 f(n) 代表要凑齐金额为 n 所要用的最少硬币数量，那么有：
    //f(n) = min(f(n - c1), f(n - c2), ... f(n - cn)) + 1
    //动态规划
    int i, j, dp[amount + 1];//需要硬币的数量
    dp[0] = 0;
    for( i = 1; i < amount + 1; ++i) {//i 表示面值的大小
        dp[i] = INT_MAX;
        for(j = 0;j < coinsSize;++j)
        {
            if(i >= coins[j])
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
