/*************************************************************************
	> File Name: LeetCode1013.cpp
	> Author:
	> Mail:  
	> Created Time: 2020年03月11日 星期三 21时25分22秒
 ************************************************************************/



bool canThreePartsEqualSum(int* A, int ASize){
    int i = 0;
    int sum = 0;
    for (;i<ASize;i++) {
        sum = sum + A[i];
    }
    if(sum%3 != 0) {
        return false;
    }
    int key = sum/3;
    sum = 0;
    int sign = 0;
    for (i = 0; i < ASize; i++) {
        if (sign == 2) {
            return true;
        }
        sum = sum + A[i];
        if (sum == key) {
            sum = 0;
            sign++;
        }
    }
    return false;
}


