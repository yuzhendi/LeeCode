/*************************************************************************
	> File Name: LeetCode58.cpp
	> Author:
	> Mail: 
	> Created Time: 2020年03月03日 星期二 19时15分57秒
 ************************************************************************/
int lengthOfLastWord(char * s){
    int ans = 0;
    int index = 0;
    //先定位到字符串尾部
    while(s[index]){
        index++;
    }
    index--;
    //从后往前读
    //过滤空格
    while(index>=0 && s[index]==' '){
        index--;
    }
    //读取单词
    while(index>=0 && s[index]!=' '){
        index--;
        ans++;
    }
    return ans;
}
