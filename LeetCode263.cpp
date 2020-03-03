/*************************************************************************
	> File Name: LeetCode263.cpp
	> Author:
	> Mail:
	> Created Time: 2020年03月03日 星期二 18时10分15秒
 ************************************************************************/
bool isUgly(int num){
    if(num < 1) return false;
    while(num % 5 == 0) {
        num /= 5;
    }
    while(num % 3 == 0) {
        num /= 3;
    }
    while(num % 2 == 0) {
        num >>= 1;
    }
    return num == 1;
}
