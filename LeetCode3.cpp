/*************************************************************************
	> File Name: LeetCode3.cpp
	> Author:
	> Mail:  
	> Created Time: 2020年03月08日 星期日 21时39分09秒
 ************************************************************************/
int lengthOfLongestSubstring(char * s){
    int start = 0, end = 0, maxlen = 0;
    char map[256] = {0};//强制转换成int 作为字符存储下标；
    map[(int)*(s+start)] = 1;
    
    while( *(s+end) )
    {
        maxlen = maxlen>(end-start+1)?maxlen:(end-start+1);
        ++end;
        while( 0 != map[ (int)*(s+end) ] )//将要加入的新元素与map内元素冲突
        {
            map[ (int)*(s+start) ] = 0;
               ++start;
        }
        map[(int)*(s+end)] = 1;
    }
    
    return maxlen;
}
