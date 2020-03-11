/*************************************************************************
	> File Name: LeetCode121.cpp
	> Author: 
	> Mail:  
	> Created Time: 2020年03月11日 星期三 21时28分35秒
 ************************************************************************/

int maxProfit(int* prices, int pricesSize){
int ans = 0;
if(pricesSize <= 1) return 0;
int min = prices[0], max = prices[0];
for(int i = 1; i < pricesSize; i++) {
    if(prices[i] > max) {
        max = prices[i];//更新最大值
        ans = (max - min) > ans ? (max - min) : ans;//和原先的利润比较
    }
    if(prices[i] <min) {
        min = prices[i];//更新最大最小值，重新计算
        max = prices[i];
    }
}
    return ans;

}
